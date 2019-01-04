#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#define DONE 1;
#define FAILURE 0;

typedef struct Etudiant{

      bool a_dormi;
      bool a_manger;
      bool c_est_deplacer;
      bool a_etudier;
      bool a_eu_examen;
      int resultat;
      bool fin;
      int nbr_actions;

      int matrice_relation[5][5];

} Etudiant;

int init_etudiant(Etudiant *e, int);
int dormir(Etudiant *e);
int manger(Etudiant *e);
int deplacer(Etudiant *e);
int etudier(Etudiant *e);
int examen(Etudiant *e);
bool resultat(Etudiant *e);
void recommencer(Etudiant *e);

#endif // ETUDIANT_H_INCLUDED
