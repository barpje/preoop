#ifndef planet_h
#define planet_h

// ** UWAGA ** NIE MODYFIKOWAC

#include <iostream>

/// Struktura zapamietujaca nazwe planety i jej mase
struct Planet {
	const char* name;
	double mass;
};


/// Funkcja wpisuje dane do podanego obiektu typu Planet
/// (pierwszy argument przekazany przez referencje). 
void SetPlanet(Planet &planet, const char* name, double mass);

/// Funkcja drukuje obiekt typu planet
inline void PrintPlanet(const Planet &planet) {
	std::cout << planet.name << "(" << planet.mass << ")" << std::endl;
}

#endif
