#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#define DONE 1
#define FAILURE 0

/**
 * \struct etudiant
 */
typedef struct etudiant{
    /*
    actions possibles :
        1) dormir
        2) manger
        3) d�placer
        4) �tudier
        5) examen
    */
    bool a_dormi;
    bool a_manger;
    bool c_est_deplacer;
    bool a_etudier;
    bool a_eu_examen;
    int resultat;
    bool fin;
    int derniere_action;
    int nbr_actions;

    int matrice_relation[5][5];

} etudiant;

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \param n
 * \return issu de l'exc�cution
 */
int init_etudiant(etudiant *e, int n);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
int dormir(etudiant *e);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
int manger(etudiant *e);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
int deplacer(etudiant *e);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
int etudier(etudiant *e);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
int examen(etudiant *e);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
bool resultat(etudiant *e);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'exc�cution
 */
void recommencer(etudiant *e);

#endif // ETUDIANT_H_INCLUDED
