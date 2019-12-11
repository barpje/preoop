#ifndef cardealer_h
#define cardealer_h

#include "car.h"
#include <vector>


class ToyotaDealer{
    public:
//konstruktor tworzacy okreslona liczbe aut
        ToyotaDealer(unsigned);
//destruktor czysci pamiec
        ~ToyotaDealer();
//metoda dodajaca nowy samochod
        void new_inventory(const ToyotaCar&,int, int);
//metoda sprzedajaca samochod o pdanym numerze inwentaryzacyjnym
        void sell(int);
//metoda zwraca wskaznik do samochodu o pdanym numerze inwentaryzacyjnym
        ToyotaCar* show(int);
//metoda zwracajaca zarobek salonu
        int get_income()const;
//metoda statyczna zwracaja zarobek wszystkich salonow
        static int get_all_dealers_income();
    private:
        std::vector<ToyotaCar>samochody;
        unsigned carsnumber;
        int income;
        static int allincome;
};

#endif
