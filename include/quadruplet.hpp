#ifndef __SETTINGS_HPP
#define __SETTINGS_HPP

#include "bgn.hpp"

void fpe_setrandom(fpe_t rop); //choisit un élément de Fp "au hasard"
void fpe_ad_minus_bc(fpe_t rop,fpe_t op1,fpe_t op2,fpe_t op3); // calcule a tel que ad-bc=1
void log2_fpe_print(FILE * outfile, const fpe_t op); // affiche la taille en bits des douze coeffs représentant un élément de Fp

#endif /* __SETTINGS_HPP */
