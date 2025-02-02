#include <stdio.h>
#include <stdlib.h>

int main() {
    char nom[50];
    char prenom[50];
    char livre[50];
    int annee;

    
    printf("Entrez votre nom : ");
    scanf("%s", nom);

    printf("Entrez votre prénom : ");
    scanf("%s", prenom);

    printf("Entrez le nom du livre emprunté : ");
    scanf("%s", livre);

    printf("Entrez l'année de l'emprunt : ");
    scanf("%d", &annee);

    
    char *commande=malloc(sizeof(char)*2000);
    sprintf(commande, "echo \"Nom : %sPrénom : %sLivre emprunté : %sAnnée de l'emprunt : %d\" | lp -d /home/tenebana/Documents", nom, prenom, livre, annee);

    
    system(commande);

    return 0;
}
