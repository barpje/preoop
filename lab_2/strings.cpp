#include "strings.h"
#include <iostream>
#include <cstring>
String *lista[5];
int count=0;

String *StringInit(const char *s){
    if(count>=5){
        std::cout<<"StringInit: Maximum no of strings has been reached."<<std::endl; 
        return NULL;}
    if(s==NULL){
        std::cout<<"StringInit: NULL pointer passed."<<std::endl;
        return NULL;}
    if((strlen(s)+1)>13){
        std::cout<<"StringInit: String is too long."<<std::endl; 
        return NULL;}
           
    String *wynik=(String*)malloc(sizeof(String));
    wynik->str=s;   
    wynik->length=strlen(s)+1;
    lista[count]=wynik;
    count++;
    return wynik;}

void PrintString(String *c){
    if(c==NULL)
       std::cout<<"PrintMyString: NULL pointer passed."<<std::endl; 
    else std::cout<<c->str<<std::endl;
};

void RemoveStrings(){
    for(int i=0;i<count;i++)
      free(lista[i]);
};

