/// \file main.cpp
/// \mainpage
///
/// Program implementujacy prosty 'pojemnik' typu lista
/// jednokrotnie laczona.
///  \n\n
///
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output.txt. \n\n
///
/// Dodatkowe zastrzezenia (UWAGA: brak spelnienia ktoregokolwiek = 0 pkt):
/// a) Prosze NIE UZYWAC klas (mozna uzywac struktur, ale tylko jako 
///    POD -- plain-old-data). 
/// b) Nalezy napisac Makefile aby calosc programu kompilowala
///    sie poleceniem make. 
///    -- MUSI istniec rowniez cel clean, aby polecenie 
///      'make clean' usuwało skompilowane biblioteki i plik wykonywalny.
///    -- musi istniec cel valgrind, ktory uruchamia polecenie 'valgrind --tool=memcheck'
///       na programie wykonywalnym 
///    -- Program musi sie re-kompilowac poleceniem make po modyfikacji plikow naglowkowych.
///    -- Plik wykonywalny musi sie nazywac 'exec'
/// c) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe
///    (czyli bez plikow wykonywalnych i bibliotek) 
/// d) Nie wolno modyfikowac pliku main.cpp ani innych plikow w ktorych jest to zastrzezone. \n\n
/// 
/// Sugestie:
/// -- Prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///    Typ *wsk = new Typ[N]; delete [] wsk; (dla tablic o rozmiarze N)
/// -- Prosze pamietac o dokumentacji.
///
///    \n\n

#include<iostream>

/// Plik naglowkowy dla implementacji struktury Planet i kilku funkcji
#include "planet.h"

/// Plik naglowkowy dla implementacji listy
#include "mylist.h"



int main() {
	
	std::cout << "\n";

	/// Lista bedzie sluzyc do przechowywania obiektow naszego wlasnego typu.
	///
	/// Dla prostoty, niech bedzie to typ Planet, ktory implemetuje dwie podstawowe informacje
	/// na temat planet: nazwa planety oraz masa.
	/// Przyklady ponizej:
	Planet mars;
	double const Mm = 0.107; // masa Marsa
	SetPlanet(mars, "Mars",Mm);
	///
	Planet saturn;
	SetPlanet(saturn,"Saturn",95.16);
	///
	Planet jupiter;
	SetPlanet(jupiter,"Jupiter",317.83);
	///
	Planet uranus;
	SetPlanet(uranus,"Uranus",14.54);


	/// Inicjalizacja listy pierwszym elementem.
	Knot* init_elem_l1 = InitList(&mars);


	/// Tak chcemy dodawac planety do listy.
	/// Lista jest wskazana dowolnym istniejacym wezlem.
	AddToList(init_elem_l1,&saturn);
	AddToList(init_elem_l1,&uranus);
	AddToList(init_elem_l1,&jupiter);

	/// Drukujemy liste poczawszy od wskazanego elementu.
	std::cout << "++++ First list ++++" << std::endl;
	PrintList(init_elem_l1);
	std::cout << "+++++++  end  ++++++\n" << std::endl;

	/// Funkcja FindLastElem zwraca ostatni element listy
	std::cout << "Last element:" << std::endl;
	PrintPlanet(*(FindLastElem(init_elem_l1)->planet_pt));



	std::cout << "\n";

	
	/// Tworzymy nowa liste;
	
	const int N = 12;
	const double Mmin = 0.1;
	const int Mmax = 1000;

	Planet planet1;	
	SetPlanet(planet1,"NewPlanet",Mmin);

	Knot *init_elem_l2 = InitList(&planet1);

	Planet* planets_pt[N-1]; // tablica zapamietujaca wsk. obiektow dynamicznych

	srand (76311); // seed dla liczb pseudo-losowych

	for (int i=2;i<=N;++i) {
		
		Planet *planet = new Planet;
		SetPlanet(*planet,"NewPlanet",rand()%Mmax/100.+Mmin);

		AddToList(init_elem_l2,planet);

		planets_pt[i-2] = planet;

	}

	std::cout << "++++ Second list ++++" << std::endl;
	PrintList(init_elem_l2);
	std::cout << "+++++++  end  +++++++\n" << std::endl;

	/// Usuwamy listy (czyscimy pamiec)
	RemoveList(init_elem_l1);
        RemoveList(init_elem_l2);

	/// Usuwamy pamiec po obiektach pokazywanych przez druga liste
	for (int k=0;k<N-1;++k)
		delete planets_pt[k];


	std::cout << "\n";

return 0;}

