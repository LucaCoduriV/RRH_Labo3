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
using namespace std;
#ifndef LABO_3_FONCTIONS_H
#define LABO_3_FONCTIONS_H
bool saisieMoisAnneeCorrect( unsigned& mois,unsigned& annee );
void saisirDates( unsigned& moisDebut, unsigned& anneeDebut, unsigned&
moisFin, unsigned& anneeFin );
void afficherCalendrier(const unsigned& jourDebut, const unsigned& nombreJours, unsigned mois, unsigned annee );
unsigned dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee);
void saisieMoisAnnee(unsigned& mois, unsigned& annee);
unsigned nbreJoursMois(unsigned mois, unsigned annee);
bool estBissextile(unsigned annee);
string moisEnLitteral(unsigned);
void affichageDesCalendriers(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin);

const unsigned ANNEE_MIN = 1900, ANNEE_MAX = 2000;
#endif //LABO_3_FONCTIONS_H
