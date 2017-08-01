#include "multiplicationL1.hpp"

//template <typename S, typename T>
BitEvalL2 multiplicationL1 (BitEvalL1<curvepoint_fp_t> eval1, BitEvalL1<twistpoint_fp2_t> eval2, PublicKey public_key)
{
	BitEvalL2 produit;
	F2 s=rand()%2;
	produit.set_bit_masque(eval1.get_bit_masque()*eval2.get_bit_masque()-s);
	Bipoint<curvepoint_fp_t> bipoint_curve_subgroupelt;
	Bipoint<twistpoint_fp2_t> bipoint_twist_subgroupelt;		
	scalar_t lambda1, lambda2;
	scalar_setrandom(lambda1, bn_r);	
	scalar_setrandom(lambda2, bn_r);	
	bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda1); // calcul de u1
	bipoint_curve_subgroupelt.makeaffine();
	bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda2); // calcul de v1
	bipoint_twist_subgroupelt.makeaffine();
	public_key.get_bipoint_twist_groupelt().makeaffine();
	
	Quadripoint factor1, factor2, factor3, factor4, factor5;
	Bipoint<curvepoint_fp_t> chiffre_1_curve;
	Bipoint<twistpoint_fp2_t> chiffre_1_twist, chiffre_s;
	
	//calcul de e(beta_1,beta_2)   
	factor1 = pairing(eval1.get_bipoint(),eval2.get_bipoint());
	
	//calcul de  e(Enc(1), a1 beta2 + Enc(s))
	
	Bipoint<curvepoint_fp_t>  temp1;		
	Bipoint<twistpoint_fp2_t> temp2;
	
	chiffrement(chiffre_s,s, public_key);
	chiffre_s.makeaffine();
	
	
	chiffrement(chiffre_1_curve,1, public_key);
	temp1=chiffre_1_curve;
	temp1.makeaffine();
			
	if (eval1.get_bit_masque() == 1)
	{
		temp2 = eval2.get_bipoint()+chiffre_s;
	}
	else
	{
		temp2 = chiffre_s;

	}	
	temp2.makeaffine();

	factor2 = pairing(temp1, temp2);
	
	//calcul de  e(a2 beta1, Enc(1))

	Bipoint<curvepoint_fp_t>  temp3; // les bipoints sont initialisés par défaut au bipoint à l'infini
	Bipoint<twistpoint_fp2_t> temp4;
	chiffrement(chiffre_1_twist,1, public_key);
	//F2 un;
	//dechiffrement(un,chiffre_1_twist,private_key);
	//zout(un);
	if (eval2.get_bit_masque() == 1) //sinon temp3 doit etre le bipoint à l'infini
	{
		temp3 = eval1.get_bipoint(); 
	}
	temp3.makeaffine();
	//temp3.print();
	
	temp4=chiffre_1_twist;
	temp4.makeaffine();
	//ecris(affichage de chiffre_1_twist);
	//temp4.print();
	
	factor3 = pairing(temp3, temp4);	
	
	//ecris(affichage de pi_1(f3[0]));
	//private_key.pi_1(temp3).print(0);	
	
	//ecris(affichage de pi_2(f3[1]));
	//private_key.pi_2(chiffre_1_twist).print();	
	
	//ecris(affichage de e(pi_1(f3[0]),pi_2(f3[1])));
	//pairing(private_key.pi_1(temp3),private_key.pi_2(temp4)).print(0);	

	//ecris(affichage de e(f3[0],f3[1]));
	//pairing(temp3,temp4).print(0);	
			
	//ecris(affichage de pi_T(e(f3[0],f3[1])));
	//private_key.pi_T(pairing(temp3,temp4)).print(0);	
			
	//calcul de  e(u,v1)
	factor4 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
	
	//calcul de e(u1,v)
	factor5 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
								
	produit.set_quadripoint(factor1*factor2*factor3*factor4*factor5);		
	return produit;
}



BitEvalL2 multiplicationL1 (BitChiffre eval1, BitChiffre eval2, PublicKey public_key)
{
	//signature;
	if (eval1.get_type() == CURVE && eval2.get_type() == TWIST)
	{
		BitEvalL2 produit;
		F2 s=rand()%2;
		//zout(s);
		//cout << "a1 = " << eval1.get_bit_masque() << endl;
		//cout << "a2 = " << eval2.get_bit_masque() << endl;
		//cin.ignore() ; //NB temps[] d'attente
		produit.set_bit_masque(eval1.get_bit_masque()*eval2.get_bit_masque()-s);
		//eval1.print_bit_masque();
		//eval2.print_bit_masque();
		//ecris(affichage de a1a2-s);
		//produit.print_bit_masque();
		Bipoint<curvepoint_fp_t> bipoint_curve_subgroupelt;
		Bipoint<twistpoint_fp2_t> bipoint_twist_subgroupelt;		
		scalar_t lambda1, lambda2;
		scalar_setrandom(lambda1, bn_r);	
		scalar_setrandom(lambda2, bn_r);
		//mpz_class mpz1, mpz2;
		//mpz1=scalar2mpz(lambda1);
		//mpz2=scalar2mpz(lambda2);			
		//scalar_print(stdout,lambda1);
		//JUMP;
		//zout(mpz1);
		//scalar_print(stdout,lambda2);
		//JUMP;
		//zout(mpz2);	
		bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda1); // calcul de u1
		bipoint_curve_subgroupelt.makeaffine();
		bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda2); // calcul de v1
		bipoint_twist_subgroupelt.makeaffine();
		public_key.get_bipoint_twist_groupelt().makeaffine();
		
		Quadripoint factor1, factor2, factor3, factor4, factor5;
		Bipoint<curvepoint_fp_t> chiffre_1_curve;
		Bipoint<twistpoint_fp2_t> chiffre_1_twist, chiffre_s;
		
		//calcul de e(beta_1,beta_2)   
		factor1 = pairing(eval1.get_bipoint_curve(),eval2.get_bipoint_twist());
		
		//calcul de  e(Enc(1), a1 beta2 + Enc(s))
		
		Bipoint<curvepoint_fp_t>  temp1;		
		Bipoint<twistpoint_fp2_t> temp2;
		
		chiffrement(chiffre_s,s, public_key);
		chiffre_s.makeaffine();
		
		
		chiffrement(chiffre_1_curve,1, public_key);
		temp1=chiffre_1_curve;
		temp1.makeaffine();
				
		if (eval1.get_bit_masque() == 1)
		{
			temp2 = eval2.get_bipoint_twist()+chiffre_s;
		}
		else
		{
			temp2 = chiffre_s;

		}	
		temp2.makeaffine();

		factor2 = pairing(temp1, temp2);
		
		//calcul de  e(a2 beta1, Enc(1))

		Bipoint<curvepoint_fp_t>  temp3; // les bipoints sont initialisés par défaut au bipoint à l'infini
		Bipoint<twistpoint_fp2_t> temp4;
		chiffrement(chiffre_1_twist,1, public_key);
		//F2 un;
		//dechiffrement(un,chiffre_1_twist,private_key);
		//zout(un);
		if (eval2.get_bit_masque() == 1) //sinon temp3 doit etre le bipoint à l'infini
		{
			temp3 = eval1.get_bipoint_curve(); 
		}
		temp3.makeaffine();
		//temp3.print();
		
		temp4=chiffre_1_twist;
		temp4.makeaffine();
		//ecris(affichage de chiffre_1_twist);
		//temp4.print();
		
		factor3 = pairing(temp3, temp4);	
		
		//ecris(affichage de pi_1(f3[0]));
		//private_key.pi_1(temp3).print(0);	
		
		//ecris(affichage de pi_2(f3[1]));
		//private_key.pi_2(chiffre_1_twist).print();	
		
		//ecris(affichage de e(pi_1(f3[0]),pi_2(f3[1])));
		//pairing(private_key.pi_1(temp3),private_key.pi_2(temp4)).print(0);	

		//ecris(affichage de e(f3[0],f3[1]));
		//pairing(temp3,temp4).print(0);	
				
		//ecris(affichage de pi_T(e(f3[0],f3[1])));
		//private_key.pi_T(pairing(temp3,temp4)).print(0);	
				
		//calcul de  e(u,v1)
		factor4 = pairing(public_key.get_bipoint_curve_groupelt(),bipoint_twist_subgroupelt);
		
		//calcul de e(u1,v)
		factor5 = pairing(bipoint_curve_subgroupelt,public_key.get_bipoint_twist_groupelt());
		
		//private_key.pi_1(bipoint_curve_subgroupelt).print();
		//private_key.pi_2(public_key.get_bipoint_twist_groupelt()).print();
		
		//ecris(affichage de e(pi_1(u),pi_2(v1)));
		//pairing(private_key.pi_1(private_key.pi_1(public_key.get_bipoint_curve_groupelt())),private_key.pi_2(bipoint_twist_subgroupelt)).print();		 
		
		//ecris(affichage de e(pi_1(u1),pi_2(v)));
		//pairing(private_key.pi_1(bipoint_curve_subgroupelt),private_key.pi_2(public_key.get_bipoint_twist_groupelt())).print();
		
		//ecris(affichage de e(-j1l1u1[0]+i1l1u1[1],-j2l2v[0]+i2l2v[1]));
		////void curvepoint_fp_scalarmult_vartime(curvepoint_fp_t rop, const curvepoint_fp_t op, const scalar_t s);
		////void curvepoint_fp_add_vartime(curvepoint_fp_t rop, const curvepoint_fp_t op1, const curvepoint_fp_t op2);
		////void curvepoint_fp_neg(curvepoint_fp_t rop, const curvepoint_fp_t op);
		//curvepoint_fp_t tempc[6], op1;
		//twistpoint_fp2_t tempt[5], op2;
		//fp12e_t tempf[60], test, test2, test3, test4;
		//curvepoint_fp_neg(tempc[0],bipoint_curve_subgroupelt[0]);
		//curvepoint_fp_scalarmult_vartime(tempc[1],tempc[0],private_key.get("j1").scalar());
		//curvepoint_fp_scalarmult_vartime(tempc[2],tempc[1],private_key.get("l1").scalar());
		//curvepoint_fp_scalarmult_vartime(tempc[3],bipoint_curve_subgroupelt[1],private_key.get("i1").scalar());
		//curvepoint_fp_scalarmult_vartime(tempc[4],tempc[3],private_key.get("l1").scalar());	
		//curvepoint_fp_makeaffine(tempc[2]);curvepoint_fp_makeaffine(tempc[4]);	
		//curvepoint_fp_add_vartime(op1,tempc[2],tempc[4]);
		
		//twistpoint_fp2_neg(tempt[0],public_key.get_bipoint_twist_groupelt()[0]);
		//twistpoint_fp2_scalarmult_vartime(tempt[1],tempt[0],private_key.get("j2").scalar());
		//twistpoint_fp2_scalarmult_vartime(tempt[2],tempt[1],private_key.get("l2").scalar());
		//twistpoint_fp2_scalarmult_vartime(tempt[3],public_key.get_bipoint_twist_groupelt()[1],private_key.get("i2").scalar());
		//twistpoint_fp2_scalarmult_vartime(tempt[4],tempt[3],private_key.get("l2").scalar());		
		//twistpoint_fp2_add_vartime(op2,tempt[5],tempt[4]);		
		
		//OptimalAte(test,op1,op2);
		//fp12e_print(stdout,test);
		//JUMP;
		
		//ecris(affichage de e(-j1l1u1[0],-j2l2v[0]+i2l2v[1])e(i1l1u1[1],-j2l2v[0]+i2l2v[1]));
		//OptimalAte(tempf[0],tempc[2],op2);
		//OptimalAte(tempf[1],tempc[4],op2);
		//fp12e_mul(test2,tempf[0],tempf[1]);
		//fp12e_print(stdout,test2);
		//JUMP;		
		
		
		//ecris(affichage de e(-j1l1u1[0],-j2l2v[0])e(-j1l1u1[0],i2l2v[1])e(i1l1u1[1],-j2l2v[0])e(i1l1u1[1],i2l2v[1]));
		//OptimalAte(tempf[2],tempc[2],tempt[2]);
		//OptimalAte(tempf[3],tempc[2],tempt[4]);		
		//OptimalAte(tempf[4],tempc[4],tempt[2]);
		//OptimalAte(tempf[5],tempc[4],tempt[4]);			
		//fp12e_mul(tempf[6],tempf[2],tempf[3]);	
		//fp12e_mul(tempf[7],tempf[4],tempf[5]);		
		//fp12e_mul(test3,tempf[6],tempf[7]);
		//fp12e_print(stdout,test3);
		//JUMP;		
		

		
		//ecris(affichage de e(u1[0],v[0])^((-j1l1)(-j2l2))	e(u1[0],v[1])^((-j1l1)(i2l2))	e(u1[1],v[0])^((i1l1)(-j2l2))	e(u1[1],v[1])^((i1l1)(i2l2)));
		
		
		//curvepoint_fp_makeaffine(bipoint_curve_subgroupelt[0]);curvepoint_fp_makeaffine(bipoint_curve_subgroupelt[1]);	
		//twistpoint_fp2_makeaffine(public_key.get_bipoint_twist_groupelt()[0]);twistpoint_fp2_makeaffine(public_key.get_bipoint_twist_groupelt()[1]);
		
		
		//OptimalAte(tempf[8],bipoint_curve_subgroupelt[0],public_key.get_bipoint_twist_groupelt()[0]);
		//OptimalAte(tempf[9],bipoint_curve_subgroupelt[0],public_key.get_bipoint_twist_groupelt()[1]);
		//OptimalAte(tempf[10],bipoint_curve_subgroupelt[1],public_key.get_bipoint_twist_groupelt()[0]);
		//OptimalAte(tempf[11],bipoint_curve_subgroupelt[1],public_key.get_bipoint_twist_groupelt()[1]);
		
		//fp12e_invert(tempf[12],tempf[8]);
		//fp12e_pow_vartime(tempf[13],tempf[12],private_key.get("j1").scalar());
		//fp12e_pow_vartime(tempf[14],tempf[13],private_key.get("l1").scalar());
		//fp12e_invert(tempf[15],tempf[14]);
		//fp12e_pow_vartime(tempf[16],tempf[15],private_key.get("j2").scalar());
		//fp12e_pow_vartime(tempf[17],tempf[16],private_key.get("l2").scalar());
		
		//fp12e_invert(tempf[18],tempf[9]);
		//fp12e_pow_vartime(tempf[19],tempf[18],private_key.get("j1").scalar());
		//fp12e_pow_vartime(tempf[20],tempf[19],private_key.get("l1").scalar());
		//fp12e_pow_vartime(tempf[21],tempf[20],private_key.get("i2").scalar());
		//fp12e_pow_vartime(tempf[22],tempf[21],private_key.get("l2").scalar());
		
		//fp12e_invert(tempf[23],tempf[10]);
		//fp12e_pow_vartime(tempf[24],tempf[23],private_key.get("i1").scalar());
		//fp12e_pow_vartime(tempf[25],tempf[24],private_key.get("l1").scalar());
		//fp12e_pow_vartime(tempf[26],tempf[25],private_key.get("j2").scalar());
		//fp12e_pow_vartime(tempf[27],tempf[26],private_key.get("l2").scalar());
		
		//fp12e_pow_vartime(tempf[28],tempf[27],private_key.get("i1").scalar());
		//fp12e_pow_vartime(tempf[29],tempf[28],private_key.get("l1").scalar());
		//fp12e_pow_vartime(tempf[30],tempf[29],private_key.get("i2").scalar());
		//fp12e_pow_vartime(tempf[31],tempf[30],private_key.get("l2").scalar());
		

		//fp12e_mul(tempf[32],tempf[17],tempf[22]);
		//fp12e_mul(tempf[33],tempf[27],tempf[31]);
		//fp12e_mul(test4,tempf[32],tempf[33]);
		
		//fp12e_print(stdout,test4);
		//JUMP;	
		
		
		//ecris(affichage de e(u1[0],v[0])^((-j1l1)(-j2l2)));
		//fp12e_print(stdout,tempf[17]);
		//JUMP;		
		
		//ecris(affichage de e(-j1l1u1[0],-j2l2v[0]));
		//fp12e_print(stdout,tempf[6]);
		//JUMP;		
		
		//zout(scalar2mpz(private_key.get("i1").scalar()));
		//zout(scalar2mpz(private_key.get("j1").scalar()));
		//zout(scalar2mpz(private_key.get("k1").scalar()));
		//zout(scalar2mpz(private_key.get("l1").scalar()));
		//zout(scalar2mpz(private_key.get("i2").scalar()));
		//zout(scalar2mpz(private_key.get("j2").scalar()));
		//zout(scalar2mpz(private_key.get("k2").scalar()));
		//zout(scalar2mpz(private_key.get("l2").scalar()));
		
		//ecris(affichage de e(u1[0],v[0])^j1);
		//fp12e_pow_vartime(tempf[34],tempf[8],private_key.get("j1").scalar());
		//fp12e_print(stdout,tempf[34]);
		//JUMP;		
		
		//ecris(affichage de e(j1u1[0],v[0]));		
		//curvepoint_fp_scalarmult_vartime(tempc[5],bipoint_curve_subgroupelt[0],private_key.get("j1").scalar());
		//curvepoint_fp_makeaffine(tempc[5]);
		//twistpoint_fp2_makeaffine(public_key.get_bipoint_twist_groupelt()[0]);
		//OptimalAte(tempf[36],tempc[5],public_key.get_bipoint_twist_groupelt()[0]);
		//fp12e_print(stdout,tempf[36]);
		//JUMP;			
		//exit(0);	
		
		
		//ecris(affichage de e(pi_1(u),pi_2(v)));
		//pairing(private_key.pi_1(public_key.get_bipoint_curve_groupelt()),private_key.pi_2(public_key.get_bipoint_twist_groupelt())).print(0);		

		//ecris(affichage de (e(pi_1(u),pi_2(v)))^2);
		//pairing(private_key.pi_1(public_key.get_bipoint_curve_groupelt()),private_key.pi_2(public_key.get_bipoint_twist_groupelt())).square().print_point(0);
		
		//ecris(affichage de (e(pi_1(u),pi_2(v)))^3);
		//scalar_t trois; trois[0]=3;
		//pairing(private_key.pi_1(public_key.get_bipoint_curve_groupelt()),private_key.pi_2(public_key.get_bipoint_twist_groupelt())).pow_vartime(trois).print_point(0);
		
		//ecris(affichage de (e(pi_1(u),pi_2(v)))^4);
		//scalar_t quatre; quatre[0]=4;
		//pairing(private_key.pi_1(public_key.get_bipoint_curve_groupelt()),private_key.pi_2(public_key.get_bipoint_twist_groupelt())).pow_vartime(quatre).print_point(0);

												
		produit.set_quadripoint(factor1*factor2*factor3*factor4*factor5);		
		return produit;
	}
	else
	{
		cout << "Problème de type dans multiplicationL1, le premier argument doit être un élément de type CURVE et le second, un élément de type TWIST" << endl;
		exit(0);
	}
}
