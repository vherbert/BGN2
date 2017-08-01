#include "dechiffrement.hpp"


void dechiffrement(F2& bit_dechiffre, BitEvalL1<curvepoint_fp_t> bit_chiffre, PrivateKey private_key)
{
	Bipoint<curvepoint_fp_t> bipoint_pi_1_chiffre, bipoint_pi_1_u, bipoint_pi_1_2u;
	bipoint_pi_1_chiffre = private_key.pi_1(bit_chiffre.get_bipoint()); 
	if (fpe_iszero(bipoint_pi_1_chiffre[0]->m_z) && fpe_iszero(bipoint_pi_1_chiffre[1]->m_z))
	{
		//cout << "cas log=0" << endl;
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	bipoint_pi_1_u = private_key.pi_1(public_key.get_bipoint_curve_groupelt());
	if (bipoint_pi_1_chiffre == bipoint_pi_1_u)
	{
		//cout << "cas log=1" << endl;
		bit_dechiffre = (bit_chiffre.get_bit_masque()+1)%2;
		return;
	}
	bipoint_pi_1_2u=bipoint_pi_1_u+bipoint_pi_1_u;
	bipoint_pi_1_2u.makeaffine();				
	if (bipoint_pi_1_chiffre == bipoint_pi_1_2u)
	{
		//cout << "cas log=2" << endl; //a améliorer
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	//cout << "cas log >=3" << endl; //a améliorer et a répercuter dans la seconde fonction dechiffrement	
	
	//cout << "cas log>2" << endl;
	Bipoint<curvepoint_fp_t> mul_log=bipoint_pi_1_2u+bipoint_pi_1_u; 
	mul_log.makeaffine();
	int log=3;
	while(!(bipoint_pi_1_chiffre == mul_log))
	{
		mul_log=mul_log+bipoint_pi_1_u;
		mul_log.makeaffine();	
		log++;
		//zout(log);
	}
	//zout(log);
	bit_dechiffre = (bit_chiffre.get_bit_masque()+ log)%2;
}

void dechiffrement(F2& bit_dechiffre, BitEvalL1<twistpoint_fp2_t> bit_chiffre, PrivateKey private_key) // pour les chiffrés de niveau 1
{
	Bipoint<twistpoint_fp2_t> bipoint_pi_2_chiffre, bipoint_pi_2_v, bipoint_pi_2_2v;
	bipoint_pi_2_chiffre = private_key.pi_2(bit_chiffre.get_bipoint()); //pi_2(bv+v1)
	if (fp2e_iszero(bipoint_pi_2_chiffre[0]->m_z) && fp2e_iszero(bipoint_pi_2_chiffre[1]->m_z))
	{
		//cout << "cas log=0" << endl;
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	bipoint_pi_2_v = private_key.pi_2(public_key.get_bipoint_twist_groupelt());
	if (bipoint_pi_2_chiffre == bipoint_pi_2_v)
	{
		//cout << "cas log=1" << endl;
		bit_dechiffre = (bit_chiffre.get_bit_masque()+1)%2;
		return;
	}
	bipoint_pi_2_2v=bipoint_pi_2_v+bipoint_pi_2_v;
	bipoint_pi_2_2v.makeaffine();				
	if (bipoint_pi_2_chiffre == bipoint_pi_2_2v)
	{
		//cout << "cas log=2" << endl; //a améliorer
		bit_dechiffre = bit_chiffre.get_bit_masque();
		return;
	}
	Bipoint<twistpoint_fp2_t> mul_log=bipoint_pi_2_2v+bipoint_pi_2_v; 
	mul_log.makeaffine();
	int log=3;
	while(!(bipoint_pi_2_chiffre == mul_log))
	{
		mul_log=mul_log+bipoint_pi_2_v;
		mul_log.makeaffine();	
		log++;
		//zout(log);
	}
	//zout(log);
	bit_dechiffre = (bit_chiffre.get_bit_masque()+ log)%2;
}


void dechiffrement(F2& bit_dechiffre, BitChiffre bit_chiffre, PrivateKey private_key, Type type)
{
	//signature;
	if (type == CURVE)
	{	
		Bipoint<curvepoint_fp_t> bipoint_pi_1_chiffre, bipoint_pi_1_u, bipoint_pi_1_2u;
		//cout << RED << "affichage du bit chiffré (le bit a et le bipoint bu+u1)" << RESET << endl;
		//bit_chiffre.print_bit_chiffre(CURVE);
		bipoint_pi_1_chiffre = private_key.pi_1(bit_chiffre.get_bipoint_curve());  //pi_1(bu+u1)
		//cout << RED << "affichage du bipoint  pi_1(bu+u1)" << RESET << endl;
		//bipoint_pi_1_chiffre.print();	
		//public_key.print();	
		//cout << RED << "affichage du bipoint  pi_1(u)" << RESET << endl;
		//bipoint_pi_1_u.print();	
		//cout << RED << "affichage du bipoint  pi_1(2u)=2pi_1(u)=pi_1(u)+pi_1(u)" << RESET << endl;
		
		//(bipoint_pi_1_2u).print();			
		//si le bipoint est (0,0) alors log=0 sinon log=1, bitdecode=bitmasque+log	
		////bit_chiffre.print_bit_masque();
		//bit_chiffre.get_bipoint_curve().print();
		//bipoint_pi_1_chiffre.print();		
		if (fpe_iszero(bipoint_pi_1_chiffre[0]->m_z) && fpe_iszero(bipoint_pi_1_chiffre[1]->m_z))
		{
			//cout << "cas log=0" << endl;
			bit_dechiffre = bit_chiffre.get_bit_masque();
			return;
		}
		bipoint_pi_1_u = private_key.pi_1(public_key.get_bipoint_curve_groupelt()); 
		if (bipoint_pi_1_chiffre == bipoint_pi_1_u)
		{
			//cout << "cas log=1" << endl;
			bit_dechiffre = (bit_chiffre.get_bit_masque()+1)%2;
			return;
		}
		bipoint_pi_1_2u=bipoint_pi_1_u+bipoint_pi_1_u;
		bipoint_pi_1_2u.makeaffine();				
		if (bipoint_pi_1_chiffre == bipoint_pi_1_2u)
		{
			//cout << "cas log=2" << endl; //a améliorer
			bit_dechiffre = bit_chiffre.get_bit_masque();
			return;
		}
		//cout << "cas log >=3" << endl; //a améliorer et a répercuter dans la seconde fonction dechiffrement
		Bipoint<curvepoint_fp_t> mul_log=bipoint_pi_1_2u+bipoint_pi_1_u; 
		mul_log.makeaffine();
		int log=3;
		while(!(bipoint_pi_1_chiffre == mul_log))
		{
			mul_log=mul_log+bipoint_pi_1_u;
			mul_log.makeaffine();	
			log++;
			//zout(log);
		}
		//zout(log);
		bit_dechiffre = (bit_chiffre.get_bit_masque()+ log)%2;		
	}
	if (type == TWIST)
	{
		Bipoint<twistpoint_fp2_t> bipoint_pi_2_chiffre, bipoint_pi_2_v, bipoint_pi_2_2v;
		bipoint_pi_2_chiffre = private_key.pi_2(bit_chiffre.get_bipoint_twist()); //pi_2(bv+v1)
		//bipoint_pi_2_v = private_key.pi_2(public_key.get_bipoint_twist_groupelt());
		//bipoint_pi_2_chiffre.print_point(0);
		//jump;
		//bipoint_pi_2_chiffre.print_point(1);
		//JUMP;
		//bipoint_pi_2_v.print_point(0);
		//jump;
		//bipoint_pi_2_v.print_point(1);
		//JUMP;
		//zout(bit_chiffre.get_bit_masque());
		//bit_chiffre.print_bit_masque();
		if (fp2e_iszero(bipoint_pi_2_chiffre[0]->m_z) && fp2e_iszero(bipoint_pi_2_chiffre[1]->m_z))
		{
			//cout << "cas log=0" << endl;
			bit_dechiffre = bit_chiffre.get_bit_masque();
			return;
		}
		bipoint_pi_2_v = private_key.pi_2(public_key.get_bipoint_twist_groupelt());
		if (bipoint_pi_2_chiffre == bipoint_pi_2_v)
		{
			//cout << "cas log=1" << endl;
			bit_dechiffre = (bit_chiffre.get_bit_masque()+1)%2;
			return;
		}
		bipoint_pi_2_2v=bipoint_pi_2_v+bipoint_pi_2_v;
		bipoint_pi_2_2v.makeaffine();				
		if (bipoint_pi_2_chiffre == bipoint_pi_2_2v)
		{
			//cout << "cas log=2" << endl; //a améliorer
			bit_dechiffre = bit_chiffre.get_bit_masque();
			return;
		}
		Bipoint<twistpoint_fp2_t> mul_log=bipoint_pi_2_2v+bipoint_pi_2_v; 
		mul_log.makeaffine();
		int log=3;
		while(!(bipoint_pi_2_chiffre == mul_log))
		{
			mul_log=mul_log+bipoint_pi_2_v;
			mul_log.makeaffine();	
			log++;
			//zout(log);
		}
		//zout(log);
		bit_dechiffre = (bit_chiffre.get_bit_masque()+ log)%2;
	}
}


void dechiffrement(F2& bit_dechiffre, Bipoint<curvepoint_fp_t> bipoint, PrivateKey private_key) 
//routine pour les évalués de niveau 3 et 4, déchiffrement sans Catalano Fiore, calcul d'un log seulement, prend en entrée un bipoint de type curve (inutile de traiter le cas twist car on peut évaluer les circuits de niveau 3 et 4 en traitant seuelement un des deux types, le type Curve opère dans Fp, les opérations sont moins couteuses) et non pas un chiffré de niveau 1
{
	Bipoint<curvepoint_fp_t> bipoint_pi_1_chiffre, bipoint_pi_1_u, bipoint_pi_1_2u;
	bipoint_pi_1_chiffre = private_key.pi_1(bipoint);  //pi_1(bu+u1)
	if (fpe_iszero(bipoint_pi_1_chiffre[0]->m_z) && fpe_iszero(bipoint_pi_1_chiffre[1]->m_z))
	{
		//cout << "cas log=0" << endl;
		bit_dechiffre = 0;
	}
	else
	{
		bipoint_pi_1_u = private_key.pi_1(public_key.get_bipoint_curve_groupelt()); 
		if (bipoint_pi_1_chiffre == bipoint_pi_1_u)
		{
			//cout << "cas log=1" << endl;
			bit_dechiffre = 1;
		}
		else 
		{
			bipoint_pi_1_2u=bipoint_pi_1_u+bipoint_pi_1_u;
			bipoint_pi_1_2u.makeaffine();				
			if (bipoint_pi_1_chiffre == bipoint_pi_1_2u)
			{
				//cout << "cas log=2" << endl; //a améliorer
				bit_dechiffre = 0;
			}
			else
			{
				//cout << "cas log >=3" << endl; //a améliorer et a répercuter dans la seconde fonction dechiffrement
				Bipoint<curvepoint_fp_t> mul_log=bipoint_pi_1_2u+bipoint_pi_1_u; 
				mul_log.makeaffine();
				int log=3;
				while(!(bipoint_pi_1_chiffre == mul_log))
				{
					mul_log=mul_log+bipoint_pi_1_u;
					mul_log.makeaffine();	
					log++;
					//zout(log);
				}
				//zout(log);
				bit_dechiffre = log%2;				
			}
		}
	}	
}


void dechiffrement(F2& bit_dechiffre, Bipoint<twistpoint_fp2_t> bipoint, PrivateKey private_key) 
//finalement, on fait le cas twist pour aider au debug
{
	Bipoint<twistpoint_fp2_t> bipoint_pi_2_chiffre, bipoint_pi_2_v, bipoint_pi_2_2v;
	bipoint_pi_2_chiffre = private_key.pi_2(bipoint);  //pi_2(bu+u1)
	if (fp2e_iszero(bipoint_pi_2_chiffre[0]->m_z) && fp2e_iszero(bipoint_pi_2_chiffre[1]->m_z))
	{
		//cout << "cas log=0" << endl;
		bit_dechiffre = 0;
	}
	else
	{
		bipoint_pi_2_v = private_key.pi_2(public_key.get_bipoint_twist_groupelt()); 
		if (bipoint_pi_2_chiffre == bipoint_pi_2_v)
		{
			//cout << "cas log=1" << endl;
			bit_dechiffre = 1;
		}
		else 
		{
			bipoint_pi_2_2v=bipoint_pi_2_v+bipoint_pi_2_v;
			bipoint_pi_2_2v.makeaffine();				
			if (bipoint_pi_2_chiffre == bipoint_pi_2_2v)
			{
				//cout << "cas log=2" << endl; //a améliorer
				bit_dechiffre = 0;
			}
			else
			{
				//cout << "cas log >=3" << endl; //a améliorer et a répercuter dans la seconde fonction dechiffrement
				Bipoint<twistpoint_fp2_t> mul_log=bipoint_pi_2_2v+bipoint_pi_2_v; 
				mul_log.makeaffine();
				int log=3;
				while(!(bipoint_pi_2_chiffre == mul_log))
				{
					mul_log=mul_log+bipoint_pi_2_v;
					mul_log.makeaffine();	
					log++;
					//zout(log);
				}
				//zout(log);
				//bit_dechiffre = log%2;
			}
		}
	}	
}
