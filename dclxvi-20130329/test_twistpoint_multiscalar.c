/*
 * File:   dclxvi-20130329/test_twistpoint_multiscalar.c
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#include <stdio.h>
#include "twistpoint_fp2.h"
#include "twistpoint_fp2_multiscalar.h"
#include "parameters.h"

extern const scalar_t bn_n;
extern const twistpoint_fp2_t bn_curvegen;

#define MAXBATCH 500

int main()
{
  struct twistpoint_fp2_struct p[MAXBATCH];
  twistpoint_fp2_t r1, r2, t;
  scalar_t s[MAXBATCH];
  int i,batch;
  for(batch=1;batch<MAXBATCH;batch++)
  {
    printf("batch: %d\n",batch);

    for(i=0;i<batch;i++)
    {
      scalar_setrandom(s[i],bn_n);
      twistpoint_fp2_set(&p[i],bn_curvegen);
      fp2e_isreduced(p[i].m_x);
      fp2e_isreduced(p[i].m_y);
      twistpoint_fp2_scalarmult_vartime(&p[i],&p[i],s[i]);
    }

    twistpoint_fp2_setneutral(r2);
    for(i=0;i<batch;i++)
    {
      scalar_setrandom(s[i],bn_n);
      twistpoint_fp2_scalarmult_vartime(t,&p[i],s[i]);
      twistpoint_fp2_add_vartime(r2,r2,t);
    }

    twistpoint_fp2_multiscalarmult_vartime(r1,p,s,batch);

    twistpoint_fp2_makeaffine(r1);
    twistpoint_fp2_makeaffine(r2);
    if(!fp2e_iseq(r1->m_x, r2->m_x) || !fp2e_iseq(r1->m_y, r2->m_y))
    {
      printf("error\n");
      return -1;
    }
  }
  return 0;
}
