#ifndef __KEYGEN_HPP

#define __KEYGEN_HPP

#include <iostream>
#include "zout.hpp"
#include "Fp.hpp"
#include "PrivateKey.hpp"
#include "PublicKey.hpp"
#include "representation.hpp"
#include "fpe2scalar.hpp"
#include <array>

using namespace std;


void keygen(PublicKey& public_key, PrivateKey& private_key);
extern const scalar_t bn_n;
extern const curvepoint_fp_t bn_curvegen;	
extern const twistpoint_fp2_t bn_twistgen;

//#ifdef NEW_PARAMETERS
//const scalar_t bn_r={bn_n[0],bn_n[1],bn_n[2],bn_n[3],bn_n[4],bn_n[5],bn_n[6],bn_n[7]}; //copie pour résoudre problème notation
//#else
//const scalar_t bn_r={bn_n[0],bn_n[1],bn_n[2],bn_n[3]};
//#endif

//static const scalar_t &bn_r=bn_n;

extern const scalar_t &bn_r; 

#endif

