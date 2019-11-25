#include "stack.h"
#include "node.h"
#include "coin.h"
#include <iostream>

using namespace std; 


Stack::Stack(const Coin& coin_ptr){
    head = new Node;
    head->coin_ptr=coin_ptr;
    head->next=NULL;
    head->_suma+=coin_ptr.get_coin_value();
};
void Stack::push(const Coin& coin_ptr){
    Node *nas=new Node;
    nas->coin_ptr=coin_ptr;
    nas->next=NULL;
    if(head == NULL)
		nas->next = NULL;
	else
		nas->next = head;
	head = nas;
    head->_suma+=coin_ptr.get_coin_value();
};

Coin* Stack::pop(){
    if(head!=NULL){
         Node *temp = head;
	     head = head->next;
         return &(temp->coin_ptr);
    }
    else return NULL;
    };
Stack::~Stack(){
        while(head!=NULL){
         Node *temp = head;
	     head = head->next;
         delete temp;
    }
};
        
