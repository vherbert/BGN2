#include "multiplicationL1L2.hpp"

BitEvalL3 multiplicationL1L2 (BitEvalL1<curvepoint_fp_t> eval1, BitEvalL2 eval2, PublicKey public_key)
{
	BitEvalL3 produit;

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
	Bipoint<curvepoint_fp_t>  temp1, chiffre_produit; // les vec_bipoints sont initialisés par défaut au bipoint à l'infini
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

	
	//calcul de  e(a2 beta1, Enc(1)) //si CURVE et e(Enc(1),a2 beta1)  si TWIST

	Bipoint<curvepoint_fp_t>  temp3; // les vec_bipoints sont initialisés par défaut au bipoint à l'infini
	Bipoint<twistpoint_fp2_t> temp4;
	//chiffrement(chiffre_1_curve,1, public_key, CURVE);
	chiffrement(chiffre_1_twist,1, public_key);
			
	//if (eval1.get_type() == CURVE)
	//{	
		if (eval2.get_bit_masque() == 1) //sinon temp3 doit etre le bipoint à l'infini
		{
			temp3 = eval1.get_bipoint(); 
		}		
		temp4=chiffre_1_twist;
	//}
	//else // eval1.get_type() == TWIST
	//{
		//temp3=chiffre_1_curve.get_bipoint_curve();
		//if (eval2.get_bit_masque() == 1) //sinon temp3 doit etre le bipoint à l'infini
		//{
			//temp4 = eval1.get_bipoint_twist(); 
		//}		
		
	//}	
	temp3.makeaffine();
	temp4.makeaffine();
	factor3 = pairing(temp3, temp4);	
	
	//calcul de  e(u,v1)
	factor4 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
	
	//calcul de e(u1,v)
	factor5 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
	
	produit.set_alpha(factor1*factor2*factor3*factor4*factor5);		
		
	
	//calcul de beta


	//if (eval1.get_type() == CURVE)
	//{
		produit.set_bipoint_curve(eval1.get_bipoint());
	//}
	//else
	//{
		//produit.set_bipoint_twist(eval1.get_bipoint_twist());
	//}	
	
	produit.set_quadripoint(eval2.get_quadripoint());
	return produit;
}




BitEvalL3 multiplicationL1L2 (BitChiffre eval1, BitEvalL2 eval2, PublicKey public_key)
{
	BitEvalL3 produit;

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
	Bipoint<curvepoint_fp_t>  temp1, chiffre_produit; // les vec_bipoints sont initialisés par défaut au bipoint à l'infini
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

	
	//calcul de  e(a2 beta1, Enc(1)) //si CURVE et e(Enc(1),a2 beta1)  si TWIST

	Bipoint<curvepoint_fp_t>  temp3; // les vec_bipoints sont initialisés par défaut au bipoint à l'infini
	Bipoint<twistpoint_fp2_t> temp4;
	//chiffrement(chiffre_1_curve,1, public_key, CURVE);
	chiffrement(chiffre_1_twist,1, public_key);
			
	//if (eval1.get_type() == CURVE)
	//{	
		if (eval2.get_bit_masque() == 1) //sinon temp3 doit etre le bipoint à l'infini
		{
			temp3 = eval1.get_bipoint_curve(); 
		}		
		temp4=chiffre_1_twist;
	//}
	//else // eval1.get_type() == TWIST
	//{
		//temp3=chiffre_1_curve.get_bipoint_curve();
		//if (eval2.get_bit_masque() == 1) //sinon temp3 doit etre le bipoint à l'infini
		//{
			//temp4 = eval1.get_bipoint_twist(); 
		//}		
		
	//}	
	temp3.makeaffine();
	temp4.makeaffine();
	factor3 = pairing(temp3, temp4);	
	
	//calcul de  e(u,v1)
	factor4 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
	
	//calcul de e(u1,v)
	factor5 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
	
	produit.set_alpha(factor1*factor2*factor3*factor4*factor5);		
		
	
	//calcul de beta


	//if (eval1.get_type() == CURVE)
	//{
		produit.set_bipoint_curve(eval1.get_bipoint_curve());
	//}
	//else
	//{
		//produit.set_bipoint_twist(eval1.get_bipoint_twist());
	//}	
	
	produit.set_quadripoint(eval2.get_quadripoint());
	return produit;
}
