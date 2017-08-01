/*
 * File:   dclxvi-20130329/final_expo.h
 * Author: Ruben Niederhagen, Peter Schwabe
 * Public Domain
 */

#ifndef FINAL_EXPO_H
#define FINAL_EXPO_H

// AVANT
//#include "fp12e.h"

// APRES
#include "mul.h"
extern "C" {	
#include "fpe.h"
#include "fp2e.h"
#include "fp6e.h"
#include "fp12e.h"
} 

void final_expo(fp12e_t rop);

#endif // ifdef FINAL_EXPO_H
