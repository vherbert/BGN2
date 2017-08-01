#ifndef __BGN_HPP

#define __BGN_HPP



#include <bitset>
#include <cinttypes>
#include <cmath>
#include <typeinfo>
#include <cxxabi.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <limits.h>		/* for CHAR_BIT */
#include "gengetopt.h"
#include "typedef.h"
#include "zout.hpp"
#include "size.hpp"
#include "mydouble.h" 
extern "C" {
#include "fpe.h"
}
#include "quadruplet.hpp"
#include "curvepoint_fp.h"
extern "C" {
#include "fp2e.h"	
}
#include "twistpoint_fp2.h"
#include "Bipoint.hpp"
#include "BitChiffre.hpp"
#include "fpe2scalar.hpp"
#include "chiffrement.hpp"
#include "circuit_chiffrement.hpp" 
#include "Fp.hpp"
#include "keygen.hpp"
#include "circuit_minmaj.hpp" 
#include "circuit_additionL1.hpp" 
#include "circuit_additionL2.hpp" 
#include "circuit_multiplicationL1.hpp" 
#include "circuit_multiplicationL1L2.hpp" 
#include "circuit_additionL3.hpp"
#include "circuit_multiplicationL2.hpp"
#include "circuit_additionL4.hpp"
#include "circuit_size.hpp" 
#include "circuit_minmaj3.hpp" 
#include "circuit_minmaj2.hpp" 
#include "circuit_time.hpp" 
#include "circuit_demo.hpp"
#include "circuit_ip.hpp"
#include "circuit_scalar_product.hpp"
#include "circuit_time2.hpp" 


// sans mydouble.h la cible « ../obj/bgn_check.o » a échouée erreur: conflicting declaration of C function ‘CheckDouble round(const CheckDouble&)’  --> ajouter mydouble.h devant le extern
// sans extern "C" la cible « bgn » a échouée référence indéfinie vers « fpe_iszero(fpe_struct const*) »


// macro pour gengetopt
#define DEV 0
#define USR 1

#define MINMAJ 0
#define CHIFFREMENT 1
#define ADDITIONL1 2
#define ADDITIONL2 3
#define ADDITIONL3 4
#define ADDITIONL4 5
#define MULTIPLICATIONL1 6
#define MULTIPLICATIONL1L2 7
#define MULTIPLICATIONL2 8
#define SIZE 9
#define TIME 10
#define MINMAJ2 11
#define MINMAJ3 12
#define DEMO 13
#define IP 14 
#define SCALAR_PRODUCT 15 
#define TIME2 16

	// BGN-Freeman-CF
	// en théorie pk:=(p, G, H, G_T, e, g, h, (g^a1,g^b1), (h^a2,h^b2))
	// en pratique pk:=(p, g, h, a1, b1, a2, b2)	
	// en sécurité 128 : p et r sont des entiers de 256 bits
	// on peut fixer p,r et t avec le x0 utilisé par Schwabe
	// E(Fp)={(x,y) :  y^2 = x^3 + 5, x,y in Fp}
	// g est un générateur de E(Fp) d'ordre p+1-t 
	// E[r]={(x,y): y^2 = x^3 + 5, x,y in Fp^12, r*(x,y)=0}
	// Ker(Pi-p)={(x,y): (x^p,y^p)=p*(x,y), x,y in Fp^12}
	// h est un générateur de E[r] inter Ker (Pi -p)
	// a1d1-b1c1 = a2d2-b2c2 = 1 choisis au hasard dans Fp
	// générer trois éléments non tous nuls (not all zero) au hasard détermine un unique quatrième élément


#endif /* __BGN_HPP */
