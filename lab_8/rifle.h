#ifndef rifle_h
#define rifle_h
#include "bullet.h"
#include <iostream>

class Rifle{
    public:
//konstruktor tworzy n kul o kalibrze x
            Rifle(int,double);
//metoda zaladowanie kuli
            void load();
//metoda do oddania strzalu
            void pull_trigger();
//metoda do automatycznego oddania n strzalow
            void pull_trigger(int);
//metoda laduje magazynek nowymi pociskami
            void new_magazine();
//metoda wyswietla informaje o pustym magazynku
            void mag_empty(){ std::cout << "Rifle: Magazine empty." << std::endl; };
//metoda wyswietla informacje o pustej komorze
            void chamb_empty() { std::cout << "Rifle: Chamber is empty. Reload." << std::endl;};
//metoda sygnalizujaca strzal
            void bang() { std::cout << "\nBang!" << std::endl;};
//konstruktor kopiujacy
            Rifle(const Rifle&);
//konstruktor przenoszacy
            Rifle(Rifle&&);
//destruktor czysci pamiec
            ~Rifle();
        


    private:
            Bullet **_mag;
            Bullet *_kom;
            int _size;
            int _count;
};





#endif

