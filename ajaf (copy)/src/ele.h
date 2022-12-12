
#include <gtk/gtk.h>
typedef struct Date{
char jour[30];
char mois[30];
char annee[30];
} date;
//struct liste
typedef struct Utilisateur{
char CIN[30];
char Nempreinte[30];
char Ntelephone[30];
char nom[30];
char prenom[30];
date d;
char municipalite[30];
char genre[30];
char role[30];
char vote[30];


}utilisateur;

void ajouterUtilisateur(utilisateur L);
void afficher_utilisateur(GtkWidget *liste);
utilisateur cherUtilisateur( char CIN[]);
void supprimer_user(utilisateur L);
