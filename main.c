#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"


//Program function that is present in matrix


void linked_list_browser(char *s)
{
    //Verify if first is a Process

    if(strstr(s, "()") != NULL) //Verify if process identifier is present
    {
        printf("Test");
    }

    if (strcmp(s, "test") == 0) //Check if action exist or not
    {
      //Call certain function
    }
    else
    {
        //Default case, so action doesn't exist
    }


}

int main(){

  	srand(time(NULL));
    int i,j;
	Etudiant e1; // Création de l'étudiant

  	init_etudiant(&e1,5); // Initialisation de notre étudiant

  	/* test unitaires pour chacune des données de la structure */

  	assert(e1.nbr_actions == 5);
  	assert(e1.a_dormi == false);
    assert(e1.a_manger == false);
    assert(e1.c_est_deplacer == false);
    assert(e1.a_etudier == false);
    assert(e1.a_eu_examen == false);

  	assert(e1.resultat == -1);
  	assert(e1.fin == false);

  	/* test unitaires pour chacune des valeurs de la matrice relationnelle */
  	int tab[5][5]={{0, 1, 1, 0, 0},
                   {1, 0, 1, 1, 1},
                   {1, 1, 1, 1, 1},
                   {0, 1, 1, 1, 1},
                   {0, 1, 1, 0, 0}};

  	for(i=0;i<e1.nbr_actions; i++)
    	for(j=0;j<e1.nbr_actions;j++)
          	assert(tab[i][j] == e1.matrice_relation[i][j]);



    return EXIT_SUCCESS;
}

