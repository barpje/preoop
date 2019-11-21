#include <iostream>
#include "coin.h"

using namespace std;

   void Coin::print_side_up()  {
    if(_x==heads)
         cout<<"heads"<<endl;
    else cout <<"tails"<<endl;
};

void Coin::toss(){
    if (rand()%2==1)
        _x=tails;
    else _x=heads;
};

Coin::Coin(){
    _y=one;
    toss();  
};

Coin::Coin(wartosc tmp){        
     _y=tmp;
    toss();
    };  
