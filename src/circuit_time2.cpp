#include "circuit_time2.hpp"


void circuit_time2(PublicKey public_key, PrivateKey private_key)
{
	zout(omp_get_num_procs(),omp_get_max_threads());

    using Clock = chrono::high_resolution_clock;
    using chrono::nanoseconds;
    using chrono::duration_cast;

   	double temps_en_nanosecondes;    
	double temps_en_secondes, temps_en_millisecondes;
	
	unsigned long graine_faible_time;
	graine_faible_time = time(NULL); 
	srand((unsigned int)graine_faible_time); //cast explicite pour être propre
			
	int nombre_instances=50;
	F2 clair;
	BitEvalL1<curvepoint_fp_t> chiffre_curve[nombre_instances], sum_curve[nombre_instances];
	BitEvalL1<twistpoint_fp2_t> chiffre_twist[nombre_instances], sum_twist[nombre_instances];
	BitEvalL2 chiffre_L2[nombre_instances], sum_L2[nombre_instances];
	BitEvalL3 chiffre_L3[nombre_instances], sum_L3[nombre_instances];
	BitEvalL4 chiffre_L4[nombre_instances], sum_L4[nombre_instances];
	

	
	
	/**encryption mode curve **/
	green(encryption mode curve);
	auto temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				//clair=rand()%2;
				chiffrement(chiffre_curve[i],clair,public_key);
			}
	}
	auto temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	

	/**encryption mode twist **/
	
	green(encryption mode twist);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				chiffrement(chiffre_twist[i],clair,public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	


	/**multiplication L1 **/
	
	yellow(multiplication L1);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				chiffre_L2[i]=multiplicationL1(chiffre_curve[i],chiffre_twist[i],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
		
	/**multiplication L1L2 curve **/
	
	yellow(multiplication L1L2);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				chiffre_L3[i]=multiplicationL1L2(chiffre_curve[i],chiffre_L2[i],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";		
	
	/**multiplication L2 **/
	
	yellow(multiplication L2);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				chiffre_L4[i]=multiplicationL2(chiffre_L2[i],chiffre_L2[i],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	


	
	/**addition L1 mode curve **/
	green(addition L1 mode curve);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				//clair=rand()%2;
				sum_curve[i]=additionL1(chiffre_curve[i],chiffre_curve[i+1],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	
	/**addition L1 mode twist **/
	green(addition L1 mode twist);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				//clair=rand()%2;
				sum_twist[i]=additionL1(chiffre_twist[i],chiffre_twist[i+1],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";		
	
	
	/**addition L2 **/
	green(addition L2);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				//clair=rand()%2;
				sum_L2[i]=additionL2(chiffre_L2[i],chiffre_L2[i+1],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	
	/**addition L3 **/
	green(addition of two L3);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				//clair=rand()%2;
				sum_L3[i]=additionL3(chiffre_L3[i],chiffre_L3[i+1],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";		
	
	/**addition L4 **/
	green(addition of two L4);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				//clair=rand()%2;
				sum_L4[i]=additionL4(chiffre_L4[i],chiffre_L4[i+1],public_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";		
	
	
		
	/**decryption L1 mode curve **/
	
	green(decryption mode curve);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				dechiffrement(clair,chiffre_curve[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	
	/**decryption L1 mode twist **/
	
	green(decryption mode twist);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				dechiffrement(clair,chiffre_twist[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	
	/**decryption L2 **/
	
	red(decryption L2);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				dechiffrementL2(clair,chiffre_L2[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";
	
	
	/**decryption L3 **/
	
	red(decryption L3);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				dechiffrementL3(clair,chiffre_L3[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";
	
	
	/**decryption L4 **/
	
	red(decryption L4);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				dechiffrementL4(clair,chiffre_L4[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	

	
	
	/**decryption sum L3 **/
	
	red(decryption sum of two L3);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				dechiffrementL3(clair,sum_L3[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";
	
	
	/**decryption sum L4 **/
	
	red(decryption sum of two L4);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances-1;i++)
			{
				dechiffrementL4(clair,sum_L4[i],private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/(nombre_instances-1);
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";	
	
	
	/**keygen **/
	green(keygen);
	temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	clair=rand()%2;
	
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_instances;i++)
			{
				keygen(public_key, private_key);
			}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
	cout << setprecision(3) << temps_en_millisecondes << " ms\n";			
			

	/**precomputation L2 **/
        
        red(precompute L2);
        temps_initial = Clock::now();
        omp_set_num_threads(omp_get_max_threads());        
#pragma omp parallel 
        {
#pragma omp for
	  for (int i=0; i<nombre_instances;i++)
	    {
	      Quadripoint base_log = private_key.pi_T(pairing(public_key.get_bipoint_curve_groupelt(),public_key.get_bipoint_twist_groupelt()));  //pi_T(e(u,v))
	    }
        }
        temps_final = Clock::now();
        temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
        temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
	//zout(temps_en_secondes);
        temps_en_millisecondes=temps_en_nanosecondes*1e-6/nombre_instances;
        cout << setprecision(3) << temps_en_millisecondes << " ms\n";
}
