#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct action{
	char nom[20];
	struct action *next_s; //Toujours utilisé
	struct action *next_e; //Utilisé pour le process conditionnel
}action;

typedef struct process{
    char* nom;
    struct action *next;
}process;



action *parseur(char *nom_fichier);


#endif // PARSER_H_INCLUDED
