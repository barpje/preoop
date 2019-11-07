#include "del_fvectors.h"
#include <iostream>
#include "fourvector.h"
void DeleteAllFVectors(FVector ** some_fvectors,int NVec){
    for(int i=0;i<NVec;i++)
        free(some_fvectors[i]);
    delete [] some_fvectors;
};
