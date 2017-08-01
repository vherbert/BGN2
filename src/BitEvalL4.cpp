#include "BitEvalL4.hpp"

Quadripoint BitEvalL4::get_alpha() const
{
		return alpha;
}

vector<Quadripoint> BitEvalL4::get_vec_quadripoints(int n) const
{
		return vec_quadripoints[n];
}


void BitEvalL4::set_alpha(Quadripoint a)
{
	alpha = a;
}



void BitEvalL4::set_vec_quadripoints(vector<Quadripoint> d, int n)
{
	int nb_quadripoints = vec_quadripoints[n].size();
	//zout(nb_quadripoints);	
	vec_quadripoints[n].insert(vec_quadripoints[n].end(),d.begin(),d.end());
}

void BitEvalL4::set_quadripoint(Quadripoint d, int n)
{
	vec_quadripoints[n].push_back(d);
}

