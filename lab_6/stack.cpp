#include "stack.h"
#include "node.h"
#include "coin.h"
#include <iostream>

using namespace std; 


Stack::Stack(const Coin& coin){
    head = new Node(coin);
    head->next=NULL;
};
void Stack::push(const Coin& coin_ptr){
    Node *nas=new Node(coin_ptr);
    nas->next=NULL;
    if(head == NULL)
		nas->next = NULL;
	else
		nas->next = head;
	head = nas;
};

Coin* Stack::pop(){
    if(head!=NULL){
         Coin* ret = head->coin_ptr;
         Node* temp = head;
	     head = head->next;
         delete temp;
         return ret;
         }
    else return NULL;
    };
Stack::~Stack(){
        while(head!=NULL){;
            Node *temp = head;
            head = head->next;
            delete temp->coin_ptr;
            delete temp;
        }
};
        
