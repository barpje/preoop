#ifndef LEGENDRE_H
#define LEGENDRE_H
#include "polynomial.h"
#include <cmath>
class Legendre : public Polynomial {
//klasa pochodna, dziedziczy po klasie Polynomial
public:
//konstruktor klasy pochodnej przyjmuje jako argument stopien wielomianu
    Legendre(int st) : Polynomial(st){
       if(st%2==0){
           for(int i = 0; i<st+1;i+=2)
                tab[i] = fact(i,st);
       }
       else {
           for(int i = 1; i<st+1;i+=2)
                tab[i] = fact(i,st);
       }
    }
    //funkcja obliczajaca wspolczynniki wielomianu Legendre
    double fact(int i, int st){
        double wsp = (pow(-1,(st-i)/2)*std::tgamma(st+i+1))/(pow(2,st)*std::tgamma((st-i)/2 +1)*
                     std::tgamma((st+i)/2 +1)*std::tgamma(i +1));
        return wsp;
    }
    //konstruktoe kopiujacy
    Legendre(const Legendre& ref) :Polynomial(ref) {}
    //konstruktor przenoszacy
    Legendre(Legendre&& ref): Polynomial(std::move(ref)){}
    //operator przypisania kopiujacy
    Legendre& operator=(const Legendre& ref) {
        this->Polynomial::operator=(ref);
        return *this;
    }
    //operator przypisania przenoszacy
    Legendre& operator=(Legendre&& ref) {
        this->Polynomial::operator=(std::move(ref));
        return *this;
    }
    
 };       

#endif
