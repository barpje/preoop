#ifndef node_h
#define node_h
#include "coin.h"
class Stack;
class Node{
    //deklaracja przyjazni z klasa Stack;
    friend class Stack;
    public:
    //metoda statyczna zwracaja calkowita wartosc stosu
        static unsigned get_tot_coins_val();
    private:
    //konstruktor przyjmujacy jako argument referecje na Coin
        Node(const Coin&);
        Coin *coin_ptr;
	Node *next;
        static unsigned _suma;
};
        
#endif
