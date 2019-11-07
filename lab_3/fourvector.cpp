#include "fourvector.h"
#include <iostream>
#include "func_fvect.h"

using namespace std;

FVector * InitFVector( double coord[]){
    FVector *wynik=(FVector*)malloc(sizeof(FVector));
    wynik->t=coord[0];
    wynik->x=coord[1];
    wynik->y=coord[2];
    wynik->z=coord[3];
    wynik->M2=CMass(coord);
return wynik;
};


void PrintFVector(FVector gluon){
    cout<<"("<<gluon.t<<","<<gluon.x<<","<<gluon.y<<","<<gluon.z<<")"<<endl;
  }; 
void PrintFVector(FVector *gluon){
    cout<<"("<<gluon->t<<","<<gluon->x<<","<<gluon->y<<","<<gluon->z<<")"<<endl;
  };     
void RemoveFVector(FVector *gluon){
    free(gluon);
};
