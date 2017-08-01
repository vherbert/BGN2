#include "bgn.hpp"



int main(int argc, char *argv[])
{
//signature;	
/** début chrono **/
    using Clock = std::chrono::high_resolution_clock;
    using std::chrono::nanoseconds;
    using std::chrono::duration_cast;

    auto temps_initial = Clock::now();
   	double temps_en_nanosecondes;    
	double temps_en_secondes, temps_en_secondes_par_symbole;
	
	//clock_t temps_initial, temps_final;  
	//    
	//temps_initial = clock (); /* initial time in microseconds */
	
		
/** gengetopt **/


	gengetopt_args_info args_info;
    if (cmdline_parser(argc, argv, &args_info) != 0)
	{
		exit(1) ;
	}

/** message clair **/	
	
	
	string message_clair;
	//if (args_info.subtitle_source_arg==DEV)
	if(!args_info.subtitle_given)
	{
		message_clair="~{|`}azertyQWERTY&é,;:!asdfasdfasdfasdfsadfasdfasdfasdfasdfasdfasdfasdfasgfdyeryh bfht gsSLRJslrkgjDLGJDALKDJ:SILFJOIElkdefgwlkerjgtfeswrjg;wrtjhlksdfmhtls/fdkmjhtsltjhmlsrtjhlsfmtjdlj.dtjhmldtjhmmmtlkmtdrlhkmmmmmmhyjldtmrh.lmd.ltlsgrtmglhksdr.tmhdtlkhmmdkrthmlkdrtmld.rkhk.rthlkdrtmhd.rktmh.ldrktmhkr.mdth.lrij"; //clair défini par le dév
		//message_clair="3\/-7rU$7"; // langage leet avec des caractères spéciaux
	
	}
	else 
	{
		message_clair=args_info.subtitle_arg;
		//cout << "Entrez un message : " << endl;
		//cin >> message_clair; //clair défini par l'utilisateur
	}
	{
		
	}


	int nombre_symboles=message_clair.length();
	if (args_info.circuit_arg==MINMAJ  || args_info.circuit_arg==MINMAJ2 || args_info.circuit_arg==MINMAJ3 || args_info.circuit_arg==CHIFFREMENT  || args_info.circuit_arg==TIME) 
	{
		zout(nombre_symboles,message_clair);
	}
	string evalue_dechiffre;
	evalue_dechiffre.resize(nombre_symboles);
	
	

	//extern PublicKey public_key;
	//debug(clef privée globale pour debug - à modifier après);
	PrivateKey private_key;
	keygen(public_key, private_key);
	//private_key.get();
	//public_key.get();



/** génération d'une graine aléatoire **/

	unsigned int graine_urandom;	
	FILE * urandom;
    urandom = fopen ("/dev/urandom","r");
	if (urandom == NULL)
	{
		fprintf(stderr, "Could not open device file /dev/urandom");
		exit(1);
	}	
	fread(&graine_urandom,sizeof(unsigned int),1,urandom);// la graine sert pour creer indirectement un nombre aléatoire via un PRNG
	// voir test_encrypt.cpp pour la génération d'aléa directement à partir d'urandom
	fclose (urandom);
	srand(graine_urandom);

/** chiffrement message clair **/

	if (args_info.circuit_arg==MINMAJ || args_info.circuit_arg==MINMAJ2|| args_info.circuit_arg==MINMAJ3 || args_info.circuit_arg==CHIFFREMENT) 
	{
		//	omp_set_num_threads(1);	    //version séquentielle  
		omp_set_num_threads(omp_get_max_threads());
		#pragma omp parallel 
		{
			#pragma omp single	//sinon l'instruction est executée par chaque thread
			{
				zout(omp_get_num_threads()); //le nombre de thread n'est modifié que dans la section parallel
			}
				
			#pragma omp for		
				for (unsigned int i=0; i<message_clair.length();i++) //pour chaque lettre
				{
					if (args_info.circuit_arg==MINMAJ)
					{
						circuit_minmaj(evalue_dechiffre[i],message_clair[i],public_key, private_key);	
					}
					if (args_info.circuit_arg==MINMAJ2)
					{
						circuit_minmaj2(evalue_dechiffre[i],message_clair[i],public_key, private_key);	
					}
					if (args_info.circuit_arg==MINMAJ3)
					{
						circuit_minmaj3(evalue_dechiffre[i],message_clair[i],public_key, private_key);	
					}
					if (args_info.circuit_arg==CHIFFREMENT)
					{
						circuit_chiffrement(message_clair[i],public_key, private_key);

					}			
			}
		}
		omp_set_num_threads(1);	
		if (args_info.circuit_arg==MINMAJ|| args_info.circuit_arg==MINMAJ2 || args_info.circuit_arg==MINMAJ3)
		{
			zout(evalue_dechiffre);
		}
		else
		{
			cout << RESET <<"vérification du chiffrement bit à bit et du déchiffrement du message en mode CURVE et TWIST" << endl;
		}		
	}
	if (args_info.circuit_arg==DEMO)
	{
		circuit_demo(evalue_dechiffre[0],message_clair[rand() % nombre_symboles],public_key, private_key);	
	    cout << "Ce mode est verbeux. Utilisez le mode minmaj pour traiter plus d'un caractère." << endl; 
	}	
	if (args_info.circuit_arg==SIZE)
	{
		circuit_size(public_key,private_key);
	}		
	if (args_info.circuit_arg==TIME)
	{
		circuit_time(message_clair,public_key, private_key);
	}		
	if (args_info.circuit_arg==ADDITIONL1)
	{
		circuit_additionL1(public_key, private_key);
	}	
	if (args_info.circuit_arg==ADDITIONL2)
	{
		circuit_additionL2(public_key, private_key);
	}					
	if (args_info.circuit_arg==ADDITIONL3)
	{
		circuit_additionL3(public_key, private_key);
	}		
	if (args_info.circuit_arg==ADDITIONL4)
	{
		circuit_additionL4(public_key, private_key);
	}		
	if (args_info.circuit_arg==MULTIPLICATIONL1)
	{
		circuit_multiplicationL1(public_key, private_key);
	}	
	if (args_info.circuit_arg==MULTIPLICATIONL1L2)
	{
		circuit_multiplicationL1L2(public_key, private_key);
	}					
	if (args_info.circuit_arg==MULTIPLICATIONL2)
	{
		circuit_multiplicationL2(public_key, private_key);
	}		
	if (args_info.circuit_arg==IP)
	{
		circuit_ip(public_key, private_key);
	}	
	if (args_info.circuit_arg==SCALAR_PRODUCT)
	{
		circuit_scalar_product(public_key, private_key);
	}		
	if (args_info.circuit_arg==TIME2)
	{
		circuit_time2(public_key, private_key);
	}	
/** fin chrono **/
	//temps_final = clock (); /* final time in microseconds */
	//temps_en_secondes = (temps_final - temps_initial) * 1e-6; /* total time in seconds */ 
	////cout << BLUE << "running time = " << temps_en_secondes  << " sec" << RESET << endl;
	//zout(temps_en_secondes) ;
	//if (args_info.circuit_arg==MINMAJ  || args_info.circuit_arg==MINMAJ2 || args_info.circuit_arg==MINMAJ3|| args_info.circuit_arg==CHIFFREMENT) 
	//{
		//temps_en_secondes_par_symbole=temps_en_secondes/nombre_symboles;
		//zout(temps_en_secondes_par_symbole);
	//}
	
	auto temps_final = Clock::now();
	temps_en_nanosecondes = duration_cast<nanoseconds>(temps_final-temps_initial).count(); /* total time in nanoseconds */ 
	temps_en_secondes= temps_en_nanosecondes*1e-9; //on pourrait passer directement en secondes avec chrono mais on perdrait de la précision avec leurs arrondis
	if (!args_info.circuit_arg==TIME)
	{
		zout(temps_en_secondes);
	}
	if (args_info.circuit_arg==MINMAJ  || args_info.circuit_arg==MINMAJ2 || args_info.circuit_arg==MINMAJ3|| args_info.circuit_arg==CHIFFREMENT) 
	{
		temps_en_secondes_par_symbole=temps_en_secondes/nombre_symboles;
		zout(temps_en_secondes_par_symbole);
	}
		
	return EXIT_SUCCESS;
}



/** chiffrement **/

	//cout << YELLOW << "Encryption" << RESET << endl;

	////mesurer le temps
	//temps_final = clock (); /* final time in microseconds */
	//temps_en_secondes = (temps_final - temps_initial) * 1e-6; 			/* total time in seconds */ 
	//zout(temps_en_secondes) ;
	//temps_initial = temps_final;
/** évaluation **/

	//cout << YELLOW << "Homomorphic Evaluation" << RESET << endl;

	////mesurer le temps
	//temps_final = clock (); /* final time in microseconds */
	//temps_en_secondes = (temps_final - temps_initial) * 1e-6; 			/* total time in seconds */ 
	//zout(temps_en_secondes) ;
	//temps_initial = temps_final;
	
/** déchiffrement **/

	//cout << YELLOW << "Decryption" << RESET << endl;

	////mesurer le temps
	//temps_final = clock (); /* final time in microseconds */
	//temps_en_secondes = (temps_final - temps_initial) * 1e-6; 			/* total time in seconds */ 
	//zout(temps_en_secondes) ;
	//temps_initial = temps_final;

