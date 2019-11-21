#ifndef moneybox_h
#define moneybox_h
#include "coin.h"

///klasa reprezentujaca skarbonke do przechowywania monet
class Moneybox{
public:
    //konstruktor, tworzacy skarbonke o zadanym rozmiarze
    Moneybox(unsigned);
    //destruktor, czysci pamiec po skarbonkach
    ~Moneybox();
    //metoda do wkladania monety do skarbonki oraz obliczajaca aktualna sume skarbonki
    void put_coin(const Coin &);
    //metoda, zwraca sume monet w skarbonce
    unsigned get_tot_value()const{
        return suma;    
    };

    
private:
    Coin *tab;
    int count;
    unsigned rozmiar;
    unsigned suma;     
};

#endif
