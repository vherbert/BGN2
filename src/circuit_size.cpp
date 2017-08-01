#include "circuit_size.hpp"
void circuit_size(PublicKey public_key, PrivateKey private_key)
{
	BitEvalL1<curvepoint_fp_t> bit_chiffre_0_curve;
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_0_twist;
	BitEvalL2 chiffre_L2_0;
	BitEvalL3 chiffre_L3_0, chiffre_somme_2_L3, chiffre_somme_3_L3, chiffre_somme_4_L3;
	BitEvalL4 chiffre_L4_0, chiffre_somme_2_L4, chiffre_somme_3_L4, chiffre_somme_4_L4;
	chiffrement(bit_chiffre_0_curve,0,public_key);
	chiffrement(bit_chiffre_0_twist,0,public_key);
	chiffre_L2_0 = multiplicationL1(bit_chiffre_0_curve,bit_chiffre_0_twist,public_key);
	chiffre_L3_0 = multiplicationL1L2(bit_chiffre_0_curve,chiffre_L2_0,public_key);
	chiffre_L4_0 = multiplicationL2(chiffre_L2_0,chiffre_L2_0,public_key);
	chiffre_somme_2_L3=additionL3(chiffre_L3_0,chiffre_L3_0,public_key);	
	chiffre_somme_3_L3=additionL3(chiffre_L3_0,chiffre_somme_2_L3,public_key);		
	chiffre_somme_4_L3=additionL3(chiffre_somme_2_L3,chiffre_somme_2_L3,public_key);	
	chiffre_somme_2_L4=additionL4(chiffre_L4_0,chiffre_L4_0,public_key);
	chiffre_somme_3_L4=additionL4(chiffre_L4_0,chiffre_somme_2_L4,public_key);		
	chiffre_somme_4_L4=additionL4(chiffre_somme_2_L4,chiffre_somme_2_L4,public_key);	
	
	cout  << "taille d'un chiffré de niveau 1 de type curve = " << sizeof(bit_chiffre_0_curve) << " octets " << GREEN <<"(taille de deux des trois chiffrés envoyés au serveur)" << RESET<<  endl;	
	cout <<  "taille d'un chiffré de niveau 1 de type twist = " << sizeof(bit_chiffre_0_twist) << " octets " << GREEN <<"(taille d'un des trois chiffrés envoyé au serveur)" << RESET<<  endl;	
	cout << "taille d'un chiffré de niveau 2 = " << sizeof(chiffre_L2_0) << " octets" << endl;
	cout <<  "taille d'un chiffrais de niveau 3 = " << sizeof(chiffre_L3_0)+sizeof(Bipoint<curvepoint_fp_t>)*(chiffre_L3_0.get_vec_bipoints().capacity()) +sizeof(Quadripoint)*(chiffre_L3_0.get_vec_quadripoints().capacity())<< " octets " GREEN << "(taille de l'évalué calculé par le serveur dans les circuit minmaj et minmaj3)" << RESET << endl;
	cout << "taille d'un chiffrais de niveau 4 = " << sizeof(chiffre_L4_0)+sizeof(Quadripoint)*(chiffre_L4_0.get_vec_quadripoints(0).capacity()+(chiffre_L4_0.get_vec_quadripoints(1).capacity())) << " octets" << endl;
	cout << "taille de la somme de deux chiffrés de niveau 3 = " << sizeof(chiffre_somme_2_L3)+sizeof(Bipoint<curvepoint_fp_t>)*(chiffre_somme_2_L3.get_vec_bipoints().capacity()) +sizeof(Quadripoint)*(chiffre_somme_2_L3.get_vec_quadripoints().capacity())<< " octets " GREEN << "(taille de l'évalué calculé par le serveur dans le circuit minmaj2)" << RESET << endl;
	cout << "taille de la somme de trois chiffrés de niveau 3 = " << sizeof(chiffre_somme_3_L3)+sizeof(Bipoint<curvepoint_fp_t>)*(chiffre_somme_3_L3.get_vec_bipoints().capacity()) +sizeof(Quadripoint)*(chiffre_somme_3_L3.get_vec_quadripoints().capacity())<< " octets " << endl;			
	cout << "taille de la somme de quatre chiffrés de niveau 3 = " << sizeof(chiffre_somme_4_L3)+sizeof(Bipoint<curvepoint_fp_t>)*(chiffre_somme_4_L3.get_vec_bipoints().capacity()) +sizeof(Quadripoint)*(chiffre_somme_4_L3.get_vec_quadripoints().capacity())<< " octets " << endl;	
	cout << "taille de la somme de deux chiffrés de niveau 4 = " << sizeof(chiffre_somme_2_L4)+sizeof(Quadripoint)*(chiffre_somme_2_L4.get_vec_quadripoints(0).capacity()+(chiffre_somme_2_L4.get_vec_quadripoints(1).capacity())) << " octets" << endl;
	cout << "taille de la somme de trois chiffrés de niveau 4 = " << sizeof(chiffre_somme_3_L4)+sizeof(Quadripoint)*(chiffre_somme_3_L4.get_vec_quadripoints(0).capacity()+(chiffre_somme_3_L4.get_vec_quadripoints(1).capacity())) << " octets" << endl;
	cout << "taille de la somme de quatre chiffrés de niveau 4 = " << sizeof(chiffre_somme_4_L4)+sizeof(Quadripoint)*(chiffre_somme_4_L4.get_vec_quadripoints(0).capacity()+(chiffre_somme_4_L4.get_vec_quadripoints(1).capacity())) << " octets" << endl;
	cout << "taille de la clef publique = " << sizeof(public_key) << " octets " << endl; 
	cout << "taille de la clef privée = " << sizeof(private_key) << " octets " << endl; 
	cout << "taille d'un Fp = " << sizeof(Fp) << " octets " << endl;
	cout << "taille d'un point de la courbe = " << sizeof(curvepoint_fp_t) << " octets "  << endl;
	cout << "taille d'un point du twist = " << sizeof(twistpoint_fp2_t) << " octets "  << endl;
	cout << "taille d'un fpe_t = " << sizeof(fpe_t) << " octets "  << endl;
	cout << "taille d'un scalar_t = " << sizeof(scalar_t) << " octets "  << endl;	
	cout << "taille d'un ull = " << sizeof(unsigned long long) << " octets "  << endl;
	cout << "taille d'un double = " << sizeof(double) << " octets "  << endl;
	cout << "taille d'un fp12e_t = " << sizeof(fp12e_t) << " octets "  << endl;
	cout << "taille d'un quadripoint = " << sizeof(Quadripoint) << " octets "  << endl;	
	
	
}
