#include <stdio.h>
#include <string.h>
#include "fonction.h"

int main()
{
     utilisateur L1={12,11,1,"issaoui","badis",1,1,2,3,1,2};
     utilisateur L3={112,15,10,"kekli","karim",10,10,10,10,10,10};
     utilisateur L4={10,15,10,"oussama","rami",10,10,10,10,10,10},L2;


     int x ;

   x=ajouterUtilisateur("utilisateur.txt",L4);

    if(x==1)
        printf("\najout de Lutilisateur avec succees!!!!!!!!!");
    else printf("\nechec ajout");

    x=modifierUtilisateur("utilisateur.txt",10,L1);
    if(x==1)
        printf("\nModification de lutisateur avec succes");
    else printf("\nechec Modification");
 x=supprimerUtilisateur("utilisateur.txt",10);
    if(x==1)
        printf("\nSuppression de utilisateur avec succes");
    else printf("\nechec Suppression");
 L3=chercherUtilisateur("utilisateur.txt",10);
    if(L3.CIN==-1)
    {
        printf("introuvable");
    }else if (L3.CIN!=-1)
     {
         printf("existe!!!\n");
    }
    return 0;
}
