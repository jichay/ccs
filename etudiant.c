#include "etudiant.h"

int init_etudiant(Etudiant *e, int n){
    int i = 0, j = 0,tmp;

    e->a_dormi = false;
    e->a_manger = false;
    e->c_est_deplacer = false;
    e->a_etudier = false;
    e->a_eu_examen = false;
    e->resultat = -1;
    e->fin = false;
    e->nbr_actions = n;

  	FILE* fichier = NULL;
    fichier = fopen("./config_etudiant.txt", "r");
    if(fichier == NULL)
    {
        printf("Le fichier n'est pas ouvert");
        return EXIT_FAILURE;
    }

    for(i=0;i<e->nbr_actions; i++)
    {
    	for(j=0;j<e->nbr_actions;j++){
      		fscanf(fichier,"%d ", &tmp);
          	if(tmp == 0 || tmp == 1){
              e->matrice_relation[i][j] = tmp;
            }else{
              return EXIT_FAILURE;
            }
    	}
        fscanf(fichier,"\n");
    }
    fclose(fichier);
  	return EXIT_SUCCESS;
}

int dormir(Etudiant *e){
  if(e){
    if(e->c_est_deplacer == false){
        e->a_dormi = true;
        e->a_manger = false;
        return DONE;
    }
  }
  return FAILURE;
}

int manger(Etudiant *e){
  if(e){
    e->a_manger = true;
    return DONE;
  }
  return FAILURE;
}


int deplacer(Etudiant *e){
  if(e){
    e->c_est_deplacer = !e->c_est_deplacer;
    return DONE;
  }
  return FAILURE;
}

int etudier(Etudiant *e){
  if(e){
    e->a_etudier = true;
    return DONE;
  }
  return FAILURE;
}

int examen(Etudiant *e){
  if(e){
    if(e->a_etudier && !e->a_eu_examen) e->a_eu_examen = true;
    return DONE;
  }
  return FAILURE;
}

bool resultat(Etudiant *e){
  if(e){
    if(e->a_eu_examen){
      int note=rand()%21;
      e->resultat = note;
      if(e->resultat>=10){
            return true;
      }
    }
  }
  return false;
}

void recommencer(Etudiant *e){
  static int nb_recommencer = 0;
  init_etudiant(e,e->nbr_actions);
  nb_recommencer++;
}
