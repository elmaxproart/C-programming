/*int code; int commande;
    printf("entrez le code du livre a empruntercode:_");
    scanf("%d",&code);
    getchar();
    FILE*fp=fopen("livre.txt","r");
    if (fp==NULL)
    {
        printf("\t\t\terreur fopen\n");
        return;
    }

    if (rech_livre(code)==1)
    {
        livre liv;
        while (fscanf(fp,"%d;%s\n;%s\n;%d\n;%s\n;%d\n",&liv.num_livre,liv.nom,liv.genre,&liv.date_creation,liv.auteur,&liv.estdispo) == 6)
        {
            if (code == liv.num_livre)
            {

                printf(" ~~~~~~les informations sur le livre sont~~~~~~~:\n");
                printf("\t\t\t---------------------------------\n");
                printf("\t\t\t|numero  |     %d                 \n", liv.num_livre);
                printf("\t\t\t|--------|-----------------------|\n");
                printf("\t\t\t|nom     |     %s                 \n", liv.nom);
                printf("\t\t\t|--------|-----------------------|\n");
                printf("\t\t\t|gerne   |     %s                 \n", liv.genre);
                printf("\t\t\t|--------|-----------------------|\n");
                printf("\t\t\t|dat_crée|     %d                 \n", liv.date_creation);
                printf("\t\t\t|--------|-----------------------|\n");
                printf("\t\t\t|auteur  |     %s                 \n", liv.auteur);
                printf("\t\t\t|--------|-----------------------|\n");
                printf("\t\t\t|dispo   |     %d                 \n", liv.estdispo);
                printf("\t\t\t---------------------------------\n");
                
            }
        }


        
         printf("\n\t continuez avec la reservation 1 ou quitter 2 ?");
         scanf("%d",&commande);
         getchar();
         if (commande == 1  )
        {
              int num;
              printf("entrez le numero de carte du membre voulant reserver pour verification\n\nnum_carte:");
              scanf("%d", &num);
              getchar();
               FILE* f = fopen("membre.txt", "r");
               if (f == NULL)
               {
                    printf("\t\t\terreur fopen");
                    gestion_emprunt();
                }else
                {

                
                

                    if (rech(num)==1)
                    {
                        membre doc;  int estdispo=1;
                       while (fscanf(f,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n" , &doc.num_carte, doc.nom, doc.prenom, doc.couleur, &doc.contact, doc.mail, &doc.cotisation, &doc.retard) == 8)
                       {
                            if ((strcmp(doc.couleur, "premium") == 0 || strcmp(doc.couleur, "PREMIUM") == 0) && doc.cotisation >= 34)
                           {
                              FILE* r = fopen("livre.txt", "r+");
                              livre liv;
                            while (fscanf(r,"%d;%s\n;%s\n;%d\n;%s\n",&liv.num_livre,liv.nom,liv.genre,&liv.date_creation,liv.auteur) == 5)
                            {
                                
                                  
                                if (liv.num_livre == code)
                               {
                                    if (liv.estdispo)
                                    {
                                       liv.estdispo = 0;
                             
                                      printf("Le livre a été réservé par: %s", doc.nom);
                                      fseek(r, -2, SEEK_CUR);
                                      fprintf(r, "%d\n;%s\n;%s\n;%d\n;%s\n;%d\n", liv.num_livre, liv.nom, liv.genre, liv.date_creation, liv.auteur, liv.estdispo);
                                       break;
                                    }
                                     else
                                   {
                                        printf("\t\t\t! le livre n'est plus disponible !\n");
                                    }
                               }
                            }

                             fclose(r);
                           }
                else if (strcmp(doc.couleur, "standard") == 0 || strcmp(doc.couleur, "STANDARD") == 0)
                {
                    printf("\t\t\tservice réservé aux membres *premium*\nPasser premium pour y accéder !\n");
                    gestion_emprunt();
                }
                else
                {
                    printf("\n\t\t\t*vous n'avez pas les droits de reservation requis verifier aux service client*\n\t\t\t\t\t!merci!\n\n\n");
                }
                
            }
            
        }
        else 
        {
            printf("\t\t\tnumero inexistant");
        }

        fclose(f);
                }
    }
    else if (commande == 2)
    {
       gestion_emprunt();
    }
    else
    {
        printf("\t\t\tEntrez une commande valide");
    }



        
    }
    else
    {
        printf("\t\t\t§§§§§§§§§§§§§§§ ! erreur livre inexistant !   §§§§§§§§§§§§§  ");
    }

    fclose(fp);

    
   #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure pour représenter un livre
typedef struct {
    char nom[50];
    int numero;
} Livre;

// Structure pour représenter une réservation
typedef struct {
    char nomMembre[50];
    int numeroCarte;
    time_t dateReservation;
} Reservation;

// Fonction pour enregistrer les informations d'un livre dans le fichier "livre.txt"
void enregistrerLivre(Livre livre) {
    FILE *fichier = fopen("livre.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    fprintf(fichier, "%s;%d", livre.nom, livre.numero);
    fclose(fichier);
}

// Fonction pour enregistrer les informations d'une réservation dans le fichier "reservation.txt"
void enregistrerReservation(Reservation reservation) {
    FILE *fichier = fopen("reservation.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }
    fprintf(fichier, "%s;%d;%ld", reservation.nomMembre, reservation.numeroCarte, reservation.dateReservation);
    fclose(fichier);
}

// Fonction principale
int main() {
    Livre livre;
    printf("Nom du livre : ");
    fgets(livre.nom, 50, stdin);
    livre.nom[strcspn(livre.nom, "\n")] = '\0';  // Supprimer le caractère de saut de ligne

    printf("Numéro du livre : ");
    scanf("%d", &livre.numero);
    getchar();  // Supprimer le caractère de saut de ligne résiduel

    enregistrerLivre(livre);

    Reservation reservation;
    printf("Nom du membre : ");
    fgets(reservation.nomMembre, 50, stdin);
    reservation.nomMembre[strcspn(reservation.nomMembre, "\n")] = '\0';  // Supprimer le caractère de saut de ligne

    printf("Numéro de carte du membre : ");
    scanf("%d", &reservation.numeroCarte);
    getchar();  // Supprimer le caractère de saut de ligne résiduel

    // Obtenir la date et l'heure actuelles
    reservation.dateReservation = time(NULL);

    enregistrerReservation(reservation);

    printf("Réservation effectuée avec succès.\n");

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

void reserverLivre(char* nom, int numeroCarteMembre) {
    time_t tempsActuel;
    struct tm* tempsLocal;
    char reservation[100];
    FILE* fichierReservation;

    // Obtenir le temps local actuel
    tempsActuel = time(NULL);
    tempsLocal = localtime(&tempsActuel);

    // Formater la date de réservation
    strftime(reservation, sizeof(reservation), "%d/%m/%Y %H:%M:%S", tempsLocal);

    // Ouvrir le fichier de réservations en mode ajout
    fichierReservation = fopen("reservation.txt", "a+");
    if (fichierReservation == NULL) {
        printf("Erreur lors de l'ouverture du fichier de réservations.\n");
        exit(1);
    }

    // Écrire les informations de réservation dans le fichier
    fprintf(fichierReservation, " :%s", nom);
    fprintf(fichierReservation, " : %d", numeroCarteMembre);
    fprintf(fichierReservation, " : %s", reservation);

    // Fermer le fichier de réservations
    fclose(fichierReservation);

    printf("Le livre a été réservé avec succès.\n");
}

int main() {
    char nomLivre[100];
    int numeroCarteMembre;

    printf("Bienvenue dans le système de réservation de la bibliothèque.\n");

    printf("Nom du livre à réserver : ");
    fgets(nomLivre, sizeof(nomLivre), stdin);

    printf("Numéro de carte de membre : ");
    scanf("%d", &numeroCarteMembre);

    // Supprimer le caractère de saut de ligne du nom du livre
    nomLivre[strlen(nomLivre) - 1] = '\0';

    reserverLivre(nomLivre, numeroCarteMembre);

    return 0;
}
