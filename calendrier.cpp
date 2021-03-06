/*
-----------------------------------------------------------------------------------
Nom du fichier : calendrier.cpp
Auteur(s)      : Tania Nunez & Chloé Fontaine & Luca Coduri
Date creation  : 6.11.2020

Description    : Ce fichier contient l'implémentation des fonctions déclarées dans
                 calendrier.h.

Remarque(s)    : Le bon fonctionnement des fonctions est assuré avec des asserts.
                 Pour les désactiver, ajoutez "#define NDEBUG" au-dessus des
                 "#include".

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <limits>
#include <iomanip>
#include <cassert>
#include "calendrier.h"

using namespace std;

enum class Mois {
   JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

bool saisieMoisAnneeCorrect(unsigned short &mois, unsigned &annee) {
   bool saisieOK = (cin >> mois && moisCorrect(mois)) && cin.peek() != '\n'
                   && (cin >> annee && anneeCorrecte(annee));

   if (!saisieOK) {
      cout << endl << "Date non valide. Veuillez SVP recommencer." << endl;
      cin.clear();
   }
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return saisieOK;
}

void afficherCalendriersIntervalle(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   assert(moisCorrect(moisDebut) && moisCorrect(moisFin) && anneeCorrecte
      (anneeDebut) && anneeCorrecte(anneeFin) &&
          dateDebutEstAnterieure(moisDebut, anneeDebut, moisFin, anneeFin));
   /* La condition ternaire vérifie si l'on doit s'arrêter au mois de
      décembre (12) ou au mois moisFin. */
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
   const unsigned JOUR_SEMAINE = dateEnJourSemaine(1, mois, annee);
   const unsigned NBRE_JOURS = nbreJoursMois(mois, annee);
   unsigned nbreEspaces = (unsigned) JOUR_SEMAINE - 1;

   cout << " L  M  M  J  V  S  D" << endl;
   // Affiche un espace ou le jour dans la case du calendrier respective.
   for (unsigned noCase = 1; noCase <= NBRE_JOURS + JOUR_SEMAINE - 1; ++noCase) {
      if (nbreEspaces >= 1) {
         cout << setw(2) << " ";
         nbreEspaces--;
      } else cout << setw(2) << noCase - JOUR_SEMAINE + 1;
      // À la fin de la semaine (jour 7), on revient à la première colonne (lundi).
      if (noCase % 7 == 0) { cout << endl; }
      else cout << " ";
   }
   cout << endl;
}

unsigned short dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee) {
   assert(jourCorrect(jour) && moisCorrect(mois) && anneeCorrecte(annee));
   // Établit le mois de mars = 1 et février = 12
   const unsigned MOIS = mois >= 3 ? mois - 2 : mois + 10;
   const unsigned ANNEE = mois >= 3 ? annee : annee - 1;

   const unsigned J = ANNEE / 100;
   const unsigned K = ANNEE % 100;
   unsigned jourSemaine =
      (jour + K + 5 * J + K / 4 + J / 4 + (13 * MOIS - 1) / 5) % 7;

   // Modifie dimanche = 0 en dimanche = 7
   if (jourSemaine == 0) jourSemaine = 7;

   return (unsigned short) jourSemaine;
}

unsigned short nbreJoursMois(unsigned mois, unsigned annee) {
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
   return anneeDebut < anneeFin || (anneeDebut == anneeFin && moisDebut <= moisFin);
}