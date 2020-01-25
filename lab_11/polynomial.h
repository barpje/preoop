#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
//klasa przechowuje wspolczynniki wielomianu
class Polynomial{
//deklaracja przyjazni z operatorem <<
friend std::ostream& operator<<(std::ostream& out, const Polynomial&ref);
public:
//konstruktor przyjmujacy stopien wielomianu oraz tablice wspolczynnikow
    Polynomial(int, double *);
//konstruktor przyjmuacy stopien wielomianu, tablice wspoolczynnnikow wypelnia zerami
    Polynomial(int);
//konstruktor kopiujacy
    Polynomial(const Polynomial &p);
//konstrukto przenoszacy
    Polynomial(Polynomial &&p);
//operator przypisania kopiujacy
    Polynomial& operator=(const Polynomial &);
//ooperator przypisania przenoszacy
    Polynomial& operator=(Polynomial &&);
//operator +=  dodaje tablice wspolczynnikow do siebie
    Polynomial& operator+=(const Polynomial&);
//operator * prawostronny, mnozy wspolczynniki przez liczbe
    Polynomial operator*(double);
//operator () oblicza wartosc wielomianu
    double operator()(double);
//destruktor czysci pamiec
    ~Polynomial(){
        if(tab!=nullptr)
            delete [] tab;
    }
protected:
    double *tab;//tablica wspolczynnikow
    int size;
    int st;
};


#endif