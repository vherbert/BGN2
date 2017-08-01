#include "bgn.hpp"

int main()
{	
	//NBTESTS = 
	//100000 (main @17) 10^5 tests
	//temps_en_secondes = 
	//126.74 (main @31) 2 minutes

	
	/** début chrono **/

	clock_t temps_initial, temps_final;  
	double temps_en_secondes;    
	temps_initial = clock (); /* initial time in microseconds */
	
	
	
	fpe_t i_1,j_1,k_1,l_1;
	
	//fpe_t temp;
	//fpe_setone(temp);
	//fpe_print(stdout,temp); // 1.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000,   0.000000
	
	
	zout(NBTESTS);
	for (int num_test=0; num_test<NBTESTS;num_test++)	
	{
		//zout(num_test);
		fpe_setrandom(j_1);
		fpe_setrandom(k_1);
		fpe_setrandom(l_1);
		fpe_ad_minus_bc(i_1,j_1,k_1,l_1); // i1*l1 - j1*k1=1  on calcule i1 = (j1*k1 + 1)*l1^(-1)
	}

	/** fin chrono **/
	temps_final = clock (); /* final time in microseconds */
	temps_en_secondes = (temps_final - temps_initial) * 1e-6; /* total time in seconds */ 
	//cout << BLUE << "running time = " << temps_en_secondes  << " sec" << RESET << endl;
	zout(temps_en_secondes) ;
	return EXIT_SUCCESS;
}
