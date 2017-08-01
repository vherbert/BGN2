#ifndef __MULTIPLICATIONL1L2_HPP

#define __MULTIPLICATIONL1L2_HPP

#include "BitChiffre.hpp"
#include "BitEvalL1.hpp"
#include "BitEvalL2.hpp"
#include "keygen.hpp"
#include "pairing.hpp"
#include "chiffrement.hpp"
#include "BitEvalL3.hpp"

BitEvalL3 multiplicationL1L2 (BitEvalL1<curvepoint_fp_t> eval1, BitEvalL2 eval2, PublicKey public_key);
BitEvalL3 multiplicationL1L2 (BitChiffre eval1, BitEvalL2 eval2, PublicKey public_key);


#endif /* __MULTIPLICATIONL1L2_HPP */
