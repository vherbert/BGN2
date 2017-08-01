/*
 * File:   dclxvi-20130329/test_curvepoint_multiscalar.c
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#include <stdio.h>
#include "curvepoint_fp.h"
#include "curvepoint_fp_multiscalar.h"
#include "parameters.h"

extern const scalar_t bn_n;
extern const curvepoint_fp_t bn_curvegen;

#define MAXBATCH 500

int main()
{
  struct curvepoint_fp_struct p[MAXBATCH];
  curvepoint_fp_t r1, r2, t;
  scalar_t s[MAXBATCH];
  int i,batch;
  for(batch=1;batch<MAXBATCH;batch++)
  {
    printf("batch: %d\n",batch);

    for(i=0;i<batch;i++)
    {
      scalar_setrandom(s[i],bn_n);
      curvepoint_fp_set(&p[i],bn_curvegen);
      fpe_isreduced(p[i].m_x);
      fpe_isreduced(p[i].m_y);
      curvepoint_fp_scalarmult_vartime(&p[i],&p[i],s[i]);
    }

    curvepoint_fp_setneutral(r2);
    for(i=0;i<batch;i++)
    {
      scalar_setrandom(s[i],bn_n);
      curvepoint_fp_scalarmult_vartime(t,&p[i],s[i]);
      curvepoint_fp_add_vartime(r2,r2,t);
    }

    curvepoint_fp_multiscalarmult_vartime(r1,p,s,batch);

    curvepoint_fp_makeaffine(r1);
    curvepoint_fp_makeaffine(r2);
    if(!fpe_iseq(r1->m_x, r2->m_x) || !fpe_iseq(r1->m_y, r2->m_y))
    {
      printf("error\n");
      return -1;
    }
  }
  return 0;
}
