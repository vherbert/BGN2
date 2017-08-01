#include "circuit_multiplicationL1.hpp"
void circuit_multiplicationL1(PublicKey public_key, PrivateKey private_key)
{
	F2 un_curve=0,zero_curve=0, produit=0, zero_twist=0, un_twist=0;
	BitEvalL1<curvepoint_fp_t> bit_chiffre_0_curve, bit_chiffre_1_curve;
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_0_twist, bit_chiffre_1_twist;
	BitEvalL2 chiffre_produit;
	
	chiffrement(bit_chiffre_0_curve,0,public_key);
	chiffrement(bit_chiffre_1_curve,1,public_key);
	chiffrement(bit_chiffre_0_twist,0,public_key);
	chiffrement(bit_chiffre_1_twist,1,public_key);
	//dechiffrement(zero_curve,bit_chiffre_0_curve,private_key);
	//dechiffrement(un_curve,bit_chiffre_1_curve,private_key);
	//dechiffrement(zero_twist,bit_chiffre_0_twist,private_key);
	//dechiffrement(un_twist,bit_chiffre_1_twist,private_key);		
	//zout(zero_curve,un_curve,zero_twist,un_twist);
	
	
	cout << "cas #1 0*0" << endl;
	
	chiffre_produit=multiplicationL1(bit_chiffre_0_curve,bit_chiffre_0_twist,public_key);
	dechiffrementL2(produit,chiffre_produit,private_key);
	zout(produit);
		
	cout << "cas #2 0*1" << endl;

	chiffre_produit=multiplicationL1(bit_chiffre_0_curve,bit_chiffre_1_twist,public_key);
	dechiffrementL2(produit,chiffre_produit,private_key);
	zout(produit);
		
	cout << "cas #3 1*0" << endl;

	//bit_chiffre_0.print();
	//bit_chiffre_1.print();

	chiffre_produit=multiplicationL1(bit_chiffre_1_curve,bit_chiffre_0_twist,public_key);
	dechiffrementL2(produit,chiffre_produit,private_key);
	zout(produit);
		
	cout << "cas #4 1*1" << endl;
	
	chiffre_produit=multiplicationL1(bit_chiffre_1_curve,bit_chiffre_1_twist,public_key);
	dechiffrementL2(produit,chiffre_produit,private_key);
	zout(produit);
	
	//cout << "cas #5 (1+0)*1" << endl; 
	//BitChiffre temp_curve = additionL1(bit_chiffre_1_curve,bit_chiffre_0_curve,public_key);	
	//chiffre_produit=multiplicationL1(temp_curve,bit_chiffre_1_twist,public_key);
	//dechiffrementL2(produit,chiffre_produit,private_key);
	//zout(produit);	
	
	//cout << "cas #6 (1+0)*(1+0)" << endl; 
	//BitChiffre temp_twist = additionL1(bit_chiffre_1_twist,bit_chiffre_0_twist,public_key);	
	//chiffre_produit=multiplicationL1(temp_curve,temp_twist,public_key);
	//dechiffrementL2(produit,chiffre_produit,private_key);
	//zout(produit);	
	
	//cout << "cas #7 1*(1+0)" << endl; 
	//chiffre_produit=multiplicationL1(bit_chiffre_1_curve,temp_twist,public_key);
	//dechiffrementL2(produit,chiffre_produit,private_key);
	//zout(produit);		
	
	//cout << "cas #8 (1+0) twist" << endl; 
	//dechiffrement(produit,temp_twist,private_key);
	//zout(produit);		
	
	
	JUMP;
	cout << "taille d'un chiffré de niveau 2 = " << sizeof(chiffre_produit) << " octets" << endl;	
}
