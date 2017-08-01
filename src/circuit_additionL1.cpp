#include "circuit_additionL1.hpp"
void circuit_additionL1(PublicKey public_key, PrivateKey private_key)
{
	ecris(CURVE);
	F2 un=0,zero=0, somme=0;
	BitEvalL1<curvepoint_fp_t> bit_chiffre_curve_0, bit_chiffre_curve_1, chiffre_curve_somme;
	
	chiffrement(bit_chiffre_curve_0,0,public_key);
	chiffrement(bit_chiffre_curve_1,1,public_key);
	dechiffrement(zero,bit_chiffre_curve_0,private_key);
	dechiffrement(un,bit_chiffre_curve_1,private_key);
	zout(zero,un);
	
	cout << "cas #1 0+0" << endl;
	
	//ecris(affichage de bit_chiffre_curve_0);
	//bit_chiffre_curve_0.print();
	chiffre_curve_somme=additionL1(bit_chiffre_curve_0,bit_chiffre_curve_0,public_key);
	//ecris(affichage de chiffre_curve_somme);
	//chiffre_curve_somme.print();
	dechiffrement(somme,chiffre_curve_somme,private_key);
	zout(somme);
			
	cout << "cas #2 0+1" << endl;

	chiffre_curve_somme=additionL1(bit_chiffre_curve_0,bit_chiffre_curve_1,public_key);
	dechiffrement(somme,chiffre_curve_somme,private_key);
	zout(somme);
		
	cout << "cas #3 1+0" << endl;

	//bit_chiffre_curve_0.print();
	//bit_chiffre_curve_1.print();

	chiffre_curve_somme=additionL1(bit_chiffre_curve_1,bit_chiffre_curve_0,public_key);
	dechiffrement(somme,chiffre_curve_somme,private_key);
	zout(somme);
		
	cout << "cas #4 1+1" << endl;
	
	chiffre_curve_somme=additionL1(bit_chiffre_curve_1,bit_chiffre_curve_1,public_key);
	dechiffrement(somme,chiffre_curve_somme,private_key);
	zout(somme);
	
	JUMP;
	
	
	
	
	ecris(TWIST);
	un=0,zero=0, somme=0;
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_twist_0, bit_chiffre_twist_1, chiffre_twist_somme;
	
	chiffrement(bit_chiffre_twist_0,0,public_key);
	chiffrement(bit_chiffre_twist_1,1,public_key);
	dechiffrement(zero,bit_chiffre_twist_0,private_key);
	dechiffrement(un,bit_chiffre_twist_1,private_key);
	zout(zero,un);
	
	cout << "cas #1 0+0" << endl;
	
	//ecris(affichage de bit_chiffre_twist_0);
	//bit_chiffre_twist_0.print();
	chiffre_twist_somme=additionL1(bit_chiffre_twist_0,bit_chiffre_twist_0,public_key);
	//ecris(affichage de chiffre_twist_somme);
	//chiffre_twist_somme.print();
	dechiffrement(somme,chiffre_twist_somme,private_key);
	zout(somme);
			
	cout << "cas #2 0+1" << endl;

	chiffre_twist_somme=additionL1(bit_chiffre_twist_0,bit_chiffre_twist_1,public_key);
	dechiffrement(somme,chiffre_twist_somme,private_key);
	zout(somme);
		
	cout << "cas #3 1+0" << endl;

	//bit_chiffre_twist_0.print();
	//bit_chiffre_twist_1.print();

	chiffre_twist_somme=additionL1(bit_chiffre_twist_1,bit_chiffre_twist_0,public_key);
	dechiffrement(somme,chiffre_twist_somme,private_key);
	zout(somme);
		
	cout << "cas #4 1+1" << endl;
	
	chiffre_twist_somme=additionL1(bit_chiffre_twist_1,bit_chiffre_twist_1,public_key);
	dechiffrement(somme,chiffre_twist_somme,private_key);
	zout(somme);	
	
	JUMP;
	cout << "taille d'un chiffré de niveau 1 de type curve = " << sizeof(bit_chiffre_curve_0) << " octets" << endl;
	cout << "taille d'un chiffré de niveau 1 de type twist = " << sizeof(bit_chiffre_twist_0) << " octets" << endl;
	//cout << "taille en octets de la somme de deux chiffrés de niveau 1 de type curve =" << sizeof(chiffre_curve_somme)<< endl;
	//cout << "taille en octets de la somme de deux chiffrés de niveau 1 de type twist" << sizeof(chiffre_twist_somme)<< endl;
	
	

}
