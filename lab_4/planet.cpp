#include "planet.h"
#include <iostream>
using namespace std;

///procedura przypisujaca nazwe oraz mase planety
void SetPlanet(Planet &planet, const char* name, double mass){
    planet.name=name;
    planet.mass=mass;
};

