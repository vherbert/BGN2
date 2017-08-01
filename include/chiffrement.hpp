#ifndef __CHIFFREMENT_HPP

#define __CHIFFREMENT_HPP


#include "BitChiffre.hpp"
#include "BitEvalL1.hpp"
#include "keygen.hpp"
#include "representation.hpp"

//template <typename T>
//void chiffrement(BitEvalL1<T>& bit_chiffre,F2 bit_clair, PublicKey public_key, Type type);
void chiffrement(BitEvalL1<curvepoint_fp_t>& bit_chiffre,F2 bit_clair, PublicKey public_key);
void chiffrement(BitEvalL1<twistpoint_fp2_t>& bit_chiffre,F2 bit_clair, PublicKey public_key);

void chiffrement(BitChiffre& bit_chiffre,F2 bit_clair, PublicKey public_key, Type type);
void chiffrement(Bipoint<curvepoint_fp_t>& ciphertext,F2 bit_clair, PublicKey public_key);
void chiffrement(Bipoint<twistpoint_fp2_t>& ciphertext,F2 bit_clair, PublicKey public_key);

extern const scalar_t bn_n;
extern const curvepoint_fp_t bn_curvegen;	
extern const twistpoint_fp2_t bn_twistgen;
	
	
#endif /* __CHIFFREMENT_HPP */


