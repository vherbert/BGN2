#include "additionL1.hpp"

//template <typename T>
//BitEvalL1<T> additionL1 (BitEvalL1<T> a, BitEvalL1<T> b, PublicKey public_key, Type type)
//{
	//BitEvalL1<T> somme;
	//somme.set_bit_masque((a.get_bit_masque()+b.get_bit_masque())%2);
	//scalar_t lambda;
	//scalar_setrandom(lambda, bn_r);	
	//if (type == CURVE) 
	//{
		//Bipoint<curvepoint_fp_t> beta, temp, bipoint_curve_subgroupelt; 
		
		
		////ecris(u+u);
		////temp=public_key.get_bipoint_curvegen()+public_key.get_bipoint_curvegen();
		////temp.makeaffine();
		////temp.print();	
					
		////ecris(beta1+beta2);
		//temp=a.get_bipoint()+b.get_bipoint();
		//temp.makeaffine();
		////temp.print();
		
		////ecris(pi_1(beta1+beta2));
		////private_key.pi_1(temp).makeaffine();
		////private_key.pi_1(temp).print();
		
		////ecris(pi_1(u1));
		//bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
		//bipoint_curve_subgroupelt.makeaffine();
		////private_key.pi_1(bipoint_curve_subgroupelt).print();
		
		////ecris(pi_1(beta1+beta2+u1));
		//beta=temp+bipoint_curve_subgroupelt; 
		//beta.makeaffine();	
		////private_key.pi_1(beta).print();
		
		//somme.set_bipoint(beta);
	//}
	//if (type == TWIST) 
	//{
		//Bipoint<twistpoint_fp2_t> beta, temp, bipoint_twist_subgroupelt;
		//temp=a.get_bipoint()+b.get_bipoint();
		//temp.makeaffine();	
		//bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
		//bipoint_twist_subgroupelt.makeaffine();
		//beta=temp+bipoint_twist_subgroupelt;
		//beta.makeaffine();
		//somme.set_bipoint(beta);
	//}
	////a.print_bit_masque();
	////b.print_bit_masque();
	////somme.print_bit_masque();
	//return somme;
//}

BitEvalL1<curvepoint_fp_t> additionL1 (BitEvalL1<curvepoint_fp_t> a, BitEvalL1<curvepoint_fp_t> b, PublicKey public_key)
{
	BitEvalL1<curvepoint_fp_t> somme;
	somme.set_bit_masque((a.get_bit_masque()+b.get_bit_masque())%2);
	scalar_t lambda;
	scalar_setrandom(lambda, bn_r);	
	Bipoint<curvepoint_fp_t> beta, temp, bipoint_curve_subgroupelt; 
	
	
	//ecris(u+u);
	//temp=public_key.get_bipoint_curvegen()+public_key.get_bipoint_curvegen();
	//temp.makeaffine();
	//temp.print();	
				
	//ecris(beta1+beta2);
	temp=a.get_bipoint()+b.get_bipoint();
	temp.makeaffine();
	//temp.print();
	
	//ecris(pi_1(beta1+beta2));
	//private_key.pi_1(temp).makeaffine();
	//private_key.pi_1(temp).print();
	
	//ecris(pi_1(u1));
	bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
	bipoint_curve_subgroupelt.makeaffine();
	//private_key.pi_1(bipoint_curve_subgroupelt).print();
	
	//ecris(pi_1(beta1+beta2+u1));
	beta=temp+bipoint_curve_subgroupelt; 
	beta.makeaffine();	
	//private_key.pi_1(beta).print();
	
	somme.set_bipoint(beta);
	return somme;
}

BitEvalL1<twistpoint_fp2_t> additionL1 (BitEvalL1<twistpoint_fp2_t> a, BitEvalL1<twistpoint_fp2_t> b, PublicKey public_key)
{
	BitEvalL1<twistpoint_fp2_t> somme;
	somme.set_bit_masque((a.get_bit_masque()+b.get_bit_masque())%2);
	scalar_t lambda;
	scalar_setrandom(lambda, bn_r);	
	Bipoint<twistpoint_fp2_t> beta, temp, bipoint_twist_subgroupelt;
	temp=a.get_bipoint()+b.get_bipoint();
	temp.makeaffine();	
	bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
	bipoint_twist_subgroupelt.makeaffine();
	beta=temp+bipoint_twist_subgroupelt;
	beta.makeaffine();
	somme.set_bipoint(beta);
	
	return somme;
}

BitChiffre additionL1 (BitChiffre a, BitChiffre b, PublicKey public_key)
{
	//signature;
	if (a.get_type() == b.get_type())
	{
		BitChiffre somme;
		somme.set_bit_masque((a.get_bit_masque()+b.get_bit_masque())%2);
		scalar_t lambda;
		scalar_setrandom(lambda, bn_r);	
		if (a.get_type() == CURVE) 
		{
			Bipoint<curvepoint_fp_t> beta, temp, bipoint_curve_subgroupelt; 
			
			
			//ecris(u+u);
			//temp=public_key.get_bipoint_curvegen()+public_key.get_bipoint_curvegen();
			//temp.makeaffine();
			//temp.print();	
						
			//ecris(beta1+beta2);
			temp=a.get_bipoint_curve()+b.get_bipoint_curve();
			temp.makeaffine();
			//temp.print();
			
			//ecris(pi_1(beta1+beta2));
			//private_key.pi_1(temp).makeaffine();
			//private_key.pi_1(temp).print();
			
			//ecris(pi_1(u1));
			bipoint_curve_subgroupelt.scalarmult_vartime(public_key.get_bipoint_curvegen(),lambda);
			bipoint_curve_subgroupelt.makeaffine();
			//private_key.pi_1(bipoint_curve_subgroupelt).print();
			
			//ecris(pi_1(beta1+beta2+u1));
			beta=temp+bipoint_curve_subgroupelt; 
			beta.makeaffine();	
			//private_key.pi_1(beta).print();
			
			somme.set_bipoint_curve(beta);
		}
		if (a.get_type() == TWIST) 
		{
			Bipoint<twistpoint_fp2_t> beta, temp, bipoint_twist_subgroupelt;
			temp=a.get_bipoint_twist()+b.get_bipoint_twist();
			temp.makeaffine();	
			bipoint_twist_subgroupelt.scalarmult_vartime(public_key.get_bipoint_twistgen(),lambda);
			bipoint_twist_subgroupelt.makeaffine();
			beta=temp+bipoint_twist_subgroupelt;
			beta.makeaffine();
			somme.set_bipoint_twist(beta);
		}
		//a.print_bit_masque();
		//b.print_bit_masque();
		//somme.print_bit_masque();
		return somme;
	}
	else
	{
		cout << "Problème de type dans additionL1" << endl;
		exit(0);
	}
}
