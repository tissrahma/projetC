#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
char type[20];
char saison[20];
char quantite[20] ;
} planatation ;


void afficher_planatation(GtkWidget *Liste);
void ajout_planatation(planatation P);
void supprimer_planatation(char type[20], char saison[20] , char quantite [20]);
void modifier_planatation(char type[], char saison[] , char quantite [] );
void chercher_planatation (GtkWidget *liste ,char type[]);
int plus_seche_annee();
