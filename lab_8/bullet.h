#ifndef bullet_h
#define bullet_h
#include <iostream>
class Bullet{
    public:
//getter zwraca kaliber kuli
       double get_caliber(){return _caliber;};
//funkcja wypisujaca "strzal"
        void click() { std::cout << "-click- "; }
//konstruktor glosny
        Bullet(double);
//konstruktor domyslny
        Bullet();
    private:
//kaliber kuli
       double _caliber;
};



#endif
