#include "fpe2scalar.hpp"

unsigned long long mpz2ull (mpz_class n)
{
  stringstream str;
  str << n;
  unsigned long long ull;
  str >> ull;
  return ull;
}

mpz_class  ull2mpz (unsigned long long n)
{
  stringstream str;
  str << n;
  mpz_class ull;
  str >> ull;
  return ull;
}

mpz_class fpe2mpz(const fpe_t op)
{
	
	
	//fpe_print(stdout,op);
	//jump;
	extern const double bn_v;
	//zout(bn_v);
	//for (int i=0;i<12;i++)
	//{
		//cout << todouble(op->v[i]) << " " ;
	//}	
	//cout << endl;
	
	
	
	
	mpz_class poly_at_one=1., increment_factor=6* bn_v;
	for (int i=0;i<12;i++)
	{	
		if (i==0)
		{
			poly_at_one=todouble(op->v[0]); 
			cout.precision ( 15 ); //NB
			////zout(std::numeric_limits<double>::digits10);
		}
		if (i>=1 && i<=6)  {poly_at_one+=increment_factor*todouble(op->v[i]); increment_factor*=bn_v;}
		if (i==7) {increment_factor*=6.; poly_at_one+=increment_factor*todouble(op->v[i]); increment_factor*=bn_v;}
		if (i>=8 && i<=11) {poly_at_one+=increment_factor*todouble(op->v[i]); increment_factor*=bn_v;}


		//if (i<11) {zout(increment_factor);}
	}
	//zout(poly_at_one);
	
			
	
	///** Méthode fausse 0: division ceil mpz_t, increment_factor=6*bn_v=11208198 l'incrément final est ok avec ce type de division mais on ne part pas du bon incrément au départ. Il faut multiplier, additionner des mpz_class pas des doubles pour le calculer correctement. **/
	//mpz_t v;
	//mpz_init_set_str (v, "1868033", 0);
	//mpz_t six;
	//mpz_init_set_str (six, "6", 0);
	//mpz_class poly_at_one=1;
	//mpz_class increment_factor=36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v; // l'erreur est ici, on peut pas définir un grand nombre en faisant des opérations sur les doubles
	//zout(increment_factor);
	//for (int i=11;i>=0;i--)
	//{	
		//if (i>=8 && i<=11) {poly_at_one+=increment_factor*todouble(op->v[i]); mpz_cdiv_q(increment_factor.get_mpz_t(), increment_factor.get_mpz_t(), v);}
		//if (i==7) {mpz_cdiv_q(increment_factor.get_mpz_t(), increment_factor.get_mpz_t(), six); poly_at_one+=increment_factor*todouble(op->v[i]); mpz_cdiv_q(increment_factor.get_mpz_t(), increment_factor.get_mpz_t(), v);}
		//if (i>=2 && i<=6) {poly_at_one+=increment_factor*todouble(op->v[i]); mpz_cdiv_q(increment_factor.get_mpz_t(), increment_factor.get_mpz_t(), v);}
		//if (i==1)  {poly_at_one+=increment_factor*todouble(op->v[i]);}
		//if (i==0) {poly_at_one+=todouble(op->v[0]);  }
		//if (i>1) {zout(increment_factor);}
	//}
	//zout(poly_at_one);	
	//mpz_clear(v);
	//mpz_clear(six);
	
		
	/** Méthode fausse 1 Ca marche presque avec / la division tronquée, mpz_class. increment_factor=11208197 **/
	//mpz_class poly_at_one=1;
	//mpz_class increment_factor=36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v;
	//for (int i=11;i>=0;i--)
	//{	
		//if (i>=8 && i<=11) {poly_at_one+=increment_factor*todouble(op->v[i]); increment_factor/=bn_v;}
		//if (i==7) {increment_factor/=6; poly_at_one+=increment_factor*todouble(op->v[i]); increment_factor/=bn_v;}
		//if (i>=2 && i<=6) {poly_at_one+=increment_factor*todouble(op->v[i]); increment_factor/=bn_v;}
		//if (i==1)  {poly_at_one+=increment_factor*todouble(op->v[i]);}
		//if (i==0) {poly_at_one+=todouble(op->v[0]);  }
		//zout(poly_at_one,increment_factor);
	//}
	//zout(poly_at_one);	
	
	///** Méthode fausse numéro 2 pour calculer poly_at_one. Tous les opérandes sont des doubles, le résultat est incorrect, la précision est inférieur à 1 sur des doubles de plus de 53 bits. Il faut additionner des mpz_class. **/
	//mpz_class poly_at_one = 
	//todouble(op->v[0])  +
	//todouble(op->v[1])  *  6 * bn_v +
	//todouble(op->v[2])  *  6 * bn_v * bn_v +
	//todouble(op->v[3])  *  6 * bn_v * bn_v * bn_v +
	//todouble(op->v[4])  *  6 * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[5])  *  6 * bn_v * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[6])  *  6 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[7])  * 36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[8])  * 36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[9])  * 36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[10]) * 36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v +
	//todouble(op->v[11]) * 36 * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v * bn_v; 
	//zout(poly_at_one);
	
	
	mpz_class bn_u, bn_p;
	bn_u=1;//attention pow(bn_v,3); ne marche pas ni bn_v*bn_v*bn_v
	
	for (int i =0;i<3;i++)
	{
		bn_u*=bn_v;
	}
	bn_p=36 * bn_u * bn_u * bn_u * bn_u+36 * bn_u * bn_u * bn_u+24 * bn_u * bn_u+6 * bn_u + 1;
	//zout(bn_p);
	mpz_class field_element = poly_at_one % bn_p; //32 octets 256 bits le reste n'est pas forcément positif, il est obtenu avec une division dite tronquée, i.e. le reste a le même signe que le divisé, poly_at_one dans ce cas.
	//field_element = (sgn(field_element)>=0)? field_element :field_element+bn_p;
	//if (sgn(field_element)<0)
	//{
		//field_element+=bn_p;
	//}

	//zout(field_element);
	return field_element;
}



void fpe2scalar(scalar_t rop, const fpe_t op)
{
	
	mpz_class field_element=fpe2mpz(op);
	
		
	///** Technique du modulo **/
		///** Calcul d'une puissance entière **/
		//mpz_class base=1;
		//for (int i=0; i<64; i++) 
		//{
			//base=base*2;
		//} 
		////zout(base); // base 2^64
	//rop[0] = mpz2ull( field_element        % base); //décomposition en base 2^64
	//rop[1] = mpz2ull((field_element >> 64)  % base);
	//rop[2] = mpz2ull((field_element >> 128)  % base);
	//rop[3] = mpz2ull((field_element >> 192)  % base);	
	
	//mpz_class test_modulo =ull2mpz(rop[0])+ull2mpz(rop[1])*base +ull2mpz(rop[2])*base*base+ull2mpz(rop[3])*base*base*base; 
	//zout(test_modulo);
	
	/** Technique du masque en C++**/
	mpz_class mask = 0xffffffffffffffff; // 8 octets 64 bits
	rop[0] = mpz2ull (field_element        & mask);
	rop[1] = mpz2ull((field_element >> 64) & mask);
	rop[2] = mpz2ull((field_element >> 128) & mask);
	rop[3] = mpz2ull((field_element >> 192) & mask);

	//mpz_class test_mask =ull2mpz(rop[0])+(ull2mpz(rop[1])<<64) +(ull2mpz(rop[2])<<128)+(ull2mpz(rop[3])<<192); //il faut mettre les parenthèses
	//zout(test_mask); //le test consiste à bien recomposer field_element à partir des rop[]
	
	/** Technique du masque en C**/
	//mpz_t c;	
	//mpz_and(c,field_element.get_mpz_t() ,mask.get_mpz_t()); 
	// pour continuer avec la méthode C, il faut définir une fonction de conversion entre mpz_t et ull
	
	
	//zout(rop[0],rop[1],rop[2],rop[3]);
}


mpz_class scalar2mpz( const scalar_t op)
{
	mpz_class r,rop;
    
	rop  = ull2mpz(op[0]);
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 64); //on doit repasser par l'interface C de GMP
	rop += ull2mpz(op[1])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 128);
	rop += ull2mpz(op[2])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 192);
	rop += ull2mpz(op[3])*r;
	
	//zout(mpz_sizeinbase(rop.get_mpz_t(),2));
	if (mpz_sizeinbase(rop.get_mpz_t(),2) == 256) //si le mpz fait 256 bits, le bit de poids fort est pour le signe
	{
		mpz_ui_pow_ui (r.get_mpz_t(), 2, 256);
		rop=rop-r;
	}
	return rop;
}


void mpz2scalar1024(scalar1024 rop, mpz_class field_element)
{
	mpz_class mask = 0xffffffffffffffff; // 8 octets 64 bits
	rop[0] = mpz2ull (field_element        & mask);
	rop[1] = mpz2ull((field_element >> 64) & mask);
	rop[2] = mpz2ull((field_element >> 128) & mask);
	rop[3] = mpz2ull((field_element >> 192) & mask);	
	rop[4] = mpz2ull((field_element >> 256) & mask);	
	rop[5] = mpz2ull((field_element >> 320) & mask);
	rop[6] = mpz2ull((field_element >> 384) & mask);
	rop[7] = mpz2ull((field_element >> 448) & mask);
	rop[8] = mpz2ull((field_element >> 512) & mask);
	rop[9] = mpz2ull((field_element >> 576) & mask);
	rop[10] = mpz2ull((field_element >> 640) & mask);
	rop[11] = mpz2ull((field_element >> 704) & mask);
	rop[12] = mpz2ull((field_element >> 768) & mask);
	rop[13] = mpz2ull((field_element >> 832) & mask);
	rop[14] = mpz2ull((field_element >> 896) & mask);
	rop[15] = mpz2ull((field_element >> 960) & mask);
}

mpz_class scalar1024_2mpz( const scalar1024 op)
{
	mpz_class r,rop;
    
	rop  = ull2mpz(op[0]);
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 64); //on doit repasser par l'interface C de GMP
	rop += ull2mpz(op[1])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 128);
	rop += ull2mpz(op[2])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 192);
	rop += ull2mpz(op[3])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 256);
	rop += ull2mpz(op[4])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 320);
	rop += ull2mpz(op[5])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 384);
	rop += ull2mpz(op[6])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 448);
	rop += ull2mpz(op[7])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 512);
	rop += ull2mpz(op[8])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 576);
	rop += ull2mpz(op[9])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 640);
	rop += ull2mpz(op[10])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 704);
	rop += ull2mpz(op[11])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 768);
	rop += ull2mpz(op[12])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 832);
	rop += ull2mpz(op[13])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 896);
	rop += ull2mpz(op[14])*r;
	mpz_ui_pow_ui (r.get_mpz_t(), 2, 960);
	rop += ull2mpz(op[15])*r;
	
	//zout(mpz_sizeinbase(rop.get_mpz_t(),2));
	if (mpz_sizeinbase(rop.get_mpz_t(),2) == 1024) //si le mpz fait 256 bits, le bit de poids fort est pour le signe
	{
		mpz_ui_pow_ui (r.get_mpz_t(), 2, 1024);
		rop=rop-r;
	}
	return rop;
}
