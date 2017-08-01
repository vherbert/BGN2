/*
 * File:   dclxvi-20130329/index_heap.h
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#ifndef INDEX_HEAP_H
#define INDEX_HEAP_H

#ifdef NEW_PARAMETERS
#include "scalar_512.h"
#else
#include "scalar.h"
#endif

#ifdef __cplusplus
 extern "C" {
#endif 

void heap_init(unsigned long long *h, unsigned long long hlen, scalar_t *s);

void heap_get2max(unsigned long long *h, unsigned long long *max1, unsigned long long *max2, scalar_t *s);

void heap_rootreplaced(unsigned long long *h, unsigned long long hlen, scalar_t *s);

#ifdef __cplusplus
 }
#endif 

#endif
