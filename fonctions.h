/*
-----------------------------------------------------------------------------------
Nom du fichier : fonctions.h
Auteur(s) : Tania Nunez & Chloé Fontaine & Luca Coduri
Date creation : 6.11.2020
Description : Ce fichier contient les déclarations de toutes les fonctions
permettant l'affichage d'un calendrier.
Remarque(s) : Les bornes de ces fonctions sont définies par ANNEE_MIN et ANNEE_MAX.
Attention ! Ne pas définir une valeur en dessous de 1582 pour ANNEE_MIN car le
programme ne donnera plus les bonnes valeurs. De même pour ANNEE_MAX, ne pas
mettre une valeur plus grande que la valeur max d'un unsigned int - 1.
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
using namespace std;
#ifndef LABO_3_FONCTIONS_H
#define LABO_3_FONCTIONS_H
const unsigned ANNEE_MIN = 1900, ANNEE_MAX = 2100;

/**
 * Vérifie le type de la saisie utilisateur et si les paramètres appartiennent
 * bien à l'intervalle défini et, s'il n'y a pas d'erreurs, attribue par référence
 * les valeurs entrées par l'utilisateur aux variables entrées en paramètres.
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return true s'il n'y a pas d'erreurs
 */
bool saisieMoisAnneeCorrect(unsigned short &mois, unsigned &annee);

/**
 * Affiche tous les calendriers appartenant à l'intervalle entré en paramètres.
 * @param moisDebut [1 - 12]
 * @param anneeDebut [ANNEE_MIN - ANNEE_MAX]
 * @param moisFin [1 - 12]
 * @param anneeFin [ANNEE_MIN - ANNEE_MAX]
 */
void afficherCalendriersIntervalle(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin);

/**
 * Affiche le calendrier du mois de l'année entrés en paramètres.
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 */
void afficherCalendrier(unsigned mois, unsigned annee);

/**
 * Calcule le jour de la semaine correspondant à une date.
 * Ex: le 7 novembre 2020 vaut 6 (= samedi)
 * Reprend la formule Zeller.
 * Source: https://en.wikipedia.org/wiki/Zeller%27s_congruence
 * @param jour [1 - 31]
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return le jour de la semaine (lundi = 1, ..., dimanche = 7)
 */
unsigned short dateEnJourSemaine(unsigned jour, unsigned mois, unsigned annee);

/**
 * Renvoie le nombre de jours présent dans le mois d'une année.
 * @param mois [1 - 12]
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return le nombre de jours [28 - 30]
 */
unsigned short nbreJoursMois(unsigned mois, unsigned annee);

/**
 * Détermine si l'année entrée en paramètre est bissextile.
 * @param annee [ANNEE_MIN - ANNEE_MAX]
 * @return true si l'année est bissextile
 */
bool estBissextile(unsigned annee);

/**
 * Renvoie le nom littéral du mois entré en chiffre en paramètre.
 * @param mois [1 -12]
 * @return le mois en littéral
 */
string moisEnLitteral(unsigned);

/**
 * Vérifie que le jour appartienne à l'intervalle [1 - 31].
 * @param jour : la valeur que l'on vérifie
 * @return true si jour appartient à l'intervalle [1 - 31]
 */
bool jourCorrect(unsigned jour);

/**
 * Vérifie que le mois appartienne à l'intervalle [1 - 12].
 * @param mois : la valeur que l'on vérifie
 * @return true si mois se trouve dans l'intervalle [1 - 12]
 */
bool moisCorrect(unsigned mois);

/**
 * Vérifie que l'année appartienne à l'intervalle [ANNEE_MIN - ANNEE_MAX].
 * @param annee : la valeur que l'on vérifie
 * @return true si annee appartient à l'intervalle [ANNEE_MIN - ANNEE_MAX]
 */
bool anneeCorrecte(unsigned annee);

/**
 * Vérifie que la date de début soit antérieure à la date de fin.
 * @param moisDebut [1 - 12]
 * @param anneeDebut [ANNEE_MIN - ANNEE_MAX]
 * @param moisFin [1 - 12]
 * @param anneeFin [ANNEE_MIN - ANNEE_MAX]
 * @return true si la date de début est antérieure
 */
bool dateDebutEstAnterieure(unsigned moisDebut, unsigned anneeDebut, unsigned
moisFin, unsigned anneeFin);

#endif
