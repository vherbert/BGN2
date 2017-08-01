#ifndef __BIPOINT_HPP

#define __BIPOINT_HPP



//#include "bgn.hpp"
#include "mydouble.h" 
extern "C" {
#include "fpe.h"
}
#include "curvepoint_fp.h"
extern "C" {
#include "fp2e.h"	
}
#include "twistpoint_fp2.h"
#include "zout.hpp"

template <typename T>
class Bipoint
{}; //il faut une définition de la classe pour un type quelconque, on choisit de rien mettre dedans, on veut traiter seulement des cas particuliers

template <>
class Bipoint  <curvepoint_fp_t> //spécialisation pour curvepoint_fp_t
{
	
	public:
	//Bipoint() = default; 
	Bipoint();
	Bipoint(curvepoint_fp_t p1,curvepoint_fp_t p2);
	//void bipoint_curvepoint_fp_init_set(Bipoint<curvepoint_fp_t> rop, const Bipoint<curvepoint_fp_t> op);
	void set_point(curvepoint_fp_t, int numpoint); 
	void print(int numpoint) const;	
	curvepoint_fp_t& operator[](int n); //la valeur de retour doit être une référence.
	Bipoint  <curvepoint_fp_t> operator+(Bipoint  <curvepoint_fp_t> b); 
	bool operator==(Bipoint<curvepoint_fp_t> b);
	void makeaffine();
	void scalarmult_vartime(Bipoint<curvepoint_fp_t> op, scalar_t s);
	void print() const;
	
	private:
	curvepoint_fp_t point[2];	
};

template <>
class Bipoint  <twistpoint_fp2_t> //spécialisation pour twistpoint_fp2_t
{
	
	public:
	Bipoint(); 
	Bipoint(twistpoint_fp2_t p1,twistpoint_fp2_t p2);	
	void set_point(twistpoint_fp2_t, int numpoint); 
	void print(int numpoint) const;
	twistpoint_fp2_t& operator[](int n);
	Bipoint<twistpoint_fp2_t> operator+(Bipoint<twistpoint_fp2_t> b);
	bool operator==(Bipoint<twistpoint_fp2_t> b);
	void makeaffine();	
	void scalarmult_vartime(Bipoint<twistpoint_fp2_t> op, scalar_t s);
	void print() const;
	
	private:
	twistpoint_fp2_t point[2];	
};


template <>
class Bipoint  <fpe_t> //spécialisation pour fpe_t
{
	
	public:
	
	void set_coordonnee(fpe_t, int numcoord); 
	void get_coordonnee(int numcoord) const;
	
	private:
	fpe_t coordonnee[2];	
};


template <>
class Bipoint  <fp2e_t> //spécialisation pour fp2e_t
{
	
	public:
	
	void set_coordonnee(fp2e_t, int numcoord); 
	void get_coordonnee(int numcoord) const;
	
	private:
	fp2e_t coordonnee[2];	
};

#endif
