#include "cardealer.h"
#include <iostream>


using namespace std;

int ToyotaDealer::allincome = 0;

ToyotaDealer::ToyotaDealer(unsigned ile){
       carsnumber = ile;
       income = 0;  
}

ToyotaDealer::~ToyotaDealer(){
    samochody.clear();
}
void ToyotaDealer::new_inventory(const ToyotaCar& car,int inv, int cena){
    if(samochody.size()<carsnumber)
       samochody.push_back(ToyotaCar(car.model,car.miles,car.miles,cena,inv));
    else cout<<"No place for more cars."<<endl;
}
void ToyotaDealer::sell(int numer){
    for(unsigned k=0;k < samochody.size();k++){
            if(samochody[k].number == numer){
                income+=samochody[k].price;
                allincome+=samochody[k].price;
                samochody.erase(samochody.begin ()+ k);
                return;
            }
        }
        cout<<"No such car"<<endl;
}
ToyotaCar* ToyotaDealer::show(int numer){
        for(unsigned k=0;k < samochody.size();k++)
            if(samochody[k].number == numer){
                return &samochody[k];        
       };
    return nullptr;
}   
int ToyotaDealer::get_income()const{
   return income;
}

int ToyotaDealer::get_all_dealers_income(){
     return allincome;
}
