#ifndef __BITEVALL3_HPP

#define __BITEVALL3_HPP

#include "typedef.h"
#include "Bipoint.hpp"
#include "Quadripoint.hpp"
#include "zout.hpp"
#include <vector>

// si le circuit utilise des additions de niveau 3, on utilise BitEvalL3 et on utilise pas BitEvalL3

class BitEvalL3
{
	public:
	
	BitEvalL3() = default; //on remet le constructeur par défaut par défaut qui n'existe plus lorsqu'un constructeur est spécifié

	Quadripoint get_alpha() const;	
	//Type get_type() const;
	vector<Bipoint<curvepoint_fp_t>> get_vec_bipoints() const;
	//Bipoint<twistpoint_fp2_t> get_bipoint_twist() const;
	vector<Quadripoint> get_vec_quadripoints() const;

	void set_alpha(Quadripoint a);
	void set_vec_bipoints(vector<Bipoint<curvepoint_fp_t>> b);
	void set_bipoint_curve(Bipoint<curvepoint_fp_t> b);	
	//void set_bipoint_twist(Bipoint<twistpoint_fp2_t> c);
	void set_vec_quadripoints(vector<Quadripoint> d); //utilisé dans additionL3
	void set_quadripoint(Quadripoint d); //utilisé dans multiplicationL1L2
	void print() const;

	private:
	
	//Type type;	
	//Bipoint<twistpoint_fp2_t> bipoint_twist;
	Quadripoint alpha;
	vector<Bipoint<curvepoint_fp_t>> vec_bipoints;
	vector<Quadripoint> vec_quadripoints;
	//int nb_additions;
};

#endif
