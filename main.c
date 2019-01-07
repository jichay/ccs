#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "etudiant.h"
#include "execute.h"




int main(){

  	srand(time(NULL));
    int i,j;
	etudiant e1; // Création de l'étudiant

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

    action *p = parseur("main.ccs");

    assert(strcmp(p[0].nom,"E()") == 0);
    assert(strcmp(p[1].nom,"Rc()") == 0);
    assert(strcmp(p[0].next_s->nom,"dormir") == 0);

    execute_liste_rec(p[0].next_s, &e1); //L'etudiant peut avoir son examen il faut relancer pour avoir un resultat different

    free(p);
    return EXIT_SUCCESS;
}
