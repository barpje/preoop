#ifndef node_h
#define node_h
#include "coin.h"
class Node{
    friend class Stack;
    public:
        static unsigned get_tot_coins_val();
    private:
        Coin coin_ptr;
	    Node *next;
        static unsigned _suma;
};
        
#endif
