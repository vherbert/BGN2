/*
 * File:   dclxvi-20130329/speedtest.c
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#include <stdio.h>
#include <stdlib.h>

#include "curvepoint_fp.h"
#include "twistpoint_fp2.h"
#include "fp12e.h"
#include "optate.h"
#include "linefunction.h"

#define NTESTS 20

#define REP 50

#ifdef __x86_64__
#define mycpucycles(RES) \
  __asm__ volatile("rdtsc;shlq $32,%%rdx;orq %%rdx,%%rax" : "=a" (RES) ::  "%rdx");
#else
#define mycpucycles(RES) \
  __asm__ volatile(".byte 15;.byte 49" : "=A" (RES));
#endif

extern const curvepoint_fp_t bn_curvegen;
extern const twistpoint_fp2_t bn_twistgen;
extern const scalar_t bn_n;

/*
static int cmp_llu(const void *a, const void*b)
{
  if(*(unsigned long long *)a < *(unsigned long long *)b) return -1;
  if(*(unsigned long long *)a > *(unsigned long long *)b) return 1;
  return 0;
}


static unsigned long long median(unsigned long long *l, size_t llen)
{
  qsort(l,llen,sizeof(unsigned long long),cmp_llu);

  if(llen%2) return l[llen/2];
  else return (l[llen/2-1]+l[llen/2])/2;
}
*/

static void print_bench(unsigned long long *l, size_t llen)
{
  size_t i;
  for(i=0;i<llen-1;i++)
  {
    l[i] = l[i+1]-l[i];
    printf("%llu", l[i]/REP);
    if(i < llen-2) printf(" ");
  }

  printf("\n");
}


fp12e_t e1;
curvepoint_fp_t p1;
twistpoint_fp2_t p2;
twistpoint_fp2_t p3;
twistpoint_fp2_t rq;

fp2e_t rop11, rop12, rop13, r2;
fpe_t fpe1;

scalar_t s1, s2, s3;

unsigned long long t[NTESTS+1];

int main(int argc, char* argv[])
{
  int i, j;
  int choose;

  if(argc >= 2) choose = atoi(argv[1]);
  else choose = 0;

  scalar_setrandom(s1, bn_n);
  scalar_setrandom(s2, bn_n);
  scalar_setrandom(s3, bn_n);

  curvepoint_fp_scalarmult_vartime(p1, bn_curvegen, s1);
  curvepoint_fp_makeaffine(p1);
  twistpoint_fp2_scalarmult_vartime(p2, bn_twistgen, s2);
  twistpoint_fp2_makeaffine(p2);
  twistpoint_fp2_scalarmult_vartime(p3, bn_twistgen, s3);
  twistpoint_fp2_makeaffine(p3);
  fp2e_setone(rop11);
  fp2e_setone(rop12);
  fp2e_setone(rop13);
  fp2e_setone(r2);
  fpe_setone(fpe1); 
  fp12e_setone(e1);

  if(!choose || choose == 1)
  {
    printf("Fp2 multiplication: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp2e_mul(r2, rop11, rop12);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 2)
  {
    printf("Fp2 squaring: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp2e_square(r2, rop11);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 3)
  {
    printf("Fp2xFp multiplication: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp2e_mul_fpe(r2, rop11, fpe1);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 4)
  {
    printf("Fp2 short coeffred: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp2e_short_coeffred(r2);
    }
    print_bench(t,NTESTS+1);
  }
  
  if(!choose || choose == 5)
  {
     printf("Linefunction add: ");
     for(i=0;i<NTESTS+1;i++)
     {
     mycpucycles(t[i]);
     for(j=0;j<REP;j++) linefunction_add_ate(rop11, rop12, rop13, rq, p2, p3, p1, r2);
     }
     print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 6)
  {
     printf("Linefunction double: ");
     for(i=0;i<NTESTS+1;i++)
     {
     mycpucycles(t[i]);
     for(j=0;j<REP;j++) linefunction_double_ate(rop11, rop12, rop13, rq, p2,  p1);
     }
     print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 7)
  {
    printf("Fp12 multiplication: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp12e_mul(e1, e1, e1);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 8)
  {
    printf("Fp12 squaring: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp12e_square(e1, e1);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 9)
  {
    printf("Fp12 linefunction multiplication: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp12e_mul_line(e1, e1, r2, r2, r2);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 10)
  {
    printf("Fp12 inversion: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) fp12e_invert(e1, e1);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 11)
  {
    printf("Miller loop: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) optate_miller(e1, p2, p1);
    }
    print_bench(t,NTESTS+1);
  }

  if(!choose || choose == 12)
  {
    printf("Optimal ate pairing: ");
    for(i=0;i<NTESTS+1;i++)
    {
      mycpucycles(t[i]);
      for(j=0;j<REP;j++) optate(e1, p2, p1);
    }
    print_bench(t,NTESTS+1);
  }
}
