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
        3) déplacer
        4) étudier
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
 * \brief Initialise tout les composants de etudiant
 * \param e
 * \param n
 * \return issu de l'excécution
 */
int init_etudiant(etudiant *e, int n);

/**
 * \brief simuler dormir pour l'etudiant (changer etat interne structure)
 * \param E
 * \return issu de l'excécution
 */
int dormir(etudiant *e);

/**
 * \brief simuler manger pour l'etudiant (changer etat interne structure)
 * \param e
 * \return issu de l'excécution
 */
int manger(etudiant *e);

/**
 * \brief simuler deplacer pour l'etudiant (changer etat interne structure)
 * \param e
 * \return issu de l'excécution
 */
int deplacer(etudiant *e);

/**
 * \brief simuler etudier pour l'etudiant (changer etat interne structure)
 * \param e
 * \return issu de l'excécution
 */
int etudier(etudiant *e);

/**
 * \brief simuler examen pour l'etudiant (changer etat interne structure)
 * \param e
 * \return issu de l'excécution
 */
int examen(etudiant *e);

/**
 * \brief permet de savoir si l'etudiant a ru son examen
 * \param e
 * \return true si il a eu son examen sinon false
 */
bool resultat(etudiant *e);

/**
 * \brief permet de recommencer
 * \param e
 */
void recommencer(etudiant *e);

#endif // ETUDIANT_H_INCLUDED
