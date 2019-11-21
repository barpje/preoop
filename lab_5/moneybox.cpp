#include <iostream>
#include "moneybox.h"
#include "coin.h"

using namespace std;

Moneybox::Moneybox(unsigned x){
    rozmiar=x;
    suma=0;
    count=0;
    tab=new Coin[x];
};
Moneybox::~Moneybox(){
    delete [] tab;
};
void Moneybox::put_coin(const Coin &tmp){
     
    if(suma+tmp.get_coin_value()<=rozmiar){
        tab[count++]=tmp;
        suma+=tmp.get_coin_value();}
    else cout<<"Moneybox is full.."<<endl;
};
