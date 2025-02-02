#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#define MAX_BUFFER 100
#define FILE_NAME "/home/tenebana/Documents/stock.txt" 

typedef enum {
    false,
    true,
} bool;

typedef struct file {
    struct file *next;
    int ID_MEMBERS;
    char NOM[MAX_BUFFER];
    char date_reservation[MAX_BUFFER];
} file;

 file *first = NULL;
 file *last = NULL;
int nb_reservation = 0;

typedef enum 
{
    FILE_ERROR,
    INPUT_ERROR,
} ErrorCode;

void print_error(ErrorCode code) {
    switch (code) {
        case FILE_ERROR:
            fprintf(stderr, "Erreur: échec de l'ouverture du fichier.\n");
            break;
        case INPUT_ERROR:
            fprintf(stderr, "Erreur: entrée invalide.\n");
            break;
    }
}

bool is_empty_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        print_error(FILE_ERROR);
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        fclose(file);
        return true;
    }
    fclose(file);
    return false;
}

int file_size(void) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        print_error(FILE_ERROR);
        exit(EXIT_FAILURE);
    }
    int size = 0;
    char line[MAX_BUFFER];
    while (fgets(line, MAX_BUFFER, file) != NULL) {
        size++;
    }
    fclose(file);
    return size;
}

int first_reservation(void) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        print_error(FILE_ERROR);
        exit(EXIT_FAILURE);
    }
    if (is_empty_file())
        exit(EXIT_SUCCESS);
    char line[MAX_BUFFER];
    if (fgets(line, MAX_BUFFER, file) != NULL) {
        char *token = strtok(line, ",");
        int ID = atoi(token);
        fclose(file);
        return ID;
    }
    fclose(file);
    exit(EXIT_SUCCESS);
}

int last_reservation(void) {
    if (is_empty_file())
        exit(EXIT_SUCCESS);
    return last->ID_MEMBERS;
}
// Ajoutez cette déclaration au début du fichier pour éviter les erreurs de segmentation lors de l'utilisation de first et last


// ...
// Veuillez considérer ces modifications à la fonction push_file()

void push_file(int ID, char name[MAX_BUFFER]) {
    file *element;
    element = malloc(sizeof(*element));
    if (element == NULL) {
        fprintf(stderr, "Erreur: allocation échouée");
        exit(EXIT_FAILURE);
    }
    element->ID_MEMBERS = ID;
    if (strlen(name) < MAX_BUFFER) {
        strcpy(element->NOM, name);
    } else {
        fprintf(stderr, "Erreur: la taille du nom dépasse la limite autorisée");
        exit(EXIT_FAILURE);
    }

    // Récupérer la date et l'heure actuelles
    time_t current_time;
    time(&current_time);
    struct tm *timeinfo = localtime(&current_time);
    strftime(element->date_reservation, MAX_BUFFER, "%Y-%m-%d %H:%M:%S", timeinfo);

    element->next = NULL;

    if (first == NULL) {
        first = element;
        last = element;
    } else {
        last->next = element;
        last = element;
    }

    nb_reservation++;

    FILE *f = fopen(FILE_NAME, "a+");
    if (f == NULL) {
        fprintf(stderr, "Erreur: impossible d'ouvrir le fichier");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "%d,%s,%s\n", element->ID_MEMBERS, element->NOM, element->date_reservation);
    fclose(f);
}
void pop_file(void) {
    if (is_empty_file())
        exit(EXIT_SUCCESS);
    file *temp = first;
    if (last == first) {
        first = NULL;
        last = NULL;
    } else {
        first = first->next;
        free(temp);
        nb_reservation--;
    }

    FILE *f = fopen(FILE_NAME, "wb");
    if (f == NULL) {
        print_error(FILE_ERROR);
        exit(EXIT_FAILURE);
    }
    file *temp1 = first;
    while (temp1 != NULL) {
        fprintf(f, "%d,%s,%s\n", temp1->ID_MEMBERS, temp1->NOM, temp1->date_reservation);
        temp1 = temp1->next;
    }
    fclose(f);
}

void clear_file(void) {
    if (is_empty_file())
        exit(EXIT_SUCCESS);
    while (!is_empty_file()) {
        pop_file();
    }

    FILE *f = fopen(FILE_NAME, "wb");
    if (f == NULL) {
        print_error(FILE_ERROR);
        exit(EXIT_FAILURE);
    }
    fclose(f);
}

void display_all_reservations(void) {
    FILE *f = fopen(FILE_NAME, "r");
    if (f == NULL) {
        print_error(FILE_ERROR);
        return;
    }

    printf("Liste des réservations :\n");
    printf("ID\t\tNom\t\tDate et heure de réservation\n\n");

    int ID_MEMBERS;
    char NOM[50];
    char date_reservation[20];

    while (fscanf(f, "%d,%[^,],%[^\n]\n", &ID_MEMBERS, NOM, date_reservation) != EOF) {
        printf("%d\t\t%s\t\t%s\n", ID_MEMBERS, NOM, date_reservation);
        
    }
    

    fclose(f);
}

bool validate_int(const char *str, int *result) {
    char *endptr;
    long val = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0' || val < 0 || val > INT_MAX) {
        return false;
    }

    *result = (int)val;
    return true;
}

int main() {
    int choix;
    int ID;
    char nom[MAX_BUFFER];
    first = NULL;
    last = NULL;
    

    do {
        printf("\nBienvenue dans le programme de gestion de file.\n");
        printf("1. Ajouter un élément à la file.\n");
        printf("2. traiter la premiere reservation.\n");
        printf("3. Afficher le premier élément de la file.\n");
        printf("4. Afficher le dernier élément de la file.\n");
        printf("5. Afficher le nombre total d'éléments dans la file.\n"); 
        printf("6. Vider la file.\n"); 
        printf("7. Afficher toutes les réservations.\n"); 
        printf("8. Quitter le programme.\n"); 
        printf("Entrez votre choix: "); 
        fflush(stdout);

 
    char input[MAX_BUFFER];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!validate_int(input, &choix)) {
        print_error(INPUT_ERROR);
        continue;
    }

    switch (choix) {
        case 1:
            printf("Entrez l'ID de la réservation: ");
            fflush(stdout);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if (!validate_int(input, &ID)) {
                print_error(INPUT_ERROR);
                break;
            }

            printf("Entrez le nom de la personne: ");
            fflush(stdout);
            fgets(nom, sizeof(nom), stdin);
            nom[strcspn(nom, "\n")] = '\0';

            push_file(ID, nom);
            printf("La réservation a été ajoutée avec succès.\n");
            break;

        case 2:
            pop_file();
            printf("La réservation a été supprimée avec succès.\n");
            break;

        case 3:
            if (is_empty_file()) {
                printf("La file est vide.\n");
            } else {
                printf("Le premier élément dans la file est: ID = %d, Nom = %s, Date de réservation = %s\n\n", first_reservation(), first->NOM, first->date_reservation); } break;

 
        case 4:
            if (is_empty_file()) {
                printf("La file est vide.\n");
            } else {
                printf("Le dernier élément dans la file est: ID = %d, Nom = %s, Date de réservation = %s\n\n", last_reservation(), last->NOM, last->date_reservation); } break;

 
        case 5:
            printf("Le nombre total d'éléments dans la file est: [%d]\n\n", nb_reservation); break;

 
        case 6:
            clear_file();
            printf("La file a été vidée avec succès.\n");
            break;

        case 7:
            display_all_reservations();
            break;

        case 8:
            printf("Sortie du programme...\n");
            break;

        default:
            printf("Choix invalide. Veuillez réessayer.\n");
    }
} while (choix != 8);

return 0;
}
