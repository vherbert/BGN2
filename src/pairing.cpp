#include "pairing.hpp"

void OptimalAte(fp12e_t rop, const curvepoint_fp_t op1,const twistpoint_fp2_t op2)
{
	optate(rop, op2, op1);
}

Quadripoint pairing(Bipoint<curvepoint_fp_t> op1,Bipoint<twistpoint_fp2_t> op2)
{
	Quadripoint rop;
	OptimalAte(rop[0],op1[0],op2[0]);
	OptimalAte(rop[1],op1[0],op2[1]);
	OptimalAte(rop[2],op1[1],op2[0]);
	OptimalAte(rop[3],op1[1],op2[1]);
	return rop;
}
