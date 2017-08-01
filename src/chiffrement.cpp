

#include "chiffrement.hpp"

//template <typename T>
//void chiffrement(BitEvalL1<T>& bit_chiffre,F2 bit_clair, PublicKey public_key, Type type)
//{
	////signature;
	//Bipoint<T> bipoint_groupelt, bipoint_subgroupelt; 
	//scalar_t lambda;
	//scalar_setrandom(lambda, bn_r);

	////1ere composante
	///** calcul des bits clairs, urandom et chiffrés **/		
	//F2 bit_urandom=rand()%2;
	//bit_chiffre.set_bit_masque(bit_clair != bit_urandom); 
	
	////2eme composante
	///** calcul sur la courbe BN sur Fp **/
	//if (type==CURVE)
	//{
		//bipoint_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
		//bipoint_subgroupelt.makeaffine();
		
		//// calcul de b.u+u_1
		//if (bit_urandom == 1) 
		//{			
			//bit_chiffre.set_bipoint(public_key.get_bipoint_curve_groupelt() + bipoint_subgroupelt); //addition et affectation	
		//}
		//else
		//{
			//bit_chiffre.set_bipoint(bipoint_subgroupelt); //affectation
		//}
	//}
	
	///** calcul sur le twist BN sur Fp^2 **/
	//if (type==TWIST)
	//{
		
		//bipoint_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
		//bipoint_subgroupelt.makeaffine();
		
		//// calcul de b.v+v_1
		//if (bit_urandom == 1) 
		//{
			//bit_chiffre.set_bipoint(public_key.get_bipoint_twist_groupelt() + bipoint_subgroupelt); //addition et affectation
		//}
		//else
		//{
			//bit_chiffre.set_bipoint(bipoint_subgroupelt); //affectation
		//}
	//}
	//bit_chiffre.makeaffine();		
//}


void chiffrement(BitEvalL1<curvepoint_fp_t>& bit_chiffre,F2 bit_clair, PublicKey public_key)
{
	//signature;
	Bipoint<curvepoint_fp_t> bipoint_groupelt, bipoint_subgroupelt; 
	scalar_t lambda;
	scalar_setrandom(lambda, bn_r);

	//1ere composante
	/** calcul des bits clairs, urandom et chiffrés **/		
	F2 bit_urandom=rand()%2;
	bit_chiffre.set_bit_masque(bit_clair != bit_urandom); 
	
	//2eme composante
	/** calcul sur la courbe BN sur Fp **/
	bipoint_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
	bipoint_subgroupelt.makeaffine();
	
	// calcul de b.u+u_1
	if (bit_urandom == 1) 
	{			
		bit_chiffre.set_bipoint(public_key.get_bipoint_curve_groupelt() + bipoint_subgroupelt); //addition et affectation	
	}
	else
	{
		bit_chiffre.set_bipoint(bipoint_subgroupelt); //affectation
	}
	bit_chiffre.makeaffine();		
}


void chiffrement(BitEvalL1<twistpoint_fp2_t>& bit_chiffre,F2 bit_clair, PublicKey public_key)
{
	//signature;
	Bipoint<twistpoint_fp2_t> bipoint_groupelt, bipoint_subgroupelt; 
	scalar_t lambda;
	scalar_setrandom(lambda, bn_r);

	//1ere composante
	/** calcul des bits clairs, urandom et chiffrés **/		
	F2 bit_urandom=rand()%2;
	bit_chiffre.set_bit_masque(bit_clair != bit_urandom); 
	
	//2eme composante
	/** calcul sur le twist BN sur Fp^2 **/
	bipoint_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
	bipoint_subgroupelt.makeaffine();
	
	// calcul de b.u+u_1
	if (bit_urandom == 1) 
	{			
		bit_chiffre.set_bipoint(public_key.get_bipoint_twist_groupelt() + bipoint_subgroupelt); //addition et affectation	
	}
	else
	{
		bit_chiffre.set_bipoint(bipoint_subgroupelt); //affectation
	}
	bit_chiffre.makeaffine();		
}

void chiffrement(BitChiffre& bit_chiffre,F2 bit_clair, PublicKey public_key, Type type)
{
	//signature;
	Bipoint<curvepoint_fp_t> bipoint_curve_groupelt, bipoint_curve_subgroupelt; // A, B, C, D, temp;
	Bipoint<twistpoint_fp2_t> bipoint_twist_groupelt, bipoint_twist_subgroupelt;
	scalar_t lambda,lambda2;
	scalar_setrandom(lambda, bn_r);
	scalar_setrandom(lambda2, bn_r);

	//1ere composante
	/** calcul des bits clairs, urandom et chiffrés **/		
	F2 bit_urandom=rand()%2;
	bit_chiffre.set_bit_masque(bit_clair != bit_urandom); // dans F2 -=+=^=XOR bitwise (!= logical XOR résultat pareil pour 0 et 1, mais l'opérateur bitwitse sur des bool convertit le bool en int, fait l'opération bitwise et reconvertit en bool)       m-b //(bit_clair != bit_urandom)
	//zout (bit_clair,bit_urandom);
	//bit_chiffre.print_bit_masque(); 
	//if (bit_clair==0 && bit_urandom==0) {cout << BOLDRED << "Cas 1" << RESET << endl;}
	//if (bit_clair==0 && bit_urandom==1) {cout << BOLDRED << "Cas 2" << RESET << endl;}
	//if (bit_clair==1 && bit_urandom==0) {cout << BOLDRED << "Cas 3" << RESET << endl;}
	//if (bit_clair==1 && bit_urandom==1) {cout << BOLDRED << "Cas 4" << RESET << endl;}
	
	//2eme composante
	/** calcul sur la courbe BN sur Fp**/
	if (type==CURVE)
	{
		////lambda_1[0]=0;lambda_1[1]=0;lambda_1[2]=0;lambda_1[3]=0; // 0
		//lambda_1[0]=1;lambda_1[1]=0;lambda_1[2]=0;lambda_1[3]=0; // 1
		//cout << RED << "affichage du scalar_t lambda_1" << RESET <<endl;
		//scalar_print(stdout, lambda_1); 
		//JUMP;
		//public_key.print();
		
		
		bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
		//D.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda2);
		//D.makeaffine();

		bipoint_curve_subgroupelt.makeaffine();
		
		// calcul de b.u+u_1
		if (bit_urandom == 1) 
		{
			//cout << RED << "affichage du bipoint  u" << RESET << endl;
			//bipoint_curve_groupelt.print();				
			//cout << RED << "affichage du bipoint  u1" << RESET << endl;
			//bipoint_curve_subgroupelt.print();				
			//A=public_key.get_bipoint_curve_groupelt();
			//A.makeaffine();
			//representation(A);
			//B=bipoint_curve_subgroupelt;
			//B.makeaffine();
			//representation(B);
			//C=A;
			//ecris(A); //u fixe
			//A.print();
			//ecris(pi1(A));
			//private_key.pi_1(A).makeaffine();
			//private_key.pi_1(A).print();
			//ecris(B); //u1
			//B.print();
			//ecris(pi1(B));
			//private_key.pi_1(B).makeaffine();
			//private_key.pi_1(B).print();
			//ecris(C); //u fixe
			//C.print();
			//ecris(pi1(C));
			//private_key.pi_1(C).makeaffine();
			//private_key.pi_1(C).print();
			//ecris(D); //u'1
			//D.print();
			//ecris(pi1(D));
			//private_key.pi_1(D).makeaffine();
			//private_key.pi_1(D).print();
			//ecris(((A+B)+C)+D);
			//temp=((A+B)+C)+D;
			//temp.makeaffine();
			//temp.print();				
			//ecris((A+(B+C))+D);
			//temp=((A+(B+C))+D);
			//temp.makeaffine();
			//temp.print();
			//ecris(((B+C)+D)+A);
			//temp=((B+C)+D)+A;
			//temp.makeaffine();
			//temp.print();				
			//ecris((B+(C+D))+A);
			//temp=((B+(C+D))+A);
			//temp.makeaffine();
			//temp.print();								
			//ecris((A+B)+(C+D));
			//temp=(A+B)+(C+D);
			//temp.makeaffine();
			//temp.print();
			//representation(temp);
			//ecris((C+D)+(A+B));
			//temp=(C+D)+(A+B);
			//temp.makeaffine();
			//temp.print();				
			//ecris(pi1((A+B)+(C+D)));
			//private_key.pi_1(temp).makeaffine();
			//private_key.pi_1(temp).print();
			//ecris(2A);
			//curvepoint_fp_double(temp[0],A[0]);
			//curvepoint_fp_double(temp[1],A[1]);
			//temp.makeaffine();
			//temp.print();				
			//ecris(2A+B+D);
			//curvepoint_fp_double(temp[0],A[0]);
			//curvepoint_fp_double(temp[1],A[1]);
			//temp=temp+B+D;
			//temp.makeaffine();
			//temp.print();
			//ecris(B);
			//B.makeaffine();
			//B.print();
			//ecris(B+B);
			//temp=B+B;
			//temp.makeaffine();
			//temp.print();
			//ecris(A+C);
			//temp=(A+C);
			//temp.makeaffine();
			//temp.print();
			//ecris(pi1(A+C));
			//private_key.pi_1(temp).makeaffine();
			//private_key.pi_1(temp).print();
			//ecris(B+D);
			//temp=(B+D);
			//temp.makeaffine();
			//temp.print();				
			//ecris((A+C)+ (B+D));
			//temp=((A+C)+ (B+D));
			//temp.makeaffine();
			//temp.print();
			//representation(temp);
			//ecris(pi1(A+C)+ (B+D));
			//private_key.pi_1(temp).makeaffine();
			//private_key.pi_1(temp).print();
			//bit_chiffre.set_bipoint_curve(bipoint_curve_groupelt + bipoint_curve_subgroupelt); //addition et affectation
			
			bit_chiffre.set_bipoint_curve(public_key.get_bipoint_curve_groupelt() + bipoint_curve_subgroupelt); //addition et affectation

			
		}
		else
		{
			//cout << RED << "affichage du bipoint  u1" << RESET << endl;
			//bipoint_curve_subgroupelt.print();
			//cout << BOLDRED << "OBJECTIF POINT A L'INFINI" << RESET << endl;
			bit_chiffre.set_bipoint_curve(bipoint_curve_subgroupelt); //affectation
		}
	}
	
	//3eme composante
	/** calcul sur le twist BN sur Fp^2 **/

	if (type==TWIST)
	{
		
		bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
		bipoint_twist_subgroupelt.makeaffine();
		
		// calcul de b.v+v_1
		if (bit_urandom == 1) 
		{
			//bit_chiffre.set_bipoint_twist(bipoint_twist_groupelt + bipoint_twist_subgroupelt); //addition et affectation
			
			bit_chiffre.set_bipoint_twist(public_key.get_bipoint_twist_groupelt() + bipoint_twist_subgroupelt); //addition et affectation
		}
		else
		{
			bit_chiffre.set_bipoint_twist(bipoint_twist_subgroupelt); //affectation
		}
	}
	bit_chiffre.makeaffine();		
}



// chiffrement BGN-F utile pour calculer Enc(1) et Enc(s) dans les chiffrés de niveau 2
void chiffrement(Bipoint<curvepoint_fp_t>& ciphertext,F2 bit_clair, PublicKey public_key)
{
	scalar_t lambda;
	scalar_setrandom(lambda, bn_r);
	Bipoint<curvepoint_fp_t> bipoint_curve_groupelt, bipoint_curve_subgroupelt;
	bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
	bipoint_curve_subgroupelt.makeaffine();
	
	// calcul de m.u+u_1
	if (bit_clair == 1) 
	{
		ciphertext = public_key.get_bipoint_curve_groupelt() + bipoint_curve_subgroupelt; //addition et affectation	
	}
	else
	{
		ciphertext = bipoint_curve_subgroupelt; //affectation
	}
	ciphertext.makeaffine();
}

void chiffrement(Bipoint<twistpoint_fp2_t>& ciphertext,F2 bit_clair, PublicKey public_key)
{
	scalar_t lambda;
	scalar_setrandom(lambda, bn_r);
	Bipoint<twistpoint_fp2_t> bipoint_twist_groupelt, bipoint_twist_subgroupelt;
	bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
	bipoint_twist_subgroupelt.makeaffine();
	
	// calcul de m.v+v_1
	if (bit_clair == 1) 
	{
		ciphertext = public_key.get_bipoint_twist_groupelt() + bipoint_twist_subgroupelt; //addition et affectation	
	}
	else
	{
		ciphertext = bipoint_twist_subgroupelt; //affectation
	}	
	ciphertext.makeaffine();
}
