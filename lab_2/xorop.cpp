#include "xorop.h"
#include <iostream>
bool XOR(bool A, bool B)
{
    return ((A || B) && !(A && B));
};
