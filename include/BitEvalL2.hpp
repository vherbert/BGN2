#ifndef __BITEVALL2_HPP

#define __BITEVALL2_HPP

#include "typedef.h"
#include "Quadripoint.hpp"
#include "zout.hpp"

class BitEvalL2
{
	public:
	
	BitEvalL2() = default; //on remet le constructeur par défaut par défaut qui n'existe plus lorsqu'un constructeur est spécifié
	void set_bit_masque(F2); //prototype 
	F2 get_bit_masque() const;
	Quadripoint get_quadripoint() const;
	void set_quadripoint(Quadripoint b);
	void print() const;
	void print_bit_masque() const;

	
	private:
	
	F2 bit_masque=0; //initialisation, attribut tjrs privé
	Quadripoint quadripoint;
};

#endif
