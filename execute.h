#ifndef EXECUTE_H_INCLUDED
#define EXECUTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"
#include "parser.h"
/**
 * \file
 * \brief fichier liee au flow d'execution des actions
 */

/** \brief execute liste des actions
 *
 * \param liste liste des actions
 * \param e objet etudiant sur lequel appliquer action
 *
 */
void execute_liste_rec(action *liste, etudiant *e);

#endif // EXECUTE_H_INCLUDED
