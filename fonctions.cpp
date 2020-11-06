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

enum class Mois {JANVIER= 1, FEVRIER, MARS, AVRIL, MAI, JUIN,JUILLET, AOUT,
   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};

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
unsigned jsemaineDT(const unsigned& jour, const unsigned& mois, const unsigned&
annee)
{
   int m, a;
   if (mois >= 3)
   {
      m = mois - 2;
      a = annee;
   }
   else
   {
      m = mois + 10;
      a = annee - 1;
   }
   int s = a / 100;
   int n = a % 100;
   int f = jour + n + 5 * s + n / 4 + s / 4 + (13 * m - 1) / 5;

   unsigned jourSemaine = (f % 7);

   //Permet de modifier dimanche = 0 en dimanche = 7
   if(jourSemaine == 0){
      jourSemaine = 7;
   }

   return jourSemaine;
}
bool estBissextile(unsigned int annee){
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

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

void affichagePreambuleCalendrier(unsigned int mois, unsigned int annee) {

   cout << moisEnLitteral(mois) << " " << annee << endl << endl
        << " L  M  M  J  V  S  D";
}

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