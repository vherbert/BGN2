#ifndef __PUBLICKEY_HPP

#define __PUBLICKEY_HPP

#include "Bipoint.hpp"
#include "zout.hpp"
#include <type_traits>

class  PublicKey
{
	public:
	PublicKey() = default;
	PublicKey(Bipoint<curvepoint_fp_t> a,Bipoint<twistpoint_fp2_t> b, Bipoint<curvepoint_fp_t> c,Bipoint<twistpoint_fp2_t> d);
	void set(Bipoint<curvepoint_fp_t> a,Bipoint<twistpoint_fp2_t> b, Bipoint<curvepoint_fp_t> c,Bipoint<twistpoint_fp2_t> d);
	void print() const;
	Bipoint<curvepoint_fp_t> get_bipoint_curvegen() const;
	Bipoint<twistpoint_fp2_t> get_bipoint_twistgen() const;	
	Bipoint<curvepoint_fp_t> get_bipoint_curve_groupelt() const;
	Bipoint<twistpoint_fp2_t> get_bipoint_twist_groupelt() const;	
		
	private :
	Bipoint<curvepoint_fp_t> bipoint_curvegen; //subgroup_gen (i1g,j1,g)
	Bipoint<twistpoint_fp2_t> bipoint_twistgen; //subgroup_gen (i2h, j2h)
	Bipoint<curvepoint_fp_t> bipoint_curve_groupelt; // u
	Bipoint<twistpoint_fp2_t> bipoint_twist_groupelt; // v
};

extern PublicKey public_key;

#endif
