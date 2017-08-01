#ifndef __DECHIFFREMENT_HPP

#define __DECHIFFREMENT_HPP

#include "BitChiffre.hpp"
#include "BitEvalL1.hpp"
#include "keygen.hpp"

void dechiffrement(F2& bit_dechiffre, BitEvalL1<curvepoint_fp_t> bit_chiffre, PrivateKey private_key); // pour les chiffrés de niveau 1
void dechiffrement(F2& bit_dechiffre, BitEvalL1<twistpoint_fp2_t> bit_chiffre, PrivateKey private_key); // pour les chiffrés de niveau 1
void dechiffrement(F2& bit_dechiffre, BitChiffre bit_chiffre, PrivateKey private_key, Type type); // pour les chiffrés de niveau 1
void dechiffrement(F2& bit_dechiffre, Bipoint<curvepoint_fp_t> bipoint, PrivateKey private_key); // routine pour les évalués de niveau 3 et 4
void dechiffrement(F2& bit_dechiffre, Bipoint<twistpoint_fp2_t> bipoint, PrivateKey private_key); // routine pour les évalués de niveau 3 et 4


#endif /* __DECHIFFREMENT_HPP */
