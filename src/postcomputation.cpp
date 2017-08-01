#include "postcomputation.hpp"

void postcomputation(char& rop, char symbole, BitEvalL3 evalue, PrivateKey private_key)
{
	//void dechiffrementL3(F2& bit_dechiffre, BitEvalL3 bit_chiffre, PrivateKey private_key)
	F2 IS_LOWER_CASE=0;
	dechiffrementL3(IS_LOWER_CASE,evalue,private_key);
	char symbole_dechiffree=symbole;
	//zout(IS_LOWER_CASE); //multiplicationL1L2 dechiffrementL3
	if (IS_LOWER_CASE == 1)
	{
		//cout << symbole << " est sensé être une minuscule!" << endl;
		symbole_dechiffree=char(symbole-32);
	}
	else
	{
		//cout << symbole << " est sensé ne pas être une minuscule!" << endl;
	}
	//cout << symbole_dechiffree << flush;
	//zout(sizeof(evalue));
	rop=symbole_dechiffree;

}
