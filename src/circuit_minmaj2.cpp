#include "circuit_minmaj2.hpp"


void circuit_minmaj2(char& rop, char symbole, PublicKey public_key, PrivateKey private_key)
{	
	F2 clair1=0, clair2=0, clair3=0; 
	clair1=bitset<sizeof(int)*CHAR_BIT>(symbole)[5] ; 
	clair2=bitset<sizeof(int)*CHAR_BIT>(symbole)[6] ;
	clair3=bitset<sizeof(int)*CHAR_BIT>(symbole)[7] ; 
	
	
	BitEvalL1<twistpoint_fp2_t> m6;
	BitEvalL1<curvepoint_fp_t> m7,m8;
	
	chiffrement(m6,clair1,public_key);	
	chiffrement(m7,clair2,public_key);	
	chiffrement(m8,clair3,public_key);

	BitEvalL1<curvepoint_fp_t> temp_curve, chiffre_1_curve;
	BitEvalL1<twistpoint_fp2_t> temp_twist, chiffre_1_twist;
	chiffrement(chiffre_1_curve,1, public_key);
	chiffrement(chiffre_1_twist, 1, public_key);

	temp_curve = additionL1(chiffre_1_curve,m8,public_key);	//calcul 1+m8

	
	BitEvalL2 temp_quadripoint; // m6(1+m8)
	temp_quadripoint = multiplicationL1(temp_curve,m6,public_key);
		
	BitEvalL2 chiffre_L2_1;	
	BitEvalL3 temp_L3, evalue, chiffre_L3_1; 	// m6m7(1+m8)	
	chiffre_L2_1 = multiplicationL1(chiffre_1_curve,chiffre_1_twist,public_key);
	chiffre_L3_1=multiplicationL1L2(chiffre_1_curve,chiffre_L2_1,public_key);
	temp_L3 = multiplicationL1L2(m7,temp_quadripoint,public_key);		
	evalue=additionL3(temp_L3,chiffre_L3_1,public_key);
	
	F2 IS_LOWER_CASE=0;
	dechiffrementL3(IS_LOWER_CASE,evalue,private_key);
	char symbole_dechiffree=symbole;
	if (IS_LOWER_CASE == 0)
	{
		//cout << symbole << " est sensé être une minuscule!" << endl;
		symbole_dechiffree=char(symbole-32);
	}
	else
	{
		//cout << symbole << " est sensé ne pas être une minuscule!" << endl;
	}
	cout << symbole_dechiffree << flush;

}
