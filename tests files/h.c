#include <stdio.h>
#include <time.h>

// Structure pour représenter une date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour représenter une heure
typedef struct {
    int heure;
    int minute;
    int seconde;
} Heure;

// Vérifier si une date est valide
int isDateValide(Date date) {
    int joursDansMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.mois < 1 || date.mois > 12)
        return 0;

    if (date.jour < 1 || date.jour > joursDansMois[date.mois - 1])
        return 0;

    if (date.mois == 2 && date.jour == 29 && (date.annee % 400 == 0 || (date.annee % 4 == 0 && date.annee % 100 != 0)))
        return 1;

    return 1;
}

// Calculer le nombre de jours entre deux dates
int nombreJours(Date debut, Date fin) {
    int jours = 0;

    while (debut.jour != fin.jour || debut.mois != fin.mois || debut.annee != fin.annee) {
        jours++;

        debut.jour++;

        if (!isDateValide(debut)) {
            debut.jour = 1;
            debut.mois++;

            if (!isDateValide(debut)) {
                debut.mois = 1;
                debut.annee++;
            }
        }
    }

    return jours;
}

// Vérifier si une date est en retard en comparaison à une autre
int isRetard(Date dateEmprunt, Date dateRetour) {
    if (nombreJours(dateEmprunt, dateRetour) > 7)
        return 1;

    return 0;
}

void epm() 
{
    Date dateEmprunt;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    Date dateRetour;
    Heure heureEmprunt;
    Heure heureretourt;

    printf("Entrez le livre à emprunter : ");
    scanf("%*c%*c"); // Vider le tampon
    getchar();
    dateEmprunt.jour = tm.tm_mday;
    dateEmprunt.mois = tm.tm_mon + 1;
    dateEmprunt.annee = tm.tm_year + 1900;
    heureEmprunt.heure = tm.tm_hour;
    heureEmprunt.minute = tm.tm_min;
    heureEmprunt.seconde = tm.tm_sec;
    heureretourt.heure = tm.tm_hour;
    heureretourt.minute = tm.tm_min;
    heureretourt.seconde = tm.tm_sec;


    printf("Date d'emprunt : %02d/%02d/%4d à %02d:%02d:%02d", dateEmprunt.jour, dateEmprunt.mois, dateEmprunt.annee, heureEmprunt.heure, heureEmprunt.minute, heureEmprunt.seconde);
    getchar();
    printf("\n\nEntrez la date de retour (format : JJ/MM/AAAA) : ");
    scanf("%d/%d/%d", &dateRetour.jour, &dateRetour.mois, &dateRetour.annee);
   getchar();
    if (!isDateValide(dateRetour)) {
        printf("Date de retour invalide.\n");
        return 0;
    }

    printf("\nDate de retour : %02d/%02d/%4d à %02d:%02d:%02d ", dateRetour.jour, dateRetour.mois, dateRetour.annee, heureretourt.heure, heureretourt.minute, heureretourt.seconde);

    if (isRetard(dateEmprunt, dateRetour)) {
        printf("Retard de remise de livre!\n");

        // Vérifier le type de membre
        int membrePremium = 1; // Exemple de type de membre (0 = standard, 1 = premium)

        if (membrePremium) {
            printf("Vous avez une pénalité, vous ne pouvez emprunter que 3 livres au lieu de 5.\n");
        } else {
            printf("Vous avez une pénalité, vous ne pouvez pas emprunter de livre avant la semaine prochaine.\n");
        }
    } else {
        printf("Retour de livre à temps!\n");
    }

    return 0;
}
/*void new_Emprunt()
{  livre liv;
    int num_livre;
  printf("\t\t\t§§§§§§§    Entrez le code du livre a emprunter           §§§§§§§\n");
  printf("\t\t\t§§§§§§§    Il est generalement etiqueter sur sa gauche     §§§§§§§\n\nreponse:_");
  scanf("%d",&num_livre);
  FILE*fichier;
  fichier=fopen("livre.txt","r");
  
  if (rech_livre(num_livre)==1 || num_livre < 1000 || num_livre >9999)
   {
    fscanf(fichier,"%d;%s\n;%s\n;%d\n;%s\n",&liv.num_livre,liv.nom,liv.genre,&liv.date_creation,liv.auteur) ;
        printf("emprunt du livre :       %s \n ",liv.nom);
        int num;
        printf("\t\t\tEntrez le numéro de carte de l'emprunteur : \n");
        printf("\t\t\trepose:");
        scanf("%d", &num);
        //verification autorisation..
        FILE* F;
        F = fopen("membre.txt", "r");
    if
    (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

       membre doc;
    int trouve = 0;

    while (  fscanf(F,"%d;%s\n;%s\n;%s\n;%d\n;%s\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation)== 7) 
    {   
        
        if (doc.num_carte == num) 
        {
            trouve = 1;
            if ((strcmp(doc.couleur, "standard") == 0||strcmp(doc.couleur, "STANDARD")) == 0) 
            {
                printf("\t\tVous avez les autorisations requises pour emprunter en tant que membre standard\n\n");
                liv.num_livre=num_livre;
                 Emprunt em; 
                 fscanf(F,"%d;%s\n;%s\n;%d\n;%s\n",&liv.num_livre,liv.nom,liv.genre,&liv.date_creation,liv.auteur) ;
                 printf(" ~~~~~~les inform@tion sur le livre sont~~~~~~~:\n\n\n\n ");
                 printf("\t\t\t---------------------------------\n");
                 printf("\t\t\t|numero  |     %d                 \n",liv.num_livre);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|nom     |     %s                 \n",liv.nom);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|gerne   |     %s                 \n",liv.genre);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|dat_crée|     %d                 \n",liv.date_creation);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|auteur  |     %s                 \n",liv.auteur);
                 printf("\t\t\t---------------------------------\n\n\n");

                 FILE*fp=fopen("emprunt.txt","a+");
                 do {
                    fscanf(fp, "%d;%s\n;%s\n", &em.num_emprunt, em.date_emprunt, em.date_Retour) ;

                        printf("\t\tEntrez la date d'emprunt (jj/mm/AAAA):\n\t\tRéponse:_");
                         scanf("%10s", em.date_emprunt);

                        printf("\t\tEntrez la date de retour (jj/mm/AAAA):\n\t\tRéponse:_");
                        scanf("%10s", em.date_Retour);
                        genererCodeRetrait();
                        fprintf(fp, "%d;%s\n;%s\n", em.num_emprunt, em.date_emprunt, em.date_Retour) ;
                    } while (!feof(fp));
    
                    fclose(fp);
                 printf("\n\t§§§§§§§§§§§§§§§§ §   emprunt enregister § §§§§§§§§§§§§§§§§§§§§§§ ");

            }
             else if ((strcmp(doc.couleur, "premium") == 0) && doc.cotisation >= 34||(strcmp(doc.couleur, "PREMIUM")==0)&&doc.cotisation>=34) 
            {
                printf("\t\tVous avez les autorisations requises pour emprunter en tant que membre *premium*\n\n");
                  liv.num_livre=num_livre;
                 Emprunt em; 
                 printf(" ~~~~~~les inform@tion sur le livre sont~~~~~~~:\n\n\n\n ");
                 printf("\t\t\t---------------------------------\n");
                 printf("\t\t\t|numero  |     %d                 \n",liv.num_livre);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|nom     |     %s                 \n",liv.nom);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|gerne   |     %s                 \n",liv.genre);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|dat_crée|     %d                 \n",liv.date_creation);
                 printf("\t\t\t|--------|-----------------------|\n");
                 printf("\t\t\t|auteur  |     %s                 \n",liv.auteur);
                 printf("\t\t\t---------------------------------\n\n\n");
                 printf("\t\t\tun code d 'emprunt vous sera gener automatiquement lors de votre enregistrement\n\n\n");
                 FILE*f=fopen("emprunt.txt","a+");
                do {
                           
                            
                            fscanf(f, "%d;%s\n;%s\n", &em.num_emprunt, em.date_emprunt, em.date_Retour) ;
                            printf("\t\tEntrez la date d'emprunt (jj/mm/AAAA):\n\t\tRéponse:_");
                            scanf("%10s", em.date_emprunt);
                            getchar();
                            printf("\t\tEntrez la date de retour (jj/mm/AAAA):\n\t\tRéponse:_");
                            scanf("%10s", em.date_Retour);
                            getchar();
                            em.num_emprunt=genererCodeRetrait();
                          
                            fprintf(f, "%d;%s\n;%s\n", em.num_emprunt, em.date_emprunt, em.date_Retour) ;  
                           

                          
                    } while (!EOF)  ; 
                    printf("[  %d  ]",em.num_emprunt);
    
                    fclose(f);

                    printf("\n\t\t\t§§§§§§§§§§§§§§§§ §   emprunt enregister § §§§§§§§§§§§§§§§§§§§§§§\n ");
                    printf("\t\\ntvoici votre code d umprunt a ne pas partager \n\t\t\t§ il vous sera demander lors du retour du document §\ncode:_");
                
            } 
          /*   else if ()
            {
                retar de remise................
            }
            
            else 
            {
                printf("Vous n'avez pas le droit d'emprunter, vérifiez si vous êtes enregistré comme membre standard ou premium.\n");
            }
            break;
        }
        
    }

    if (!trouve) 
    {
        printf("\t\t\tnumero de carte introuvable\n\n");
    }

    fclose(F);
  }
  else
  {
    printf("§§§§§§§§§§§§§§§§§§§§§§§§§§    livre inexistant    §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ \n\n");
  }
  
 fclose(fichier);
  
}*/
