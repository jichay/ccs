#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * \file  
 * \brief fichier parser avec les structures des actions et le parser
 */

/**
 * \struct action
 * \brief Structure action qui represente les actions a executer
 */
typedef struct action{
	char nom[20]; /**< nom de l'action ou du processus */
	struct action *next_s; /**< pointeur sur la prochaine action */ //Toujours utilisé
	struct action *next_e; /**< pointeur optionnel sur les actions conditionnel */ //Utilisé pour le process conditionnel
}action;

/** \brief parse le fichier a executer
 *
 * \param nom_fichier
 * \return pointeur vers le tableau des actions
 *
 */
action *parseur(char *nom_fichier);


#endif // PARSER_H_INCLUDED
