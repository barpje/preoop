#ifndef binaryarr_h
#define binaryarr_h
#include "strings.h"
#include <iostream>
typedef bool* BinaryArr;
    

unsigned int CalcBinary(String *str, BinaryArr &binary);
void PrintBinArr(BinaryArr binary, unsigned int binlength); 
void PrintBinArr(String *str); 


#endif

