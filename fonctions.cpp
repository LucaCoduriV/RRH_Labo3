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

/**
 * Vérifie le type de la saisie utilisateur et si les paramètres appartiennent
 * bien à l'intervalle défini et, s'il n'y a pas d'erreurs, attribue par référence
 * les valeurs entrées par l'utilisateur aux variables entrées en paramètres.
 *
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return 1 (true) s'il n'y a pas d'erreurs, 0 (false) s'il y a des erreurs
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
 * Affiche tous les calendriers appartenant à l'intervalle entré par paramètres.
 *
 * @param moisDebut [1 - 12]
 * @param anneeDebut [ANNEE_MIN - ANNEE_MAX]
 * @param moisFin [1 - 12]
 * @param anneeFin [ANNEE_MIN - ANNEE_MAX]
 */
void afficherCalendriersIntervalle(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   assert(moisCorrect(moisDebut) && moisCorrect(moisFin) && anneeCorrecte
   (anneeDebut) && anneeCorrecte(anneeFin) && dateDebutEstAnterieure(moisDebut,
                                                                     anneeDebut,
                                                                     moisFin,
                                                                     anneeFin));
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
         afficherCalendrier(mois, annee);
      }
      moisDebut = 1;
   }
}

/**
 * Affiche le calendrier du mois de l'année entrés en paramètres.
 *
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 */
void afficherCalendrier(unsigned mois, unsigned annee) {
   assert(moisCorrect(mois) && anneeCorrecte(annee));

   cout << endl << moisEnLitteral(mois) << " " << annee << endl << endl;
   unsigned jourSemaine = dateEnJourSemaine(1, mois, annee);
   unsigned nbreJours = nbreJoursMois(mois, annee);
   //TODO doit vraiment faire un assert du nombre jours et jour de la semaine ???
   unsigned nbreEspaces = (unsigned) jourSemaine - 1;
   cout << " L  M  M  J  V  S  D" << endl;
   for (unsigned colonne = 1; colonne <= nbreJours + jourSemaine - 1; ++colonne) {
      if (nbreEspaces >= 1) {
         cout << setw(2) << " ";
         --nbreEspaces;
      } else {
         cout << setw(2) << colonne - jourSemaine + 1;
      }

      if (colonne % 7 == 0) {
         cout << endl;
      } else {
         cout << " ";
      }
   }
   cout << endl;
}

/**
 * Calcule le jour de la semaine correspondant à une date.
 * Ex: le 7 novembre 2020 vaut 6 (= samedi)
 * Reprend la formule Zeller.
 * Source: https://en.wikipedia.org/wiki/Zeller%27s_congruence
 *
 * @param jour [1 - 31]
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return le jour de la semaine (lundi = 1, ..., dimanche = 7)
 */
unsigned short dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee) {
   unsigned m, a;
   assert(jourCorrect(jour) && moisCorrect(mois) && anneeCorrecte(annee));

   // Etablit le mois de mars = 1 et février = 12
   if (mois >= 3) { m = mois - 2; a = annee; }
   else { m = mois + 10; a = annee - 1; }

   const unsigned J = a / 100;
   const unsigned K = a % 100;
   unsigned h =  (jour + K + 5 * J + K / 4 + J / 4 + (13 * m - 1) / 5) % 7;

   // Modifie dimanche = 0 en dimanche = 7
   if (h == 0) h = 7;

   return (unsigned short)h;
}

/**
 * Renvoie le nombre de jours présent dans le mois d'une année.
 *
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return le nombre de jours [28 - 30]
 * Permet d'avoir le nombre de jour dans un mois selon l'année.
 * @param mois se trouve dans l'intervalle 1-12. indique pour quel mois on veut
 * connaitre le nombre de jour.
 * @param annee se trouve dans l'intervalle ANNEE_MIN - ANNEE_MAX. Indique l'année
 * dans laquelle se trouve le mois.
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
 * Détermine si l'année entrée en paramètre est bissextile.
 *
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return 1 (true) si l'année est bissextile, 0 (false) autrement
 */
bool estBissextile(unsigned annee) {
   assert(anneeCorrecte(annee));
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

/**
 * Renvoie le nom littéral du mois entré en paramètre.
 *
 * @param mois [1 -12]
 * @return le mois en littéral
 * Permet d'avoir le nom du mois correspondant à un chiffre.
 * @param mois est un nombre qui se trouve dans l'intervalle 1-12.
 * @return le nom du mois.
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
/**
 * Permet de vérifier que le nombr en paramètre se trouve dans l'intervalle 1-31.
 * @param jour est le nombre que l'on vérifie.
 * @return True si jour se trouve dans l'intervalle 1-31
 */

/**
 * Vérifie que le jour appartiennent à l'intervalle [1 - 31].
 *
 * @param jour
 * @return 1 (true) si la valeur appartient à l'intervalle, 0 (false) autrement
 */
bool jourCorrect(unsigned jour) {
   return jour >= 1 && jour <= 31;
}
/**
 * Permet de vérifier que le nombre en paramètre se trouve dans l'intervalle 1-12.
 * @param mois est le nombre que l'on vérifie.
 * @return True si mois se trouve dans l'intervalle 1-12
 */

/**
 * Vérifie que le mois appartienne à l'intervalle [1 - 12].
 *
 * @param mois
 * @return 1 (true) si la valeur appartient à l'intervalle, 0 (false) autrement
 */
bool moisCorrect(unsigned mois) {
   return mois >= 1 && mois <= 12;
}

/**
 *Permet de vérifier si le nombre en paramètre se trouve dans l'intervalle
 * ANNEE_MIN - ANNEE_MAX.
 * @param annee est le nombre que l'on vérifie.
 * @return True si annee se trouve l'intervalle ANNEE_MIN - ANNEE_MAX.
 */
/**
 * Vérifie que l'année appartienne à l'intervalle [ANNEE_MIN - ANNEE_MAX].
 *
 * @param annee
 * @return 1 (true) si la valeur appartient à l'intervalle, 0 (false) autrement
 */
bool anneeCorrecte(unsigned annee) {
   return annee >= ANNEE_MIN && annee <= ANNEE_MAX;
}

/**
 * Permet de vérifier si le nombre en paramètre se trouve dans l'intervalle 1-7 et
 * est donc un jour de semaine valide.
 * @param jourSemaine est le nombre que l'on vérifie
 * @return True si jourSemaine se trouve dans l'intervalle 1-7
 */
/**
 * Vérifie que le jour de la semaine appartienne à l'intervalle [1 - 7]
 *
 * @param jourSemaine
 * @return
 */
bool jourSemaineCorrect(unsigned short jourSemaine) {
   return jourSemaine >= 1 && jourSemaine <= 7;
}

/**
 * Vérifie que la date de début soit antérieure à la date de fin.
 *
 * @param moisDebut [1 - 12]
 * @param anneeDebut [ANNEE_MIN - ANNEE_MAX]
 * @param moisFin [1 - 12]
 * @param anneeFin [ANNEE_MIN - ANNEE_MAX]
 * @return 1 (true) si la date de début est antérieure, 0 (false) autrement
 */
bool dateDebutEstAnterieure(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin) {
   return anneeDebut < anneeFin || (anneeDebut == anneeFin && moisDebut < moisFin);
}
