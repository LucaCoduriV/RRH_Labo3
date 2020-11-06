/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s) : Tania Nunez
Date creation : <jj.mm.aaaa>
Description : <à compléter>
Remarque(s) : <à compléter>
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include "fonctions.h"
using namespace std;
int main() {
   unsigned int moisDebut, anneeDebut, moisFin, anneeFin;

   cout << "Entrez la date de debut [mm(1-12) aaaa(1900-2100] : ";
   saisieMoisAnnee(moisDebut, anneeDebut);
   cout << "Entrez la date de fin [mm(1-12) aaaa(1900-2100] : ";
   saisieMoisAnnee(moisFin, anneeFin);


   return EXIT_SUCCESS;
}