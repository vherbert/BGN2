#ifndef __POSTCOMPUTATION_HPP

#define __POSTCOMPUTATION_HPP

#include <limits.h>		/* for CHAR_BIT */
#include "typedef.h"
#include <iostream>
#include "zout.hpp"
#include <typeinfo>
#include <cxxabi.h>
#include "BitEvalL3.hpp"
#include "dechiffrementL3.hpp"
#include "PrivateKey.hpp"


void postcomputation(char& rop, char symbole, BitEvalL3 evalue, PrivateKey private_key);

#endif /* __POSTCOMPUTATION_HPP */
