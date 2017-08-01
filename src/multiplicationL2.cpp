#include "multiplicationL2.hpp"

BitEvalL4 multiplicationL2 (BitEvalL2 eval1, BitEvalL2 eval2, PublicKey public_key)
{
	BitEvalL4 produit;

	//calcul de alpĥa
	Bipoint<curvepoint_fp_t> bipoint_curve_subgroupelt;
	Bipoint<twistpoint_fp2_t> bipoint_twist_subgroupelt;		
	scalar_t lambda1, lambda2;
	scalar_setrandom(lambda1, bn_r);	
	scalar_setrandom(lambda2, bn_r);		
	bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda1); // calcul de u1
	bipoint_curve_subgroupelt.makeaffine();
	bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda2); // calcul de v1
	bipoint_twist_subgroupelt.makeaffine();
	Quadripoint factor1, factor2, factor3, factor4, factor5;
	
	
	//calcul de e(Enc(a1a2),Enc(1))
	Bipoint<curvepoint_fp_t>  temp1, chiffre_produit; // les bipoints sont initialisés par défaut au bipoint à l'infini
	Bipoint<twistpoint_fp2_t> temp2, chiffre_1_twist;
	chiffrement(chiffre_produit,eval1.get_bit_masque()*eval2.get_bit_masque(), public_key);	
	temp1=chiffre_produit;	
	chiffrement(chiffre_1_twist,1, public_key);	
	temp2=chiffre_1_twist;
	temp1.makeaffine();
	temp2.makeaffine();
	factor1=pairing(temp1,temp2);
	
	//calcul de beta2^a1

	if (eval1.get_bit_masque() == 1) // sinon c'est (1,1,1,1)
	{
		factor2=eval2.get_quadripoint();
	}

	//calcul de beta1^a2
	if (eval2.get_bit_masque() == 1) // sinon c'est (1,1,1,1)
	{
		factor3=eval1.get_quadripoint();
	}	
	
	//calcul de  e(u,v1)
	factor4 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
	
	//calcul de e(u1,v)
	factor5 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
	
	produit.set_alpha(factor1*factor2*factor3*factor4*factor5);		
		
	
	//calcul de beta


	//if (eval1.get_type() == CURVE)
	//{
		produit.set_quadripoint(eval1.get_quadripoint(),0);
	//}
	//else
	//{
		//produit.set_bipoint_twist(eval1.get_bipoint_twist());
	//}	
	
	produit.set_quadripoint(eval2.get_quadripoint(),1);
	return produit;
}
