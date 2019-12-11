/// \file main.cpp
/// \mainpage
///
/// \n\n
///
//  ----------------------------------------------------------------------------------
/// Należy utworzyć brakujące pliki 
/// i utworzyć w nich odpowiedni kod, tak aby 
/// program się kompilowal BEZ OSTRZEŻEŃ i poprawnie wykonywał,
/// dając DOKŁADNIE wynik podany w pliku output.txt. 
/// (Należy użyć komendy diff -- patrz porady na końcu pliku).
///  \n\n
/// 
/// Ponadto:
/// a) Należy użyc ***  CMake *** do przygotowania programu
/// -- pliki źrodłowe muszą być w podkatalogu 'src'
/// -- pliki nagłówkowe muszą być w podkatalogu 'include' 
/// -- kod musi się kompilować w nowym podkatalogu (np. 'build')
///    poleceniem 'cmake .. && make' 
/// b) program musi się kompilować z flagami '-Wall -g', jako minimum
/// c) Jako rozwiązanie, proszę przeslać spakowany katalog źrodlowy, 
///    WŁĄCZAJĄC plik main.cpp, ale BEZ katalogu 'build'. 
/// d) Nie wolno modyfikować pliku main.cpp.
//  --------------------------------------------------------------------------------- 
///
///    \n\n


// -----------------------------------------------------------
//
/// *** Klasa Bullet ***
///
/// Prosta klasa implementująca pocisk. Klasa musi zawierać:
/// -- getter 'get_caliber' zwracający kaliber kuli.
/// -- 'głośny' konstruktor nie-domyślny wywołujący funkcję:
///      void click() { std::cout << "-click- "; }
/// -- ewentualny konstruktor domyślny musi być 'cichy'
///     
#include "bullet.h"
// ----------------------------------------------------------


// -----------------------------------------------------------
//
/// *** Klasa Rifle ***
///
/// Klasa implementująca broń długą. Klasa musi implementować następujący
/// mechanizm:
/// a) broń posiada magazynek na N pocisków o kalibrze d określanych 
///    podczas tworzenia broni;
///    Magazynek MUSI być dynamiczną tablicą pointerów
///    (nie można używać STL)
/// b) broń posiada komorę na jeden pocisk
/// c) nabój jest wpowadzony do komory z magazynka metodą 'load'
///    (czyli w magazynku zmniejszamy liczbę naboi)
/// d) metoda 'pull_trigger' powoduje wystrzał broni;
///    Komora jest opróżniana.
///    Podczas wystrzału jest wywołana fcja
///    void bang() { std::cout << "\nBang!" << std::endl;}
///    Musi istnieć przeładowana wersja fcji 'pull_trigger'
///    powalająca na automatyczne oddanie M strzałów.
/// e) metoda 'new_magazine' ładuje magazynek nowymi pociskami
/// f) przy próbie przeładowania (metoda 'load') i braku pocisków
///    w magazynku musi zostać wyświetlona informacja używając fcji:
///    void mag_empty() { std::cout << "Rifle: Magazine empty." << std::endl; }
/// g) przy próbie oddania strzału (metoda 'pull_trigger') i pustej komorze
///    musi zostać wyświetlona informacja używając fcji:
///    void chamb_empty() { std::cout << "Rifle: Chamber is empty. Reload." << std::endl; }
/// 
/// -- klasa musi mieć konstruktor kopiujący
/// -- klasa musi mieć konstruktor przenoszący (brak = -1pkt za wyjście)
/// 
#include "rifle.h"
// --------------------------------------------------------------------     


#include<iostream>


/// --------------------------------------------
/// fcja testująca konstruktor przenoszący
Rifle copy_gun(Rifle rifle) {
	return rifle; }
/// --------------------------------------------



/// -------------------------------------------------------------
int main() {
	

	std::cout << "\n";

	// Tworzymy egzemplarz broni o pojemności magazynka 5
	// i kalibrze 0.32 cala
	Rifle winchester(5,0.32);
	std::cout << "\n";

	// Załadowanie broni (pocisk z mag. do komory)
	winchester.load(); 
	
	// wystrzał:
	winchester.pull_trigger(); 
	
	// próba wystrzału (ale brak pocisku w komorze):
	winchester.pull_trigger(); 
	
	// tryb auto; próba oddania 5 strzałów
	winchester.pull_trigger(5); 
	
	// magazynek jest pusty; przeładowanie:
	winchester.new_magazine();
	std::cout << "\n";
	
	// tryb auto; oddanie 5 strzałów
	winchester.pull_trigger(5); 
	
	
	std::cout << "\n++++++++++++++++\n" << std::endl;

	
	// Nowy egzemplarz broni
	Rifle beretta(6,0.375);
	std::cout << "\n";
	
	// Oddajemy 4 strzały w trybie auto:
	beretta.pull_trigger(4);
	
	// Robimy kopię broni:
	Rifle newgun(copy_gun(beretta));
	
	// Próba oddania 4 strzałów:
	newgun.pull_trigger(4);


	std::cout << "\n";

return 0;}
/// -----------------------------------------------------------------------



/// =======================================================================
///
///    *** Porady/Pomoc ***
///
///  -- Wszystkie krótkie fcje najlepiej zaimplementować w ciele klasy.
///     Poza klasą, implementujemy tylko fcje na wiele linijek.
///     Przyspieszy to pisanie programu.
///  -- Konstruktor kopiujący musi zaalokować nowe tablice, w zależności 
///     od stanu magazynka i komory broni, którą kopiujemy, tak
///     aby stan 'fizyczny' kopii był identyczny jak oryginału.
///  -- Destruktor musi być tak napisany, aby nie powodował crash'u
///     programu przy wywołaniu konstruktora przenoszącego (patrz niżej).
///  -- Konstruktor przenoszący musi umożliwić poprawne uruchomienie
///     destruktora. Np. powinien ustawić wskaźniki na null, tak
///     aby destruktor nie zwalniał komórek pamięci przeniesionego
///     obiektu.
///  -- poprawność wyjścia można sprawdzić komendą:
///     diff output.txt <( ./exec )
///
/// =======================================================================
