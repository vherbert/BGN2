#include "Fp.hpp"
#include "fpe2scalar.hpp" //problem : Fp does not name a type --> solution :  include fpe2scalar.hpp only in the cpp files

	Fp Fp::operator-()
	{
		Fp rop;
		fpe_t temp;
		fpe_neg(temp,fpe_rep);
		rop.set(temp);
		return rop;		
	}
	
	Fp Fp::operator* (Fp b)
	{
		Fp rop;
		fpe_t temp;
		fpe_mul(temp,fpe_rep,b.fpe_rep); //b.fpe_rep on peut accéder au champ fpe_rep ici bien qu'il soit privé
		fpe_print(stdout,temp);
		zout(fpe2mpz(temp));
		rop.set(temp);
		zout(scalar2mpz(rop.scalar()));
		return rop;
	}

	void Fp::set(fpe_t fpe)
	{
		//abc;
		//zout(scalar_rep[0],scalar_rep[1],scalar_rep[2],scalar_rep[3]);
		fpe_set(fpe_rep,fpe);
		fpe2scalar(scalar_rep,fpe_rep);	
		//zout(scalar_rep[0],scalar_rep[1],scalar_rep[2],scalar_rep[3]);
		//xyz;
	}
	void Fp::set_random()
	{
		fpe_setrandom(fpe_rep);
		fpe2scalar(scalar_rep,fpe_rep);	
	}
	void Fp::set_ad_minus_bc(Fp b,Fp c,Fp d) // i1*l1 - j1*k1=1  on calcule i1 = (j1*k1 + 1)*l1^(-1)
	{
		fpe_ad_minus_bc(fpe_rep,b.fpe_rep,c.fpe_rep,d.fpe_rep);
		fpe2scalar(scalar_rep,fpe_rep);	
		
		/** bloc pour vérifier si ad-bc=1 en représentation mpz_class,   **/
		//extern const double bn_v;
		//mpz_class bn_u, bn_p;
		//zout(bn_v);
		//bn_u=1;//pow(bn_v,3); ne marche pas ni bn_v*bn_v*bn_v moral: d'abord initialiser pour travailler avec des mpz_class plutôt que des doubles
		//for (int i =0;i<3;i++)
		//{
			//bn_u*=bn_v;
		//}
		//bn_p=36 * bn_u * bn_u * bn_u * bn_u+36 * bn_u * bn_u * bn_u+24 * bn_u * bn_u+6 * bn_u + 1;
		//zout (fpe2mpz(fpe_rep),fpe2mpz(d.fpe_rep),fpe2mpz(b.fpe_rep),fpe2mpz(c.fpe_rep),fpe2mpz(fpe_rep)*fpe2mpz(d.fpe_rep)-fpe2mpz(b.fpe_rep)*fpe2mpz(c.fpe_rep));		
		//mpz_class field_element=(fpe2mpz(fpe_rep)*fpe2mpz(d.fpe_rep)-fpe2mpz(b.fpe_rep)*fpe2mpz(c.fpe_rep)) % bn_p;
		//field_element = (sgn(field_element)>=0)? field_element :field_element+bn_p; //il faut faire le modulo p et changer le reste de la division tronqué (obtenu avec %) est négatif, le modulo est du même signe que le dividende (celui qu'on divise) 
		//zout(field_element);
	}	
	const scalar_t& Fp::scalar() const
	{
		return scalar_rep;
	}
	void Fp::print_fpe() const
	{
		cout << fpe_rep << endl;
	}
