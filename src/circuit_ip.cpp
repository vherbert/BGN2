#include "circuit_ip.hpp"

void circuit_ip(PublicKey public_key, PrivateKey private_key)
{
	ecris(original server);
	/** définition du plaintext clair **/
	
	
	/** adresses ipv4s en clair **/
	unsigned int adress_size=4;
	vector<unsigned char> original_server = {10,0,1,10}; 
	vector<unsigned char> cdn1 = {10,0,1,10};
	vector<unsigned char> cdn2 = {10,1,1,10};
	vector<unsigned char> cdn3 = {10,2,1,10};
	vector<unsigned char> cdn4 = {10,3,1,10};
	vector<unsigned char> receiver = {100,0,1,10};
	vector<unsigned char> null={0,0,0,0};
	
	
	vector<unsigned char> aes_key = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
	vector<unsigned char> offset={0}; //obligé de mettre les {} avec vector contrairement à unsigned char
	
	vector<unsigned char> original_server_addr,original_server_dest,cdn1_addr,cdn1_source,cdn1_dest,cdn2_addr,cdn2_source,cdn2_dest,cdn3_addr,cdn3_source,cdn3_dest,cdn4_addr,cdn4_source,cdn4_dest;
	
	original_server_addr=original_server;
	original_server_dest=cdn1; 
	cdn1_addr=null; 
	cdn1_source=null; 
	cdn1_dest=null; 	
	cdn2_addr=null; 
	cdn2_source=null; 
	cdn2_dest=null; 	
	cdn3_addr=null; 
	cdn3_source=null; 
	cdn3_dest=null; 	
	cdn4_addr=null; 
	cdn4_source=null; 
	cdn4_dest=null; 	
	
	vector<unsigned char> plaintext;
	plaintext.reserve(aes_key.size()+offset.size()+original_server_addr.size()+original_server_dest.size()+cdn1_addr.size()+cdn1_source.size()+cdn1_dest.size()+cdn2_addr.size()+cdn2_source.size()+cdn2_dest.size()+cdn3_addr.size()+cdn3_source.size()+cdn3_dest.size()+cdn4_addr.size()+cdn4_source.size()+cdn4_dest.size());	
	plaintext.insert(plaintext.end(), aes_key.begin(), aes_key.end());
	plaintext.insert(plaintext.end(), offset.begin(), offset.end());
	plaintext.insert(plaintext.end(), original_server_addr.begin(), original_server_addr.end());
	plaintext.insert(plaintext.end(), original_server_dest.begin(), original_server_dest.end());
	plaintext.insert(plaintext.end(), cdn1_addr.begin(), cdn1_addr.end());
	plaintext.insert(plaintext.end(), cdn1_source.begin(), cdn1_source.end());
	plaintext.insert(plaintext.end(), cdn1_dest.begin(), cdn1_dest.end());
	plaintext.insert(plaintext.end(), cdn2_addr.begin(), cdn2_addr.end());
	plaintext.insert(plaintext.end(), cdn2_source.begin(), cdn2_source.end());
	plaintext.insert(plaintext.end(), cdn2_dest.begin(), cdn2_dest.end());	
	plaintext.insert(plaintext.end(), cdn3_addr.begin(), cdn3_addr.end());
	plaintext.insert(plaintext.end(), cdn3_source.begin(), cdn3_source.end());
	plaintext.insert(plaintext.end(), cdn3_dest.begin(), cdn3_dest.end());	
	plaintext.insert(plaintext.end(), cdn4_addr.begin(), cdn4_addr.end());
	plaintext.insert(plaintext.end(), cdn4_source.begin(), cdn4_source.end());
	plaintext.insert(plaintext.end(), cdn4_dest.begin(), cdn4_dest.end());
	zout(plaintext.size());
	
	BitEvalL1<curvepoint_fp_t>  bit_chiffre_curve[plaintext.size()*CHAR_BIT], chiffre_poids_faible_offset_curve, chiffre_poids_fort_offset_curve;
	BitEvalL1<twistpoint_fp2_t>  bit_chiffre_twist, chiffre_poids_faible_offset_twist, chiffre_poids_fort_offset_twist;
	F2 bit_clair=0, poids_faible_offset=0, poids_fort_offset=0;
	
	//mode curve
	for (unsigned int i=0; i<plaintext.size();i++)
	{
		printf("%u\t",plaintext[i]); //affichage des unsigned char avec printf, pas avec cout qui affiche les caractères
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(plaintext[i])[j] ;
			chiffrement(bit_chiffre_curve[i*CHAR_BIT+j],bit_clair,public_key); //on chiffre le plaintext bit à bit en mode curve
		}
	}
	jump;
	chiffre_poids_faible_offset_curve=bit_chiffre_curve[128];//16*8+0=128
	chiffre_poids_fort_offset_curve=bit_chiffre_curve[129];

	//mode twist
	bit_clair=bitset<CHAR_BIT>(plaintext[16])[0] ; //en plus, on chiffre les bit de l'offset (les 16 premiers unsigned char, c'est la clef AES) en mode twist
	chiffrement(chiffre_poids_faible_offset_twist,bit_clair,public_key);	
	bit_clair=bitset<CHAR_BIT>(plaintext[16])[1] ; 
	chiffrement(chiffre_poids_fort_offset_twist,bit_clair,public_key);	

	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_curve,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_curve,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_twist,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_twist,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	
	
	//serveur 1
	ecris(CDN 1);
	BitEvalL1<curvepoint_fp_t>  chiffre_IP1[12*adress_size*CHAR_BIT]; //12 IPs =  4 blocs de 3 IPs en bits 12*4*8=384 bits
	BitEvalL2 is_zero, is_one, is_two, is_three;
	BitEvalL1<curvepoint_fp_t> bit_chiffre_curve_0, bit_chiffre_curve_1;
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_twist_0, bit_chiffre_twist_1;
	chiffrement(bit_chiffre_curve_0,0,public_key);
	chiffrement(bit_chiffre_twist_0,0,public_key);
	chiffrement(bit_chiffre_curve_1,1,public_key);
	chiffrement(bit_chiffre_twist_1,1,public_key);
	
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn1[i])[j] ;
			chiffrement(chiffre_IP1[i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			//NB au lieu de cela, dans les faits, il faudra chiffrer 3 IPs concaténer 3*(nb CDN -1) IP à 0.0.0.0 puis permuter  ce chiffré par bloc de 3 IPs
			//zout(i*CHAR_BIT+j);
		}
	}	
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(original_server[i])[j] ;
			chiffrement(chiffre_IP1[32+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			//zout(32+i*CHAR_BIT+j);
		}
	}		
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn2[i])[j] ;
			chiffrement(chiffre_IP1[64+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			//zout(64+i*CHAR_BIT+j);
			
		}
	}		
	for (unsigned int i=0; i<9*CHAR_BIT*adress_size;i++) //on chiffre les 9 IP restantes
	{
		chiffrement(chiffre_IP1[96+i],0,public_key); //on chiffre l'IP bit à bit en mode curve
		//zout(96+i);
	}	
		
	//incrémentation du offset (2 bits) modulo 4
	
	chiffre_poids_fort_offset_curve=additionL1(chiffre_poids_fort_offset_curve,chiffre_poids_faible_offset_curve,public_key);
	chiffre_poids_fort_offset_twist=additionL1(chiffre_poids_fort_offset_twist,chiffre_poids_faible_offset_twist,public_key);	//poids fort twist	
	chiffre_poids_faible_offset_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1,public_key); //poids faible curve
	//chiffre_poids_faible_offset_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1,public_key);


	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_curve,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_curve,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_twist,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_twist,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
		
	//4 tests d'égalité --> x1,x2,x3,x4
	
	BitEvalL1<curvepoint_fp_t> faible_plus_zero_curve, faible_plus_one_curve, fort_plus_zero_curve, fort_plus_one_curve;
	BitEvalL1<twistpoint_fp2_t> faible_plus_zero_twist, faible_plus_one_twist, fort_plus_zero_twist, fort_plus_one_twist;
	faible_plus_zero_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_0, public_key);
	faible_plus_one_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1, public_key);
	//fort_plus_zero_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_0, public_key);
	//fort_plus_one_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_1, public_key);
	//faible_plus_zero_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_0, public_key);
	//faible_plus_one_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1, public_key);
	fort_plus_zero_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_0, public_key);
	fort_plus_one_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_1, public_key);	
	
	is_zero=multiplicationL1(faible_plus_one_curve,fort_plus_one_twist,public_key); // 00 +1 +1
	is_one=multiplicationL1(faible_plus_one_curve,fort_plus_zero_twist,public_key); //01 +1 +0
	is_two=multiplicationL1(faible_plus_zero_curve,fort_plus_one_twist,public_key); //10  +0 +1
	is_three=multiplicationL1(faible_plus_zero_curve,fort_plus_zero_twist,public_key); //11 +0 +0
	
	//porte conditionnelle/select sur tous les bits des IP à MAJ par le serveur 1
	// select(x1,bit de IP1,bit de null) or select (x2,bit de IP1,bit de null) or select(x3,bit de IP1,bit de null) or select (x4,bit de IP1,bit de null)
	
	cout << "Incrémentation OK, test d'égalité OK, MAJ KO. On ne peut pas réaliser qu'une seule MAJ avec le circuit. Le circuit est de profondeur 1 + nb de MAJs." << endl;
	//BitEvalL3 evalue[384];
	////si compteur=0
	//for (int i=0; i<384; i++)
	//{
		//multiplicationL1L2(,,public_key);
		//multiplicationL1L2(,,public_key);
		//evalue[i]=additionL3(,,public_key);
	//}
	////si compteur=1
	//for (int i=0; i<384; i++)
	//{
		//multiplicationL1L2(,,public_key);
		//multiplicationL1L2(,,public_key);
		//evalue[i]=additionL3(,,public_key);
	//}
	////si compteur=2
	//for (int i=0; i<384; i++)
	//{
		//multiplicationL1L2(,,public_key);
		//multiplicationL1L2(,,public_key);
		//evalue[i]=additionL3(,,public_key);
	//}
	////si compteur=3
	//for (int i=0; i<384; i++)
	//{
		//multiplicationL1L2(,,public_key);
		//multiplicationL1L2(,,public_key);
		//evalue[i]=additionL3(,,public_key);
	//}		
	
	//serveur 2
	ecris(CDN 2);
	
	BitEvalL1<curvepoint_fp_t>  chiffre_IP2[12*adress_size*CHAR_BIT];
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn2[i])[j] ;
			chiffrement(chiffre_IP2[i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			//NB au lieu de cela, dans les faits, il faudra chiffrer 3 IPs concaténer 3*(nb CDN -1) IP à 0.0.0.0 puis permuter  ce chiffré par bloc de 3 IPs
		}
	}	
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn1[i])[j] ;
			chiffrement(chiffre_IP2[32+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
		}
	}		
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn3[i])[j] ;
			chiffrement(chiffre_IP2[64+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			
		}
	}		
	for (unsigned int i=0; i<9*CHAR_BIT*adress_size;i++) //on chiffre les 9 IP restantes
	{
		chiffrement(chiffre_IP2[96+i],0,public_key); //on chiffre l'IP bit à bit en mode curve
	}		

	chiffre_poids_fort_offset_curve=additionL1(chiffre_poids_fort_offset_curve,chiffre_poids_faible_offset_curve,public_key);
	chiffre_poids_fort_offset_twist=additionL1(chiffre_poids_fort_offset_twist,chiffre_poids_faible_offset_twist,public_key);	
	chiffre_poids_faible_offset_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1,public_key);
	//chiffre_poids_faible_offset_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1,public_key);


	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_curve,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_curve,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_twist,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_twist,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	
	//4 tests d'égalité --> x1,x2,x3,x4
	
	faible_plus_zero_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_0, public_key);
	faible_plus_one_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1, public_key);
	//fort_plus_zero_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_0, public_key);
	//fort_plus_one_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_1, public_key);
	//faible_plus_zero_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_0, public_key);
	//faible_plus_one_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1, public_key);
	fort_plus_zero_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_0, public_key);
	fort_plus_one_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_1, public_key);	
	
	is_zero=multiplicationL1(faible_plus_one_curve,fort_plus_one_twist,public_key); // 00 +1 +1
	is_one=multiplicationL1(faible_plus_one_curve,fort_plus_zero_twist,public_key); //01 +1 +0
	is_two=multiplicationL1(faible_plus_zero_curve,fort_plus_one_twist,public_key); //10  +0 +1
	is_three=multiplicationL1(faible_plus_zero_curve,fort_plus_zero_twist,public_key); //11 +0 +0	
	
	
	//exit(0);	
		
	//serveur 3
	ecris(CDN 3);

	BitEvalL1<curvepoint_fp_t>  chiffre_IP3[12*adress_size*CHAR_BIT];
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn3[i])[j] ;
			chiffrement(chiffre_IP3[i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			//NB au lieu de cela, dans les faits, il faudra chiffrer 3 IPs concaténer 3*(nb CDN -1) IP à 0.0.0.0 puis permuter  ce chiffré par bloc de 3 IPs
		}
	}	
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn2[i])[j] ;
			chiffrement(chiffre_IP3[32+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
		}
	}		
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn4[i])[j] ;
			chiffrement(chiffre_IP3[64+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			
		}
	}		
	for (unsigned int i=0; i<9*CHAR_BIT*adress_size;i++) //on chiffre les 9 IP restantes
	{
		chiffrement(chiffre_IP3[96+i],0,public_key); //on chiffre l'IP bit à bit en mode curve
	}		

	chiffre_poids_fort_offset_curve=additionL1(chiffre_poids_fort_offset_curve,chiffre_poids_faible_offset_curve,public_key);
	chiffre_poids_fort_offset_twist=additionL1(chiffre_poids_fort_offset_twist,chiffre_poids_faible_offset_twist,public_key);	
	chiffre_poids_faible_offset_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1,public_key);
	//chiffre_poids_faible_offset_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1,public_key);
	

	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_curve,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_curve,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_twist,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_twist,private_key);
	//zout(poids_faible_offset,poids_fort_offset);


	//4 tests d'égalité --> x1,x2,x3,x4
	
	faible_plus_zero_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_0, public_key);
	faible_plus_one_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1, public_key);
	//fort_plus_zero_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_0, public_key);
	//fort_plus_one_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_1, public_key);
	//faible_plus_zero_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_0, public_key);
	//faible_plus_one_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1, public_key);
	fort_plus_zero_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_0, public_key);
	fort_plus_one_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_1, public_key);	
	
	is_zero=multiplicationL1(faible_plus_one_curve,fort_plus_one_twist,public_key); // 00 +1 +1
	is_one=multiplicationL1(faible_plus_one_curve,fort_plus_zero_twist,public_key); //01 +1 +0
	is_two=multiplicationL1(faible_plus_zero_curve,fort_plus_one_twist,public_key); //10  +0 +1
	is_three=multiplicationL1(faible_plus_zero_curve,fort_plus_zero_twist,public_key); //11 +0 +0	
		
	//serveur 4
	ecris(CDN 4);

	BitEvalL1<curvepoint_fp_t>  chiffre_IP4[12*adress_size*CHAR_BIT];
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn4[i])[j] ;
			chiffrement(chiffre_IP4[i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			//NB au lieu de cela, dans les faits, il faudra chiffrer 3 IPs concaténer 3*(nb CDN -1) IP à 0.0.0.0 puis permuter  ce chiffré par bloc de 3 IPs
		}
	}	
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(cdn3[i])[j] ;
			chiffrement(chiffre_IP4[32+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
		}
	}		
	for (unsigned int i=0; i<adress_size;i++)
	{
		for (unsigned int j=0; j<CHAR_BIT;j++) //pour chaque bit
		{
			bit_clair=bitset<CHAR_BIT>(receiver[i])[j] ;
			chiffrement(chiffre_IP4[64+i*CHAR_BIT+j],bit_clair,public_key); //on chiffre l'IP bit à bit en mode curve
			
		}
	}		
	for (unsigned int i=0; i<9*CHAR_BIT*adress_size;i++) //on chiffre les 9 IP restantes
	{
		chiffrement(chiffre_IP4[96+i],0,public_key); //on chiffre l'IP bit à bit en mode curve
	}	

	chiffre_poids_fort_offset_curve=additionL1(chiffre_poids_fort_offset_curve,chiffre_poids_faible_offset_curve,public_key);
	chiffre_poids_fort_offset_twist=additionL1(chiffre_poids_fort_offset_twist,chiffre_poids_faible_offset_twist,public_key);	
	chiffre_poids_faible_offset_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1,public_key);
	//chiffre_poids_faible_offset_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1,public_key);

	
	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_curve,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_curve,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	//dechiffrement(poids_faible_offset,chiffre_poids_faible_offset_twist,private_key);
	//dechiffrement(poids_fort_offset,chiffre_poids_fort_offset_twist,private_key);
	//zout(poids_faible_offset,poids_fort_offset);
	
	//4 tests d'égalité --> x1,x2,x3,x4
	
	faible_plus_zero_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_0, public_key);
	faible_plus_one_curve=additionL1(chiffre_poids_faible_offset_curve,bit_chiffre_curve_1, public_key);
	//fort_plus_zero_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_0, public_key);
	//fort_plus_one_curve=additionL1(chiffre_poids_fort_offset_curve,bit_chiffre_curve_1, public_key);
	//faible_plus_zero_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_0, public_key);
	//faible_plus_one_twist=additionL1(chiffre_poids_faible_offset_twist,bit_chiffre_twist_1, public_key);
	fort_plus_zero_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_0, public_key);
	fort_plus_one_twist=additionL1(chiffre_poids_fort_offset_twist,bit_chiffre_twist_1, public_key);	
	
	is_zero=multiplicationL1(faible_plus_one_curve,fort_plus_one_twist,public_key); // 00 +1 +1 a égale b = a nxor b = a xor non b
	is_one=multiplicationL1(faible_plus_one_curve,fort_plus_zero_twist,public_key); //01 +1 +0
	is_two=multiplicationL1(faible_plus_zero_curve,fort_plus_one_twist,public_key); //10  +0 +1
	is_three=multiplicationL1(faible_plus_zero_curve,fort_plus_zero_twist,public_key); //11 +0 +0	
		
	//contenu final
	//unsigned char cdn1[4]= {0x0A,0x01,0x01,0x0A};
	//unsigned char cdn1_source[4]= {0x0A,0x00,0x01,0x0A};
	//unsigned char cdn1_dest[4]= {0x0A,0x02,0x01,0x0A};
	//unsigned char cdn2[4]= {0x0A,0x02,0x01,0x0A};
	//unsigned char cdn2_source[4]= {0x0A,0x01,0x01,0x0A};
	//unsigned char cdn2_dest[4]= {0x0A,0x03,0x01,0x0A};	
	//unsigned char cdn3[4]= {0x0A,0x03,0x01,0x0A};
	//unsigned char cdn3_source[4]= {0x0A,0x02,0x01,0x0A};
	//unsigned char cdn3_dest[4]= {0x0A,0x04,0x01,0x0A};	
	//unsigned char cdn4[4]= {0x0A,0x01,0x04,0x0A};
	//unsigned char cdn4_source[4]= {0x0A,0x03,0x01,0x0A};
	//unsigned char cdn4_dest[4]= {0x64,0x01,0x01,0x0A};	//6*16+4
	
	/** compteur (2 bits) + 1 modulo 4, 2 circuits (1 entrée: bit de poids faible et 2 entrées:bit de l'offset) de profondeur 0, 4 serveurs **/
	
	/** 4 tests d'égalité, 1 circuit de profondeur 1 (2 entrées:bits de l'offset)**/
	
	/** si vrai alors bit de 192.0.0.1 sinon bit de 0.0.0.0 (3 entrées:2 bits de l'offset et 1 bit de l'IP)**/
	
	/** chaque cdn fait les tests d'égalité une seule fois **/
	 
}
