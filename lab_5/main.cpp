/// \file main.cpp
/// \mainpage
///
/// \n\n
///
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output.txt. \n\n
///
/// Dodatkowe zastrzezenia (UWAGA: brak spelnienia ktoregokolwiek = 0 pkt):
/// a) Nie wolno uzywac struktur (nalezy uzyc klas).
/// b) Nalezy dolaczyc Makefile aby calosc programu kompilowala
///    sie poleceniem make. 
///    -- MUSI istniec rowniez cel clean, aby polecenie 
///      'make clean' usuwało skompilowane biblioteki i plik wykonywalny.
///    -- musi istniec cel valgrind, ktory uruchamia polecenie 'valgrind --tool=memcheck'
///       na programie wykonywalnym 
///    -- Program musi sie re-kompilowac poleceniem make po modyfikacji plikow naglowkowych.
///    -- Plik wykonywalny musi sie nazywac 'exec'
/// c) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe i naglowkowe, 
///     wlaczajac main (nie wysylamy skompilowanych bibliotek ani pliku wykonywalnego)
/// d) Nie wolno modyfikowac pliku main.cpp.
/// 
///
///    \n\n


#include<iostream>

/// Plik naglowkowy deklarujacy klase Coin, ktora implementuje
/// monete EUR lezaca na stole. Moneta taka lezy losowo 'orlem' (ang. heads) 
/// lub 'reszka' (ang. tails) do gory i posiada wartosc.
/// Zarowno mozliwe wartosci monety (1EUR, 2EUR), jak i
/// widoczna strona monety (heads,tails) powinny byc zdefiniowane 
/// jako nowe typy enum.
/// UWAGA: przynajmniej jedna metoda klasy musi zostac zdefiniowana w pliku
///        zrodlowym coin.cpp
//
#include "coin.h"

/// Plik naglowkowy deklarujacy klase Moneybox. Jest to skarbonka
/// o rozmiarze (maksymalnej liczbie monet) definiowanym podczas 
/// tworzenia instancji klasy.
/// UWAGA 1: nie wolno uzywac kontenerow.
/// UWAGA 2: przynajmniej jedna metoda klasy musi zostac zdefiniowana w pliku
///          zrodlowym moneybox.cpp
//
#include "moneybox.h"


int main() {
	
	std::cout << "\n";

	srand (232113443); // seed dla generator licz pseudo losowych


	unsigned boxsize = 12; // rozmiar skarbonki
	Moneybox box1(boxsize); // tworzymy skarbonke

	Coin oneEUR; // tworzymy monete na stole (losowo jest 'orzel' lub 'reszka')
	std::cout << "I tossed " << oneEUR.get_coin_value() << " EUR and got:" << std::endl;
	oneEUR.print_side_up(); // wyswietla czy orzel czy reszka
	// rzucamy dopoki nie wypadnie reszka
	while (oneEUR.get_side_up()!=tails) {
		oneEUR.toss();
		oneEUR.print_side_up();
	}
	std::string info("I put my coin to the moneybox.");
	std::cout << info << std::endl;
	box1.put_coin(oneEUR); // wrzucamy monete do skarbonki

	Coin twoEUR(two);
	std::cout << "I tossed " << twoEUR.get_coin_value() << " EUR and got:" << std::endl;
	twoEUR.print_side_up();
	box1.put_coin(twoEUR);
	std::cout << info << std::endl;


	// wyswietlamy kwote w skarbonce
	std::cout << "\nMy moneybox has " << box1.get_tot_value() << " EUR in total." << std::endl;


	std::cout << "\n++++++++++++++++++++++++++++++\n\n";

	// nowa skarbonka i test przepelnienia
	unsigned box2size = 24;
	Moneybox box2(box2size);
	for (unsigned k=0;k<box2size+2;++k) {
		Coin coin;	
		box2.put_coin(coin); }
	std::cout << "\nMy moneybox has " << box2.get_tot_value() << " EUR in total." << std::endl;

	std::cout << "\n";

return 0;}

