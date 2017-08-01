#include "BitChiffre.hpp"

Type BitChiffre::get_type() const
{
	return type;
}

void BitChiffre::print() const
{
	cout << "____________" << endl;
	zout(bit_masque);
	JUMP;
	if (type == CURVE)
	{
		cout << RED << "si bit_urandom=0 affichage du bipoint u1=(lambda1*i1*g, lambda1*j1*g)" << RESET << endl; 
		bipoint_curve.print();
	}
	if (type == TWIST)
	{
		bipoint_twist.print();
	}
	cout << "____________" << endl;

}

void BitChiffre::print_bit_masque() const
{
	zout(bit_masque);
}

Bipoint<curvepoint_fp_t> BitChiffre::get_bipoint_curve() const
{
		return bipoint_curve;
}

Bipoint<twistpoint_fp2_t> BitChiffre::get_bipoint_twist() const
{
		return bipoint_twist;
}

BitChiffre::BitChiffre(F2 a,Bipoint<curvepoint_fp_t> b ,Bipoint<twistpoint_fp2_t> c)
{
	bit_masque = a;
	bipoint_curve = b;
	bipoint_twist = c;
}

void BitChiffre::set_bit_masque(F2 bit)
//manipulateur pour modifer attribut si nécessaire, méthode définie en dehors de la classe
{
	bit_masque = bit;
}


F2 BitChiffre::get_bit_masque() const
{
	return bit_masque;
}

void BitChiffre::set_bipoint_curve(Bipoint<curvepoint_fp_t> b)
{
	bipoint_curve = b;
	type=CURVE;
}

void BitChiffre::set_bipoint_twist(Bipoint<twistpoint_fp2_t> c)
{
	bipoint_twist = c;
	type=TWIST;
}

void BitChiffre::makeaffine()
{
	bipoint_curve.makeaffine();
	bipoint_twist.makeaffine();
}
