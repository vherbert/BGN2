#ifndef SCALAR1024_H
#define SCALAR1024_H
#include <stdio.h>
#include "mul.h" 
extern "C" {
#include "fp12e.h"
}




typedef unsigned long long scalar1024[16] ;


int scalar1024_getbit(const scalar1024 s, unsigned int pos);

// Returns the position of the most significant set bit
int scalar1024_scanb(const scalar1024 s);
void scalar1024_print(FILE *fh, const scalar1024 t);
void fp12e_pow_vartime1024(fp12e_t rop, const fp12e_t op, const scalar1024 exp); //NB rajout



#endif
