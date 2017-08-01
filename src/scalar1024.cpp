#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scalar1024.hpp"
#include "zout.hpp"

void fp12e_pow_vartime1024(fp12e_t rop, const fp12e_t op, const scalar1024 exp)
{	
  fp12e_t dummy;
  unsigned int startbit;

  startbit = scalar1024_scanb(exp);
  //zout(startbit);
  fp12e_set(dummy, op);
  fp12e_set(rop,op);
  int i;
  for(i = startbit; i > 0; i--)
  {
    fp12e_square(rop, rop);
    if(scalar1024_getbit(exp, i - 1)) 
      fp12e_mul(rop, rop, dummy);
  }
}

int scalar1024_getbit(const scalar1024 s, unsigned int pos)
{
  //zout(s[0]); 
  //printf("s[0] en mode d = %d\n", s[0]);
  //printf("s[0] en mode llx = %llx\n", s[0]);

  assert(pos < 1024);
  //zout(pos >> 28,s[pos >> 28],(pos & 0x3f),s[pos >> 28] >> (pos & 0x3f));
  return (s[pos >> 6] >> (pos & 0x3f)) & 1;
}

// Returns the position of the most significant set bit
int scalar1024_scanb(const scalar1024 s)
{
  int i;
  unsigned int pos = 0;
  //for(i=1023;i>0;i--)
    //if(scalar1024_getbit(s,i) && pos == 0) pos = i;
  i=1023;
  while(scalar1024_getbit(s,i)!=1)
  {i--;}  
  pos=i;
  return pos;
}

void scalar1024_print(FILE *fh, const scalar1024 t)
{
  int i;
  for(i=15;i>=0;i--)
    fprintf(fh, "%d\t", t[i]);
    //fprintf(fh, "%llx\t", t[i]);

}

