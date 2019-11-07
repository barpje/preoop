#include "mylist.h"
#include <iostream>
using namespace std;

Knot*  InitList(Planet* planet_pt){
 ///inicjalizacja listy, alokacja pamieci, przypisanie planet_pt oraz nastepnego elementu jako NULL;      
    Knot* init= new Knot;
    init->planet_pt = planet_pt;
    init->next=NULL;
    return init;
};

///procedura dodajaca element do listy, 
void AddToList(Knot *prev_elem, Planet* planet_pt){
    ///sprawdzamy czy lista jest pusta
    if(prev_elem==NULL)
        return;
///prev wskazuje na ostatni element listy
    Knot* prev =FindLastElem(prev_elem);
///alokujemy pamiec na nowy element oraz ustawiamy go na koncu listy
    Knot*nas=new Knot;
    prev->next=nas;
    nas->planet_pt=planet_pt;
    nas->next=NULL;
};
    
    
Knot *FindLastElem(Knot *init_elem){
///jesli lista pusta zwroc NULL
    if(init_elem==NULL)
        return NULL;
    Knot *tmp=init_elem;
///przewijamy do ostatniego elementu listy
    while(tmp->next!=NULL)
        tmp=tmp->next;
return tmp;
};

void RemoveList(Knot *init_elem){

    Knot* tmp=init_elem;
    Knot *tmp2=init_elem->next;
///usuwamy elementy listy po kolei, az do ostatniego
    while(tmp2!=NULL){
        delete tmp;
        tmp=tmp2;
        tmp2=tmp->next;
    }
///usuwamy ostatni element
  delete tmp;
};  

