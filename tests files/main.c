/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

// Structure pour stocker les informations d'un emprunt
typedef struct {
    char membre[MAX_LENGTH];
    char manuel[MAX_LENGTH];
    time_t timestamp_emprunt;
    int delai_remise;
} Emprunts;

// Fonction pour enregistrer un emprunt
void enregistrer_emprunt() 
{
    Emprunts emprunt;

    // Saisie des informations de l'emprunt
    printf("Membre: ");
    fgets(emprunt.membre, MAX_LENGTH, stdin);
    emprunt.membre[strcspn(emprunt.membre, "\n")] = '\0';

    printf("Manuel emprunté: ");
    fgets(emprunt.manuel, MAX_LENGTH, stdin);
    emprunt.manuel[strcspn(emprunt.manuel, "\n")] = '\0';

    emprunt.timestamp_emprunt = time(NULL);

    printf("Délai de remise (en jours): ");
    scanf("%d", &emprunt.delai_remise);

    // Enregistrement de l'emprunt dans le fichier
    FILE* fichier = fopen("emprunts.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(fichier, "%s,%s,%ld,%d\n", emprunt.membre, emprunt.manuel, emprunt.timestamp_emprunt, emprunt.delai_remise);

    fclose(fichier);

    printf("Emprunt enregistré avec succès.\n");
}

// Fonction pour vérifier le statut de l'emprunt
void verifier_emprunt() {
    char membre[MAX_LENGTH];
    printf("Membre: ");
    fgets(membre, MAX_LENGTH, stdin);
    membre[strcspn(membre, "\n")] = '\0';

    time_t timestamp_actuel = time(NULL);

    FILE* fichier = fopen("emprunts.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    char ligne[MAX_LENGTH];
    while (fgets(ligne, MAX_LENGTH, fichier)) {
        char membre_emprunt[MAX_LENGTH];
        char manuel[MAX_LENGTH];
        time_t timestamp_emprunt;
        int delai_remise;

        sscanf(ligne, "%[^,],%[^,],%ld,%d", membre_emprunt, manuel, &timestamp_emprunt, &delai_remise);

        if (strcmp(membre_emprunt, membre) == 0) {
            struct tm* tm_emprunt = localtime(&timestamp_emprunt);
            struct tm* tm_remise = localtime(&timestamp_emprunt);
            tm_remise->tm_mday += delai_remise;
            time_t timestamp_remise = mktime(tm_remise);
            
            double difference_temps = difftime(timestamp_actuel, timestamp_remise);
            int jours_retard = difference_temps / (24 * 60 * 60);

            if (jours_retard > 0) {
                // Mise à jour du statut du membre en retard
                FILE* fichier_membres = fopen("membres.txt", "a");
                if (fichier_membres == NULL) {
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    return;
                }

                fprintf(fichier_membres, "%s,%d\n", membre, jours_retard);
                fclose(fichier_membres);

                printf("Le membre %s est en retard de %d jour(s).\n", membre, jours_retard);
            } else {
                int jours_avance = abs(jours_retard);
                printf("Le membre %s est en avance de %d jour(s).\n", membre, jours_avance);
            }

            fclose(fichier);
            return;
        }
    }

    printf("Aucun emprunt enregistré pour ce membre.\n");
    fclose(fichier);
}

int main() {
    int choix;

    do {
        printf("1. Enregistrer un emprunt\n");
        printf("2. Vérifier l'état de l'emprunt\n");
        printf("3. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        getchar(); // Supprimer le caractLa réponse a été tronquée. Voici la suite du co
        switch (choix) {
            case 1:
                enregistrer_emprunt();
                break;
            case 2:
                verifier_emprunt();
                break;
            case 3:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 3);

    return 0;
}*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>
#define MAX_LENGTH 100

// Structure pour stocker les informations d'un emprunt 
typedef struct { 
char membre[MAX_LENGTH]; 
char manuel[MAX_LENGTH]; 
time_t timestamp_emprunt; 
time_t timestamp_remise; 
int delai_remise; 
} Emprunts;

// Fonction pour enregistrer un emprunt 
void enregistrer_emprunt() 
{ 
Emprunts emprunt;


// Saisie des informations de l'emprunt
printf("Membre: ");
fgets(emprunt.membre, MAX_LENGTH, stdin);
emprunt.membre[strcspn(emprunt.membre, "\n")] = '\0';

printf("Manuel emprunté: ");
fgets(emprunt.manuel, MAX_LENGTH, stdin);
emprunt.manuel[strcspn(emprunt.manuel, "\n")] = '\0';

emprunt.timestamp_emprunt = time(NULL);

printf("Délai de remise (en jours): ");
scanf("%d", &emprunt.delai_remise);


struct tm* tm_remise = localtime(&emprunt.timestamp_emprunt);
tm_remise->tm_mday += emprunt.delai_remise;
emprunt.timestamp_remise = mktime(tm_remise);
printf("date:%s  \n",asctime(tm_remise));
// Enregistrement de l'emprunt dans le fichier
FILE* fichier = fopen("emprunts.txt", "a");
if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
}

fprintf(fichier, "%s,%s,%ld,%ld,%d\n", emprunt.membre, emprunt.manuel, emprunt.timestamp_emprunt, emprunt.timestamp_remise, emprunt.delai_remise);

 
fclose(fichier);

printf("Emprunt enregistré avec succès.\n");
}

// Fonction pour vérifier le statut de l'emprunt 
void verifier_emprunt() 
{ char membre[MAX_LENGTH]; printf("Membre: "); 
fgets(membre, MAX_LENGTH, stdin); 
membre[strcspn(membre, "\n")] = '\0';

 
time_t timestamp_actuel = time(NULL);

FILE* fichier = fopen("emprunts.txt", "r");
if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
}

char ligne[MAX_LENGTH];
while (fgets(ligne, MAX_LENGTH, fichier)) {
    char membre_emprunt[MAX_LENGTH];
    char manuel[MAX_LENGTH];
    time_t timestamp_emprunt;
    time_t timestamp_remise;
    int delai_remise;

    sscanf(ligne, "%[^,],%[^,],%ld,%ld,%d", membre_emprunt, manuel, &timestamp_emprunt, &timestamp_remise, &delai_remise);
  
    if (strcmp(membre_emprunt, membre) == 0) {
        struct tm* tm_remise = localtime(&timestamp_remise);
        time_t timestamp_remise_reelle = mktime(tm_remise);
        
        double difference_temps = difftime(timestamp_actuel, timestamp_remise_reelle);
        int jours_retard = difference_temps / (24 * 60 * 60);

        if (jours_retard > 0) {
            // Mise à jour du statut du membre en retard
            FILE* fichier_membres = fopen("membres.txt", "a");
            if (fichier_membres == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return;
            }

            fprintf(fichier_membres, "%s,%d", membre, jours_retard); 
            fclose(fichier_membres);

 
            printf("Le membre %s est en retard de %d jour(s).\n", membre, jours_retard);
            printf(" les infos:%s,%s,%ld,%ld,%d", membre_emprunt, manuel, timestamp_emprunt, timestamp_remise, delai_remise);
            // Vérification de l'amende
            if (jours_retard >= 7) {
                printf("Le membre ne peut pas emprunter pendant une semaine et doit payer une amende de 10 euros.\n");
            }
        } else {
            int jours_avance = abs(jours_retard);
            printf("Le membre %s est en avance de %d jour(s).\n", membre, jours_avance);
             printf(" les infos:%s,%s,%ld,%ld,%d", membre_emprunt, manuel, timestamp_emprunt, timestamp_remise, delai_remise);
        }

        fclose(fichier);
        return;
    }
}

printf("Aucun emprunt enregistré pour ce membre.\n");
fclose(fichier);
}

int main()
{ 
int choix;

 
do {
    printf("1. Enregistrer un emprunt\n"); 
    printf("2. Vérifier l'état de l'emprunt\n "); 
    printf("3. Quitter\n ");
    printf("Choix: "); 
    scanf("%d", &choix);

 

    getchar(); // Supprimer le caractère de saut de ligne

    switch (choix) {
        case 1:
            enregistrer_emprunt();
            break;
        case 2:
            verifier_emprunt();
            break;
        case 3:
            printf("Au revoir.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
} while (choix != 3);

return 0;
}



