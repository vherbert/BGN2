# BGN2
Proof of concept implementation of BGNFCF scheme

Date : 28 July, 2017

BGN2 is a free software, it is the implementation of scheme described in the article 
"Design and Implementation of Low Depth Pairing-based Homomorphic Encryption Scheme" 
by Vincent Herbert, Bhaskar Biswas and Caroline Fontaine.

# Description
Our scheme is based on an improvement of [BGN05], that we call BGN-F-CF, and which can homomorphically evaluate polynomial of degree at most 4. This solution provides smaller ciphertexts than lattice based solutions, and its security is based on a hard problem that has been investigated in depth. More precisely, it employs together two improvements of the original BGN scheme [BGN05], based on [F10] and [CF15]. Only Freeman's work [F10] has already been coupled with BGN in [G13A,G13B] to greatly improve BGN's speed, resulting in a scheme that we call here BGN-F. To our knowledge, it is the first time that Catalone and Fiore's construction [CF15] is applied to this particular setting in order to add one more multiplicative depth.

# Dependencies and Installation
To use the implementation BGN2, copy/clone the repository, go to /src directory and use make command to construct binaries in /bin directory.

Additional options in Makefile and more info using the flag -h with generated binaries.

BGN2 is written in C++ language and uses as main dependency, the library dclxvi-20130329, written in C and qhasm languages.

Dependency repository: https://github.com/BGN2/BGN2/tree/master/dclxvi-20130329

For compatibility reasons between programming languages, it is part of our repository in /dclxvi-20130329 directory. 

# References
[BGN05] : Dan Boneh, Eu-Jin Goh, and Kobbi Nissim. Evaluating 2-DNF Formulas on Ciphertexts. In Joe Kilian, editor, Theory of Cryptography, Second Theory of Cryptography Conference, TCC 2005, Cambridge, MA, USA, February 10-12, 2005, Proceedings, volume 3378 of Lecture Notes in Computer Science, pages 325–341. Springer, 2005.

[F10] : David Mandell Freeman. Converting Pairing-Based Cryptosystems from Composite-Order Groups to Prime-Order Groups. In Henri Gilbert, editor, Advances in Cryptology - EUROCRYPT 2010, 29th Annual International Conference on the Theory and Applications of Cryptographic Techniques, French Riviera, May 30 - June 3, 2010. Proceedings, volume 6110 of Lecture Notes in Computer Science, pages 44–61. Springer, 2010.

[CF15] : Dario Catalano and Dario Fiore. Using Linearly Homomorphic Encryption to Evaluate Degree-2 Functions on Encrypted Data. In Indrajit Ray, Ninghui Li, and Christopher Kruegel, editors, Proceedings of the 22nd ACM SIGSAC Conference on Computer and Communications Security, Denver, CO, USA, October 12-6, 2015, pages 1518–1529. ACM, 2015.

[G13A] : Aurore Guillevic. Arithmetic of pairings on algebraic curves for cryptography. Theses, Ecole Normale Supérieure de
Paris - ENS Paris, December 2013.

[G13B] : Aurore Guillevic. Comparing the Pairing Efficiency over Composite-Order and Prime-Order Elliptic Curves. In Applied Cryptography and Network Security - 11th International Conference, ACNS 2013, Banff, AB, Canada, June 25-28, 2013. Proceedings, pages 357–372, 2013.

