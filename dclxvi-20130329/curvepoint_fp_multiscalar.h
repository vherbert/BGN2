/*
 * File:   dclxvi-20130329/curvepoint_fp_multiscalar.h
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#ifndef CURVEPOINT_FP_MULTISCALAR_H
#define CURVEPOINT_FP_MULTISCALAR_H

void curvepoint_fp_multiscalarmult_vartime(curvepoint_fp_t rop, struct curvepoint_fp_struct *p, scalar_t *s, const unsigned long long npoints);

#endif
