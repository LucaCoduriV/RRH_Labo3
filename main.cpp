/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) : Tania Nunez & Chloé Fontaine & Luca Coduri
Date creation : 6.11.2020
Description : Ce programme demande à l'utilisateur d'entrer une date de début et une
date de fin dans la console. Il va ensuite afficher l'ensemble des pages du
calendrier correspondant à l'intervalle date début – date fin (mois et année).
Remarque(s) : Dans le cadre de notre labo en PROG1, il nous est demandé que
l'utilisateur ne puisse pas entrer une date inférieur à 1900 et supérieur à 2100.
En revanche l'algorithme utilisé nous permet d'aller du début du calendrier
grégorien jusqu'à la valeur max d'un unsigned int - 1 (dans notre cas 4294967294).
À la fin du programme lorsque l'on demande à l'utilisateur s'il veut quitter ou
non, nous ne traitons que le premier caractère de l'entrée.
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
//todo corriger l'en-tête
//todo faire les commentaires, Tania OK
//todo renommer fichier fonctions.h et .cpp calculAffichageCalendrier.h/cpp
//todo verifier la check list


#include <cstdlib>
#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
   while (true) {
      unsigned moisDebut, anneeDebut, moisFin, anneeFin;
      do {
         cout << "Entrez la date de debut [1 - 12 " << ANNEE_MIN
         <<  " - " << ANNEE_MAX << "] : ";
      } while (!saisieMoisAnneeCorrect(moisDebut, anneeDebut));

      do {
         cout << endl << "Entrez la date de fin [1 - 12 " << anneeDebut
              <<  " - " << ANNEE_MAX << "] : ";
      } while (!saisieMoisAnneeCorrect(moisFin, anneeFin));

      if (!dateDebutEstAnterieure(moisDebut, anneeDebut, moisFin, anneeFin)) {
         cout << endl << "La date de fin que vous avez entre est anterieure a la "
                         "date de debut. Veuillez SVP recommencer." << endl;
         continue;
      }

      afficherCalendriersIntervalle(moisDebut, anneeDebut, moisFin, anneeFin);

      char reponse;
      bool saisieOK;
      do {
         cout << "Voulez-vous quitter le programme ? [o/n]: ";

         if (!(saisieOK = cin >> reponse && (reponse == 'o' || reponse == 'n'))) {
            cin.clear();
            cout << endl << "Votre reponse n'est pas valide. Veuillez SVP "
                            "recommencer." << endl;
         }
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << endl;
      } while (!saisieOK);

      if (reponse == 'o') {
         return EXIT_SUCCESS;
      }
   }
}