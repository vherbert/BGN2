#include "keygen.hpp"

const scalar_t &bn_r=bn_n;

void keygen(PublicKey& public_key, PrivateKey& private_key)
{
	//signature;

	

	/** générer des données privées avant la création d'une paire de clefs **/

	Fp i1,j1,k1,l1,i2,j2,k2,l2;
	do
	{
		////cout << "j1 = " << endl;
		j1.set_random();
		//cout << "k1 = " << endl;
		k1.set_random();
		//cout << "l1 = " << endl;
		l1.set_random();
		//cout << "i1 = " << endl;
		i1.set_ad_minus_bc(j1,k1,l1);
	}
	while (scalar2mpz(i1.scalar())<0); 
	do
	{
	//cout << "j2 = " << endl;
	j2.set_random();
	//cout << "k2 = " << endl;
	k2.set_random();
	//cout << "l2 = " << endl;
	l2.set_random();
	//cout << "i2 = " << endl;
	i2.set_ad_minus_bc(j2,k2,l2);	
	}
	while (scalar2mpz(i2.scalar())<0);
	/** génération de la clef privée **/

	//cout << YELLOW << "Private Key Generation" << RESET << endl;
	
	//cout << "sk:=(pi_1,pi_2,pi_T)" << endl;
	
	// Pi_1(x,y)=((-j1*k1)x + (i1*k1)y ,(-j1*l1)x + (i1*l1)y)
	
	
	//PrivateKey private_key(i1,j1,k1,l1,i2,j2,k2,l2);
	
	private_key.set(i1,j1,k1,l1,i2,j2,k2,l2);
	
	
	//fpe_t test;
	//int i;
	//for(i=1;i<12;i++)
	//{
		//test->v[i] = 0.;
	//}
	//test->v[0] = 2;
	//i1.set(test);
	
	//private_key.Pi_1(x,y);
		
	/** génération de la clef publique **/

	//cout << YELLOW << "Public Key Generation" << RESET << endl;
	
	//cout << "pk:=(p, G, H, G_T, e, g, h, (i_1*g,j_1*g), (i_2*h,j_2*h))" << endl;
	
	// 1) (i_1*g,j_1*g)  public_key.bipoint_curve (i_2*h,j_2*h) public_key:bipoint_twist
	// 2) on utilise bn_curvegen comme générateur g, on pourrait (devrait?) utiliser un générateur aléatoire plutôt qu'un générateur fixé
	
	curvepoint_fp_t c1,c2,c3,c4;	
	
	//cout << RED << "affichage du curvepoint g = " << RESET << endl;
	//curvepoint_fp_print(stdout,bn_curvegen);
	//JUMP;
	// calcul du générateur (i1g,j1g) du sous groupe  des bipoints de la courbe
	//ecris(g);
	//curvepoint_fp_print(stdout,bn_curvegen);
	//jump;
	//representation(bn_curvegen);
	
	curvepoint_fp_scalarmult_vartime(c1, bn_curvegen,i1.scalar());  
	curvepoint_fp_scalarmult_vartime(c2, bn_curvegen,j1.scalar());
	curvepoint_fp_makeaffine(c1); //il faut homogénéiser pour pouvoir faire des tests lors du déchiffrement
	curvepoint_fp_makeaffine(c2);



	
	//cout << RED << "affichage du scalar_t i1" << RESET <<endl;
	//scalar_print(stdout, i1.scalar()); 
	//JUMP;
	//cout << RED << "affichage du scalar_t j1" << RESET <<endl;
	//scalar_print(stdout, j1.scalar()); 
	//JUMP;
	//cout << RED << "affichage du curvepoint i1 g = " << RESET << endl;
	//curvepoint_fp_print(stdout,c1);
	//JUMP;
	//representation(c1);
	//JUMP;
	//cout << RED << "affichage du curvepoint j1 g = " << RESET << endl;
	//curvepoint_fp_print(stdout,c2);
	//representation(c2);
	//JUMP;
	
	//ecris(2g);
	//curvepoint_fp_t temp;
	//curvepoint_fp_double(temp,bn_curvegen);
	//curvepoint_fp_makeaffine(temp);
	//curvepoint_fp_print(stdout,temp);
	//jump;
	//representation(temp);
	//ecris(g+g);
	//curvepoint_fp_add_vartime(temp,bn_curvegen,bn_curvegen);
	//curvepoint_fp_makeaffine(temp);
	//curvepoint_fp_print(stdout,temp);
	//jump;
	//representation(temp);			
	//curvepoint_fp_t test1,test2;
	//curvepoint_fp_scalarmult_vartime(test1, c1,j1.scalar());  
	//curvepoint_fp_scalarmult_vartime(test2, c2,i1.scalar());
	//cout << RED << "affichage du curvepoint j1 (i1 g) = " << RESET << endl;
	//curvepoint_fp_makeaffine(test1);
	//curvepoint_fp_print(stdout,test1);
	//JUMP;
	//cout << RED << "affichage du curvepoint i1 (j1 g) = " << RESET << endl;
	//curvepoint_fp_makeaffine(test2);
	//curvepoint_fp_print(stdout,test2);
	//JUMP;	
	
	
	//Fp test3=j1*i1, test4=i1*j1;
	//cout << RED << "affichage du scalar_t (i1 j1) =" << RESET <<endl;
	//scalar_print(stdout, test3.scalar()); 
	//JUMP;
	//cout << RED << "affichage du scalar_t (j1 i1) =" << RESET <<endl;
	//scalar_print(stdout, test4.scalar()); 
	//JUMP;
	//curvepoint_fp_t test5,test6;
	//curvepoint_fp_scalarmult_vartime(test5,bn_curvegen,test3.scalar());
	//curvepoint_fp_scalarmult_vartime(test6,bn_curvegen,test4.scalar());
	//cout << RED << "affichage du curvepoint (i1j1) g = " << RESET << endl;
	//curvepoint_fp_makeaffine(test5);
	//curvepoint_fp_print(stdout,test5);
	//test5.get_fpe();
	//JUMP;
	//curvepoint_fp_makeaffine(test6);
	//curvepoint_fp_print(stdout,test6);
	//JUMP;
	
	
	//curvepoint_fp_t temp1,temp2, temp3, temp4;
	//curvepoint_fp_neg(temp1,test1);
	//curvepoint_fp_add_vartime(temp2,temp1,test5);
	//cout << RED << "affichage du curvepoint = test5 - test1 = (i1j1) g - j1 (i1 g)" << RESET << endl;
	//curvepoint_fp_makeaffine(temp2);
	//curvepoint_fp_print(stdout,temp2);
	//JUMP;
	//curvepoint_fp_neg(temp3,test5);
	//curvepoint_fp_add_vartime(temp4,test1,temp3);
	//cout << RED << "affichage du curvepoint = test1 - test5" << RESET << endl;
	//curvepoint_fp_makeaffine(temp4);
	//curvepoint_fp_print(stdout,temp4);
	//exit(0);
	
	//curvepoint_fp_t test6,test7;
	//curvepoint_fp_neg(test6,bn_curvegen);
	//curvepoint_fp_add_vartime(test7,bn_curvegen,test6);
	//cout << RED << "affichage du curvepoint = test7 =g-g" << RESET << endl;
	//curvepoint_fp_print(stdout,test7);
	//JUMP;

	Bipoint<curvepoint_fp_t> b1(c1,c2);	
	// calcul du générateur (i2h,j2h) du sous groupe des bipoints du twist
	twistpoint_fp2_t t1,t2,t3,t4;	
	twistpoint_fp2_scalarmult_vartime(t1, bn_twistgen,i2.scalar());
	twistpoint_fp2_scalarmult_vartime(t2, bn_twistgen,j2.scalar());
	twistpoint_fp2_makeaffine(t1);
	twistpoint_fp2_makeaffine(t2);
	Bipoint<twistpoint_fp2_t> b2(t1,t2);
	scalar_t s1, s2, s3, s4;
	//scalar_print(stdout,bn_r);
	scalar_setrandom(s1, bn_r);
	scalar_setrandom(s2, bn_r);
	scalar_setrandom(s3, bn_r);
	scalar_setrandom(s4, bn_r);
	// calcul de u, un bipoint de la courbe dans le groupe
	curvepoint_fp_scalarmult_vartime(c3, bn_curvegen,s1);
	curvepoint_fp_scalarmult_vartime(c4, bn_curvegen,s2);
	Bipoint<curvepoint_fp_t> b3(c3,c4);	
	b3.makeaffine();
	// calcul de v, un bipoint du twist dans le groupe
	
	twistpoint_fp2_scalarmult_vartime(t3, bn_twistgen,s3);
	twistpoint_fp2_scalarmult_vartime(t4, bn_twistgen,s4);
	Bipoint<twistpoint_fp2_t> b4(t3,t4);
	b4.makeaffine();

	//PublicKey public_key(b1,b2,b3,b4);		
	public_key.set(b1,b2,b3,b4);		
	//public_key.bipoint_curvegen.set_point(p1,0);
	//public_key.bipoint_curvegen.set_point(p2,1);
	
}
