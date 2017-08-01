#include "circuit_chiffrement.hpp"

void circuit_chiffrement(char lettre, PublicKey public_key, PrivateKey private_key)
{
	signature;
	F2 bit_clair=0, bit_dechiffre=0; 
	BitEvalL1<curvepoint_fp_t> bit_chiffre_curve;	
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_twist;	
	for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
	{
		bit_clair=bitset<CHAR_BIT>(lettre)[j] ;
		//zout(bit_clair);
		chiffrement(bit_chiffre_curve,bit_clair,public_key);
		dechiffrement(bit_dechiffre,bit_chiffre_curve,private_key);
		//zout(bit_dechiffre);
		if (bit_clair != bit_dechiffre)
		{
			cout << BOLDRED << "KO" << endl;
			exit(0);
		}
		cout << BOLDRED << "OK" << endl;
		chiffrement(bit_chiffre_twist,bit_clair,public_key);
		dechiffrement(bit_dechiffre,bit_chiffre_twist,private_key);
		//zout(bit_dechiffre);
		if (bit_clair != bit_dechiffre)
		{
			cout << BOLDRED << "KO" << endl;
			exit(0);
		}
		cout << BOLDRED << "OK" << endl;		
	}
	//BitChiffre eval11, eval12;
	//chiffrement(eval11,bit_clair,public_key,CURVE);
	//chiffrement(eval12,bit_clair,public_key,TWIST);
	//BitEvalL2 eval2= multiplicationL1 ( eval11, eval12, public_key);
	//BitEvalL3 eval3= multiplicationL1L2 ( eval11, eval2, public_key);
	//BitEvalL3 eval31 = multiplicationL1L2 ( eval11, eval2, public_key);
	//BitEvalL3 eval32 = additionL3(eval31,eval31,public_key);
	//BitEvalL3 eval33 = additionL3(eval32,eval32,public_key);
	//BitEvalL3 eval34 = additionL3(eval33,eval33,public_key);
	//BitEvalL3 eval35 = additionL3(eval31,eval33,public_key);
	//BitEvalL3 eval36 = additionL3(eval33,eval31,public_key);

	//zout(lettre, char(lettre+31), char(lettre+5));
}
