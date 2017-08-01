#ifndef __FP_HPP

#define __FP_HPP


//#include "bgn.hpp" 

#include "mydouble.h" 
extern "C" {
#include "fpe.h"
#ifdef NEW_PARAMETERS
#include "scalar_512.h"
#else
#include "scalar.h"
#endif
}
//#include "fpe2scalar.hpp"



class Fp
{
	friend class PrivateKey; //nécessaire pour fournir à PrivateKey l'accès aux membres privés de Fp.
	friend class PublicKey;
	
	public:
	
	void set(fpe_t fpe); 
	void set_random();
	void set_ad_minus_bc(Fp b,Fp c,Fp d);
	const scalar_t& scalar() const; //problem declared as function returning an array --> solution passage en réference de la valeur de retour
	void print_fpe() const;	
	Fp operator*(Fp b); // there is already one implicit parameter: the object for which the method is invoked! 
	Fp operator-();
	
	private:
	
	scalar_t scalar_rep={};
	fpe_t fpe_rep;
	
};

#endif
