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
#ifndef LABO_3_FONCTIONS_H
#define LABO_3_FONCTIONS_H
void moisAnneeCorrect( unsigned& mois,unsigned& annee );
void saisirDates( unsigned& moisDebut, unsigned& anneeDebut, unsigned&
moisFin, unsigned& anneeFin );
void afficherMoisAnnee( const unsigned& jourDebut, const unsigned& nombreJours );
void moisAnneeCorrect(int& mois,int& annee);
void saisirDates(int& moisDebut, int& anneeDebut, int& moisFin, int& anneeFin);
unsigned jsemaineDT(const unsigned& jour, const unsigned& mois, const unsigned&
annee);
#endif //LABO_3_FONCTIONS_H
