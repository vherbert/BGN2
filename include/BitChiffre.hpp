#ifndef __BITCHIFFRE_HPP

#define __BITCHIFFRE_HPP

#include "typedef.h"
#include "Bipoint.hpp"
#include "zout.hpp"


class BitChiffre
{
	public:
	
	BitChiffre() = default; //on remet le constructeur par défaut par défaut qui n'existe plus lorsqu'un constructeur est spécifié
	BitChiffre(F2 a,Bipoint<curvepoint_fp_t> b ,Bipoint<twistpoint_fp2_t> c);
	void set_bit_masque(F2); //prototype 
	F2 get_bit_masque() const;
	Type get_type() const;
	Bipoint<curvepoint_fp_t> get_bipoint_curve() const;
	Bipoint<twistpoint_fp2_t> get_bipoint_twist() const;
	void set_bipoint_curve(Bipoint<curvepoint_fp_t> b);
	void set_bipoint_twist(Bipoint<twistpoint_fp2_t> c);
	void print() const;
	void print_bit_masque() const;
	void makeaffine();

	
	private:
	
	F2 bit_masque=0; //initialisation, attribut tjrs privé
	Type type;		
	Bipoint<curvepoint_fp_t> bipoint_curve;
	Bipoint<twistpoint_fp2_t> bipoint_twist;
};


//typedef BitChiffre BitEvalL1; //BitEvalL1 est un alias utilisé pour dénommer le type de la somme homomorphique de chiffrés de niveau 1
#endif
