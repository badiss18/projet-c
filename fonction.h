#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

typedef struct Date{
int jour;
int mois;
int annee;
} date;
//struct liste
typedef struct infoUtilisateur{
int CIN;
int Nempreinte;
int Ntelephone;
char nom[30];
char prenom[30];
int municipalite;
int role;
int genre;
 date d;
}utilisateur;
//les fonctions

int ajouterUtilisateur(char * filename, utilisateur L);
int modifierUtilisateur( char * filename,int CIN,utilisateur nouvL );
int supprimerUtilisateur(char * filename, int CIN);
utilisateur chercherUtilisateur(char * filename, int CIN);


#endif // FUNCTION_H_INCLUDE
