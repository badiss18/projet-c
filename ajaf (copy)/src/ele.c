#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ele.h"


enum
{
	ECIN,
	ENEMPREINTE,
	ENTELEPHONE,
	ENOM,
	EPRENOM,
	EJOUR,
	EMOIS,
	EANNEE,
	EMUNICIPALITE,
	EGENRE,
	EROLE,
	EVOTE,
	COLUMNS,
};

void ajouterUtilisateur(utilisateur L)
{FILE *f=fopen("user.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote);
      
fclose(f);
}
}

//AFF

void afficher_utilisateur(GtkWidget *liste)
{


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char CIN[30];
	char Nempreinte[30];
	char Ntelephone[30];
	char nom[30];
	char prenom[30];
	char jour[30];
	char mois[30];
	char annee[30];
	char municipalite[30];
	char genre[30];
	char role[30];
	char vote[30];

	utilisateur L;

	store=NULL;
	FILE* f=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", ECIN , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Nempreinte", renderer, "text", ENEMPREINTE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Ntelephone", renderer, "text", ENTELEPHONE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRENOM , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text", EMUNICIPALITE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("genre", renderer, "text", EGENRE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("role", renderer, "text", EROLE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("vote", renderer, "text", EVOTE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("user.txt","r");
	if(f==NULL)
	{return;
	}	
	else 
	{

		f=fopen("user.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",CIN,Nempreinte,Ntelephone,nom,prenom,jour,mois,annee,municipalite,genre,role,vote)!=EOF)
		{	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store,&iter, ECIN, CIN, ENEMPREINTE, Nempreinte,ENTELEPHONE,Ntelephone,ENOM,nom,EPRENOM,prenom, EJOUR, jour, EMOIS, mois, EANNEE, annee,EMUNICIPALITE, municipalite,EGENRE,genre,EROLE,role,EVOTE,vote,-1);
		}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
// RECHERCHE
utilisateur cherUtilisateur( char CIN[])
{
    utilisateur L;
    int tr=0;
    FILE *f=fopen("user.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote)!=EOF)
        {   
            if (strcmp(L.CIN,CIN)==0)
                tr=1;
        }
 
    }
    fclose(f);
    if(tr==0){
	strcpy(L.CIN,"-1");}
    return L;
}
//supprimer
void supprimer_user(utilisateur L)
    {   utilisateur L1;
	FILE *f, *g;
	f=fopen("user.txt","r");
	g=fopen("user1.txt","w");
	if(f==NULL || g==NULL)
	  { return;
	  }
	else
	{ while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L1.CIN,L1.Nempreinte,L1.Ntelephone,L1.nom,L1.prenom,L1.d.jour,L1.d.mois,L1.d.annee,L1.municipalite,L1.genre,L1.role,L1.vote)!=EOF)
	   {
if( strcmp(L.CIN,L1.CIN)!=0 || strcmp(L.Nempreinte,L1.Nempreinte)!=0 || strcmp(L.Ntelephone,L1.Ntelephone)!=0 || strcmp(L.nom,L1.nom)!=0 ||strcmp(L.prenom,L1.prenom)!=0 || strcmp(L.d.jour,L1.d.jour)!=0 || strcmp(L.d.mois,L1.d.mois)!=0 || strcmp(L.d.annee,L1.d.annee)!=0 || strcmp(L.municipalite,L1.municipalite)!=0 || strcmp(L.genre,L1.genre)!=0 || strcmp(L.role,L1.role)!=0 || strcmp(L.vote,L1.vote)!=0) 
fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L1.CIN,L1.Nempreinte,L1.Ntelephone,L1.nom,L1.prenom,L1.d.jour,L1.d.mois,L1.d.annee,L1.municipalite,L1.genre,L1.role,L1.vote);
	   }
fclose(f);
fclose(g);
remove("user.txt");
rename("user1.txt","user.txt");
	}
    }

