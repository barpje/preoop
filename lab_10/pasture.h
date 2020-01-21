#pragma once
#include <iostream>
class Pasture{
//deklaracja przyjazni dla funkcji globalnych
//operator << wypisuje pole areny i owce w podanym formacie
friend std::ostream& operator<<(std::ostream& o, const Pasture& ref);
//operator *  z liczba z lewej strony, ,mnozy pole przez wartosc, zwraca nowy obiekt
friend Pasture operator*(double val, const Pasture& ref);
//operator *  z liczba z prawej strony, ,mnozy pole przez wartosc, zwraca nowy obiekt
friend Pasture operator*(const Pasture& ref, double val);
//operator + dodaje pastwisko na koniec drugiego, sumuje ich pola, zwraca nowy obiekt
friend Pasture operator+(const Pasture& ref1, const Pasture&ref2);
public:
//konstruktor domyslny
    Pasture() : count(0), area(0), tab(nullptr) {}
//konstruktor przyjmujacy argument bok oraz liczbe owiec, oblicza pole oraz losuje wartosci owiec
    Pasture(double, int);
//destruktor czysci pamiec
    ~Pasture(){
        if(tab!=nullptr)
            delete [] tab;
    }
//konstruktor kopiujacy
    Pasture(const Pasture&);
//operator przypisania kopiujacy
    Pasture& operator=(const Pasture&);
//konstruktor przenoszacy
    Pasture(Pasture&&);
//operator przypisania przenoszacy
    Pasture& operator=(Pasture&&);
 // operator *= mnozy pole przez zadana wartosc, zwraca referencje
    Pasture& operator*=(double val){
        area *= val; 
        return *this;
    }
//predykat sluzacy do sortowania malejaco wg pola, zwraca wartosc logiczna false jesli wielkosc areny obiektu1 jest mniejsza od wielkosci areny obiektu2
    bool operator()(const Pasture& ref1, const Pasture &ref2){
        if(ref1.area < ref2.area)
            return false;
        else return true;
    }
    
private:
    int count;//ilosc owiec
    double area;//pole powierzchni;
    bool *tab;//tablica owiec
};