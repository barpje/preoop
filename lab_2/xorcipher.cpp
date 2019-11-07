#include "xorcipher.h"
#include <iostream>
#include <cmath>


/// encoding XOR function

char* XOREncode(String* str, String* passwd) {

	
	BinaryArr binin = NULL;
	unsigned binin_l = CalcBinary(str,binin);

	
	BinaryArr binpass = NULL;
	unsigned binpass_l = CalcBinary(passwd,binpass);
	BinaryArr binpass_ext = new bool[binin_l];
	unsigned m = 0;
	for (unsigned k=0;k<binin_l;++k) { 
		if (m>=binpass_l) 
			m=0;	
		binpass_ext[k] = binpass[m];
		++m;
	}

	
	BinaryArr binout = new bool[binin_l];
	for (unsigned int l=0;l<binin_l;++l) 
		binout[l] = XOR(binin[l],binpass_ext[l]);
	const int NBit = 8; 
	unsigned Nchars = binin_l/NBit+1; 
	char* textout = new char[Nchars]; 
	char* textout_begin = textout;
	
	for (unsigned p=0;p<binin_l;p=p+NBit) {
		*textout=0; 
		for (unsigned l=0;l<NBit;++l) 	
			*textout += binout[p+l]*pow(2,NBit-l-1);
		if (*textout==0) { 
			std::cout << "Encode: 0 character encountered while encoding, please choose another passphrase." << std::endl;
			delete [] textout;
			return NULL;	
		}
		textout++;
	}
	*textout = '\0'; 
	textout = textout_begin; 

	delete [] binin;
	delete [] binout;
	delete [] binpass;
	delete [] binpass_ext;

	return textout;
}


//XOR decoding function
char* XORDecode(String* str, String* passwd) {
	return XOREncode(str,passwd);
}
