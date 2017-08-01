#include "BitEvalL3.hpp"


void BitEvalL3::print() const
{
	cout << "____________" << endl;

	alpha.print();
	JUMP;
	vec_bipoints[0].print();
	JUMP;
	vec_quadripoints[0].print();
	cout << "____________" << endl;

}

Quadripoint BitEvalL3::get_alpha() const
{
		return alpha;
}

//Type BitEvalL3::get_type() const
//{
	//return type;
//}

vector<Bipoint<curvepoint_fp_t>> BitEvalL3::get_vec_bipoints() const
{
		return vec_bipoints;
}

//Bipoint<twistpoint_fp2_t> BitEvalL3::get_bipoint_twist() const
//{
		//return bipoint_twist;
//}

vector<Quadripoint> BitEvalL3::get_vec_quadripoints() const
{
		return vec_quadripoints;
}


void BitEvalL3::set_alpha(Quadripoint a)
{
	alpha = a;
}

void BitEvalL3::set_vec_bipoints(vector<Bipoint<curvepoint_fp_t>> b)
{
	

	vec_bipoints.insert( vec_bipoints.end(), b.begin(), b.end() );
	//zout(vec_bipoints.size());
}

void BitEvalL3::set_bipoint_curve(Bipoint<curvepoint_fp_t> b)
{
	int nb_bipoints = vec_bipoints.size();
	//zout(nb_bipoints);	
	vec_bipoints.push_back(b);
}

//void BitEvalL3::set_bipoint_twist(Bipoint<twistpoint_fp2_t> c)
//{
	//bipoint_twist = c;
	//type=TWIST;
//}

void BitEvalL3::set_vec_quadripoints(vector<Quadripoint> d)
{
	vec_quadripoints.insert(vec_quadripoints.end(),d.begin(),d.end());
}

void BitEvalL3::set_quadripoint(Quadripoint d)
{
	vec_quadripoints.push_back(d);
}

