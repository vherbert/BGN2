#ifndef __PRIVATEKEY_HPP

#define __PRIVATEKEY_HPP
#include "Bipoint.hpp"
#include "Fp.hpp" 
#include "zout.hpp"
#include "Quadripoint.hpp"
#include "fp12e.h"

extern const curvepoint_fp_t bn_curvegen;

class  PrivateKey
{
	
	public:
	PrivateKey() = default; 
	PrivateKey(Fp a, Fp b, Fp c, Fp d, Fp e, Fp f, Fp g, Fp h);
	void set(Fp a, Fp b, Fp c, Fp d, Fp e, Fp f, Fp g, Fp h);
	Fp get(string name);
	void print() const;
	Bipoint<curvepoint_fp_t>  pi_1(Bipoint<curvepoint_fp_t>);
	Bipoint<twistpoint_fp2_t> pi_2(Bipoint<twistpoint_fp2_t>);
	Quadripoint pi_T(Quadripoint);
	
	private :
	Fp i1, j1, k1, l1, i2, j2, k2, l2;
	
};

//to remove after debug REMOVE
//extern PrivateKey private_key;

#endif

