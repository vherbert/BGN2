#include "PublicKey.hpp"

PublicKey public_key;
	
Bipoint<curvepoint_fp_t> PublicKey::get_bipoint_curvegen() const
{
	return bipoint_curvegen;
}

Bipoint<twistpoint_fp2_t> PublicKey::get_bipoint_twistgen() const
{
	return bipoint_twistgen;
}

Bipoint<curvepoint_fp_t> PublicKey::get_bipoint_curve_groupelt() const
{
	return bipoint_curve_groupelt;
}

Bipoint<twistpoint_fp2_t> PublicKey::get_bipoint_twist_groupelt() const
{
	return bipoint_twist_groupelt;
}

void PublicKey::print() const
{
	cout << RED << "affichage du point i1.g" << RESET << endl;
	bipoint_curvegen.print(0);
	JUMP;
	cout << RED << "affichage du point j1.g" << RESET << endl;
	bipoint_curvegen.print(1);
	JUMP;
	cout << RED << "affichage du point i2.h" << RESET << endl;
	bipoint_twistgen.print(0);
	JUMP;
	cout << RED << "affichage du point j2.h" << RESET << endl;
	bipoint_twistgen.print(1);
	JUMP;
	cout << RED << "affichage du point u[0]" << RESET << endl;
	bipoint_curve_groupelt.print(0);
	JUMP;
	cout << RED << "affichage du point u[1]" << RESET << endl;
	bipoint_curve_groupelt.print(1);
	JUMP;
	cout << RED << "affichage du point v[0]" << RESET << endl;
	bipoint_twist_groupelt.print(0);
	JUMP;
	cout << RED << "affichage du point v[1]" << RESET << endl;
	bipoint_twist_groupelt.print(1);
	JUMP;	
	
	
	
}
	
PublicKey::PublicKey(Bipoint<curvepoint_fp_t> a ,Bipoint<twistpoint_fp2_t> b, Bipoint<curvepoint_fp_t> c ,Bipoint<twistpoint_fp2_t> d)
{
	a.makeaffine();
	b.makeaffine();
	c.makeaffine();
	d.makeaffine();
	bipoint_curvegen = a;
	bipoint_twistgen = b;
	bipoint_curve_groupelt = c;
	bipoint_twist_groupelt = d;
}

void PublicKey::set(Bipoint<curvepoint_fp_t> a,Bipoint<twistpoint_fp2_t> b, Bipoint<curvepoint_fp_t> c ,Bipoint<twistpoint_fp2_t> d)
{
	a.makeaffine();
	b.makeaffine();
	c.makeaffine();
	d.makeaffine();
	bipoint_curvegen = a;
	bipoint_twistgen = b;
	bipoint_curve_groupelt = c;
	bipoint_twist_groupelt = d;
}
