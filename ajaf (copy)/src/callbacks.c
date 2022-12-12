#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ele.h"
#include <string.h>
int g=1;
utilisateur LL;
utilisateur badis;
//affichage
void
on_bajtree_row_activated               (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* CIN;
        gchar* Nempreinte;
	gchar* Ntelephone;
        gchar* nom;
	gchar* prenom;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* municipalite;
	gchar* genre;
        gchar* role;
	gchar* vote;

	utilisateur L;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &CIN, 1, &Nempreinte, 2, &Ntelephone, 3, &nom, 4, &prenom, 5,&jour,6,&mois,7, &annee,8,&municipalite,9,&genre,10,&role,11,&vote, -1);

strcpy(L.CIN,CIN);	
strcpy(L.Nempreinte,Nempreinte);
strcpy(L.Ntelephone,Ntelephone);
strcpy(L.nom,nom);
strcpy(L.prenom,prenom);
strcpy(L.d.jour,jour);
strcpy(L.d.mois,mois);
strcpy(L.d.annee,annee);
strcpy(L.municipalite,municipalite);
strcpy(L.genre,genre);
strcpy(L.role,role);
strcpy(L.vote,vote);

	supprimer_user(L);

	afficher_utilisateur(treeview);
	}
}



void
on_bafrf_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_bafsu_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_bafmo_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajj;
	GtkWidget *afff;
	afff=lookup_widget(objet,"bajmo");
	gtk_widget_destroy(afff);
	ajj=create_bajmo();
	gtk_widget_show (ajj);



}

/*
void
on_bafaj_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
utilisateur L;
char CIN;
char Nempreinte;
char Ntelephone;
char nom[30];
char prenom[30];
char jour;
char mois;
char annee;
char municipalite;
char genre;
char role;
char vote;
GtkWidget *CIN, *Nempreinte ,*Ntelephone, *nom, *prenom, *jour,*mois,*annee,*municipalite,*genre,*role,*vote;
GtkWidget *window;
window=lookup_widget(objet,"useraj");
CIN=lookup_widget(objet,"bjcin");
Nempreinte=lookup_widget(objet,"bajmdp");
Ntelephone=lookup_widget(objet,"bajntel");
nom=lookup_widget(objet,"bajnom");
prenom=lookup_widget(objet,"bajprenom");
jour=lookup_widget(objet,"bajj");
mois=lookup_widget(objet,"bajm");
annee=lookup_widget(objet,"baja");
municipalite=lookup_widget(objet,"bajmun");
genre=lookup_widget(objet,"bajgenre");
role=lookup_widget(objet,"bajrole");
vote=lookup_widget(objet,"bajvote");

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
an=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee2));

sprintf(jour,"%d",j);
sprintf(mois,"%d",m);
sprintf(annee,"%d",an);


strcpy(e.del.jour2,jour);
strcpy(e.del.mois2,mois);
strcpy(e.del.annee2,annee);


strcpy(c.CIN, gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(c.Nempreinte, gtk_entry_get_text(GTK_ENTRY(Nempreinte)));
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.municipalite, gtk_entry_get_text(GTK_ENTRY(municipalite)));
strcpy(c.genre, gtk_entry_get_text(GTK_ENTRY(genre)));
strcpy(c.role, gtk_entry_get_text(GTK_ENTRY(role)));
strcpy(c.vote, gtk_entry_get_text(GTK_ENTRY(vote)));




}*/


void
on_bafre_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
char idch[50];
int  j1, m1, a1;
utilisateur L;
utilisateur Lb;

//declarer les GTKwidget.
	GtkWidget *recherch,*entry,*retour,*modif,*sup,*view,*ref,*jourb,*moisb,*anneeb,*municipaliteb,*label;

/* *windowb, *CINb, *Nempreinteb ,*Ntelephoneb, *nomb, *prenomb, *jourb,*moisb,*anneeb,*municipaliteb,*genreb,*roleb,*voteb,*recherch;

windowb=lookup_widget(objet,"userajm");
CINb=lookup_widget(objet,"bajcinm");
Nempreinteb=lookup_widget(objet,"bajmdpm");
Ntelephoneb=lookup_widget(objet,"bajntelm");
nomb=lookup_widget(objet,"bajnomm");
prenomb=lookup_widget(objet,"bajprem");
roleb=lookup_widget(objet,"bajrolem");
voteb=lookup_widget(objet,"bajvotem");
recherch=lookup_widget(objet,"entry8");*/


//window=lookup_widget(objet,"bajmo");
entry=lookup_widget(objet,"entry8");
label=lookup_widget(objet,"baffex");
/*recherch=lookup_widget(objet,"bafrch");
ref=lookup_widget(objet,"bafref");
sup=lookup_widget(objet,"bafsup");
modif=lookup_widget(objet,"bafmod");
retour=lookup_widget(objet,"bafret");
view=lookup_widget(objet,"bajtree");*/


strcpy(idch,gtk_entry_get_text(GTK_ENTRY(entry)));
//app
 

	
	LL=cherUtilisateur(idch);	
	if(strcmp(LL.CIN,"-1")!=0){ 
	GtkWidget *existance;
existance= lookup_widget (objet ,"baffex");
gtk_label_set_text(GTK_LABEL(existance),"existe !");
gtk_widget_show (existance);}

        /* j1 = atoi (LL.d.jour);
	 m1 = atoi (LL.d.mois);
	 a1 = atoi (LL.d.annee);


	jourb=lookup_widget(objet, "bajj");
         gtk_spin_button_set_value(jourb,j1);
	 moisb=lookup_widget(objet, "bajm");
         gtk_spin_button_set_value(moisb,m1);
	 anneeb=lookup_widget(objet,"baja");
         gtk_spin_button_set_value(anneeb,a1);

municipaliteb=lookup_widget(objet,"bajmun");
	 if(strcmp(LL.municipalite,"Gafsa")==0){
         	gtk_combo_box_set_active(municipaliteb,0);}
	 else if(strcmp(LL.municipalite,"Tunise")==0){
         	gtk_combo_box_set_active(municipaliteb,1);}
	else if(strcmp(LL.municipalite,"sousse")==0){
         	gtk_combo_box_set_active(municipaliteb,2);}
	 else if(strcmp(LL.municipalite,"Gabes")==0){
         	gtk_combo_box_set_active(municipaliteb,3);}
	 else if(strcmp(LL.municipalite,"Sfaxe")==0){
         	gtk_combo_box_set_active(municipaliteb,4);}*/
 	else /*if(strcmp(L.CIN,"-1")!=0)*/
			{
         	GtkWidget *existance;
existance= lookup_widget (objet ,"baffex");
gtk_label_set_text(GTK_LABEL(existance),"N'existe pas !");
gtk_widget_show (existance);}
}


void
on_bajgf_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
g=1;


}


/*void
on_bajgh_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
g=2;
}*/


void 
on_bajaj_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{

utilisateur L;

char jourj[30];
char moisj[30];
char anneej[30];
char genrej[30];
int j,m,an;
GtkWidget *CIN, *Nempreinte ,*Ntelephone, *nom, *prenom, *jour,*mois,*annee,*municipalite,*genre,*role,*vote;
GtkWidget *window;
window=lookup_widget(objet,"useraj");
CIN=lookup_widget(objet,"bajcin");
Nempreinte=lookup_widget(objet,"bajmdp");
Ntelephone=lookup_widget(objet,"bajntel");
nom=lookup_widget(objet,"bajnom");
prenom=lookup_widget(objet,"bajpre");
jour=lookup_widget(objet,"bajj");
mois=lookup_widget(objet,"bajm");
annee=lookup_widget(objet,"baja");
municipalite=lookup_widget(objet,"bajmun");
//genre=lookup_widget(objet,"bajgf");
//genre=lookup_widget(objet,"bajgf");
role=lookup_widget(objet,"bajrole");
vote=lookup_widget(objet,"bajvote");


sprintf(genrej,"%d",g);
sprintf(jourj,"%d",j);
sprintf(moisj,"%d",m);
sprintf(anneej,"%d",an);

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
an=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));




strcpy(L.d.jour,jourj);
strcpy(L.d.mois,moisj);
strcpy(L.d.annee,anneej);


strcpy(L.CIN, gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(L.Nempreinte, gtk_entry_get_text(GTK_ENTRY(Nempreinte)));
strcpy(L.Ntelephone, gtk_entry_get_text(GTK_ENTRY(Ntelephone)));
strcpy(L.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(L.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(L.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
//strcpy(L.genre, gtk_entry_get_text(GTK_ENTRY(genre)));
strcpy(L.role, gtk_entry_get_text(GTK_ENTRY(role)));
strcpy(L.vote, gtk_entry_get_text(GTK_ENTRY(vote)));

ajouterUtilisateur(L);
}


void
on_bafret_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
affiche=lookup_widget(objet,"useraj");

gtk_widget_destroy(affiche);

ajout=create_useraj();
gtk_widget_show(ajout);

}

/*
void
on_bajgh_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
g=2;

}*/


void
on_bajaff_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
GtkWidget *treeview;

ajout=lookup_widget(objet,"useraj");
gtk_widget_destroy(ajout);

affiche=create_useraf();
gtk_widget_show(affiche);

treeview=lookup_widget(affiche,"bajtree");
	afficher_utilisateur(treeview);


}


void
on_bajgh_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
g=2;

}


void
on_bmodaff_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *modif, *affiche;
GtkWidget *treeview;

modif=lookup_widget(objet,"bajmo");
gtk_widget_destroy(modif);

affiche=create_useraf();
gtk_widget_show(affiche);

treeview=lookup_widget(affiche,"bajtree");
	afficher_utilisateur(treeview);

}


void
on_bmobr_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
char cinch[50];
int  j1, m1, a1;
utilisateur L;


//declarer les GTKwidget.
	GtkWidget *recherch,*entry,*retour,*modif,*sup,*view,*ref,*jourb,*moisb,*anneeb,*municipaliteb,*windowb, *CINb, *Nempreinteb ,*Ntelephoneb, *nomb, *prenomb,*genrebh,*genrebf,*roleb,*voteb;

//windowb=lookup_widget(objet,"userajm");
CINb=lookup_widget(objet,"bajcinm");
Nempreinteb=lookup_widget(objet,"bajmdpm");
Ntelephoneb=lookup_widget(objet,"bajntelm");
nomb=lookup_widget(objet,"bajnomm");
prenomb=lookup_widget(objet,"bajprem");
roleb=lookup_widget(objet,"bajrolem");
voteb=lookup_widget(objet,"bajvotem");
//municipaliteb=lookup_widget(objet,"bajmunm");
recherch=lookup_widget(objet,"bmor");


genrebh=lookup_widget(objet,"bajgh");
genrebf=lookup_widget(objet,"bajgfm");
/*recherch=lookup_widget(objet,"bafrch");
ref=lookup_widget(objet,"bafref");
sup=lookup_widget(objet,"bafsup");*/
modif=lookup_widget(objet,"bajam");
moisb=lookup_widget(objet,"bajmm");
jourb=lookup_widget(objet,"bajjm");


strcpy(cinch, gtk_entry_get_text(GTK_ENTRY(recherch)));
//app
	LL=cherUtilisateur(cinch);
	if(strcmp(L.CIN,"-1")!=0)
	{ 
/*toggle
if(strcmp(L.genre,"1")){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(genrebf),TRUE);
}
else if(strcmp(L.genre,"0")){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(genrebh),TRUE);
}*/
	gtk_entry_set_text(GTK_ENTRY(CINb),LL.CIN);

	gtk_entry_set_text(GTK_ENTRY(Nempreinteb), LL.Nempreinte);

	gtk_entry_set_text(GTK_ENTRY(Ntelephoneb), LL.Ntelephone);

	gtk_entry_set_text(GTK_ENTRY(nomb), LL.nom);

	gtk_entry_set_text(GTK_ENTRY(prenomb), LL.prenom);
	gtk_entry_set_text(GTK_ENTRY(roleb), LL.role);

	gtk_entry_set_text(GTK_ENTRY(voteb), LL.vote);
	
	//gtk_widget_show (Nempreinteb); 
	

	j1 = atoi (LL.d.jour);
	 m1 = atoi (LL.d.mois);
	 a1 = atoi (LL.d.annee);

	 jourb=lookup_widget(objet, "bajjm");
         gtk_spin_button_set_value(jourb,j1);
	 moisb=lookup_widget(objet, "bajmm");
         gtk_spin_button_set_value(moisb,m1);
	 anneeb=lookup_widget(objet,"bajam");
         gtk_spin_button_set_value(anneeb,a1);



municipaliteb=lookup_widget(objet,"bajmunm");
	 if(strcmp(LL.municipalite,"Gafsa")==0){
         	gtk_combo_box_set_active(municipaliteb,0);}
	 else if(strcmp(LL.municipalite,"Tunise")==0){
         	gtk_combo_box_set_active(municipaliteb,1);}
	else if(strcmp(LL.municipalite,"sousse")==0){
         	gtk_combo_box_set_active(municipaliteb,2);}
	 else if(strcmp(LL.municipalite,"Gabes")==0){
         	gtk_combo_box_set_active(municipaliteb,3);}
	 else if(strcmp(LL.municipalite,"Sfaxe")==0){
         	gtk_combo_box_set_active(municipaliteb,4);}

strcpy(cinch,gtk_entry_get_text(GTK_ENTRY(recherch)));


}
}

