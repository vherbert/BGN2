#ifndef __SIZE_HPP
#define __SIZE_HPP

/**
 *   définition des symboles de taille limite des messages
 **/
 
#include <gmp.h> 
#include <gmpxx.h>
//en général, pour manipuler de grands entiers
//en pratique, pour définir x0 entier de 63 bits et calculer p,r et t, entiers de respectivement 256,256 et 128 bits pour une sécurité 128 bits 
 

// taille en octets pour BGNC2F

//size(n)=3072
//size(q)=1500 a peu pres
//size(t)=700 a peu pres
//eval=XY(1+Z)
// profondeur 2
//L=0

// BGN n=pq (poly de degré 2) subgroup decision problem
//clair Choisir un message m entre 0 et T avec T < q
//chiffré On calcule le chiffré $c=g^mh^r$.

//BGNCF groupe d'ordre n=pq (certains polys de degré 4) subgroup decision problem - public space
// clairs M groupe (Z/tZ,+,\times) avec t <<q
// chiffrés C=MxC' avec C'=(G,\times),~(G_T,*) des groupes cycliques d'ordre pq où p et q sont premiers
//évalués C^(2L+3) avec L nombre d'addition de pas frais

//BGNC2F (certains polys de degré 4 - déchiffrement plus rapide - plusieurs pairings) decision linear problem (généralisable au k-linear assumption) - public space 
// clairs M groupe (Z/tZ,+,\times) avec t <<q
// pairing asymétrique GG=G1^2 HH=G2^2 -> Gt^4 ordre premier sécurité sur DDH dans G1 G2 et sur generalized subgroup dans dans GG et HH 


#define MAX_MESSAGE_SIZE
#define MAX_CIPHER_SIZE

#endif /* __SIZE_HPP */

