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
#include <iostream>
#include <limits>
#include <iomanip>
#include <cassert>;
#include "fonctions.h"

using namespace std;

enum class Mois {
   JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

/**
 *
 * @param mois
 * @param annee
 * @return
 */
bool saisieMoisAnneeCorrect(unsigned &mois, unsigned &annee) {
   bool saisieOK;

   if (!(saisieOK = cin >> mois >> annee && moisCorrect(mois) && anneeCorrecte(annee)
      )) {
      cin.clear();
      cout << endl << "Date non valide. Veuillez SVP recommencer." << endl;
   }
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return saisieOK;
}

/**
 *
 * @param moisDebut
 * @param anneeDebut
 * @param moisFin
 * @param anneeFin
 */
void afficherCalendriersIntervalle(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   assert(moisCorrect(moisDebut) && moisCorrect(moisFin) && anneeCorrecte
   (anneeDebut) && anneeCorrecte(anneeFin));
//   while (anneeDebut < anneeFin || (anneeDebut == anneeFin && moisDebut <=
//   moisFin)) {
//      unsigned jourSemaine = dateEnJourSemaine( 1, moisDebut, anneeDebut);
//      unsigned nombreJours = nbreJoursMois(moisDebut, anneeDebut);
//      afficherCalendrier( jourSemaine, nombreJours, moisDebut, anneeDebut );
//
//      if (moisDebut >= 12) {
//         moisDebut = 1;
//         ++anneeDebut;
//      } else {
//         ++moisDebut;
//      }
//   }

   for (unsigned annee = anneeDebut; annee <= anneeFin; ++annee) {
      for (unsigned mois = moisDebut; mois <= (annee == anneeFin ? moisFin : 12);
           ++mois) {
         unsigned short jourSemaine = dateEnJourSemaine(1, mois, annee);
         unsigned nombreJours = nbreJoursMois(mois, annee);
         afficherCalendrier(jourSemaine, nombreJours, mois, annee);
      }
      moisDebut = 1;
   }
}

/**
 * Formule Zeller source: https://en.wikipedia.org/wiki/Zeller%27s_congruence
 * Cette fonction permet de déterminer le jour de la semaine d'une date. Ex:
 * le 7 novembre 2020 vaut 6 (= samedi)
 * @param jour
 * @param mois
 * @param annee
 * @return le jour de la semaine (lundi = 1, ..., dimanche = 7)
 */
unsigned short dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee) {
   unsigned m, a;
   assert(jourCorrect(jour) && moisCorrect(mois) && anneeCorrecte(annee));

   //établir le mois de mars à 1 et janvier et février à 11 et 12.
   if (mois >= 3) {
      m = mois - 2;
      a = annee;
   } else {
      m = mois + 10;
      a = annee - 1;
   }
   const unsigned J = a / 100;
   const unsigned K = a % 100;
   unsigned h =  jour + K + 5 * J + K / 4 + J / 4 + (13 * m - 1) / 5;

   unsigned short jourSemaine = (unsigned short)h % 7;

   //Permet de modifier dimanche = 0 en dimanche = 7
   if (jourSemaine == 0) {
      jourSemaine = 7;
   }

   return jourSemaine;
}


/**
 *
 * @param jourDebut
 * @param nombreJours
 * @param mois
 * @param annee
 */
void afficherCalendrier(unsigned short jourDebut, unsigned nombreJours,
                        unsigned mois, unsigned annee) {
   assert(jourSemaineCorrect(jourDebut) && jourCorrect(nombreJours) && moisCorrect
   (mois) && anneeCorrecte(annee));
   cout << endl << moisEnLitteral(mois) << " " << annee << endl << endl;

   unsigned nombreEspaces = (unsigned) (jourDebut) - 1;
   cout << " L  M  M  J  V  S  D" << endl;
   for (unsigned i = 1; i <= nombreJours + jourDebut - 1; ++i) {
      if (nombreEspaces >= 1) {
         cout << setw(2) << " ";
         --nombreEspaces;
      } else {
         cout << setw(2) << i - jourDebut + 1;
      }

      if (i % 7 == 0) {
         cout << endl;
      } else {
         cout << " ";
      }
   }
   cout << endl;
}


/**
 *
 * @param annee
 * @return
 */
bool estBissextile(unsigned annee) {
   assert(anneeCorrecte(annee));
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

/**
 *
 * @param mois
 * @param annee
 * @return
 */
unsigned nbreJoursMois(unsigned mois, unsigned annee) {
   assert(moisCorrect(mois) && anneeCorrecte(annee));

   switch ((Mois) mois) {
      case Mois::AVRIL:
      case Mois::JUIN:
      case Mois::SEPTEMBRE:
      case Mois::NOVEMBRE:
         return 30;
      case Mois::FEVRIER :
         return estBissextile(annee) ? 29 : 28;
      default:
         return 31;
   }
}

/**
 *
 * @param mois
 * @return
 */
string moisEnLitteral(unsigned mois) {
   assert(moisCorrect(mois));
   switch ((Mois) mois) {
      case Mois::JANVIER:
         return "Janvier";
      case Mois::FEVRIER:
         return "Fevrier";
      case Mois::MARS:
         return "Mars";
      case Mois::AVRIL:
         return "Avril";
      case Mois::MAI:
         return "Mai";
      case Mois::JUIN:
         return "Juin";
      case Mois::JUILLET:
         return "Juillet";
      case Mois::AOUT:
         return "Aout";
      case Mois::SEPTEMBRE:
         return "Septembre";
      case Mois::OCTOBRE:
         return "Octobre";
      case Mois::NOVEMBRE:
         return "Novembre";
      case Mois::DECEMBRE:
         return "Decembre";
      default:
         return "Mois non existant.";
   }
}

bool jourCorrect(unsigned jour) {
   return jour >= 1 && jour <= 31;
}

bool moisCorrect(unsigned mois) {
   return mois >= 1 && mois <= 12;
}

bool anneeCorrecte(unsigned annee) {
   return annee >= ANNEE_MIN && annee <= ANNEE_MAX;
}

bool jourSemaineCorrect(unsigned short jourSemaine) {
   return jourSemaine >= 1 && jourSemaine <= 7;
}
