#include "BitEvalL2.hpp"


void BitEvalL2::print() const
{
	zout(bit_masque);
	JUMP;
	quadripoint.print();
	JUMP;
}

void BitEvalL2::print_bit_masque() const
{
	zout(bit_masque);
}



Quadripoint BitEvalL2::get_quadripoint() const
{
		return quadripoint;
}


void BitEvalL2::set_bit_masque(F2 bit)
//manipulateur pour modifer attribut si nécessaire, méthode définie en dehors de la classe
{
	bit_masque = bit;
}


F2 BitEvalL2::get_bit_masque() const
{
	return bit_masque;
}

void BitEvalL2::set_quadripoint(Quadripoint b)
{
	quadripoint = b;
}
