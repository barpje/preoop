#include "pasture.h"

Pasture::Pasture(double bok , int liczba) : count(liczba){
    area = bok * bok;
    tab = new bool[count];
    for(int i = 0; i<count;i++)
        tab[i] = std::rand()%2;
}
Pasture::Pasture(const Pasture& tmp){
    area = tmp.area;
    count = tmp.count;
    tab = new bool[count];
    for(int i = 0; i<count;i++)
        tab[i] = tmp.tab[i];
}
Pasture& Pasture::operator=(const Pasture& tmp){
    if(this == &tmp)
        return *this;
    else{
        area = tmp.area;
        count = tmp.count;
        delete [] tab;
        tab = new bool[count];
        for(int i = 0; i<count;i++)
            tab[i] = tmp.tab[i];
        return *this;
    }
}
Pasture::Pasture(Pasture&& tmp){
    area = tmp.area;
    count = tmp.count;
    tab = tmp.tab;
    tmp.tab = nullptr;
}
Pasture& Pasture::operator=(Pasture&& tmp){
    if(this == &tmp)
        return *this;
    else{
        area = tmp.area;
        count = tmp.count;
        delete [] tab;
        tab = tmp.tab;
        tmp.tab = nullptr;
        return *this;
        }
 }
 Pasture operator+(const Pasture& ref1, const Pasture& ref2){
    Pasture tmp;
    tmp.count = ref1.count + ref2.count;
    tmp.area = ref1.area + ref2.area;
    tmp.tab = new bool[tmp.count];
    for(int i = 0; i<ref1.count;i++)
        tmp.tab[i] = ref1.tab[i];

    for(int i = ref1.count; i<tmp.count;i++)
        tmp.tab[i] = ref2.tab[i-ref1.count];
    return tmp;
    }

Pasture operator*(double val, const Pasture& ref){
    Pasture tmp (ref);
    tmp*=val;
    return tmp;
}

Pasture operator*(const Pasture& ref, double val){
    Pasture tmp (ref);
    tmp*=val;
    return tmp;
}

std::ostream& operator<<(std::ostream& o, const Pasture& ref){
    o<<"area: "<<ref.area<<", sheeps: ";
    for(int i = 0; i<ref.count;i++)
        o<<ref.tab[i]<<" ";
    return o;
}
