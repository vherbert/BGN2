#ifndef __BITEVALL1_HPP

#define __BITEVALL1_HPP

#include "typedef.h"
#include "Bipoint.hpp"
#include "zout.hpp"


template<typename T>
class BitEvalL1
{
	public:
	
	BitEvalL1() = default; //on remet le constructeur par défaut par défaut qui n'existe plus lorsqu'un constructeur est spécifié
	BitEvalL1(F2 a,Bipoint<T>);
	void set_bit_masque(F2); //prototype 
	F2 get_bit_masque() const;
	Bipoint<T> get_bipoint() const;
	void set_bipoint(Bipoint<T> b);
	void print() const;
	void print_bit_masque() const;
	void makeaffine();

	
	private:
	
	F2 bit_masque=0; //initialisation, attribut tjrs privé
	Bipoint<T> bipoint;
};

#include "BitEvalL1.tpp" 

#endif
