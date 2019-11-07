#ifndef func_fvect_h
#define func_fvect_h
#include "fourvector.h"
#include <iostream>

///funkcja sumujaca dwa czterowektory
FVector *AddFVectors(FVector gluon,FVector quark);
///funkcja obliczajaca kwadrat masy niezmienniczej czterowektora
double CMass(double coord[]);


#endif
