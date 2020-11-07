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

   if (!(saisieOK = cin >> mois >> annee && mois <= 12 && mois >= 1
                    && annee >= ANNEE_MIN && annee <= ANNEE_MAX)) {
      cin.clear();
      cout << "Date non valide, veuillez SVP recommencer." << endl;
   }
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return saisieOK;
}

/**
 *
 * @param jourDebut
 * @param nombreJours
 * @param mois
 * @param annee
 */
void afficherCalendrier(const unsigned &jourDebut, const unsigned &nombreJours,
                        unsigned mois, unsigned annee) {
   cout << endl << moisEnLitteral(mois) << " " << annee << endl << endl;

   unsigned nombreEspaces = jourDebut - 1;
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
 * Formule Zeller
 *
 * @param jour
 * @param mois
 * @param annee
 * @return le jour de la semaine (lundi = 1, ..., dimanche = 7)
 */
unsigned dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee) {
   int m, a;
   if (mois >= 3) {
      m = (int)mois - 2;
      a = (int)annee;
   } else {
      m = (int)mois + 10;
      a = (int)annee - 1;
   }
   int s = a / 100;
   int n = a % 100;
   int f = (int)jour + n + 5 * s + n / 4 + s / 4 + (13 * m - 1) / 5;

   unsigned jourSemaine = (unsigned)(f % 7);

   //Permet de modifier dimanche = 0 en dimanche = 7
   if (jourSemaine == 0) {
      jourSemaine = 7;
   }

   return jourSemaine;
}

/**
 *
 * @param annee
 * @return
 */
bool estBissextile(unsigned annee) {
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

/**
 *
 * @param mois
 * @param annee
 * @return
 */
unsigned nbreJoursMois(unsigned mois, unsigned annee) {
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

/**
 *
 * @param moisDebut
 * @param anneeDebut
 * @param moisFin
 * @param anneeFin
 */
void affichageDesCalendriers(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
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
         unsigned jourSemaine = dateEnJourSemaine(1, mois, annee);
         unsigned nombreJours = nbreJoursMois(mois, annee);
         afficherCalendrier(jourSemaine, nombreJours, mois, annee);
      }
      moisDebut = 0;
   }
}