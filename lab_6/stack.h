#ifndef stack_h
#define stack_h

#include "node.h"
#include "coin.h"


//klasa stack implementujaca stos
class Stack{
  //  friend class Node;
    public:
//konstruktor inicjalizujacy stos
        Stack(const Coin&);
//destruktor zwalniajacy stos
        ~Stack();
//metoda dodajaca monete do stosu
        void push(const Coin&);      
//metoda zdejmujaca ze stosu, zwracajaca wskaznik do monety
        Coin* pop();
    private:
        Node *head;
};

#endif
