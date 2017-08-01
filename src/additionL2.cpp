#include "additionL2.hpp"

BitEvalL2 additionL2 (BitEvalL2 a, BitEvalL2 b, PublicKey public_key)
{
	BitEvalL2 somme;
	somme.set_bit_masque((a.get_bit_masque()+b.get_bit_masque())%2);
	scalar_t lambda1, lambda2;
	scalar_setrandom(lambda1, bn_r);	
	scalar_setrandom(lambda2, bn_r);	
	Quadripoint beta, temp1, temp2, factor3, factor4;
	Bipoint<curvepoint_fp_t> bipoint_curve_subgroupelt; 
	Bipoint<twistpoint_fp2_t> bipoint_twist_subgroupelt;
	temp1=a.get_quadripoint()*b.get_quadripoint();
	bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda1);
	bipoint_curve_subgroupelt.makeaffine();
	bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda2);
	bipoint_twist_subgroupelt.makeaffine();	
	//calcul de  e(u,v1)
	factor3 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
	//calcul de e(u1,v)
	factor4 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
	temp2=factor3*factor4;
	beta=temp1*temp2; 
	somme.set_quadripoint(beta);
	//private_key.pi_T(a.get_quadripoint()).print();
	//private_key.pi_T(b.get_quadripoint()).print();
	//private_key.pi_T(factor3).print();
	//private_key.pi_T(factor4).print();
	return somme;
}
