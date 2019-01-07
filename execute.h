#ifndef EXECUTE_H_INCLUDED
#define EXECUTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"
#include "parser.h"

/** \brief execute liste des actions
 *
 * \param liste des actions
 * \param objet etudiant sur lequel appliquer action
 *
 */

void execute_liste_rec(action *liste, etudiant *e);

#endif // EXECUTE_H_INCLUDED
