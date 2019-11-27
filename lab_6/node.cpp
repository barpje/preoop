#include "node.h"
#include <iostream>

using namespace std;

unsigned Node::_suma=0;
 Node::Node(const Coin& tmp){
    coin_ptr=new Coin(tmp);
    _suma+=coin_ptr->get_coin_value(); 
 };
 
unsigned Node::get_tot_coins_val(){
   return _suma;
};


    
