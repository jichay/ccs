#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

/**
 * \file 
 * \brief fichier etudiant avec ses variables et ses fonctions liee
 */

#define DONE 1 /**< define action reussite */
#define FAILURE 0 /**< define action fail */

/**
 * \struct etudiant
 * \brief Structure etudiant qui represente l'objet sur lequel les actions seront execute.\n
 *   actions possibles :
 *       1) dormir
 *       2) manger
 *       3) deplacer
 *       4) etudier
 *       5) examen
 */
typedef struct etudiant{
    
    bool a_dormi; /**< bool pour savoir si il a dormi */
    bool a_manger; /**< bool pour savoir si il a mange */
    bool c_est_deplacer; /**< bool pour savoir si il c'est deplace */
    bool a_etudier; /**< bool pour savoir si il a etudie */
    bool a_eu_examen; /**< bool pour savoir si il a eu son examen */
    int resultat; /**< sont resultat d'examen (entre 0 et 20) */
    bool fin; /**< bool pour savoir si ses actions sont fini */
    int derniere_action; /**< int pour connaitre l'id de la derniere action */
    int nbr_actions; /**< nombre d'action associe a l'objet */

    int matrice_relation[5][5]; /**< matrice de relation des actions */

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
 * \param e
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
