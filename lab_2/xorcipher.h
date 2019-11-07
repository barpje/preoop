#ifndef xorcipher_h
#define xorcipher_h
#include "strings.h"
#include "binaryarr.h"
#include "xorop.h"
char* XOREncode(String* str, String* passwd);
char* XORDecode(String* str, String* passwd);






#endif
