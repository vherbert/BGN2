#include "quadruplet.hpp"








void fpe_setrandom(fpe_t rop)
{
	//zout(sizeof(*rop));
	//cout << abi::__cxa_demangle(typeid(rop->v[8]).name(), 0, 0, 0) <<  endl;
	bool tableau_entier[12]={}; /** Les shorts sont stockés sur 2  octets ne provoquent pas d'overflow après 10000 tests. Les ints sur 4 octets provoquent des overflows lorsqu'on multiplie les fpe_t entre eux. La mantisse des doubles est limitée à 53 bits. Les fpe_t sont associées à 12 doubles. On peut aussi générer des ints, puis faire un modulo pour voir la taille maximale. Avec cette méthode, on a pas d'overflow avec un modulo 2<<22-1. Autrement dit, le résultat fait moins de 22 bits soit moins de 2,75 octets. Edit : On a remplacé les shorts par des bools (3 occurences dans le fichier) pour diminuer la taille des coefficients qui faisaient parfois 256 bits et empêchent un décodage L2 correct.  **/
	FILE * urandom;
    urandom = fopen ("/dev/urandom","r");
	if (urandom == NULL)
	{
		fprintf(stderr, "Could not open device file /dev/urandom");
		exit(1);
	}
	
	#ifdef CHECK
	for (int i=0; i<12;i++)
	{
		fread(&tableau_entier[i],sizeof(bool),1,urandom); 
		(rop->v[i]).v=(double)tableau_entier[i]; 
		(rop->v[i]).mmax = (unsigned long long)fabs((double)tableau_entier[i]);
	}
	#else
	for (int i=0; i<12;i++)
	{
		fread(&tableau_entier[i],sizeof(bool),1,urandom); 
		rop->v[i]=(double)tableau_entier[i]; // version sans DCHECK, équivalent (*rop).v[i]
		//zout(log(abs(rop->v[i]))/log(2));
	}
	#endif
	

	//fpe_print(stdout,rop);
	//cout << endl; 
	//log2_fpe_print(stdout,rop);
	//cout << endl; 
	
		
	fclose (urandom);

}

void fpe_ad_minus_bc(fpe_t rop,fpe_t op1,fpe_t op2,fpe_t op3) //(i_1,j_1,k_1,l_1); // rop*op3- op1*op2 = i1*l1 - j1*k1=1  on calcule i1 = (j1*k1 + 1)*l1^(-1)
{
	if (fpe_iszero(op3)==1) //1=vrai
	{
		fpe_setrandom(rop); //rop quelconque
		
		fpe_t temp;
		fpe_invert(temp,op1);
		fpe_neg(op2,temp); //op2 = - (1/op1)
		cout << "op2=k1 modifié car op3=l1 vaut 0" << endl;
		//fpe_print(stdout,op2);
		//cout << endl; 
		//log2_fpe_print(stdout,op2);
		//cout << endl; 
	}	
	else
	{
		fpe_t temp1, temp2, temp3, temp4;
		fpe_mul(temp1,op1,op2);
		fpe_setone(temp2);
		fpe_add(temp3,temp1,temp2);
		fpe_invert(temp4,op3);
		fpe_mul(rop,temp3,temp4);
	}
	
	

	
	/** affichage de rop=i1 **/
	//fpe_print(stdout,rop);
	//cout << endl; 
	//log2_fpe_print(stdout,rop);
	//cout << endl; 
	
	/** verifions que ad-bc = 1  **/
	fpe_t temp5,temp6,temp7;
	fpe_mul(temp5,rop,op3);
	fpe_mul(temp6,op1,op2);
	fpe_sub(temp7,temp5,temp6);
	
	
	//cout << "i1*l1 - j1*k1" << endl;
	//fpe_print(stdout,temp7);
	//jump;
	
	

}


// Print the bitsize of the element to stdout:
void log2_fpe_print(FILE * outfile, const fpe_t op)
{
  int i;
  for(i=0;i<11;i++)
  {
	   fprintf(outfile, "%d, ", int(ceil(log2(fabs(todouble(op->v[i]))))));
  }
  fprintf(outfile, "%d\n", int(ceil(log2(fabs(todouble(op->v[11]))))));
}
