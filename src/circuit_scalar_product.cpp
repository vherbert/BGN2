#include "circuit_scalar_product.hpp"
void circuit_scalar_product(PublicKey public_key, PrivateKey private_key)
{
	unsigned long graine_faible_time;
	graine_faible_time = time(NULL); 
	srand((unsigned int)graine_faible_time); //cast explicite pour être propre
		
	// longueur des vecteurs n
	
	int n=5;
	deque<bool> clair_1(n),clair_2(n);
	for (unsigned int i=0; i<clair_1.size();i++)
	{
		clair_1[i]=rand()%2;
		cout << "clair_1[" << i << "] = " << clair_1[i] << endl;
		clair_2[i]=rand()%2;
		cout << "clair_2[" << i << "] = " << clair_2[i] << endl;	
		jump;	
	}
	
	
	// chiffrement vecteur binaire 1
	
	BitEvalL1<curvepoint_fp_t> A[n];	
	for (unsigned int i=0; i<clair_1.size();i++) //pour chaque bit
	{
		chiffrement(A[i],clair_1[i],public_key);
	}
	
	// chiffrement vecteur binaire 2

	BitEvalL1<twistpoint_fp2_t> B[n];	
	for (unsigned int i=0; i<clair_2.size();i++) //pour chaque bit
	{
		chiffrement(B[i],clair_2[i],public_key);
	}
		
	// évaluation produit scalaire
	
	BitEvalL2 evalue, C[n];
	int scalar_product=0;
	for (unsigned int i=0; i<clair_1.size();i++) //pour chaque bit
	{
		C[i]=multiplicationL1(A[i],B[i],public_key);
		evalue=additionL2(evalue,C[i],public_key);
	}	
	
	// déchiffrement de l'évalué (somme de n chiffrés L1)
	
	F2 evalue_dechiffre=0;
	dechiffrementL2(evalue_dechiffre,evalue,private_key);
	zout (evalue_dechiffre); // produit scalaire modulo 2
	for (unsigned int i=0; i<clair_1.size();i++) //pour chaque bit
	{
		dechiffrementL2(evalue_dechiffre,C[i],private_key);
		scalar_product+=evalue_dechiffre;
	}	
	zout(scalar_product);
}
