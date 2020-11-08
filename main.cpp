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
//todo faire les asserts
//todo afficherCalendriersIntervalle regarder ce qui est le mieux.
//todo faire les commentaires
//todo checker les limites du programme
//todo faut-il faire une fonction pour la saisie
//todo renommer fichier fonctions.h et .cpp
//todo verifier la check list


#include <cstdlib>
#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
   while (true) {
      unsigned moisDebut, anneeDebut, moisFin, anneeFin;
      do {
         cout << "Entrez la date de debut [1 - 12 1900 - 2100] : ";
      } while (!saisieMoisAnneeCorrect(moisDebut, anneeDebut));

      do {
         cout << endl << "Entrez la date de fin [1 - 12 1900 - 2100] : ";
      } while (!saisieMoisAnneeCorrect(moisFin, anneeFin));

      if (anneeDebut > anneeFin || (anneeDebut == anneeFin && moisDebut > moisFin)) {
         cout << endl << "La date de fin que vous avez entre est anterieure a la "
                         "date de debut. Veuillez recommencer." << endl;
         continue;
      }

      afficherCalendriersIntervalle(moisDebut, anneeDebut, moisFin, anneeFin);

      char reponse;
      bool saisieOK;
      do {
         cout << "voulez vous quitter le programme ? [o/n]";

         if (!(saisieOK = cin >> reponse && (reponse == 'o' || reponse == 'n'))) {
            cin.clear();
            cout << endl << "Votre reponse n'est pas valide. Veuillez SVP "
                            "recommencer." << endl;
         }
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } while (!saisieOK);

      if (reponse == 'o') {
         return EXIT_SUCCESS;
      }
   }
}