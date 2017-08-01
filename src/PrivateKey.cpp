#include "PrivateKey.hpp"
#include "fpe2scalar.hpp"

//to remove after debug
//PrivateKey private_key;

	Fp PrivateKey::get(string name)
	{
		 if (name == "i1") return i1; 
		 if (name == "i2") return i2; 
		 if (name == "j1") return j1; 
		 if (name == "j2") return j2; 	
		 if (name == "k1") return k1; 
		 if (name == "k2") return k2; 
		 if (name == "l1") return l1; 
		 if (name == "l2") return l2; 	
	}
	
	PrivateKey::PrivateKey(Fp a, Fp b, Fp c, Fp d, Fp e, Fp f, Fp g, Fp h)
	{
		i1 = a;
		j1 = b;
		k1 = c;
		l1 = d;
		i2 = e;
		j2 = f;
		k2 = g;
		l2 = h;
	}
	
	void PrivateKey::set(Fp a, Fp b, Fp c, Fp d, Fp e, Fp f, Fp g, Fp h)
	{
		i1 = a;
		j1 = b;
		k1 = c;
		l1 = d;
		i2 = e;
		j2 = f;
		k2 = g;
		l2 = h;
	}
	
	void PrivateKey::print() const
	{
		zout(*i1.scalar_rep, *j1.scalar_rep, *k1.scalar_rep, *l1.scalar_rep, *i2.scalar_rep, *j2.scalar_rep, *k2.scalar_rep, *l2.scalar_rep); 
		
	}
	
	
	Bipoint<curvepoint_fp_t>  PrivateKey::pi_1(Bipoint<curvepoint_fp_t> op)
	{
		//what;
		Bipoint<curvepoint_fp_t> rop;
		curvepoint_fp_t rop0, rop1; // rop0=coeff1.op[0] + coeff2.op[1]=(-j1*k1)x +(i1*k1)y    rop1=coeff3.op[0] + coeff4.op[1]=(-j1*l1)x + (i1*l1)y
		//cout << RED << "affichage du scalar_t i1" << RESET <<endl;
		//scalar_print(stdout, i1.scalar()); 
		//JUMP;
		//cout << RED << "affichage du scalar_t j1" << RESET <<endl;
		//scalar_print(stdout, j1.scalar()); 
		//JUMP;
		//cout << RED << "affichage du scalar_t k1" << RESET <<endl;
		//scalar_print(stdout, k1.scalar()); 
		//JUMP;		
		
		//cout << "à modifier après débug" << endl;
		//Fp coeff1=-(j1*k1), coeff2=i1*k1,coeff3=-(j1*l1),coeff4=i1*l1; // en théorie, on peut faire les calculs dans Fp d'abord puis les multiplications scalaires, en pratique, on obtient des représentants différents à cause du modulo lors du produit
		//cout << RED << "affichage du scalar_t coeff1.scalar()" << RESET <<endl;
		//scalar_print(stdout, coeff1.scalar()); 
		//JUMP;
		//cout << RED << "affichage du scalar_t coeff2.scalar()" << RESET <<endl;
		//scalar_print(stdout, coeff2.scalar()); 
		//JUMP;
		
		
		
		
		//Fp test1=j1*k1*i1, test2=i1*k1*j1;
		//cout << RED << "affichage du scalar_t test1" << RESET <<endl;
		//scalar_print(stdout, test1.scalar()); 
		//JUMP;
		//cout << RED << "affichage du scalar_t test2" << RESET <<endl;
		//scalar_print(stdout, test2.scalar()); 
		//JUMP;	
		//curvepoint_fp_t test3,test4;
		//curvepoint_fp_scalarmult_vartime(test3,bn_curvegen,test1.scalar());
		//curvepoint_fp_scalarmult_vartime(test4,bn_curvegen,test2.scalar());
		//curvepoint_fp_print(stdout,test3);
		//JUMP;
		//curvepoint_fp_print(stdout,test4);
		//JUMP;
			
		curvepoint_fp_t temp1a,temp2a,temp3a,temp4a,temp1b,temp2b,temp3b,temp4b,temp1c,temp3c;
		//scalar_print(stdout, coeff1.scalar());		JUMP;

		//scalar_print(stdout, coeff2.scalar());		JUMP;

		//curvepoint_fp_print(stdout,op[0]);		JUMP;

		//curvepoint_fp_print(stdout,op[1]);		JUMP;

		
		//cout << "coeff1[0] = " << coeff1.scalar()[0] << endl;
		//cout << "coeff1[1] = " << coeff1.scalar()[1] << endl;
		//cout << "coeff1[2] = " << coeff1.scalar()[2] << endl;
		//cout << "coeff1[3] = " << coeff1.scalar()[3] << endl;
		
		//scalar_t test5;
		//test5[0]=1; test5[1]=0; test5[2]=0; test5[3]=0; 
		//curvepoint_fp_scalarmult_vartime(temp1,op[0],test5);
		//exit(0);
		
		//curvepoint_fp_scalarmult_vartime(temp1,op[0],coeff1.scalar());
		curvepoint_fp_scalarmult_vartime(temp1a,op[0],j1.scalar());
		curvepoint_fp_scalarmult_vartime(temp1b,temp1a,k1.scalar());
		curvepoint_fp_neg(temp1c,temp1b);
		curvepoint_fp_makeaffine(temp1c);
		//cout << RED << "si bit_urandom=0 et op=u1 affichage du curvepoint coeff1*u1[0]=-(j1*k1)u1[0]=-(j1*k1) (lambda1*i1*g)=" << RESET << endl; curvepoint_fp_print(stdout,temp1c); JUMP; 
		//curvepoint_fp_scalarmult_vartime(temp2,op[1],coeff2.scalar());
		curvepoint_fp_scalarmult_vartime(temp2a,op[1],i1.scalar());
		curvepoint_fp_scalarmult_vartime(temp2b,temp2a,k1.scalar());
		curvepoint_fp_makeaffine(temp2b);
		//cout << RED "si bit_urandom=0 et op=u1 affichage du curvepoint coeff2*u1[1]=(i1*k1)u1[1]=(i1*k1) (lambda1*j1*g)=" << RESET << endl; curvepoint_fp_print(stdout,temp2b);JUMP;
		curvepoint_fp_add_vartime(rop0,temp1c,temp2b);
		curvepoint_fp_makeaffine(rop0);
		curvepoint_fp_set(rop[0],rop0);
		//cout << RED << "si bit_urandom=0 et op=u1 affichage du curvepoint pi_1(u1)[0]=-(j1*k1)u1[0]+(i1*k1)u1[1]=-(j1*k1) (lambda1*i1*g)+(i1*k1) (lambda1*j1*g)" << RESET << endl; curvepoint_fp_print(stdout,rop[0]); JUMP; 

		
		//cout << RED << "affichage du scalar_t j1" << RESET <<endl;
		//scalar_print(stdout, j1.scalar()); 
		//JUMP;		
		//cout << RED << "affichage du scalar_t -j1" << RESET <<endl;
		//scalar_print(stdout, (-j1).scalar()); 
		//JUMP;		
		//cout << RED << "affichage du scalar_t l1" << RESET <<endl;
		//scalar_print(stdout, l1.scalar()); 
		//JUMP;		
		//cout << RED << "affichage du scalar_t -l1" << RESET <<endl;
		//scalar_print(stdout, (-l1).scalar()); 
		//JUMP;
		
		//curvepoint_fp_scalarmult_vartime(temp3,op[0],coeff3.scalar());
		curvepoint_fp_scalarmult_vartime(temp3a,op[0],j1.scalar());
		curvepoint_fp_scalarmult_vartime(temp3b,temp3a,l1.scalar());
		curvepoint_fp_neg(temp3c,temp3b);
		curvepoint_fp_makeaffine(temp3c);
		//cout << RED << "si bit_urandom=0 et op=u1 affichage du curvepoint -(j1*l1)u1[0]=-(j1*l1) (lambda1*i1*g)=" << RESET << endl; curvepoint_fp_print(stdout,temp3c); JUMP;
		//curvepoint_fp_scalarmult_vartime(temp4,op[1],coeff4.scalar());
		curvepoint_fp_scalarmult_vartime(temp4a,op[1],i1.scalar());
		curvepoint_fp_scalarmult_vartime(temp4b,temp4a,l1.scalar());
		curvepoint_fp_makeaffine(temp4b);
		//cout << RED << "si bit_urandom=0 et op=u1 affichage du curvepoint (i1*l1)u1[1]=(i1*l1) (lambda1*j1*g)=" << RESET << endl; curvepoint_fp_print(stdout,temp4b); JUMP;
		curvepoint_fp_add_vartime(rop1,temp3c,temp4b);
		curvepoint_fp_makeaffine(rop1);
		curvepoint_fp_set(rop[1],rop1);	
		//cout << RED << "si bit_urandom=0 et op=u1 affichage du curvepoint pi_1(u1)[1]=-(j1*l1)u1[0]+(i1*l1)u1[1]=-(j1*l1) lambda1*i1*g+(i1*l1) lambda1*j1*g" << RESET << endl; curvepoint_fp_print(stdout,rop[1]); JUMP; 

		return rop;
	}

	Bipoint<twistpoint_fp2_t>  PrivateKey::pi_2(Bipoint<twistpoint_fp2_t> op)
	{
		Bipoint<twistpoint_fp2_t> rop;
		twistpoint_fp2_t rop0, rop1; // rop0=coeff1.op[0] + coeff2.op[1]=(-j2*k2)x +(i2*k2)y    rop1=coeff3.op[0] + coeff4.op[1]=(-j2*l2)x + (i2*l2)y
		//Fp coeff1 = -j2*k2, coeff2 = i2*k2, coeff3 = -j2*l2, coeff4 = i2*l2;
		twistpoint_fp2_t temp1a,temp2a,temp3a,temp4a,temp1b,temp2b,temp3b,temp4b,temp1c,temp3c;
		//twistpoint_fp2_scalarmult_vartime(temp1,op[0],coeff1.scalar());
		twistpoint_fp2_scalarmult_vartime(temp1a,op[0],j2.scalar());
		twistpoint_fp2_scalarmult_vartime(temp1b,temp1a,k2.scalar());
		twistpoint_fp2_neg(temp1c,temp1b);
		twistpoint_fp2_makeaffine(temp1c);
		//twistpoint_fp2_scalarmult_vartime(temp2,op[1],coeff2.scalar());
		twistpoint_fp2_scalarmult_vartime(temp2a,op[1],i2.scalar());
		twistpoint_fp2_scalarmult_vartime(temp2b,temp2a,k2.scalar());
		twistpoint_fp2_makeaffine(temp2b);
		twistpoint_fp2_add_vartime(rop0,temp1c,temp2b);
		twistpoint_fp2_makeaffine(rop0);
		twistpoint_fp2_set(rop[0],rop0);
		
		//twistpoint_fp2_scalarmult_vartime(temp3,op[0],coeff3.scalar());
		twistpoint_fp2_scalarmult_vartime(temp3a,op[0],j2.scalar());
		twistpoint_fp2_scalarmult_vartime(temp3b,temp3a,l2.scalar());
		twistpoint_fp2_neg(temp3c,temp3b);		
		twistpoint_fp2_makeaffine(temp3c);
		//twistpoint_fp2_scalarmult_vartime(temp4,op[1],coeff4.scalar());
		twistpoint_fp2_scalarmult_vartime(temp4a,op[1],i2.scalar());
		twistpoint_fp2_scalarmult_vartime(temp4b,temp4a,l2.scalar());
		twistpoint_fp2_makeaffine(temp4b);
		twistpoint_fp2_add_vartime(rop1,temp3c,temp4b);
		twistpoint_fp2_makeaffine(rop1);
		twistpoint_fp2_set(rop[1],rop1);	
		return rop;		
	}
	
	Quadripoint PrivateKey::pi_T(Quadripoint op)
	{
		Quadripoint rop;
		fp12e_t rop1, rop2, rop3, rop4;
		fp12e_t temp1[20],temp2[20],temp3[20],temp4[20];
		//void fp12e_pow_vartime(fp12e_t rop, const fp12e_t op, const scalar_t exp);
		//void fp12e_mul(fp12e_t rop, const fp12e_t op1, const fp12e_t op2);
		//void fp12e_invert(fp12e_t rop, const fp12e_t op);
		
		//fpe_t un={139089155.,0,0,0,0,0,0,0,0,0,0,0};
		//fpe_t deux={13908915423.,0,0,0,0,0,0,0,0,0,0,0};
		//Fp UN,DEUX;
		//UN.set(un);
		//DEUX.set(deux);
		//zout(fpe2mpz(un),fpe2mpz(deux));
		//fp12e_pow_vartime(temp1[0],op[0],UN.scalar());
		//fp12e_pow_vartime(temp1[1],temp1[0],DEUX.scalar());
		//fp12e_print(stdout,temp1[1]);
		//JUMP;
		//fp12e_pow_vartime(temp1[2],op[0],(UN*DEUX).scalar());
		//fp12e_print(stdout,temp1[2]);
		//JUMP;
		//scalar_print(stdout,(UN*DEUX).scalar());		
		//jump;
		//zout(scalar2mpz((UN*DEUX).scalar()))
		//exit(0);

		
		//composante 1
		//scalar1024 exp1={}, exp2={}, exp3={}, exp4={};
		//mpz2scalar1024(exp1,scalar2mpz(j1.scalar())*scalar2mpz(k1.scalar())*scalar2mpz(j2.scalar())*scalar2mpz(k2.scalar()));	
		//mpz2scalar1024(exp2,scalar2mpz(j1.scalar())*scalar2mpz(k1.scalar())*scalar2mpz(i2.scalar())*scalar2mpz(k2.scalar()));	
		//mpz2scalar1024(exp3,scalar2mpz(i1.scalar())*scalar2mpz(k1.scalar())*scalar2mpz(j2.scalar())*scalar2mpz(k2.scalar()));	
		//mpz2scalar1024(exp4,scalar2mpz(i1.scalar())*scalar2mpz(k1.scalar())*scalar2mpz(i2.scalar())*scalar2mpz(k2.scalar()));	
		
		//fp12e_pow_vartime1024(temp1[3],op[0],exp1);
		
		//fp12e_invert(temp1[4],op[1]);
		//fp12e_pow_vartime1024(temp1[8],temp1[4],exp2);

		//fp12e_invert(temp1[9],op[2]);
		//fp12e_pow_vartime1024(temp1[13],temp1[9],exp3);

		//fp12e_pow_vartime1024(temp1[17],op[3],exp4);

		fp12e_pow_vartime(temp1[0],op[0],j1.scalar()); // le produit d'entiers j1*k1 est trop grand pour aller dans un scalaire 
		fp12e_pow_vartime(temp1[1],temp1[0],k1.scalar()); //le produit de fpe_t (j1*k1) est réduit modulo p 
		fp12e_pow_vartime(temp1[2],temp1[1],j2.scalar()); 
		fp12e_pow_vartime(temp1[3],temp1[2],k2.scalar());

		
		fp12e_invert(temp1[4],op[1]);
		fp12e_pow_vartime(temp1[5],temp1[4],j1.scalar());
		fp12e_pow_vartime(temp1[6],temp1[5],k1.scalar());
		fp12e_pow_vartime(temp1[7],temp1[6],i2.scalar());
		fp12e_pow_vartime(temp1[8],temp1[7],k2.scalar());

		fp12e_invert(temp1[9],op[2]);
		fp12e_pow_vartime(temp1[10],temp1[9],i1.scalar());
		fp12e_pow_vartime(temp1[11],temp1[10],k1.scalar());
		fp12e_pow_vartime(temp1[12],temp1[11],j2.scalar());
		fp12e_pow_vartime(temp1[13],temp1[12],k2.scalar());

		fp12e_pow_vartime(temp1[14],op[3],i1.scalar());
		fp12e_pow_vartime(temp1[15],temp1[14],k1.scalar());
		fp12e_pow_vartime(temp1[16],temp1[15],i2.scalar());
		fp12e_pow_vartime(temp1[17],temp1[16],k2.scalar());

		fp12e_mul(temp1[18],temp1[3],temp1[8]);
		fp12e_mul(temp1[19],temp1[13],temp1[17]);
		fp12e_mul(rop1,temp1[18],temp1[19]);

		//composante 2
		fp12e_pow_vartime(temp2[0],op[0],j1.scalar());
		fp12e_pow_vartime(temp2[1],temp2[0],k1.scalar());
		fp12e_pow_vartime(temp2[2],temp2[1],j2.scalar());
		fp12e_pow_vartime(temp2[3],temp2[2],l2.scalar());

		fp12e_pow_vartime(temp2[4],op[1],j1.scalar());
		fp12e_invert(temp2[5],temp2[4]);
		fp12e_pow_vartime(temp2[6],temp2[5],k1.scalar());
		fp12e_pow_vartime(temp2[7],temp2[6],i2.scalar());
		fp12e_pow_vartime(temp2[8],temp2[7],l2.scalar());

		fp12e_pow_vartime(temp2[9],op[2],i1.scalar());
		fp12e_pow_vartime(temp2[10],temp2[9],k1.scalar());
		fp12e_pow_vartime(temp2[11],temp2[10],j2.scalar());
		fp12e_invert(temp2[12],temp2[11]);
		fp12e_pow_vartime(temp2[13],temp2[12],l2.scalar());
//
		fp12e_pow_vartime(temp2[14],op[3],i1.scalar());
		fp12e_pow_vartime(temp2[15],temp2[14],k1.scalar());
		fp12e_pow_vartime(temp2[16],temp2[15],i2.scalar());
		fp12e_pow_vartime(temp2[17],temp2[16],l2.scalar());

		fp12e_mul(temp2[18],temp2[3],temp2[8]);
		fp12e_mul(temp2[19],temp2[13],temp2[17]);
		fp12e_mul(rop2,temp2[18],temp2[19]);
		
		
		//composante 3
		fp12e_pow_vartime(temp3[0],op[0],j1.scalar());
		fp12e_pow_vartime(temp3[1],temp3[0],l1.scalar());
		fp12e_pow_vartime(temp3[2],temp3[1],j2.scalar());
		fp12e_pow_vartime(temp3[3],temp3[2],k2.scalar());

		fp12e_pow_vartime(temp3[4],op[1],j1.scalar());
		fp12e_invert(temp3[5],temp3[4]);
		fp12e_pow_vartime(temp3[6],temp3[5],l1.scalar());
		fp12e_pow_vartime(temp3[7],temp3[6],i2.scalar());
		fp12e_pow_vartime(temp3[8],temp3[7],k2.scalar());

		fp12e_pow_vartime(temp3[9],op[2],i1.scalar());
		fp12e_pow_vartime(temp3[10],temp3[9],l1.scalar());
		fp12e_pow_vartime(temp3[11],temp3[10],j2.scalar());
		fp12e_invert(temp3[12],temp3[11]);
		fp12e_pow_vartime(temp3[13],temp3[12],k2.scalar());

		fp12e_pow_vartime(temp3[14],op[3],i1.scalar());
		fp12e_pow_vartime(temp3[15],temp3[14],l1.scalar());
		fp12e_pow_vartime(temp3[16],temp3[15],i2.scalar());
		fp12e_pow_vartime(temp3[17],temp3[16],k2.scalar());
		
		fp12e_mul(temp3[18],temp3[3],temp3[8]);
		fp12e_mul(temp3[19],temp3[13],temp3[17]);
		fp12e_mul(rop3,temp3[18],temp3[19]);
		
		//composante 4
		
		fp12e_pow_vartime(temp4[0],op[0],j1.scalar());
		fp12e_pow_vartime(temp4[1],temp4[0],l1.scalar());
		fp12e_pow_vartime(temp4[2],temp4[1],j2.scalar());
		fp12e_pow_vartime(temp4[3],temp4[2],l2.scalar());

		fp12e_pow_vartime(temp4[4],op[1],j1.scalar());
		fp12e_invert(temp4[5],temp4[4]);
		fp12e_pow_vartime(temp4[6],temp4[5],l1.scalar());
		fp12e_pow_vartime(temp4[7],temp4[6],i2.scalar());
		fp12e_pow_vartime(temp4[8],temp4[7],l2.scalar());

		fp12e_pow_vartime(temp4[9],op[2],i1.scalar());
		fp12e_pow_vartime(temp4[10],temp4[9],l1.scalar());
		fp12e_pow_vartime(temp4[11],temp4[10],j2.scalar());
		fp12e_invert(temp4[12],temp4[11]);
		fp12e_pow_vartime(temp4[13],temp4[12],l2.scalar());

		fp12e_pow_vartime(temp4[14],op[3],i1.scalar());
		fp12e_pow_vartime(temp4[15],temp4[14],l1.scalar());
		fp12e_pow_vartime(temp4[16],temp4[15],i2.scalar());
		fp12e_pow_vartime(temp4[17],temp4[16],l2.scalar());

		fp12e_mul(temp4[18],temp4[3],temp4[8]);
		fp12e_mul(temp4[19],temp4[13],temp4[17]);
		fp12e_mul(rop4,temp4[18],temp4[19]);		
		
		rop.set(rop1,0);
		rop.set(rop2,1);
		rop.set(rop3,2);
		rop.set(rop4,3);
		
		return rop;
	}
