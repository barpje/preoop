#ifndef mylist_h
#define mylist_h

// ** UWAGA ** NIE MODYFIKOWAC 

#include "planet.h"

/// Struktura zapamietujaca wskaznik do obiektu znajdujacego sie
/// na danym miejscu listy (planet_pt) 
/// oraz zapamietujaca wskaznik do nastepnego elementu listy (next). 
/// Jesli next = nullptr jest to ostatni element listy.
/// Obiekty niniejszego typu nawywaja sie wezlami listy.
struct Knot {
	Planet *planet_pt;
	Knot *next;
};


/// Inicjalizacja listy.
/// Funkcja tworzy pierwszy wezel listy i zwraca wskaznik
/// do tego wezla.
/// UWAGA: lista tylko zapamietuje wskazniki do istniejacych
/// obiektow! Nie robi kopii obiektow.
Knot*  InitList(Planet* planet_pt);


/// Funkcja dodajaca element do listy. Lista jest wskazana
/// poprzez podanie dowolnego poprzedniego wezla listy.
void AddToList(Knot *prev_elem, Planet* planet_pt);


/// Funkcja znajduje ostatni element listy (wezel) i zwraca
/// do niego wskaznik.
/// Fcja powinna byc uzyta w AddToList.
Knot *FindLastElem(Knot *init_elem);


/// Funkcja drukujaca zawartosc listy, poczawszy
/// od wskazanego elementu (wezla).
inline void PrintList(Knot *init_elem) {
	Knot* elem = init_elem;
	do {
		PrintPlanet(*(elem->planet_pt));
		elem = elem->next; 
	}
	while (elem!=nullptr);
}


/// Funkcja usuwa wezly z pamieci, poczawszy od wskazanego.
/// Wskazanie pierwszego wezla usuwa liste.
void RemoveList(Knot *init_elem);

#endif
