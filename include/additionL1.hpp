#ifndef __ADDITIONL1_HPP

#define __ADDITIONL1_HPP

#include "BitChiffre.hpp"
#include "BitEvalL1.hpp"
#include "keygen.hpp"

//template <typename T>
//BitEvalL1<T> additionL1 (BitEvalL1<T> a, BitEvalL1<T> b, PublicKey public_key, Type type);
BitEvalL1<curvepoint_fp_t> additionL1 (BitEvalL1<curvepoint_fp_t> a, BitEvalL1<curvepoint_fp_t> b, PublicKey public_key);
BitEvalL1<twistpoint_fp2_t> additionL1 (BitEvalL1<twistpoint_fp2_t> a, BitEvalL1<twistpoint_fp2_t> b, PublicKey public_key);
BitChiffre additionL1 (BitChiffre a, BitChiffre b, PublicKey public_key);


#endif /* __ADDITIONL1_HPP */
