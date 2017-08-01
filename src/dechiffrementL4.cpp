#include "dechiffrementL4.hpp"

void dechiffrementL4(F2& bit_dechiffre, BitEvalL4 bit_chiffre, PrivateKey private_key)
{
	F2 alpha_dechiffre;
	dechiffrementL2(alpha_dechiffre,bit_chiffre.get_alpha() ,private_key);
	bit_dechiffre=alpha_dechiffre;
	int nb_quadripoints=(bit_chiffre.get_vec_quadripoints(0)).size(); //égal à B dans bgnfcf p.6
	F2 beta1_dechiffre[nb_quadripoints], beta2_dechiffre[nb_quadripoints];
	for (int i=0; i<nb_quadripoints; i++)
	{
		dechiffrementL2(beta1_dechiffre[i],bit_chiffre.get_vec_quadripoints(0)[i], private_key);
		dechiffrementL2(beta2_dechiffre[i],bit_chiffre.get_vec_quadripoints(1)[i] ,private_key);
		bit_dechiffre = (bit_dechiffre+(beta1_dechiffre[i]*beta2_dechiffre[i]))%2;
	}
}
