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
#include <iomanip>
#include "fonctions.h"
using namespace std;
int main() {
   while(true){
      unsigned moisDebut, anneeDebut, moisFin, anneeFin;
      saisirDates(moisDebut, anneeDebut, moisFin, anneeFin);
      affichageDesCalendriers(moisDebut, anneeDebut, moisFin,  anneeFin);

      cout << "voulez vous quitter le programme ? [o/n]";
      char reponse;
      cin >> reponse;
      if(reponse == 'o' || reponse == 'O'){
         break;
      }
   }


   return EXIT_SUCCESS;
}