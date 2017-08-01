#ifndef __PAIRING_HPP

#define __PAIRING_HPP

#include "Quadripoint.hpp"
#include "Bipoint.hpp"
#include "optate.h"

void OptimalAte(fp12e_t rop, const curvepoint_fp_t op1,const twistpoint_fp2_t op2);
Quadripoint pairing(Bipoint<curvepoint_fp_t> op1,Bipoint<twistpoint_fp2_t> op2);

#endif

