/*
 * File:   dclxvi-20130329/gmp_convert.h
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#ifndef GMP_CONVERT_H
#define GMP_CONVERT_H

#include <stdio.h>
#include <gmp.h>
#include "fpe.h"
#include "fp2e.h"
#include "fp6e.h"
#include "fp12e.h"

void fp2mpz(mpz_t rop, const fpe_t op);

void mpz2fp(fpe_t rop, const mpz_t op);

void fpe_out_str(FILE *outfile, const fpe_t op);

void fp2e_out_str(FILE *outfile, const fp2e_t op);

void fp6e_out_str(FILE *outfile, const fp6e_t op);

void fp12e_out_str(FILE *outfile, const fp12e_t op);

//void fp12e_out_magma(FILE *outfile, const fp12e_t op);

int fp12e_iseq_gmp(const fp12e_t op1, const fp12e_t op2);
int fp12e_iszero_gmp(const fp12e_t op);
int fp12e_isone_gmp(const fp12e_t op);

#endif
