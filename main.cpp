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
using namespace std;


const string NOMSJOURS[] =
   {"Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi"};
/**
Nom d’un jour de semaine en toutes lettres
@param[in] jsem - numéro jour de semaine dans (0=dimanche,...,6=samedi)
@return le nom de jsem en toutes lettres
*/
string nomJSemaine(int jsem)
{
   return NOMSJOURS[jsem];
}


int main() {
   int mois;
   int annee;
   //moisAnneeCorrect(mois, annee);


   cout << nomJSemaine(jsemaineDT(6,11,2020));
   return EXIT_SUCCESS;
}


