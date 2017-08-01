#include "circuit_time.hpp"


void circuit_time(string message, PublicKey public_key, PrivateKey private_key)
{
	zout(omp_get_num_procs(),omp_get_max_threads());

	int nombre_symboles = message.length();
    using Clock = std::chrono::high_resolution_clock;
    using std::chrono::nanoseconds;
    using std::chrono::duration_cast;

   	double temps_en_nanosecondes;    
	double temps_en_secondes, temps_en_millisecondes_par_symbole;
	
	///circuit minmaj
	grostitre(Circuit minmaj : Sans erreur et avec précalcul et postcalcul);
	F2 clair1[nombre_symboles]={}, clair2[nombre_symboles]={},clair3[nombre_symboles]={}; // resp de n8, n9, o8 (voir rapport.pdf, page 24)
	BitEvalL1<curvepoint_fp_t> n8[nombre_symboles],n9[nombre_symboles],temp_curve[nombre_symboles], chiffre_1_curve[nombre_symboles];
	BitEvalL1<twistpoint_fp2_t> o8[nombre_symboles],temp_twist[nombre_symboles], chiffre_1_twist[nombre_symboles];
	BitEvalL2 temp_quadripoint[nombre_symboles]; // (1+n9)(1+o8)
	BitEvalL3 evalue[nombre_symboles]; 	// n8(1+n9)(1+o8)	
	//char dechiffre[nombre_symboles]={}; //GREEN
	string dechiffre;
	dechiffre.resize(nombre_symboles); // on donne explicitement la taille de la string pour faciliter l'affichage
	///précalcul, chiffrement
	ecris(précalcul et chiffrement);
    auto temps_initial = Clock::now();
	omp_set_num_threads(omp_get_max_threads());	
	//	omp_set_num_threads(1);	    //version séquentielle  
	#pragma omp parallel 
	{    
		#pragma omp single	//sinon l'instruction est executée par chaque thread
		{
		zout(omp_get_num_threads()); //le nombre de thread n'est modifié que dans la section parallel
		}
		#pragma omp for
			for (int i=0; i<nombre_symboles;i++)
			{
				precomputation(clair1[i], clair2[i], clair3[i], message[i]);
				chiffrement(n8[i],clair1[i],public_key);	
				chiffrement(n9[i],clair2[i],public_key);	
				chiffrement(o8[i],clair3[i],public_key);
			}
		
	}
  
	auto temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);
	
	///évaluation homomorphique
	ecris(évaluation homomorphique);
    temps_initial = Clock::now();
	#pragma omp parallel 
	{    
		#pragma omp for
		for (int i=0; i<nombre_symboles;i++)
		{
			chiffrement(chiffre_1_curve[i],1, public_key);
			chiffrement(chiffre_1_twist[i],1, public_key);
			temp_curve[i] = additionL1(chiffre_1_curve[i],n9[i],public_key);	//NB il faut rajouter CURVE pour passer de BitChiffre à BitEvalL1, la diff entre les deux, la taille mémoire
			temp_twist[i] = additionL1(chiffre_1_twist[i],o8[i],public_key);
			temp_quadripoint[i] = multiplicationL1(temp_curve[i],temp_twist[i],public_key);	
			evalue[i] = multiplicationL1L2(n8[i],temp_quadripoint[i],public_key);	
		}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);	
 
	/// déchiffrement et poscalcul
	ecris(dechiffrement et postcalcul);
	//int max=omp_get_max_threads();
	//for (int nb_threads=1;nb_threads<=max;nb_threads++)
	//{
		//omp_set_num_threads(nb_threads);
	temps_initial = Clock::now();
	#pragma omp parallel 
	{
		#pragma omp for
			for (int i=0; i<nombre_symboles;i++)
			{
				postcomputation(dechiffre[i], message[i], evalue[i], private_key);	
			}
	}

	temps_final = Clock::now();

	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(dechiffre,temps_en_millisecondes_par_symbole);
	//}
	

	
	///circuit minmaj2
	grostitre(Circuit minmaj2 : avec erreur sur les caractères ~{|`});	
	BitEvalL1<twistpoint_fp2_t> m6[nombre_symboles];
	BitEvalL1<curvepoint_fp_t> m7[nombre_symboles],m8[nombre_symboles];
	BitEvalL2 chiffre_L2_1[nombre_symboles];	
	BitEvalL3 temp_L3[nombre_symboles],  chiffre_L3_1[nombre_symboles]; 	// m6m7(1+m8)		
	F2 IS_LOWER_CASE[nombre_symboles]={};
	
	///chiffrement
	ecris(chiffrement);
    temps_initial = Clock::now();

	#pragma omp parallel 
	{    
		#pragma omp single	//sinon l'instruction est executée par chaque thread
		{
		zout(omp_get_num_threads()); //le nombre de thread n'est modifié que dans la section parallel
		}
		#pragma omp for
		for (int i=0; i<nombre_symboles;i++)
		{		
			clair1[i]=bitset<sizeof(int)*CHAR_BIT>(message[i])[5] ; 
			clair2[i]=bitset<sizeof(int)*CHAR_BIT>(message[i])[6] ;
			clair3[i]=bitset<sizeof(int)*CHAR_BIT>(message[i])[7] ; 
			chiffrement(m6[i],clair1[i],public_key);	
			chiffrement(m7[i],clair2[i],public_key);	
			chiffrement(m8[i],clair3[i],public_key);
		}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);	
	
	
	///évaluation homomorphique
	ecris(évaluation homomorphique);
    temps_initial = Clock::now();
	#pragma omp parallel 
	{    
		#pragma omp for
		for (int i=0; i<nombre_symboles;i++)
		{	
			chiffrement(chiffre_1_curve[i],1, public_key);
			chiffrement(chiffre_1_twist[i], 1, public_key);
			temp_curve[i] = additionL1(chiffre_1_curve[i],m8[i],public_key);	//calcul 1+m8
			temp_quadripoint[i] = multiplicationL1(temp_curve[i],m6[i],public_key);
			chiffre_L2_1[i] = multiplicationL1(chiffre_1_curve[i],chiffre_1_twist[i],public_key);
			chiffre_L3_1[i]=multiplicationL1L2(chiffre_1_curve[i],chiffre_L2_1[i],public_key);
			temp_L3[i] = multiplicationL1L2(m7[i],temp_quadripoint[i],public_key);	
			evalue[i]=additionL3(temp_L3[i],chiffre_L3_1[i],public_key);
		}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
    //zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);	
 
	/// déchiffrement 
	ecris(dechiffrement);
	dechiffre.clear();
	dechiffre.resize(nombre_symboles); 
    temps_initial = Clock::now();
	#pragma omp parallel 
	{    
		#pragma omp for	
		for (int i=0; i<nombre_symboles;i++)
		{		
			dechiffrementL3(IS_LOWER_CASE[i],evalue[i],private_key);
			if (IS_LOWER_CASE[i] == 0)
			{
				//cout << symbole << " est sensé être une minuscule!" << endl;
				dechiffre[i]=char(message[i]-32);
			}
			else
			{
				dechiffre[i]=char(message[i]);	
			}
			//cout << dechiffre[i] << flush;
		}
	}
	jump;
	zout(dechiffre);
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
	//zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);
	
	
	
	
	
	///circuit minmaj3
	grostitre(Circuit minmaj3 : avec erreur sur les caractères ~{|`} et avec postcalcul);	
	
	
	///chiffrement
	ecris(chiffrement);

	cout << "Circuit de chiffrement identique à circuit minmaj2" << endl;
	
	///évaluation homomorphique
	ecris(évaluation homomorphique);
    temps_initial = Clock::now();
	#pragma omp parallel 
	{    
		#pragma omp for
		for (int i=0; i<nombre_symboles;i++)
		{		
			chiffrement(chiffre_1_curve[i],1, public_key);
			temp_curve[i] = additionL1(chiffre_1_curve[i],m8[i],public_key);	//calcul 1+m8	
			temp_quadripoint[i] = multiplicationL1(temp_curve[i],m6[i],public_key);
			evalue[i] = multiplicationL1L2(m7[i],temp_quadripoint[i],public_key);	
		}
	}
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
	//zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);
	
	
	
	/// déchiffrement 
	ecris(dechiffrement);
	dechiffre.clear();
	dechiffre.resize(nombre_symboles); 
	temps_initial = Clock::now();
	#pragma omp parallel 
	{    
		#pragma omp for	
		for (int i=0; i<nombre_symboles;i++)
		{		
			postcomputation(dechiffre[i], message[i], evalue[i], private_key);
		}	
	}
	jump;
	zout(dechiffre);
	temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
	//zout(temps_en_secondes);
	temps_en_millisecondes_par_symbole=temps_en_nanosecondes*1e-6/nombre_symboles;
	zout(temps_en_millisecondes_par_symbole);	
	
	
		
}
