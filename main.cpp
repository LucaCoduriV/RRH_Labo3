/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s) : Tania Nunez & Chloe Fontaine & Luca Coduri
Date creation : 6.11.2020
Description : Ce programme demande à l'utilisateur d'entrer une date de début et une
date de fin dans la console. Il va ensuite fournir à l'utilisateur  l'ensemble des
pages calendrier correspondant à l'intervalle date début – date fin.
Remarque(s) : Dans le cadre de notre labo en PROG1, il nous est demandé que
l'utilisateur ne puisse pas entrer une date inférieur à 1900 et supérieur à 2100.
En revanche l'algorithme utilisé nous permet d'aller jusqu'au début du calendrier
grégorien jusqu'en 9999.
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
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
         cout << "Voulez-vous quitter le programme ? [o/n]";

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