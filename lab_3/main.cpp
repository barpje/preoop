/// \file main.cpp
/// \mainpage
///
/// Program implemetuje wektory w czterowymiarowej czasoprzestrzeni (czterowektory),
/// oraz dwie operacje na czterowektorach:
/// (i) obliczenie normy (lub masy niezmienniczej), (ii) dodawanie. \n\n
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
/// c) W plikach naglowkowych musza znajdowac sie TYLKO deklaracje funkcji.
///    Definicje prosze umiescic w plikach *.cpp.
/// d) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe
///    (czyli bez plikow wykonywalnych i bibliotek) \n\n
/// 
/// Sugestie:
/// -- W miare mozliwosci (lub gdy konieczne)  prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///    Typ *wsk = new Typ[N]; delete [] wsk; (dla tablic o rozmiarze N)
/// -- Prosze pamietac o dokumentacji.
///
///    \n\n


#include<iostream>

/// Naglowek deklarujacy czterowektory
/// oraz funkcje do ich tworzenia, usuwania i drukowania
#include "fourvector.h"

/// Naglowek deklarujacy operacje na czterowektorach
/// (funkcja obliczajaca mase niezmiennicza, oraz sume, w tym sume wielokrotna)
#include "func_fvect.h"

/// Naglowek deklarujacy funkcje pomocnicza DeleteAllFVectors
#include "del_fvectors.h"

/// Funkcja zwraca liczbe pseudolosowa z przedzialu (0,100)
double gen_rand_coord() {
        const int MaxRange = 100;
        return rand()%MaxRange;
}


int main() {
	
	std::cout << "\n";

	/// Czterowektor to wektor o 4 wspolrzednych: (t,x,y,z),
        /// gdzie t jest czasem, x,y,z -- sa wspolrzednymi przestrzennymi.
        

	/// Tworzymy dwa czterowektory:
	
	/// a) czterowektor nr 1
	
	double coord1[] = {101.2,0.,0.,101.2}; 
	FVector *gluon = InitFVector(coord1);
	
	/// b) czterowektor nr 2

	double coord2[] = {80.76,-63.1412132,44.64758,-23.28}; 
	FVector *quark = InitFVector(coord2);

	/// Drukujemy czterowektory, i kwadrat ich masy niezmienniczej (czyli norme).
	/// Masa niezmiennicza do kwadratu: 
	/// \f$ M^2 = t^2-x^2-y^2-z^2 \f$,
	/// gdzie wspolrzedne wektora to
	/// \f$ v=(t,x,y,z) \f$.
	
	std::cout << "Fourvector of a gluon: " << std::endl;
	PrintFVector(*gluon);
	std::cout << "Invariant mass squared: " << gluon->M2 << std::endl;
	std::cout << "Fourvector of a quark: " << std::endl;
	PrintFVector(quark);
	std::cout << "Invariant mass squared: " << quark->M2 << std::endl;

	std::cout << "\n";

	/// Dodajemy czterowektory kwarku i gluonu
	/// (czterowektory dodaje sie tak samo jak zwykle wektory)
	
	FVector *fvec_qg = AddFVectors(*gluon,*quark);

	std::cout << "Fourvector of (quark+gluon): " << std::endl;
	PrintFVector(*fvec_qg);
	std::cout << "Invariant mass squared: " << (*fvec_qg).M2 << std::endl;

	std::cout << "\n";	

	/// Usuwamy czterowektory z pamieci
	RemoveFVector(gluon);
	RemoveFVector(quark);
	RemoveFVector(fvec_qg);

	std::cout << "\n";

	/// Losujemy tablice czterowektorow
	
	srand (7633211); // seed generatora liczb pseudolosowych	
	int NVec = 4;  // rozmiar tablicy

	FVector **some_fvectors = new FVector*[NVec]; // tablica wskaznikow

	std::cout << "Random fourvectors:" << std::endl;
	for (int k=0;k<NVec;++k) {
		// tworzymy tablice losowych liczb calkowitych (0,100)
		double tmp_arr[] = {gen_rand_coord(),gen_rand_coord(),gen_rand_coord(),gen_rand_coord()};
		// tworzymy czterowektor
		some_fvectors[k] = InitFVector(tmp_arr);
		PrintFVector(*some_fvectors[k]);	
		std::cout << some_fvectors[k]->M2 << std:: endl;
	}

	/// Usuwamy zaalokowane obiekty z pamieci
	DeleteAllFVectors(some_fvectors,NVec);
	
	std::cout << "\n";

return 0;}

