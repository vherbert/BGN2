#include "dechiffrementL3.hpp"

void dechiffrementL3(F2& bit_dechiffre, BitEvalL3 bit_chiffre, PrivateKey private_key)
{
	//signature;
	F2 alpha_dechiffre;
	dechiffrementL2(alpha_dechiffre,bit_chiffre.get_alpha() ,private_key);
	bit_dechiffre=alpha_dechiffre;
	int nb_bipoints=(bit_chiffre.get_vec_bipoints()).size(); //égal à B dans bgnfcf p.6
	F2 beta1_dechiffre[nb_bipoints], beta2_dechiffre[nb_bipoints];
	for (int i=0; i<nb_bipoints; i++)
	{
		dechiffrement(beta1_dechiffre[i],bit_chiffre.get_vec_bipoints()[i], private_key);
		dechiffrementL2(beta2_dechiffre[i],bit_chiffre.get_vec_quadripoints()[i] ,private_key);
		bit_dechiffre = (bit_dechiffre+(beta1_dechiffre[i]*beta2_dechiffre[i]))%2;
	}
}
