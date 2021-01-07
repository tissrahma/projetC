#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"planatation.h"

enum 
{	Etype ,
	Esaison ,
	Equantite ,
	COLUMNS 
};
/////////////////////////////////
void ajout_planatation(planatation P)
{
FILE *f ;
f=fopen("planatation.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s\n",P.type,P.saison,P.quantite);
}
fclose(f);
}
////////////////////////////////
void supprimer_planatation(char type[], char saison[] , char quantite [])
{
planatation P ;
FILE *f ;
FILE *f1;
f=fopen("planatation.txt","r");
f1=fopen("planatation1.txt","w");
if((f!=NULL )&& (f1!=NULL))
{
while(fscanf(f,"%s %s %s \n",P.type ,P.saison ,P.quantite)!=EOF)
{
if(strcmp(P.type,type)!=0)
fprintf(f1,"%s %s %s \n" ,P.type,P.saison,P.quantite);
}
remove("planatation.txt");
rename("planatation1.txt","planatation.txt");
fclose(f);
fclose(f1);
}
}
/////////////////////////////////
void afficher_planatation(GtkWidget *Liste)
{ 
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter *iter ;
GtkListStore *store;
char type[20];
char saison[20];
char quantite [20] ;
FILE*f;
store=NULL;
store=gtk_tree_view_get_model(Liste);
if(store==0)
{
renderer =gtk_cell_renderer_text_new ();
column =gtk_tree_view_column_new_with_attributes("type",renderer,"text",Etype,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(Liste),column);
column= gtk_tree_view_column_new_with_attributes("saison",renderer,"text",Esaison,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(Liste),column);
renderer=gtk_cell_renderer_text_new ();
column= gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",Equantite,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(Liste),column);
store=gtk_list_store_new (COLUMNS , G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING);
}
renderer=gtk_cell_renderer_text_new ();
f=fopen("planatation.txt","r");
if(f==NULL)
{ 
return;
}
else 
{
f=fopen("planatation.txt","a+");
while(fscanf(f,"%s %s %s \n ",type,saison,quantite)!=EOF)
{         
gtk_list_store_append (store , &iter );
gtk_list_store_set(store,&iter,Etype,type,Esaison,saison,Equantite,quantite,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(Liste),GTK_TREE_MODEL (store));

g_object_unref (store);
} 
}
/////////////////////////////////
void modifier_planatation (char type[], char saison[] , char quantite [])
{ 
FILE *f ;
FILE *g ;
planatation P ;
f=fopen("planatation.txt","r");
g=fopen("planatation2.txt","a");
       
if(f!=NULL)
{
while(fscanf(f,"%s %s %s \n",P.type,P.saison,P.quantite)!=EOF)
{
if(strcmp(P.type,type)!=0)
fprintf(g,"%s %s %s \n",P.type,P.saison,P.quantite);
else 
fprintf(g,"%s %s %s \n" ,type,saison,quantite);
}

remove("planatation.txt");
rename("planatation2.txt","planatation.txt");
fclose(f);
fclose(g);
}
}
///////////////////////////////////
void chercher_planatation(GtkWidget *liste ,char type[])
{
    
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char saison[20];
char quantite[20];
store =NULL;
planatation P;
FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();           
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",Etype,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();               
column=gtk_tree_view_column_new_with_attributes("saison",renderer,"text",Esaison,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
renderer=gtk_cell_renderer_text_new();                
column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",Equantite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
renderer=gtk_cell_renderer_text_new();                		store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("planatation.txt","r");

if(f==NULL)
{
return;
}
else
	
{ 
f=fopen("planatation.txt","a+");
while(fscanf(f,"%s %s %s  \n",type,saison,quantite)!=EOF)
{
if(strcmp(P.type,type)==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Etype,type,Esaison,saison,Equantite,quantite,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}



