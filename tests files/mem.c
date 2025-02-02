#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 100

// Structure pour représenter un membre
typedef struct {
    int numero;
    char nom[50];
    char prenom[50];
    char type[20];
    float cotisation;
} Membre;

// Rechercher un membre par son numéro de carte
Membre rechercherMembre(int numero) {
    FILE* fichier = fopen("memb.txt", "a+");
    Membre membre;
    
    while (fread(&membre, sizeof(Membre), 1, fichier)) {
        if (membre.numero == numero) {
            fclose(fichier);
            return membre;
        }
    }
    
    fclose(fichier);
    membre.numero = -1; // Membre non trouvé
    return membre;
}

// Vérifier si le membre est autorisé à emprunter un livre
int est_Autorise(Membre membre) {
    if (membre.numero != -1) {
        if (strcmp(membre.type, "Premium") == 0) {
            return 1;
        } else if (strcmp(membre.type, "Standard") == 0 && membre.cotisation >= 34) {
            return 1;
        }
    }
    
    return 0;
}
int rech(int numrech)
{
     Membre doc;
    FILE *F;
    F=fopen ("memb.txt","r");
   
   do
   {
        fscanf(F,"%d;%s\n;%s\n;%s\n;%f\n",&doc.numero,doc.nom,doc.prenom,doc.type,&doc.cotisation);
        fflush(stdin);
        if (doc.numero==numrech)
        {
            fclose(F);
            return 1;
        }   
    } while (!feof(F));
   fclose(F);
   return -1;
}

// Ajouter un membre à la base de données


// Supprimer un membre de la base de données
void supprimerMembre(int numero) {
    FILE* fichier = fopen("memb.txt", "r");
    FILE* temp = fopen("temp.txt", "w");
    Membre membre;
   
    while (fread(&membre, sizeof(Membre), 1, fichier)) {
        if (membre.numero != numero) {
            fwrite(&membre, sizeof(Membre), 1, temp);
        }
    }
    
    fclose(fichier);
    fclose(temp);
    
    remove("memb.txt"); // Supprimer le fichier original
    rename("temp.txt", "memb.txt"); // Renommer temp.txt comme membre.txt
}

int main() {
    // Exemple d'utilisation des procédures
    
    // Vérification de la validité d'un membre
    ajouterMembre();

    int numeroMembre;
    printf("Veuillez fournir votre numéro de membre : ");
    scanf("%d", &numeroMembre);
    Membre membre = rechercherMembre(numeroMembre);
   /* 
    if (membre.numero == -1) {
        printf("Vous devez être membre pour pouvoir emprunter un livre.\n");
        return 0;
    }
    
    if (!estAutorise(membre)) {
        printf("Vous n'êtes pas autorisé à emprunter un livre.\n");
        return 0;
    }
    
    // Ajouter un nouveau membre
    Membre nouveauMembre;
    nouveauMembre.numero = 1234;
    strcpy(nouveauMembre.nom, "Dupont");
    strcpy(nouveauMembre.prenom, "Jean");
    strcpy(nouveauMembre.type, "Standard");
    nouveauMembre.cotisation = 50;
    
    ajouterMembre(nouveauMembre);
    
    // Supprimer un membre existant
    int numeroMembreASupprimer = 1234;
    supprimerMembre(numeroMembreASupprimer);
    */
    return 0;
}
