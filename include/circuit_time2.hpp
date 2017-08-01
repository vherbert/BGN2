#ifndef __CIRCUIT_TIME2_HPP

#define __CIRCUIT_TIME2_HPP

#include <limits.h>		/* for CHAR_BIT */
#include "typedef.h"
#include "BitChiffre.hpp"
#include "BitEvalL1.hpp"
#include "BitEvalL2.hpp"
#include "BitEvalL3.hpp"
#include "BitEvalL4.hpp"
#include "chiffrement.hpp" 
#include "keygen.hpp"
#include "dechiffrement.hpp" 
#include "dechiffrementL2.hpp" 
#include "dechiffrementL3.hpp"
#include "dechiffrementL4.hpp"
#include "additionL1.hpp"
#include "multiplicationL1.hpp"
#include "multiplicationL1L2.hpp"
#include "multiplicationL2.hpp"
#include "additionL2.hpp"
#include "additionL3.hpp"
#include "precomputation.hpp"
#include "postcomputation.hpp"
#include <chrono>
#include <omp.h>
#include <iomanip> //setprecision

void circuit_time2(PublicKey public_key, PrivateKey private_key);

#endif /* __CIRCUIT2_TIME_HPP */
