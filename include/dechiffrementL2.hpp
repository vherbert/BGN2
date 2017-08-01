#ifndef __DECHIFFREMENTL2_HPP

#define __DECHIFFREMENTL2_HPP

#include "BitEvalL2.hpp"
#include "keygen.hpp"
#include "pairing.hpp"

void dechiffrementL2(F2& bit_dechiffre, BitEvalL2 bit_chiffre, PrivateKey private_key);
void dechiffrementL2(F2& bit_dechiffre, Quadripoint quadripoint, PrivateKey private_key); // routine pour les évalués de niveau 3 et 4


#endif /* __DECHIFFREMENTL2_HPP */
