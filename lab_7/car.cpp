#include "car.h"
#include <iostream>

using namespace std;

ToyotaCar::ToyotaCar(const char* n,int a, int b,int c,int d){
    model = n;
    year = a;
    miles = b;
    price =c;
    number =d ;
}
ToyotaCar::ToyotaCar(const char* mode,int rok,int przebieg){
    model = mode;
    year = rok;
    miles = przebieg;
};

    
