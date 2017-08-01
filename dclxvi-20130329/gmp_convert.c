/*
 * File:   dclxvi-20130329/gmp_convert.c
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#include <math.h>
#include <stdio.h>
#include <gmp.h>
//#include "parameters.h"


//avant
//#include "fpe.h"
//#include "fp2e.h"
//#include "fp6e.h"
//#include "fp12e.h"


//APRES
#include "mul.h"
extern "C" {	
#include "fpe.h"
#include "fp2e.h"
#include "fp6e.h"
#include "fp12e.h"
} 

extern const double bn_v;
extern const double bn_v6;
extern const char * bn_pstr;

#ifndef CHECK
static long long ftoll(double arg)
{
  return (long long)arg;
}
#endif

void fp2mpz(mpz_t rop, const fpe_t op)
{
  mpz_t v, vp, t, p;
  mpz_init_set_ui(v, (long)bn_v);
  mpz_init_set_str(p, bn_pstr, 10);
  mpz_init(t);
  mpz_init(vp);

  mpz_set_si(rop, ftoll(op->v[0]));
  mpz_set_si(t,ftoll(op->v[1]));
  mpz_mul(t,t,v);
  mpz_mul_si(t,t,6);
  mpz_mul(vp,v,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[2]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,6);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[3]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,6);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[4]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,6);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[5]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,6);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[6]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,6);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[7]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,36);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[8]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,36);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[9]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,36);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[10]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,36);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_set_si(t,ftoll(op->v[11]));
  mpz_mul(t,t,vp);
  mpz_mul_si(t,t,36);
  mpz_mul(vp,vp,v);
  mpz_add(rop, rop, t);
  mpz_mod(rop, rop, p);
  mpz_clear(v);
  mpz_clear(p);
  mpz_clear(t);
  mpz_clear(vp);
}

void mpz2fp(fpe_t rop, const mpz_t op)
{
  mpz_t t, r;
  mpz_init(r);
  mpz_init_set(t, op);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v6);
  rop->v[0] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[1] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[2] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[3] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[4] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[5] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v6);
  rop->v[6] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[7] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[8] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[9] = mpz_get_d(r);
  mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[10] = mpz_get_d(r);
  //mpz_tdiv_qr_ui(t, r, t, (long)bn_v);
  rop->v[11] = mpz_get_d(t);

  setmax(rop->v[0],(long)bn_v6/2);
  setmax(rop->v[6],(long)bn_v6/2);

  setmax(rop->v[1],(long)bn_v/2);
  setmax(rop->v[3],(long)bn_v/2);
  setmax(rop->v[4],(long)bn_v/2);
  setmax(rop->v[7],(long)bn_v/2);
  setmax(rop->v[9],(long)bn_v/2);
  setmax(rop->v[10],(long)bn_v/2);

  setmax(rop->v[2],(long)bn_v);
  setmax(rop->v[5],(long)bn_v);
  setmax(rop->v[8],(long)bn_v);
  setmax(rop->v[11],(long)bn_v);
  mpz_clear(r);
  mpz_clear(t);
}

void fpe_out_str(FILE *outfile, const fpe_t op)
{
  mpz_t t;
  mpz_init(t);
  fp2mpz(t, op);
  mpz_out_str(outfile, 10, t);
  mpz_clear(t);
}

void fp2e_out_str(FILE *outfile, const fp2e_t op)
{
  fpe_t a, b;
  mpz_t ma, mb;
  mpz_init(ma);
  mpz_init(mb);
  int i;
  for(i=0;i<12;i++)
  {
    b->v[i] = op->v[2*i];
    a->v[i] = op->v[2*i+1];
  }
  fp2mpz(ma, a);
  fp2mpz(mb, b);
  fprintf(outfile, "(");
  mpz_out_str(outfile, 10, ma);
  fprintf(outfile, "*X + ");
  mpz_out_str(outfile, 10, mb);
  fprintf(outfile, ")");
  mpz_clear(ma);
  mpz_clear(mb);
}

void fp6e_out_str(FILE *outfile, const fp6e_t op)
{
	fprintf(outfile, "[");
	fp2e_out_str(outfile, op->m_a);
	fprintf(outfile, " * Y^2 + ");
	fp2e_out_str(outfile, op->m_b);
	fprintf(outfile, " * Y + ");
	fp2e_out_str(outfile, op->m_c);
	fprintf(outfile, "]");
}

void fp12e_out_str(FILE *outfile, const fp12e_t op)
{
	fp6e_out_str(outfile, op->m_a);
	fprintf(outfile, " * Z + ");
	fp6e_out_str(outfile, op->m_b);
}

/*
void fp12e_out_magma(FILE *outfile, const fp12e_t op)
{
  fpe_t f[12];
  fp2e_to_2fpe(f[10],f[11],(op->m_a)->m_a);
  fp2e_to_2fpe(f[8],f[9],(op->m_a)->m_b);
  fp2e_to_2fpe(f[6],f[7],(op->m_a)->m_c);
  fp2e_to_2fpe(f[4],f[5],(op->m_b)->m_a);
  fp2e_to_2fpe(f[2],f[3],(op->m_b)->m_b);
  fp2e_to_2fpe(f[0],f[1],(op->m_b)->m_c);
  int i;
  fprintf(outfile, "[");
  for(i=0;i<11;i++)
  {
    fprintf(outfile, "Fp!");
    fpe_out_str(outfile, f[i]); 
    fprintf(outfile,", ");
  }
  fprintf(outfile, "Fp!");
  fpe_out_str(outfile, f[11]);
  fprintf(outfile, "]");
}
*/

int fp12e_iseq_gmp(const fp12e_t op1, const fp12e_t op2)
{
  fpe_t a[12];
  fp2e_to_2fpe(a[10],a[11],(op1->m_a)->m_a);
  fp2e_to_2fpe(a[8],a[9],(op1->m_a)->m_b);
  fp2e_to_2fpe(a[6],a[7],(op1->m_a)->m_c);
  fp2e_to_2fpe(a[4],a[5],(op1->m_b)->m_a);
  fp2e_to_2fpe(a[2],a[3],(op1->m_b)->m_b);
  fp2e_to_2fpe(a[0],a[1],(op1->m_b)->m_c);

  fpe_t b[12];
  fp2e_to_2fpe(b[10],b[11],(op2->m_a)->m_a);
  fp2e_to_2fpe(b[8],b[9],(op2->m_a)->m_b);
  fp2e_to_2fpe(b[6],b[7],(op2->m_a)->m_c);
  fp2e_to_2fpe(b[4],b[5],(op2->m_b)->m_a);
  fp2e_to_2fpe(b[2],b[3],(op2->m_b)->m_b);
  fp2e_to_2fpe(b[0],b[1],(op2->m_b)->m_c);

  int i;
  mpz_t at, bt;
  mpz_init(at);
  mpz_init(bt);
  for(i=0;i<12;i++)
  {
    fp2mpz(at, a[i]);
    fp2mpz(bt, b[i]);
    if(mpz_cmp(at,bt)) return 0;
  }
  mpz_clear(at);
  mpz_clear(bt);
  return 1;
}

int fp12e_iszero_gmp(const fp12e_t op)
{
  fpe_t a[12];
  fp2e_to_2fpe(a[10],a[11],(op->m_a)->m_a);
  fp2e_to_2fpe(a[8],a[9],(op->m_a)->m_b);
  fp2e_to_2fpe(a[6],a[7],(op->m_a)->m_c);
  fp2e_to_2fpe(a[4],a[5],(op->m_b)->m_a);
  fp2e_to_2fpe(a[2],a[3],(op->m_b)->m_b);
  fp2e_to_2fpe(a[0],a[1],(op->m_b)->m_c);

  int i;
  mpz_t at;
  mpz_init(at);
  int ret = 1;
  for(i=0;i<12;i++)
  {
    fp2mpz(at, a[i]);
    if(mpz_cmp_ui(at,0)) ret = 0;
  }
  mpz_clear(at);
  return ret;
}


int fp12e_isone_gmp(const fp12e_t op)
{
  fpe_t a[12];
  fp2e_to_2fpe(a[10],a[11],(op->m_a)->m_a);
  fp2e_to_2fpe(a[8],a[9],(op->m_a)->m_b);
  fp2e_to_2fpe(a[6],a[7],(op->m_a)->m_c);
  fp2e_to_2fpe(a[4],a[5],(op->m_b)->m_a);
  fp2e_to_2fpe(a[2],a[3],(op->m_b)->m_b);
  fp2e_to_2fpe(a[0],a[1],(op->m_b)->m_c);

  int i;
  mpz_t at;
  mpz_init(at);
  int ret = 1;
  for(i=1;i<12;i++)
  {
    fp2mpz(at, a[i]);
    if(mpz_cmp_ui(at,0)) ret = 0;
  }
  fp2mpz(at, a[0]);
  if(mpz_cmp_ui(at,1)) ret = 0;
  mpz_clear(at);
  return ret;
}
