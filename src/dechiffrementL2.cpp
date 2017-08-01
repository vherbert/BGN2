#include "dechiffrementL2.hpp"

void dechiffrementL2(F2& bit_dechiffre, BitEvalL2 bit_chiffre, PrivateKey private_key) //valeur du log b1b2+a1b2+a2b1+s
{
	signature;
	//ecris(log=b1b2+a1b2+a2b1+s);
	Quadripoint quadripoint_pi_T_chiffre;
	quadripoint_pi_T_chiffre = private_key.pi_T(bit_chiffre.get_quadripoint());  //pi_T(beta)
	//ecris(affichage de beta);
	//bit_chiffre.get_quadripoint().print();
	//ecris(affichage de pi_T(beta));
	//quadripoint_pi_T_chiffre.print(0);
	Quadripoint base_log, pow_log; 
	base_log = private_key.pi_T(pairing(public_key.get_bipoint_curve_groupelt(),public_key.get_bipoint_twist_groupelt()));  //pi_T(e(u,v))
	//ecris(affichage de pi_T(e(u,v)));
	//base_log.print(0);
	//ecris(affichage de private_key);
	//private_key.print();
	
	if (fp12e_isone(quadripoint_pi_T_chiffre[0]) && fp12e_isone(quadripoint_pi_T_chiffre[1]) && fp12e_isone(quadripoint_pi_T_chiffre[2]) && fp12e_isone(quadripoint_pi_T_chiffre[3]))
	{
		//cout << "cas log=0" << endl;
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	if (quadripoint_pi_T_chiffre == base_log)
	{
		//cout << "cas log=1" << endl;
		bit_dechiffre = (bit_chiffre.get_bit_masque()+1)%2;
		return;
	}
	pow_log=base_log*base_log;
	//ecris(affichage de pi_T(e(u,v))^2);
	//pow_log.print();	
	if (quadripoint_pi_T_chiffre == pow_log)
	{
		//cout << "cas log=2" << endl;
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	pow_log=pow_log*base_log;
	//ecris(affichage de pi_T(e(u,v))^3);
	//pow_log.print();	
	if (quadripoint_pi_T_chiffre == pow_log)
	{
		//cout << "cas log=3" << endl;
		bit_dechiffre = (bit_chiffre.get_bit_masque()+1)%2;
		return;
	}	
	pow_log=pow_log*base_log;
	//ecris(affichage de pi_T(e(u,v))^4);
	//pow_log.print();
	if (quadripoint_pi_T_chiffre == pow_log)
	{
		//cout << "cas log=4" << endl;
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	int log=4;
	abc;
	while (!(quadripoint_pi_T_chiffre == pow_log))
	{
		pow_log=pow_log*base_log;
		log++;
		//zout(log);
	}
	xyz;
	//zout(log);
	bit_dechiffre = (bit_chiffre.get_bit_masque()+ log)%2;
	

}

void dechiffrementL2(F2& bit_dechiffre, Quadripoint quadripoint, PrivateKey private_key)
//routine pour les évalués de niveau 3 et 4, déchiffrement sans Catalano Fiore, calcul d'un log seulement, prend en entrée un quadripoint et non pas un évalué de niveau 2
{
	Quadripoint quadripoint_pi_T_chiffre;
	quadripoint_pi_T_chiffre = private_key.pi_T(quadripoint);  //pi_T(beta)
	Quadripoint base_log, pow_log; 
	base_log = private_key.pi_T(pairing(public_key.get_bipoint_curve_groupelt(),public_key.get_bipoint_twist_groupelt()));  //pi_T(e(u,v))
	if (fp12e_isone(quadripoint_pi_T_chiffre[0]) && fp12e_isone(quadripoint_pi_T_chiffre[1]) && fp12e_isone(quadripoint_pi_T_chiffre[2]) && fp12e_isone(quadripoint_pi_T_chiffre[3]))
	{
		//cout << "cas log=0" << endl;
		bit_dechiffre = 0;
		return;
	}
	if (quadripoint_pi_T_chiffre == base_log)
	{
		//cout << "cas log=1" << endl;
		bit_dechiffre = 1;
		return;
	}	
	pow_log=base_log*base_log;
	if (quadripoint_pi_T_chiffre == pow_log)
	{
		//cout << "cas log=2" << endl;
		bit_dechiffre = 0;
		return;
	}
	pow_log=pow_log*base_log;
	if (quadripoint_pi_T_chiffre == pow_log)
	{
		//cout << "cas log=3" << endl;
		bit_dechiffre = 1;
		return;
	}	
	pow_log=pow_log*base_log;
	if (quadripoint_pi_T_chiffre == pow_log)
	{
		//cout << "cas log=4" << endl;
		bit_dechiffre = 0;
		return;
	}
	int log=4;
	
	//quadripoint_pi_T_chiffre.print(0);
	//quadripoint_pi_T_chiffre.print(1);
	//quadripoint_pi_T_chiffre.print(2);
	//quadripoint_pi_T_chiffre.print(3);
	//abc;
	while (!(quadripoint_pi_T_chiffre == pow_log))
	{
		pow_log=pow_log*base_log;
		log++;
	}
	//xyz;
	//zout(log);
	bit_dechiffre = log%2;
}
