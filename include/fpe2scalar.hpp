#ifndef __DECOMPOSITION_HPP

#define __DECOMPOSITION_HPP

#include "bgn.hpp"
#include <sstream>
#include "scalar1024.hpp"

void fpe2scalar(scalar_t rop, const fpe_t op); //choix d'utiliser des procédures dans le main pour lisibilté
mpz_class fpe2mpz(const fpe_t);
unsigned long long mpz2ull (mpz_class n);
mpz_class  ull2mpz (unsigned long long n);
mpz_class  scalar2mpz(const scalar_t op);
void mpz2scalar1024(scalar1024 rop, mpz_class field_element);
mpz_class scalar1024_2mpz( const scalar1024 op);
#endif /* __DECOMPOSITION_HPP */
