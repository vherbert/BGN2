/*
 * File:   dclxvi-20130329/twistpoint_fp2_multiscalar.h
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#ifndef TWISTPOINT_FP2_MULTISCALAR_H
#define TWISTPOINT_FP2_MULTISCALAR_H
#include "twistpoint_fp2.h"
#include "scalar.h"

void twistpoint_fp2_multiscalarmult_vartime(twistpoint_fp2_t rop, struct twistpoint_fp2_struct *p, scalar_t *s, const unsigned long long npoints);

#endif
