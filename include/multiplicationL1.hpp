#ifndef __MULTIPLICATIONL1_HPP

#define __MULTIPLICATIONL1_HPP

#include "BitChiffre.hpp"
#include "BitEvalL2.hpp"
#include "BitEvalL1.hpp"
#include "keygen.hpp"
#include "pairing.hpp"
#include "chiffrement.hpp"
#include "fpe2scalar.hpp"

//template <typename S, typename T>
BitEvalL2 multiplicationL1 (BitEvalL1<curvepoint_fp_t> a, BitEvalL1<twistpoint_fp2_t> b, PublicKey public_key);
BitEvalL2 multiplicationL1 (BitChiffre a, BitChiffre b, PublicKey public_key);


#endif /* __MULTIPLICATIONL1_HPP */
