#include "circuit_additionL3.hpp"
void circuit_additionL3(PublicKey public_key, PrivateKey private_key)
{
	F2 un=0,zero=0, somme=0;
	BitEvalL1<curvepoint_fp_t> bit_chiffre_0_curve, bit_chiffre_1_curve;
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_0_twist, bit_chiffre_1_twist;	BitEvalL2 chiffre_L2_0, chiffre_L2_1;
	BitEvalL3 chiffre_L3_0, chiffre_L3_1, chiffre_somme;
	chiffrement(bit_chiffre_0_curve,0,public_key);
	chiffrement(bit_chiffre_1_curve,1,public_key);
	chiffrement(bit_chiffre_0_twist,0,public_key);
	chiffrement(bit_chiffre_1_twist,1,public_key);	
	chiffre_L2_0 = multiplicationL1(bit_chiffre_0_curve,bit_chiffre_0_twist,public_key);
	chiffre_L2_1 = multiplicationL1(bit_chiffre_1_curve,bit_chiffre_1_twist,public_key);
	chiffre_L3_0 = multiplicationL1L2(bit_chiffre_0_curve,chiffre_L2_0,public_key);
	chiffre_L3_1 = multiplicationL1L2(bit_chiffre_1_curve,chiffre_L2_1,public_key);
	
	dechiffrementL3(zero,chiffre_L3_0,private_key);
	dechiffrementL3(un,chiffre_L3_1,private_key);
	zout(zero,un);
		
	cout << "cas #1 0+0" << endl;
	
	chiffre_somme=additionL3(chiffre_L3_0,chiffre_L3_0,public_key);
	dechiffrementL3(somme,chiffre_somme,private_key);
	zout(somme);
		
	cout << "cas #2 0+1" << endl;

	chiffre_somme=additionL3(chiffre_L3_0,chiffre_L3_1,public_key);
	dechiffrementL3(somme,chiffre_somme,private_key);
	zout(somme);
		
	cout << "cas #3 1+0" << endl;

	//chiffre_L3_0.print_bit_masque();
	//chiffre_L3_1.print_bit_masque();

	chiffre_somme=additionL3(chiffre_L3_1,chiffre_L3_0,public_key);
	dechiffrementL3(somme,chiffre_somme,private_key);
	zout(somme);
	
	//chiffre_somme.print_bit_masque();

		
	cout << "cas #4 1+1" << endl;
	
	chiffre_somme=additionL3(chiffre_L3_1,chiffre_L3_1,public_key);
	dechiffrementL3(somme,chiffre_somme,private_key);
	zout(somme);
	
	JUMP;
	cout << "taille d'un chiffré de niveau 3 = " << sizeof(chiffre_L3_0)+sizeof(Bipoint<curvepoint_fp_t>)*(chiffre_L3_0.get_vec_bipoints().capacity()) +sizeof(Quadripoint)*(chiffre_L3_0.get_vec_quadripoints().capacity())<< " octets" << endl;
	cout << "taille de la somme de 2 chiffrés de niveau 3 = " << sizeof(chiffre_somme)+sizeof(Bipoint<curvepoint_fp_t>)*(chiffre_somme.get_vec_bipoints().capacity()) +sizeof(Quadripoint)*(chiffre_somme.get_vec_quadripoints().capacity())<< " octets" << endl;	
}
