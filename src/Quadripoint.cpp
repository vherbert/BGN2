#include "Quadripoint.hpp"


void Quadripoint::print() const
{
	fp12e_print(stdout,point[0]);
	jump;
	fp12e_print(stdout,point[1]);
	jump;
	fp12e_print(stdout,point[2]);
	jump;
	fp12e_print(stdout,point[3]);	
	JUMP;
}

bool Quadripoint::operator==(Quadripoint b)
{
	bool rop;

	
	if(fp12e_iseq(point[0],b[0]) && fp12e_iseq(point[1],b[1]) && fp12e_iseq(point[2],b[2]) && fp12e_iseq(point[3],b[3])) 
	{
		rop=true;
	}
	else
	{
		rop=false;
	}
	return rop;
}

Quadripoint Quadripoint::square()
{
	Quadripoint   rop;
	fp12e_square(rop[0],point[0]);
	fp12e_square(rop[1],point[1]);
	fp12e_square(rop[2],point[2]);
	fp12e_square(rop[3],point[3]);
	return rop;	
}

Quadripoint Quadripoint::pow_vartime(const scalar_t exp)
{
	Quadripoint   rop;
	fp12e_pow_vartime(rop[0],point[0],exp);
	fp12e_pow_vartime(rop[1],point[1],exp);
	fp12e_pow_vartime(rop[2],point[2],exp);
	fp12e_pow_vartime(rop[3],point[3],exp);
	return rop;	
}
Quadripoint Quadripoint::operator*(Quadripoint b)
{
	Quadripoint   rop;
	fp12e_mul(rop[0],point[0],b.point[0]);
	fp12e_mul(rop[1],point[1],b.point[1]);
	fp12e_mul(rop[2],point[2],b.point[2]);
	fp12e_mul(rop[3],point[3],b.point[3]);
	return rop;
}

fp12e_t& Quadripoint::operator[](int n)
{
	return point[n];
}




Quadripoint::Quadripoint()
{
	fp12e_setone(point[0]);
	fp12e_setone(point[1]);
	fp12e_setone(point[2]);
	fp12e_setone(point[3]);	
}


Quadripoint::Quadripoint(fp12e_t p1,fp12e_t p2, fp12e_t p3,fp12e_t p4)
{
	fp12e_set(point[0],p1);
	fp12e_set(point[1],p2);
	fp12e_set(point[2],p3);
	fp12e_set(point[3],p4);
	}



void Quadripoint::set(fp12e_t element,int numpoint)
{
	fp12e_set(point[numpoint],element);
}




void Quadripoint::print(int numpoint) const
{
	fp12e_print(stdout,point[numpoint]);
	JUMP;
}

