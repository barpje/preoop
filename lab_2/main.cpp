/// \file main.cpp
/// \mainpage
///
/// Program do szyfrowania i odszyfrowania podanego tekstu
/// przy pomocy szyfru opartego na operacji logicznej XOR. 
/// Wszystkie informacje potrzebne do napisania programu 
/// znajduja sie w komentarzach.
///
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output*.txt.
/// Dodatkowe zastrzezenia:
/// a) Prosze NIE UZYWAC klas (mozna uzywac struktur, ale tylko jako 
/// POD -- plain-old-data). 
/// b) Nalezy napisac Makefile aby calosc programu kompilowala
/// sie poleceniem make.
/// c) W plikach naglowkowych musza znajdowac sie tylko deklaracje funkcji.
/// Definicje prosze umiescic w plikach *.cpp.
/// d) NIE WOLNO uzywac klasy std::string
/// e) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe
/// (czyli bez plikow wykonywalnych i bibliotek)
/// 
/// Sugestie:
/// -- W miare mozliwosci prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///    Typ *wsk = new Typ[rozmiar]; delete [] wsk; (dla tablic)
///
///    \n\n
///
/// Zasady ogolne pracowni: \n
/// 1) Nie wolno modyfikowac pliku main.cc oraz ewentualnych innych 
///  plikow gdzie jest to explicite zastrzezone odpowiednim komentarzem. \n 
/// 2) Nie wolno korzystac z pomocy kolegow/prowadzacego, internetu, notatek,
/// ani zadnych innych materialow (w tym wlasnych wczesniej
/// przygotowanych plikow).\n
/// 2) Kod zrodlowy musi znajdowac sie w katalogu o prawach dostepu 
/// tylko dla uzytkownika.\n
/// 3) Nalezy zadbac o przejrzystosc programu oraz dobre zarzadzanie pamiecia.\n
/// 4) Punktacja: poprawna kompilacja - 2pkt, poprawne wyjscie oraz brak wyciekow pamieci -- 3pkt,
/// dokumentacja -- 1pkt, ocena kodu -- max 4pkt. 
/// Kod musi sie kompilowac oraz dzialac poprawnie aby byl w ogole oceniany.
///
/// POWODZENIA!


#include<iostream>

#include "strings.h"
#include "xorcipher.h"
#include "binaryarr.h"
#include "xorop.h"



int main() {
	
	std::cout << "\n";

	// Zapisujemy obiekt zawierajacy ciag znakow w pamieci komputera.
	// Uzywamy wlasnego typu MyString obslugujacego napisy do 13 znakow.
	// UWAGA: wskazniki do tych obiektow muszą być gdzieś zapamiętane, 
	// a na koncu pamiec zwolniona (patrz koniec programu).
	// Zakladamy, ze maksymalna dozwolona liczba obiektow MyString to 5.
	String *str1 = StringInit("Bare Bones");
	// Wydruk:
	std::cout << "String to be encoded:" << std::endl;
	PrintString(str1);
	// Wydruk postaci binarnej
	std::cout << "In binary representation:" << std::endl;
	PrintBinArr(str1);

	// Sekretne haslo
	String *passwd = StringInit("elm21");
	
	std::cout << "\n";

	// Szyfrowanie XOR uzywajac naszego hasla (patrz dokumentacja w innych plikach)
	char* cstr1_enc = XOREncode(str1,passwd);
        String *str1_enc = StringInit(cstr1_enc);
	// Wydruk:
	std::cout << "Encoded string:" << std::endl;
	PrintString(str1_enc);
	// W postaci binarnej
	std::cout << "In binary representation:" << std::endl;
	PrintBinArr(str1_enc);
	
	std::cout << "\n";


	// Rozszyfrowujemy napis
	char* cstr1_dec = XORDecode(str1_enc,passwd);
	String *str1_dec = StringInit(cstr1_dec);
	// Wyswietlamy rozszyfrowany napis
	std::cout << "Decoded string:" << std::endl;
	PrintString(str1_dec);
	
	std::cout << "\n";


	// Ponizszy kod sprawdza nastepujace elementy (ich brak to -2 punkty)
	// 1) ograniczenie dlugosci tekstu MyString i odpornosc fcji drukujacej na wskaznik NULL
	PrintString(StringInit("Wasted damn years"));
	// 2) sprawdzenie pustego ciagu
	StringInit(NULL);
	// 3) ograniczenie ilosci obiektow MyString
	PrintString(StringInit("new1"));PrintString(StringInit("new2"));
	// Powyzsze bledy powinny byc sygnalizowane jako komunikaty.
	

	// Czyscimy zaalokowana pamiec
	delete [] cstr1_enc; // tablice znakowe
	delete [] cstr1_dec; // utworzone w funkcjach kodujacych/dekodujacych
	RemoveStrings(); // czyscimy obiekty MyString


return 0;}

