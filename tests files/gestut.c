#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct bibliotheque {
    char nom[100];
    int identifiant;
    int mot_de_passe;
} bibliotheque;

void menu_principale_publique() {
    // Code pour le menu de la bibliothèque publique
}

void menu_principale() {
    // Code pour le menu de la bibliothèque privée
}

void bienvenue() {
    // Code pour accueillir les utilisateurs
}

void gere_bibliotheque() {
    int rep, rep1, id;
    bibliotheque bio;

    printf("\t|**************************************************************************************************************************************|\n");
    printf("\n\t|********************************************** WELCOME TO CREATION AND GETION HOME ***************************************************|\n");


    printf("\n\t|**************************************************************************************************************************************|\n");
    sleep(3);
    system("clear");
    printf("\n\t\t\t\t******** CHOISIR LE TYPE DE BIBLIOTHEQUE A GERER... ********\n");
    printf("\t\t\t[1] Mini bibliotheque \n");
    printf("\t\t\t[2] Grande bibliotheque");
    printf("Reponse : ");
    scanf("%d", &rep);

    printf("\n\t\t\t\t********BIBLIOTHEQUE PUBLIQUE (1) OU PRIVEE (2) ? ********\n");
    printf("Reponse : ");
    scanf("%d", &rep1);

    FILE* fichier = NULL;

    if (rep1 == 1) {
        fichier = fopen("mini_b_pu.txt", "a+");

        if (fichier == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            sleep(1);
            system("clear");
            exit(0);
        } else {
            printf("\n\t\t\t\t******** Entrez les informations de cette bibliotheque ********\n");

            printf(" SON NOM (EN UN SEUL MOT) : ");
            scanf("%s", bio.nom);
            getchar();
            printf("IDENTIFIANT : ");
            scanf("%d", &bio.identifiant);

            printf("MOT DE PASSE : ");
            scanf("%d", &bio.mot_de_passe);

            fprintf(fichier, "%s;%d;%d", bio.nom, bio.identifiant, bio.mot_de_passe);

            fclose(fichier);
            printf("\t\t\t\t******** LA BIBLIOTHEQUE EST ENREGISTRÉ ********\n");
            printf("\t\t\t\t******** VOULEZ-VOUS y ACCEDER (1) OU SORTIR (2) ? ********\n");
            printf("Reponse : ");
            scanf("%d", &rep);

            if (rep == 1) {
                int id_temp;
                int mot_de_passe_temp;

                FILE* fichier = NULL;
                printf("§§§§§§§*    ETAIT-ELLE PUBLIQUE [1] OU PRIVEE[2]  ?  *§§§§");
                scanf("%d", &rep);
                if (rep1 == 1) {
                    fichier = fopen("mini_b_pu.txt", "r");
                } else if (rep1 == 2) {
                    fichier = fopen("mini_b_pr.txt", "r");
                }

                if (fichier == NULL) {
                    printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
                    exit(0);
                }
                do {
                    fscanf(fichier, "%s;%d;%d\n", bio.nom, &bio.identifiant, &bio.mot_de_passe);

                h:
                    printf("Identifiant de cette bibliotheque : ");
                    scanf("%d", &id_temp);

                    if (id_temp == bio.identifiant) {
                        printf("Mot de passe : ");
                        scanf("%d", &mot_de_passe_temp);

                        if (mot_de_passe_temp == bio.mot_de_passe) {
                            menu_principale_publique();
                        } else {
                            printf("Erreur : Mot de passe non reconnu, veuillez réessayer!\n");
                            scanf("%d", &mot_de_passe_temp);
                        }
                    } else {
                        printf("Erreur : Identifiant non reconnu comme pré-existant, veuillez réessayer!\n");
                        sleep(2);
                        goto h;
                    }

                } while (!feof(fichier));
                fclose(fichier);
            } else if (rep == 2) {
                sleep(2);
                system("clear");
                bienvenue();
            }
        }
    }

    else if (rep1 == 2) {
        FILE* fich;
        fich = fopen("mini_b_pr.txt", "a+");

        if (fich == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            exit(0);
        } else {
            printf("\t\t\t\t******** Entrez les informations de cette bibliotheque ********\n");
            fprintf(fich, "\n");
            printf("SON NOM (En un seul mot) : ");
            scanf("%s", bio.nom);
            getchar();

            printf("Identifiant : ");
            scanf("%d", &bio.identifiant);

            printf("Mot de passe : ");
            scanf("%d", &bio.mot_de_passe);
            fprintf(fich, "%s;%d;%d", bio.nom, bio.identifiant, bio.mot_de_passe);
            fclose(fich);
            printf("\t\t\t\t******** LA BIBLIOTHEQUE EST ENREGISTRÉ ********\n");
            printf("\t\t\t\t******** VOULEZ-VOUS y ACCEDER (1) OU SORTIR (2) ? ********\n");
            printf("Reponse : ");
            scanf("%d", &rep);

            if (rep == 1) {
                int id_temp;
                int mot_de_passe_temp;

                FILE* fich = NULL;
                printf("§§§§§§§*    ETAIT ELLE PUBLIQUE [1] ou priveé[2]  ?  *§§§§\nreponce:");
                scanf("%d", &rep);
                if (rep1 == 1) {
                    fich = fopen("mini_b_pu.txt", "r");
                } else if (rep1 == 2) {
                    fich = fopen("mini_b_pr.txt", "r");
                }

                if (fich == NULL) {
                    printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
                    exit(0);
                }

                fscanf(fich, "%[^;];%d;%d", bio.nom, &bio.identifiant, &bio.mot_de_passe);

            F:
                printf("Identifiant de cette bibliotheque : ");
                scanf("%d", &id_temp);

                if (id_temp == bio.identifiant) {
                    printf("Mot de passe : ");
                    scanf("%d", &mot_de_passe_temp);

                    if (mot_de_passe_temp == bio.mot_de_passe) {
                        menu_principale();
                    } else {
                        printf("Erreur : Mot de passe incorrect, veuillez réessayer!\n");
                        sleep(2);
                        goto F;
                    }
                } else {
                    printf("Erreur : Identifiant NON RECONNUE, veuillez réessayer!\n");
                    sleep(2);
                    goto F;
                }

                fclose(fich);
            } else if (rep == 2) {
                sleep(2);
                system("clear");
                bienvenue();
            }
        }
    }
}

int main() {
    gere_bibliotheque();
    return 0;
}
