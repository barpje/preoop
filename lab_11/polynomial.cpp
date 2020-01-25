#include "polynomial.h"
#include <iostream>
#include <cmath>

Polynomial::Polynomial(int i, double *w):st(i) {
    size = i+1;
    tab = new double[size];
    for(int j=0; j< size; j++)
        tab[j] = w[j];
}
Polynomial::Polynomial(int i):st(i) {
    size = i+1;
    tab = new double[size];
    for(int j=0; j< size; j++)
        tab[j] = 0;
}
Polynomial::Polynomial(const Polynomial &p): size(p.size), st(p.st) {
    tab = new double[size];
    for(int j=0; j< size; j++)
        tab[j] = p.tab[j];
}
Polynomial::Polynomial(Polynomial &&p): tab(p.tab), size(p.size), st(p.st) {
    p.tab = nullptr;
    p.size = p.st = 0;
}
Polynomial& Polynomial::operator=(const Polynomial &p) {
    if(&p==this)
        return *this;
    delete [] tab;
    size = p.size;
    st = p.st;
    tab = new double[size];
    for(int j=0; j< size; j++)
        tab[j] = p.tab[j];
    return *this;
}
Polynomial& Polynomial::operator=(Polynomial &&p) {
    if(&p==this)
        return *this;
    delete [] tab;
    size = p.size;
    st = p.st;
    tab = p.tab;
    p.tab = nullptr;
    p.size = p.st = 0;
    return *this;
}
Polynomial& Polynomial::operator+=(const Polynomial& ref){
    if(size > ref.size){
        for(int j=0; j< ref.size; j++)
            tab[j] += ref.tab[j];
    }
    else {
        double *n = new double[ref.size];
        for(int i=0; i< ref.size; i++)
            n[i] = ref.tab[i];
        for(int i=0; i<size; i++)
            n[i] += tab[i];
        delete [] tab;
        tab = n;
        size = ref.size;
    }
    return *this;
}
Polynomial Polynomial::operator*(double val){
    Polynomial tmp(*this);
    for(int i=0; i<tmp.size; i++)
        tmp.tab[i]*=val;
    return tmp;
}
double Polynomial::operator()(double val){
    double wartosc = 0;
    for(int i=0; i<size; i++)
        wartosc += tab[i]* pow(val,i);
    return wartosc;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& ref){
    if(ref.tab[0]!=0)
        out<<ref.tab[0];
    for(int i = 1;i<ref.size;i++){
        if(ref.tab[i]>0)
            out<<" +"<<ref.tab[i]<<"*x^"<<i;
        else if(ref.tab[i]<0)
            out<<" "<<ref.tab[i]<<"*x^"<<i;
    }
    return out;
}