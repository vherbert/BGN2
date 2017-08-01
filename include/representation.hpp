#ifndef __REPRESENTATION_HPP

#define __REPRESENTATION_HPP

#include "Bipoint.hpp"
#include "Fp.hpp" 
#include "zout.hpp"
#include "Quadripoint.hpp"
#include "fp12e.h"
#include "size.hpp"

void representation(Bipoint<curvepoint_fp_t> op);
void representation(const curvepoint_fp_t op);
mpz_class poly(mpz_class coeff[12]);

#endif
