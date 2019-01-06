#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

char* reduc_string(char *str, char delim){
    int i = 0;
    int j = 0;
    while (str[i] != delim) {
        i++;
    }
    i++;
    char *str2 = (char*)malloc((strlen(str) - i) * sizeof(char));
    while (str[i] != '\0') {
        str2[j] = str[i];
        i++;
        j++;
    }
    str2[j++] = '\0';
    return str2;
}

int nombre_process(char *nom_fichier){
    int nb_process = 0;
    char buffer[2000];
    char buffer2[20];
    FILE *fp = NULL;

    fp = fopen(nom_fichier, "r");
    if(fp == NULL) return NULL; //preciser erreur
  	while(fscanf(fp, "%[^\n]", buffer) != EOF)
    {
        fgetc(fp);
        sscanf(buffer,"%s",buffer2);
        if(strstr(buffer2, "()") != NULL)
        {
          nb_process++;
        }
    }
    fclose(fp);
    return nb_process;
}

action * creation_maillon(char* nom_action){
    action *res=(action*)malloc(sizeof(action));
    res->next_s=NULL;
    res->next_e=NULL;
    strcpy(res->nom,nom_action);
    return res;
}

action * ajoute_en_queue_rec(action *liste, action *m)
{
    if(liste==NULL) return m;
    liste->next_s=ajoute_en_queue_rec(liste->next_s,m);
    return liste;
}

action * ajoute_queue(action * l, action * e){
    if (l==NULL)return e;
    action*temp=l;
    while(temp->next_s!=NULL)
        temp=temp->next_s;
    temp->next_s=e;
    return l;
}

action*ajout_string_queue(action* l, char*s){
    action*nouveau_maillon=creation_maillon(s);
    return ajoute_queue(l,nouveau_maillon);
}

void affiche_liste_rec(action *liste)
{
    if(liste!=NULL)
    {
        printf("%s->",liste->nom);
        affiche_liste_rec(liste->next_s);
    }
}

action *parseur(char *nom_fichier){
  	int nb_process = nombre_process(nom_fichier);
  	int pnb = 0;
    char buffer[2000];
    char buffer2[20];
    char buffer3[20];
    action *p = (action*)malloc(sizeof(action)*nb_process);
    FILE *fp = NULL;

    fp = fopen(nom_fichier, "r");
    if(fp == NULL) return NULL; //preciser erreur

    while(fscanf(fp, "%[^\n]", buffer) != EOF)
    {
        fgetc(fp); //lis le dernier '\n' pour passer a la ligne suivante
        sscanf(buffer,"%s",buffer2);
        if(strstr(buffer2, "()") != NULL)
        {
            if(strstr(buffer2, "c") != NULL)
            {
                printf("Process Condi\n");
                //read apres =
                    //if + est present ok sinon erreur
                        //get process avant present
                        //get process apres present
                    //mettre dans liste chainée
            }
            else //Process classique
            {
                sscanf(buffer2,"%s",buffer3);
                strcpy(p[pnb].nom,buffer3);
                char *reduc = reduc_string(buffer,'='); //reduit la string a partir du =
                char *ptr = strtok(reduc, " %s;"); // on vient split la string _UneAction;
                p[pnb].next_s = NULL;
                while(ptr != NULL)
                {
                    p[pnb].next_s = ajoute_en_queue_rec(p[pnb].next_s,creation_maillon(ptr));
                    ptr = strtok(NULL, " %s;");
                }
                affiche_liste_rec(p[pnb].next_s);
            }
            pnb++;
        }
        else if(strstr(buffer2, "main") != NULL)
        {
            // on regarde le process appéllé et on le stock
        }
        else
        {
            printf("Error");
        }
        //printf("%s\n",buffer2);

    }
	fclose(fp);
    return p;
}
