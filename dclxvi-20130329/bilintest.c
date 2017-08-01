// g++  -lgmp -lgmpxx -I ../dclxvi-20130329 -I ../update -o ../bin/bilintest ../dclxvi-20130329/bilintest.c  ../dclxvi-20130329/fpe.c ../dclxvi-20130329/fp2e.c ../dclxvi-20130329/curvepoint_fp.c ../dclxvi-20130329/twistpoint_fp2.c  ../dclxvi-20130329/scalar.c ../dclxvi-20130329/parameters.c ../dclxvi-20130329/mul.c ../dclxvi-20130329/mydouble.c ../update/parameters_512.c ../update/fp2e_512.c ../update/scalar_512.c ../update/complete_addition.c ../update/test_functions.cpp ../dclxvi-20130329/optate.c     ../dclxvi-20130329/fp6e.c  ../dclxvi-20130329/linefunction.c ../dclxvi-20130329/fp12e.c ../dclxvi-20130329/final_expo.c ../update/final_expo_512.c   -DNTESTS=10 && ../bin/bilintest

#include <stdio.h>

#include "test_functions.hpp" //ajouté pour la mise à jour vers une clef 512 bits


#include "mydouble.h" 
extern "C" {	
#include "fpe.h"
#include "fp2e.h"
#include "fp6e.h"
#include "fp12e.h"
} 
#include "curvepoint_fp.h"
#include "twistpoint_fp2.h"
#include "optate.h"
#include <unistd.h> //fonction sleep

extern const curvepoint_fp_t bn_curvegen;
extern const twistpoint_fp2_t bn_twistgen;
extern const scalar_t bn_n;

int main(int argc, char* argv[])
{
	titre(Bilintest);
	//zout(!0,!1,!456465);
	//return 0;
	fp12e_t e1, e2, e3;

	curvepoint_fp_t p1;

	twistpoint_fp2_t p2;

	scalar_t s1, s2;

	int i;
	// Test with neutral element as argument
	scalar_setrandom(s1, bn_n);
	//scalar_print(stdout, s1); 
	//exit(0);
	curvepoint_fp_set(p1, bn_curvegen);

	//curvepoint_fp_print(stdout,p1);
	//exit(0);
	twistpoint_fp2_setneutral(p2);
	fpe_isreduced(p1->m_x);
	fpe_isreduced(p1->m_y);
	//abc;
	//curvepoint_fp_print(stdout,p1);
	//scalar_print(stdout,s1);
	//where;
	curvepoint_fp_scalarmult_vartime(p1, p1, s1); //64 additions
	
	//xyz;
	curvepoint_fp_makeaffine(p1);
	optate(e1, p2, p1);
	if(!fp12e_isone(e1))
	printf("Error in optimal ate: e(infty,P) != 1\n");
	scalar_setrandom(s2, bn_n);
	curvepoint_fp_setneutral(p1);
	twistpoint_fp2_set(p2, bn_twistgen);
	fp2e_isreduced(p2->m_x);
	fp2e_isreduced(p2->m_y);

	twistpoint_fp2_scalarmult_vartime(p2, p2, s2);
	twistpoint_fp2_makeaffine(p2);
	optate(e1, p2, p1);
	if(!fp12e_isone(e1))
	printf("Error in optimal ate: e(Q,infty) != 1\n");
	
	// Bilinearity test of optimal ate Pairing:
	for(i=0;i<NTESTS;i++)
	{
		#if (NTESTS > 100)
			if(!(i%(NTESTS/100)) && i!=0) printf("Number of tests: %d\n",i);
		#else
			if(i>=0) printf("Number of tests: %d\n",i);
		#endif
		//ecris(bn_n = );
		//scalar_print(stdout,bn_n);
		scalar_setrandom(s1, bn_n);

		scalar_setrandom(s2, bn_n);
		
		
		
		
		
		//unsigned long long tab[4]={0x8ae69c5bcb039b07,	0x58549b8019d00d7b,	0x1102df67a4a9ace2,	0xc36d19fe776fac9f};
		//scalar_set_lluarray(s1,tab);
		
		//unsigned long long tab2[4]={0xad89b6fb63df1643,	0x354658972be46274,	0x4df1d15eaa4d2322,	0x10bf308f77d3d38d};
		//scalar_set_lluarray(s2,tab2);		
		
		
		//unsigned long long tab[4]={8,0,0,0};
		//unsigned long long tab2[4]={1,0,0,0};
		//scalar_set_lluarray(s1,tab);
		//scalar_set_lluarray(s2,tab2);

		curvepoint_fp_set(p1, bn_curvegen);
		twistpoint_fp2_set(p2, bn_twistgen);
		//twistpoint_fp2_print(stdout,bn_twistgen);
		fpe_isreduced(p1->m_x);
		fpe_isreduced(p1->m_y);
		fp2e_isreduced(p2->m_x);
		fp2e_isreduced(p2->m_y);
		curvepoint_fp_scalarmult_vartime(p1, p1, s1);
		curvepoint_fp_makeaffine(p1);
		twistpoint_fp2_scalarmult_vartime(p2, p2, s2);
		twistpoint_fp2_makeaffine(p2);
		//printf("s1p1 affine: ");
		//curvepoint_fp_print(stdout,p1);
		//printf("\n");
		//printf("s2p2 affine: ");
		//twistpoint_fp2_print(stdout,p2);
		//printf("\n");
		optate(e1, p2, p1);
		curvepoint_fp_set(p1, bn_curvegen);
		twistpoint_fp2_set(p2, bn_twistgen);
		fpe_isreduced(p1->m_x);
		fpe_isreduced(p1->m_y);
		fp2e_isreduced(p2->m_x);
		fp2e_isreduced(p2->m_y);
		curvepoint_fp_scalarmult_vartime(p1, p1, s2);
		curvepoint_fp_makeaffine(p1);
		twistpoint_fp2_scalarmult_vartime(p2, p2, s1);
		twistpoint_fp2_makeaffine(p2);
		//printf("s2p1 affine: ");
		//curvepoint_fp_print(stdout,p1);
		//printf("\n");
		//printf("s1p2 affine: ");
		//twistpoint_fp2_print(stdout,p2);
		//printf("\n");
		optate(e2, p2, p1);

		curvepoint_fp_set(p1, bn_curvegen);
		twistpoint_fp2_set(p2, bn_twistgen);

		optate(e3, p2, p1);

		fp12e_pow_vartime(e3, e3, s1);
		fp12e_pow_vartime(e3, e3, s2);

		if(!fp12e_iseq(e1,e2))
		{
		  printf("Error in optimal ate: e1 != e2\n");
		  //printf("e1: ");
		  //fp12e_print(stdout, e1);
		  //printf("\ne2: ");
		  //fp12e_print(stdout, e2);
		  //printf("\nScalars:\n");
		  //printf("s1= ");
		  //scalar_print(stdout, s1); 
		  //printf("\ns2= ");
		  //scalar_print(stdout, s2); 
		  //printf("\n");
		  }
		else if(!fp12e_iseq(e2,e3))
		{
		  printf("Error in optimal ate: e2 != e3\n");
		  printf("e2: ");
		  fp12e_print(stdout, e2);
		  printf("\ne3: ");
		  fp12e_print(stdout, e3);
		  printf("\nScalars:\n");
		  printf("s1= ");
		  scalar_print(stdout, s1); 
		  printf("\ns2= ");
		  scalar_print(stdout, s2); 
		  printf("\n");
		}
		else if(fp12e_iszero(e2))
		  printf("Error: Pairing value is zero\n");
		else if(fp12e_isone(e2))
		  printf("Warning: Pairing value is one\n");
		}
		return 0;
}
