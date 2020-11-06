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

enum class Mois {JANVIER= 1, FEVRIER, MARS, AVRIL, MAI, JUIN,JUILLET, AOUT,
   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};

//OK
void saisieMoisAnnee(unsigned int& mois, unsigned int& annee) {
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

// OK
bool estBissextile(unsigned int annee){
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

// OK
unsigned int nbreJoursMois(unsigned int mois, unsigned annee){
   switch ((Mois) mois) {
      case Mois::AVRIL:
      case Mois::JUIN:
      case Mois::SEPTEMBRE:
      case Mois::NOVEMBRE:
         return 30;
      case Mois::FEVRIER :
         return estBissextile(annee) ?  29 : 28;
      default:
         return 31;
   }
}

// OK
void affichagePreambuleCalendrier(unsigned int mois, unsigned int annee) {
   cout << moisEnLitteral(mois) << " " << annee << endl << endl;
}

// OK
string moisEnLitteral(unsigned int mois) {
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
   }
}

// OK
void affichageDesCalendriers(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   while (anneeDebut < anneeFin || (anneeDebut == anneeFin && moisDebut <= moisFin)) {
      // Afficher calendrier
      if (moisDebut >= 12) {
         moisDebut = 0;
         ++anneeDebut;
      } else {
         ++moisDebut;
      }
   }
}