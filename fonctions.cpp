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
#include <cassert>
#include "fonctions.h"

using namespace std;

enum class Mois {
   JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

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

void afficherCalendriersIntervalle(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   assert(moisCorrect(moisDebut) && moisCorrect(moisFin) && anneeCorrecte
      (anneeDebut) && anneeCorrecte(anneeFin) &&
          dateDebutEstAnterieure(moisDebut, anneeDebut, moisFin, anneeFin));

   for (unsigned annee = anneeDebut; annee <= anneeFin; ++annee) {
      for (unsigned mois = moisDebut; mois <= (annee == anneeFin ? moisFin : 12);
           ++mois) {
         afficherCalendrier(mois, annee);
      }
      moisDebut = 1;
   }
}

void afficherCalendrier(unsigned mois, unsigned annee) {
   assert(moisCorrect(mois) && anneeCorrecte(annee));

   cout << endl << moisEnLitteral(mois) << " " << annee << endl << endl;
   unsigned jourSemaine = dateEnJourSemaine(1, mois, annee);
   unsigned nbreJours = nbreJoursMois(mois, annee);
   unsigned nbreEspaces = (unsigned) jourSemaine - 1;
   cout << " L  M  M  J  V  S  D" << endl;
   // Affichage des espaces et du jour dans la case du calendrier respective.
   for (unsigned nCase = 1; nCase <= nbreJours + jourSemaine - 1; ++nCase) {
      if (nbreEspaces >= 1) {
         cout << setw(2) << " ";
         --nbreEspaces;
      } else cout << setw(2) << nCase - jourSemaine + 1;

      if (nCase % 7 == 0) { cout << endl; }
      else cout << " ";
   }
   cout << endl;
}

unsigned short dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee) {
   unsigned m, a;
   assert(jourCorrect(jour) && moisCorrect(mois) && anneeCorrecte(annee));

   // Etablit le mois de mars = 1 et février = 12
   if (mois >= 3) {
      m = mois - 2;
      a = annee;
   } else {
      m = mois + 10;
      a = annee - 1;
   }

   const unsigned J = a / 100;
   const unsigned K = a % 100;
   unsigned jourSemaine = (jour + K + 5 * J + K / 4 + J / 4 + (13 * m - 1) / 5) % 7;

   // Modifie dimanche = 0 en dimanche = 7
   if (jourSemaine == 0) jourSemaine = 7;

   return (unsigned short) jourSemaine;
}

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

bool estBissextile(unsigned annee) {
   assert(anneeCorrecte(annee));
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

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

bool dateDebutEstAnterieure(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   return anneeDebut <= anneeFin || (anneeDebut == anneeFin && moisDebut <= moisFin);
}