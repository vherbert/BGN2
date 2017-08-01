#include "precomputation.hpp"

void precomputation(F2 &clair1, F2 &clair2, F2 &clair3, char symbole)
{
	//zout(symbole);
	clair1=bitset<sizeof(int)*CHAR_BIT>(symbole+31)[7] ; //clair de n8 //après l'addition le char est un int, si on fait +0 les 8 premiers bits sont identiques au char, les 24 suivants sont nuls
	clair2=bitset<sizeof(int)*CHAR_BIT>(symbole+31)[8] ; //clair de n9
	clair3=bitset<sizeof(int)*CHAR_BIT>(symbole+5)[7] ; //clair de o8
	//zout(clair1,clair2,clair3); // 100 pour une minuscule
	
	//for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
	//{
		//bit_clair=bitset<CHAR_BIT>(symbole)[j] ;
		//zout(bit_clair);
	//}
	
	//JUMP;
	//for (unsigned int j=0; j<sizeof(symbole+0)*CHAR_BIT;j++) //pour chaque bit
	//{
		//bit_clair=bitset<sizeof(symbole+0)*CHAR_BIT>(symbole+0)[j] ;
		//zout(bit_clair);
	//}
	
	//cout << abi::__cxa_demangle(typeid(symbole).name(), 0, 0, 0) <<  endl;
	//cout << abi::__cxa_demangle(typeid(symbole+0).name(), 0, 0, 0) <<  endl;	
	
}
