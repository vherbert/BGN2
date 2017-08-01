/*
 * File:   dclxvi-20130329/index_heap.c
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#include <assert.h>
#ifdef NEW_PARAMETERS
#include "scalar_512.h"
#else
#include "scalar.h"
#endif
#include "index_heap.h"

static void heap_push(unsigned long long *h, unsigned long long *hlen, unsigned long long elem, scalar_t *s)
{
  /* Move up towards the root */
  /* XXX: Check size of hlen, whether cast to signed value is ok */
  signed long long pos = *hlen;
  signed long long ppos = (pos-1)/2;
  unsigned long long t;
  h[*hlen] = elem;
  while(pos > 0)
  {
    if(scalar_lt_vartime(s[h[ppos]], s[h[pos]]))
    {
      t = h[ppos];
      h[ppos] = h[pos];
      h[pos] = t;
      pos = ppos;
      ppos = (pos-1)/2;
    }
    else break;
  } 
  (*hlen)++;
}

/* caller's responsibility to ensure hlen>=3 */
void heap_init(unsigned long long *h, unsigned long long hlen, scalar_t *s)
{
  assert(hlen>=5); 
  assert(hlen&1);
  h[0] = 0;
  unsigned long long i=1;
  while(i<hlen)
    heap_push(h, &i, i, s);
}

/* Put the largest value in the heap in max1, the second largest in max2 */
void heap_get2max(unsigned long long *h, unsigned long long *max1, unsigned long long *max2, scalar_t *s)
{
  *max1 = h[0];
  *max2 = h[1];
  if(scalar_lt_vartime(s[h[1]],s[h[2]]))
    *max2 = h[2];
}
