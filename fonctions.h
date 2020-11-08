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
const unsigned ANNEE_MIN = 1900, ANNEE_MAX = 2100;

bool saisieMoisAnneeCorrect(unsigned &mois, unsigned &annee);

void saisirDates(unsigned &moisDebut, unsigned &anneeDebut, unsigned &
moisFin, unsigned &anneeFin);

void afficherCalendrier(unsigned short jourDebut, unsigned nombreJours, unsigned
mois, unsigned annee);

unsigned short dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee);

void saisieMoisAnnee(unsigned &mois, unsigned &annee);

unsigned nbreJoursMois(unsigned mois, unsigned annee);

bool estBissextile(unsigned annee);

string moisEnLitteral(unsigned);

void afficherCalendriersIntervalle(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin);

bool jourCorrect(unsigned jour);

bool moisCorrect(unsigned mois);

bool anneeCorrecte(unsigned annee);

bool jourSemaineCorrect(unsigned short jourSemaine);


#endif //LABO_3_FONCTIONS_H
