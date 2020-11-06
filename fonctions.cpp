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
#include <iomanip>
using namespace std;
void moisAnneeCorrect( unsigned& mois,unsigned& annee ) {
   bool saisieOK;
   do {
      if (!(saisieOK = cin >> mois >> annee && mois <= 12 && mois >= 1
                       && annee >= 1900 && annee <= 2100))
      {
         cin.clear(), cout << "Date non valide, veuillez SVP recommencer." << endl;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (!saisieOK);
}
void saisirDates( unsigned& moisDebut, unsigned& anneeDebut, unsigned& moisFin,
                  unsigned& anneeFin ) {
   cout << "Entrez la date de debut [1 - 12 1900 - 2100] : ";
   moisAnneeCorrect(moisDebut, anneeDebut);
   cout << "Entrez la date de fin [1 - 12 1900 - 2100] : ";
   moisAnneeCorrect(moisFin, anneeFin);
}
void afficherMoisAnnee( const unsigned& jourDebut, const unsigned& nombreJours ) {
   unsigned nombreEspaces = jourDebut - 1;
   cout << " L  M  M  J  V  S  D" << endl;
   for ( int i = 1; i <= nombreJours + jourDebut - 1; ++i ) {
      if ( nombreEspaces >= 1 ) {
         cout << setw(2) << " ";
         --nombreEspaces;
      }
      else {
         cout << setw(2) << i - int(jourDebut) + 1;
      }
      if ( i % 7 == 0 ) { cout << "\n"; }
      else { cout << " "; }
   }
}