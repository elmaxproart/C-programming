#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMBERS 100
#define MAX_BOOKS 100

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
} Membre;

typedef struct {
    int id;
    char titre[100];
    char auteur[100];
} Livre;

typedef struct {
    int membreId;
    int livreId;
    char dateEmprunt[20];
    char dateRetour[20];
} Emprunt;

Membre membres[MAX_MEMBERS];
int nbMembres = 0;

Livre livres[MAX_BOOKS];
int nbLivres = 0;

Emprunt emprunts[MAX_BOOKS];
int nbEmprunts = 0;

int rechercherMembre(int id) {
    for (int i = 0; i < nbMembres; i++) {
        if (membres[i].id == id) {
            return i;
        }
    }
    return -1;
}

int rechercherLivre(int id) {
    for (int i = 0; i < nbLivres; i++) {
        if (livres[i].id == id) {
            return i;
        }
    }
    return -1;
}

void enregistrerEmprunt() {
    int membreId, livreId;
    char dateEmprunt[20], dateRetour[20];

    printf("Formulaire d'emprunt :\n");
    printf("ID du membre : ");
    scanf("%d", &membreId);
    printf("ID du livre : ");
    scanf("%d", &livreId);

    // Vérification de membre
    int membreIndex = rechercherMembre(membreId);
    if (membreIndex == -1) {
        printf("Ce membre n'existe pas.\n");
        return;
    }

    // Vérification de livre
    int livreIndex = rechercherLivre(livreId);
    if (livreIndex == -1) {
        printf("Ce livre n'existe pas.\n");
        return;
    }

    // Vérification de retard
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    strftime(dateEmprunt, sizeof(dateEmprunt), "%d-%m-%Y", tm_struct);
    tm_struct->tm_mday += 7;
    mktime(tm_struct);
    strftime(dateRetour, sizeof(dateRetour), "%d-%m-%Y", tm_struct);

    strcpy(emprunts[nbEmprunts].dateEmprunt, dateEmprunt);
    strcpy(emprunts[nbEmprunts].dateRetour, dateRetour);
    emprunts[nbEmprunts].membreId = membreId;
    emprunts[nbEmprunts].livreId = livreId;
    nbEmprunts++;

    printf("Emprunt enregistré avec succès.\n");
}

void trierEmprunts() {
    // Tri des emprunts par date d'emprunt
    for (int i = 0; i < nbEmprunts - 1; i++) {
        for (int j = 0; j < nbEmprunts - i - 1; j++) {
            struct tm tm1, tm2;
            memset(&tm1, 0, sizeof(struct tm));
            memset(&tm2, 0, sizeof(struct tm));
            
            strptime(emprunts[j].dateEmprunt, "%d-%m-%Y", &tm1);
            strptime(emprunts[j+1].dateEmprunt, "%d-%m-%Y", &tm2);
            
            time_t time1 = mktime(&tm1);
            time_t time2 = mktime(&tm2);
            
            if (time1 > time2) {
                Emprunt temp = emprunts[j];
                emprunts[j] = emprunts[j+1];
                emprunts[j+1] = temp;
            }
        }
    }

    // Mise à jour du fichier de registre
    FILE *registreFile = fopen("register.txt", "w");
    if (registreFile == NULL) {
        printf("Impossible d'ouvrir le fichier register.txt.\n");
        return;
    }

    fprintf(registreFile, "Emprunts par ordre d'emprunt :\n");
    fprintf(registreFile, "Nom\tPrénom\tID membre\tID livre\tDate emprunt\tDate retour\tRetard");
    fprintf(registreFile, "--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < nbEmprunts; i++) {
        int membreIndex = rechercherMembre(emprunts[i].membreId);
        int livreIndex = rechercherLivre(emprunts[i].livreId);
        
        fprintf(registreFile, "%s\t%s\t%d\t%d\t%s\t%s\t", membres[membreIndex].nom, membres[membreIndex].prenom, emprunts[i].membreId, emprunts[i].livreId, emprunts[i].dateEmprunt, emprunts[i].dateRetour);
        
        struct tm tm_retour;
        memset(&tm_retour, 0, sizeof(struct tm));
        strptime(emprunts[i].dateRetour, "%d-%m-%Y", &tm_retour);
        time_t time_retour = mktime(&tm_retour);
        
        time_t now = time(NULL);
        if (time_retour < now) {
            fprintf(registreFile, "Retard");
        } else {
            fprintf(registreFile, "À temps");
        }
    }

    fclose(registreFile);

    printf("Les emprunts ont été triés et enregistrés dans register.txt.\n");
}

void afficherRegistre() {
    FILE *registreFile = fopen("register.txt", "r");
    if (registreFile == NULL) {
        printf("Impossible d'ouvrir le fichier register.txt.\n");
        return;
    }

    char caractere;
    while ((caractere = fgetc(registreFile)) != EOF) {
        printf("%c", caractere);
    }

    fclose(registreFile);
}

int main() {
    int choix;
    do {
        printf("\n-- Menu --\n");
        printf("1. Enregistrer un emprunt\n");
        printf("2. Trier les emprunts et enregistrer dans register.txt\n");
        printf("3. Afficher le registre\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                enregistrerEmprunt();
                break;
            case 2:
                trierEmprunts();
                break;
            case 3:
                afficherRegistre();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 4);

    return 0;
}

