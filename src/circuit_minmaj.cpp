#include "circuit_minmaj.hpp"


void circuit_minmaj(char& rop, char symbole, PublicKey public_key, PrivateKey private_key)
{
	//signature;
	
	F2 clair1=0, clair2=0, clair3=0; // resp de n8, n9, o8 (voir rapport.pdf, page 24)
	precomputation(clair1, clair2, clair3, symbole);
	F2 curve, twist, quadripoint;
	//F2 clair_n8, clair_n9, clair_o8;
	
	//BitChiffre n8,n9,o8;
	BitEvalL1<curvepoint_fp_t> n8,n9;
	BitEvalL1<twistpoint_fp2_t> o8;
	chiffrement(n8,clair1,public_key);	
	chiffrement(n9,clair2,public_key);	
	chiffrement(o8,clair3,public_key);
	//zout(sizeof(n8),sizeof(o8));
	//dechiffrement(clair_n8,n8,private_key,CURVE);
	//dechiffrement(clair_n9,n9,private_key,CURVE);
	//dechiffrement(clair_o8,o8,private_key,TWIST);	
	
	//BitChiffre temp_curve, temp_twist; //resp 1+n9 et 1+o8
	//BitChiffre chiffre_1_curve, chiffre_1_twist;
	BitEvalL1<curvepoint_fp_t> temp_curve, chiffre_1_curve;
	BitEvalL1<twistpoint_fp2_t> temp_twist, chiffre_1_twist;
	chiffrement(chiffre_1_curve,1, public_key);
	chiffrement(chiffre_1_twist,1, public_key);
	temp_curve = additionL1(chiffre_1_curve,n9,public_key);	//NB il faut rajouter CURVE pour passer de BitChiffre à BitEvalL1, la diff entre les deux, la taille mémoire
	temp_twist = additionL1(chiffre_1_twist,o8,public_key);
	//dechiffrement(curve,temp_curve,private_key,CURVE);
	//dechiffrement(twist,temp_twist,private_key,TWIST);
	
	BitEvalL2 temp_quadripoint; // (1+n9)(1+o8)
	temp_quadripoint = multiplicationL1(temp_curve,temp_twist,public_key);
	//dechiffrementL2(quadripoint,temp_quadripoint,private_key);

	//zout(clair1,clair2,clair3);
	//zout(curve,twist,quadripoint); 
		
	BitEvalL3 evalue; 	// n8(1+n9)(1+o8)	
	evalue = multiplicationL1L2(n8,temp_quadripoint,public_key);
	//jump;
	//zout(sizeof(evalue),sizeof(evalue.get_vec_bipoints()),sizeof(evalue.get_vec_quadripoints()),sizeof(evalue.get_alpha()),sizeof(temp_quadripoint.get_bit_masque()),sizeof(temp_quadripoint.get_quadripoint()));
	
	postcomputation(rop, symbole, evalue, private_key);	
}
