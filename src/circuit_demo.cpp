#include "circuit_demo.hpp"


void circuit_demo(char& evalue_dechiffre, char clair, PublicKey public_key, PrivateKey private_key)
{
	cout <<  "Tapez le caractère de votre choix" << endl;
	zout(clair);	
	F2 clair1=0, clair2=0, clair3=0; // resp de n8, n9, o8 (voir rapport.pdf, page 24)
	precomputation(clair1, clair2, clair3, clair);
	F2 curve, twist, quadripoint;
	
	BitEvalL1<curvepoint_fp_t> n8,n9;
	BitEvalL1<twistpoint_fp2_t> o8;
	chiffrement(n8,clair1,public_key);	
	chiffrement(n9,clair2,public_key);	
	chiffrement(o8,clair3,public_key);
	grostitre(affichage des trois chiffrés correspondant aux trois bits utiles);
	cout << "Un chiffré consiste en un bit et deux points de la courbe ou du twist" << endl;
	n8.print();
	n9.print();
	o8.print();

	BitEvalL1<curvepoint_fp_t> temp_curve, chiffre_1_curve;
	BitEvalL1<twistpoint_fp2_t> temp_twist, chiffre_1_twist;
	chiffrement(chiffre_1_curve,1, public_key);
	chiffrement(chiffre_1_twist,1, public_key);
	temp_curve = additionL1(chiffre_1_curve,n9,public_key);	//NB il faut rajouter CURVE pour passer de BitChiffre à BitEvalL1, la diff entre les deux, la taille mémoire
	temp_twist = additionL1(chiffre_1_twist,o8,public_key);
	
	BitEvalL2 temp_quadripoint; // (1+n9)(1+o8)
	temp_quadripoint = multiplicationL1(temp_curve,temp_twist,public_key);

		
	BitEvalL3 evalue; 	// n8(1+n9)(1+o8)	
	evalue = multiplicationL1L2(n8,temp_quadripoint,public_key);	

	cout << BOLDCYAN << "affichage de l'évalué" << RESET << endl;
	cout << " Dans ce circuit, l'évalué consiste en 2*4 points du corps Fp^12 et deux points de la courbe" << endl;
	evalue.print();
	postcomputation(evalue_dechiffre, clair, evalue, private_key);	
	zout(clair, evalue_dechiffre);
}
