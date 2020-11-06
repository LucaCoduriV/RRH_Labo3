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
void saisieMoisAnnee(unsigned int& mois, unsigned int& annee);
unsigned int nbreJoursMois(unsigned int mois, unsigned annee);
bool estBissextile(unsigned int annee);
void affichagePreambuleCalendrier(unsigned int mois, unsigned int annee);
string moisEnLitteral(unsigned int);
void affichageDesCalendriers(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin);
#endif //LABO_3_FONCTIONS_H
