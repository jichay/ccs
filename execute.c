#include "execute.h"


void execute_liste_rec(action *liste, etudiant *e)
{
    if(liste!=NULL)
    {
        if(strcmp(liste->nom,"dormir") == 0)
        {
            if(e->derniere_action == -1){
                if(dormir(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }else if(e->matrice_relation[e->derniere_action][0]){
                if(dormir(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }
        }
        else if(strcmp(liste->nom,"manger") == 0)
        {
            if(e->derniere_action == -1){
                if(manger(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }else if(e->matrice_relation[e->derniere_action][1]){
                if(manger(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }
        }
        else if(strcmp(liste->nom,"deplacer") == 0)
        {
            if(e->derniere_action == -1){
                deplacer(e);
            }else if(e->matrice_relation[e->derniere_action][2]){
                deplacer(e);
            }
        }
        else if(strcmp(liste->nom,"etudier") == 0)
        {
            if(e->derniere_action == -1){
                if(etudier(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }else if(e->matrice_relation[e->derniere_action][3]){
                if(etudier(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }
        }
        else if(strcmp(liste->nom,"examen") == 0)
        {
            if(e->derniere_action == -1){
                if(examen(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }else if(e->matrice_relation[e->derniere_action][4]){
                if(examen(e) == FAILURE){
                    printf("Action non réalisable!\n");
                    return EXIT_FAILURE;
                }
            }
        }
        else if(strstr(liste->nom, "()") != NULL)
        {
            printf("Action conditionnel sur resultat examen\n");
            if(resultat(e)){
                printf("L'etudiant a eu son examen\n");
            }else{
                printf("L'etudiant n'a pas eu son examen ou n'a pas encore passe son exam\n");
            }
        }
        else
        {
            printf("ERROR");
            return EXIT_FAILURE;
        }
        execute_liste_rec(liste->next_s,e);
    }
}

/*int execute(action *p, char *point_entrer)
{
    etudiant *e = (etudiant*)malloc(sizeof(etudiant));
    int i = 0;
    int nb_process = nombre_process("main.ccs");
    //Créer etudiant
    for(i = 0; i < nb_process; i++)
    {
        if(strcmp(p[i].nom,point_entrer) == 0)
        {
            //on parcour la liste
                //si () alors on
            //if(execute_action());
        }
    }

    return EXIT_SUCCESS;
}*/
