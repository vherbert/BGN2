#ifndef __QUADRIPOINT_HPP

#define __QUADRIPOINT_HPP



//#include "bgn.hpp"
#include "mydouble.h" 
extern "C" {
#include "fpe.h"
}
extern "C" {
#include "fp2e.h"	
}
extern "C" {
#include "fp6e.h"	
}
extern "C" {
#include "fp12e.h"	
}
#include "zout.hpp"

class Quadripoint
{
	public:
	//Quadripoint() = default; 
	Quadripoint();
	Quadripoint(fp12e_t p1,fp12e_t p2, fp12e_t p3,fp12e_t p4);
	void set(fp12e_t, int numpoint); 
	void print(int numpoint) const;	
	fp12e_t& operator[](int n); //la valeur de retour doit être une référence.
	bool operator==(Quadripoint b);
	Quadripoint operator*(Quadripoint b); 
	Quadripoint square();
	Quadripoint pow_vartime(const scalar_t exp);

	void print() const;
	
	private:
	fp12e_t point[4];	}; 

#endif
