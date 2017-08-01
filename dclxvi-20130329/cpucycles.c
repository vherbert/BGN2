/*
 * File:   dclxvi-20130329/cpucycles.c
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#include <stdio.h>

long long int cpucycles(void)
{
#ifdef __x86_64__
  unsigned long long result;
  __asm__ volatile(".byte 15;.byte 49;shlq $32,%%rdx;orq %%rdx,%%rax"
      : "=a" (result) ::  "%rdx");
  return result;
#else
  long long result;
  __asm__ volatile(".byte 15;.byte 49" : "=A" (result));
  return result;
#endif
}

