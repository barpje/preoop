#include "func_fvect.h"
#include "fourvector.h"
#include <iostream>
FVector *AddFVectors(FVector gluon,FVector quark){
    FVector *wynik=(FVector*)malloc(sizeof(FVector));
    wynik->t=gluon.t+quark.t;
    wynik->x=gluon.x+quark.x;
    wynik->y=gluon.y+quark.y;
    wynik->z=gluon.z+quark.z;
    wynik->M2=wynik->t*wynik->t-wynik->x*wynik->x-wynik->y*wynik->y-wynik->z*wynik->z;
return wynik;
};
    
double CMass(double coord[]){
    double suma;
    suma=coord[0]*coord[0]-coord[1]*coord[1]-coord[2]*coord[2]-coord[3]*coord[3];
    return suma;
};


