#include "Bipoint.hpp"


void Bipoint<curvepoint_fp_t>::print() const
{
	curvepoint_fp_print(stdout,point[0]);
	jump;
	curvepoint_fp_print(stdout,point[1]);
	JUMP;
}

void Bipoint<twistpoint_fp2_t>::print() const
{
	twistpoint_fp2_print(stdout,point[0]);
	jump;
	twistpoint_fp2_print(stdout,point[1]);	
	JUMP;
}

Bipoint<curvepoint_fp_t> Bipoint<curvepoint_fp_t>::operator+(Bipoint<curvepoint_fp_t> b)
{
	Bipoint  <curvepoint_fp_t> rop;
	if (*this==b) //l'addition a+b dans la lib 666 est mal défini si a=b, il faut distinguer les cas
	{
		curvepoint_fp_double(rop[0],point[0]);
		curvepoint_fp_double(rop[1],point[1]);		
	}
	else
	{
		curvepoint_fp_add_vartime(rop[0],point[0],b.point[0]);
		curvepoint_fp_add_vartime(rop[1],point[1],b.point[1]);
	}
	return rop;
}


Bipoint<twistpoint_fp2_t> Bipoint<twistpoint_fp2_t>::operator+(Bipoint<twistpoint_fp2_t> b)
{
	Bipoint  <twistpoint_fp2_t> rop;
	if (*this==b)
	{
		twistpoint_fp2_double(rop[0],point[0]);
		twistpoint_fp2_double(rop[1],point[1]);		
	}
	else
	{
		twistpoint_fp2_add_vartime(rop[0],point[0],b.point[0]);
		twistpoint_fp2_add_vartime(rop[1],point[1],b.point[1]);
	}
	return rop;
}

bool Bipoint<curvepoint_fp_t>::operator==(Bipoint<curvepoint_fp_t> b)
{
	bool rop;

	
	if(fpe_iseq(point[0]->m_x,b[0]->m_x) && fpe_iseq(point[0]->m_y,b[0]->m_y) && fpe_iseq(point[0]->m_z,b[0]->m_z) && fpe_iseq(point[1]->m_x,b[1]->m_x) && fpe_iseq(point[1]->m_y,b[1]->m_y) && fpe_iseq(point[1]->m_z,b[1]->m_z)) 
	{
		rop=true;
	}
	else
	{
		rop=false;
	}
	return rop;
}


bool Bipoint<twistpoint_fp2_t>::operator==(Bipoint<twistpoint_fp2_t> b)
{
	bool rop;

	
	if(fp2e_iseq(point[0]->m_x,b[0]->m_x) && fp2e_iseq(point[0]->m_y,b[0]->m_y) && fp2e_iseq(point[0]->m_z,b[0]->m_z) && fp2e_iseq(point[1]->m_x,b[1]->m_x) && fp2e_iseq(point[1]->m_y,b[1]->m_y) && fp2e_iseq(point[1]->m_z,b[1]->m_z)) 
	{
		rop=true;
	}
	else
	{
		rop=false;
	}
	return rop;
}

void Bipoint<curvepoint_fp_t>::makeaffine()
{
	curvepoint_fp_makeaffine(point[0]);
	curvepoint_fp_makeaffine(point[1]);
}

void Bipoint<twistpoint_fp2_t>::makeaffine()
{
	twistpoint_fp2_makeaffine(point[0]);
	twistpoint_fp2_makeaffine(point[1]);
}

void Bipoint<twistpoint_fp2_t>::scalarmult_vartime(Bipoint<twistpoint_fp2_t> op, scalar_t s)
{
	twistpoint_fp2_t a,b;
	twistpoint_fp2_scalarmult_vartime(a, op[0],s);
	twistpoint_fp2_scalarmult_vartime(b, op[1],s);
	set_point(a,0);
	set_point(b,1);	
}

void Bipoint<curvepoint_fp_t>::scalarmult_vartime(Bipoint<curvepoint_fp_t> op, scalar_t s) 
//pb cannot call member function blabla without object --> sol Bipoint<curvepoint_fp_t>::
{
	curvepoint_fp_t a,b;
	//cout << RED << "affichage de op[0] " << RESET << endl;
	//curvepoint_fp_print(stdout,op[0]);
	//jump;
	//cout << RED "affichage de op[1] " << RESET << endl;
	//curvepoint_fp_print(stdout,op[1]);
	//JUMP;
	curvepoint_fp_scalarmult_vartime(a, op[0],s);
	curvepoint_fp_scalarmult_vartime(b, op[1],s);
	//cout << RED << "affichage du curvepoint u1[0] " << RESET << endl;
	//curvepoint_fp_print(stdout,a);
	//jump;
	//cout << RED "affichage du curvepoint u1[1]" << RESET << endl;
	//curvepoint_fp_print(stdout,b);
	//JUMP;
	set_point(a,0);
	set_point(b,1);
}

curvepoint_fp_t& Bipoint<curvepoint_fp_t>::operator[](int n)
{
	return point[n];
}

twistpoint_fp2_t& Bipoint<twistpoint_fp2_t>::operator[](int n)
{
	return point[n];
}


Bipoint<curvepoint_fp_t>::Bipoint()
{
	curvepoint_fp_setneutral(point[0]);
	curvepoint_fp_setneutral(point[1]);
}

Bipoint<twistpoint_fp2_t>::Bipoint()
{
	twistpoint_fp2_setneutral(point[0]);
	twistpoint_fp2_setneutral(point[1]);
}

Bipoint<curvepoint_fp_t>::Bipoint(curvepoint_fp_t p1,curvepoint_fp_t p2)
{
	curvepoint_fp_set(point[0],p1);
	curvepoint_fp_set(point[1],p2);
}

Bipoint<twistpoint_fp2_t>::Bipoint(twistpoint_fp2_t p1,twistpoint_fp2_t p2)
{
	twistpoint_fp2_set(point[0],p1);
	twistpoint_fp2_set(point[1],p2);
}

void Bipoint<curvepoint_fp_t>::set_point(curvepoint_fp_t element,int numpoint)
{
	curvepoint_fp_set(point[numpoint],element);
}

void Bipoint<twistpoint_fp2_t>::set_point(twistpoint_fp2_t element,int numpoint)
{
	twistpoint_fp2_set(point[numpoint],element);
}

void Bipoint<fpe_t>::set_coordonnee(fpe_t element,int numcoord)
{
	fpe_set(coordonnee[numcoord],element);
}

void Bipoint<fp2e_t>::set_coordonnee(fp2e_t element,int numcoord)
{
	fp2e_set(coordonnee[numcoord],element);
}

void Bipoint<curvepoint_fp_t>::print(int numpoint) const
{
	curvepoint_fp_print(stdout,point[numpoint]);
	JUMP;
}

void Bipoint<twistpoint_fp2_t>::print(int numpoint) const
{
	twistpoint_fp2_print(stdout,point[numpoint]);
	JUMP;
}

void Bipoint<fpe_t>::get_coordonnee(int numcoord) const
{
	fpe_print(stdout,coordonnee[numcoord]);
}

void Bipoint<fp2e_t>::get_coordonnee(int numcoord) const
{
	fp2e_print(stdout,coordonnee[numcoord]);
}
