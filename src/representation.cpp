#include "representation.hpp"

void representation(Bipoint<curvepoint_fp_t> op)
 {
	 representation(op[0]);
	 representation(op[1]);
}

void representation(const curvepoint_fp_t op)
{
mpz_class X,Y;
	
	extern const double bn_v;
	mpz_class bn_u, bn_p;
	bn_u=1;//pow(bn_v,3); ne marche pas ni bn_v*bn_v*bn_v moral: d'abord initialiser pour travailler avec des mpz_class plutôt que des doubles
	
	for (int i =0;i<3;i++)
	{
		bn_u*=bn_v;
	}
	bn_p=36 * bn_u * bn_u * bn_u * bn_u+36 * bn_u * bn_u * bn_u+24 * bn_u * bn_u+6 * bn_u + 1;	
	zout(bn_u,bn_v);
	mpz_class f[12],g[12];
	for (int i=0;i<12;i++)
	{
		f[i]=todouble((op->m_x) -> v[i]);
		g[i]=todouble((op->m_y) -> v[i]);
		//cout << "f[" <<i<<"] = "<< f[i] << endl;		
	}
	X=poly(f);
	Y=poly(g);	

	zout(X%bn_p,Y%bn_p);
}


mpz_class poly(mpz_class coeff[12])
{
	extern const double bn_v;
	mpz_class rop=coeff[0]+6*coeff[1]*bn_v
	+6*coeff[2]*bn_v*bn_v
	+6*coeff[3]*bn_v*bn_v*bn_v
	+6*coeff[4]*bn_v*bn_v*bn_v*bn_v
	+6*coeff[5]*bn_v*bn_v*bn_v*bn_v*bn_v
	+6*coeff[6]*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v
	+36*coeff[7]*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v
	+36*coeff[8]*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v
	+36*coeff[9]*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v
	+36*coeff[10]*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v
	+36*coeff[11]*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v*bn_v;
	return rop;
}
