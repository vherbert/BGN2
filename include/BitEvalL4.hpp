#ifndef __BITEVALL4_HPP

#define __BITEVALL4_HPP

#include "typedef.h"
#include "Bipoint.hpp"
#include "Quadripoint.hpp"
#include "zout.hpp"
#include <vector>

// si le circuit utilise des additions de niveau 4, on utilise BitEvalL4 et on utilise pas BitEvalL4

class BitEvalL4
{
	public:
	
	BitEvalL4() = default; //on remet le constructeur par défaut par défaut qui n'existe plus lorsqu'un constructeur est spécifié
	Quadripoint get_alpha() const;	
	vector<Quadripoint> get_vec_quadripoints(int n) const;

	void set_alpha(Quadripoint a);
	void set_vec_quadripoints(vector<Quadripoint> d, int n); //utilisé dans additionL4
	void set_quadripoint(Quadripoint d, int n); //utilisé dans multiplicationL2
	
	private:
	

	Quadripoint alpha;
	vector<Quadripoint> vec_quadripoints[2];
};

#endif
