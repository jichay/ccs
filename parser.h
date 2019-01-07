#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * \struct action
 */
typedef struct action{
	char nom[20];
	struct action *next_s; //Toujours utilisé
	struct action *next_e; //Utilisé pour le process conditionnel
}action;

/** \brief parse le fichier a executer
 *
 * \param nom_fichier
 * \return pointeur vers le tableau des actions
 *
 */
action *parseur(char *nom_fichier);


#endif // PARSER_H_INCLUDED
