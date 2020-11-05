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
#include <limits>
using namespace std;
void moisAnneeCorrect(int& mois,int& annee) {
   bool saisieOK;
   do {
      if (!(saisieOK = cin >> mois >> annee && mois <= 12 && mois >= 1
                       && annee >= 1900 && annee <= 2100))
      {
         cin.clear(), cout << "Date non valide. Veuillez SVP recommencer." << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (!saisieOK);
}
