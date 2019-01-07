#include "etudiant.h"

int init_etudiant(etudiant *e, int n)
{
    int i = 0, j = 0,tmp;
    e->a_dormi = false;
    e->a_manger = false;
    e->c_est_deplacer = false;
    e->a_etudier = false;
    e->a_eu_examen = false;
    e->resultat = -1;
    e->fin = false;
    e->nbr_actions = n;
    e->derniere_action = -1;

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

int dormir(etudiant *e)
{
  if(e){
    if(e->c_est_deplacer == false)
    {
        e->derniere_action = 0;
        e->a_dormi = true;
        e->a_manger = false;
        printf("L'etudiant dors\n");
        return DONE;
    }
  }
  return FAILURE;
}

int manger(etudiant *e){
  if(e){
    e->derniere_action = 1;
    e->a_manger = true;
    printf("L'etudiant mange\n");
    return DONE;
  }
  return FAILURE;
}


int deplacer(etudiant *e){
  if(e){
    e->derniere_action = 2;
    e->c_est_deplacer = !e->c_est_deplacer;
    printf("L'etudiant se deplace\n");
    return DONE;
  }
  return FAILURE;
}

int etudier(etudiant *e){
  if(e){
    e->derniere_action = 3;
    e->a_etudier = true;
    printf("L'etudiant etudie\n");
    return DONE;
  }
  return FAILURE;
}

int examen(etudiant *e){
  if(e){
    e->derniere_action = 4;
    if(e->a_etudier && !e->a_eu_examen){
      e->a_eu_examen = true;
      printf("L'etudiant passe son examen\n");
    }
    return DONE;
  }
  return FAILURE;
}

bool resultat(etudiant *e){
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

void recommencer(etudiant *e){
  static int nb_recommencer = 0;
  init_etudiant(e,e->nbr_actions);
  nb_recommencer++;
}
