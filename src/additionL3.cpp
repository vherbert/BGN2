#include "additionL3.hpp"

BitEvalL3 additionL3 (BitEvalL3 a, BitEvalL3 b, PublicKey public_key)
{
	BitEvalL3 somme;
	
	// calcul de alpha
	scalar_t lambda1, lambda2;
	scalar_setrandom(lambda1, bn_r);	
	scalar_setrandom(lambda2, bn_r);		
	Quadripoint alpha, temp1, temp2, factor3, factor4;
	Bipoint<curvepoint_fp_t> bipoint_curve_subgroupelt; 
	Bipoint<twistpoint_fp2_t> bipoint_twist_subgroupelt;
	temp1=a.get_alpha()*b.get_alpha();
	bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda1);
	bipoint_curve_subgroupelt.makeaffine();
	bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda2);
	bipoint_twist_subgroupelt.makeaffine();	
	//calcul de  e(u,v1)
	factor3 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
	//calcul de e(u1,v)
	factor4 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
	temp2=factor3*factor4;
	alpha=temp1*temp2; 
	somme.set_alpha(alpha);	
	
	somme.set_vec_bipoints(a.get_vec_bipoints());
	somme.set_vec_bipoints(b.get_vec_bipoints());
	somme.set_vec_quadripoints(a.get_vec_quadripoints());
	somme.set_vec_quadripoints(b.get_vec_quadripoints());
	
	return somme;
}
