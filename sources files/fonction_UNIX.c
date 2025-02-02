//WELCOME TO UNIX_MAX THANK FOR DOWNLOAD
//made by unix team............................................................................................................................................*/
/*L'ENSEMBLE DES COMMANDE DE CE PROGRMME FONCTIONNE SUIVANT DES BRANCHEMENT ENTIERS ET CARACTERES
POUR TOUS SOUCI VEUILLEZ LES POSER A LA PARTIE "ABOUT"
//entete du programme..........................................................................................................................................*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "fonction_UNIX.h"
#include <unistd.h>
#include <limits.h>

//constantes...................................................................................................................................................

#define MAX_LENGTH 1000
#define MAX_BUFFER 1000

//structures:GLOBALE PARAMETERS.....................................................................................................................................................
 
 bibiotheque bio;
 membre  doc;
file *first = NULL;
file *last = NULL;
int nb_reservation = 0;

//fichiers de sauvegardes............................................................................................................................................................
#define BIBLI "../backup/creébilbi.txt"
#define PRI_BIBLI "../backup/mini_b_pr.txt"
#define PUB_BIBLI "../backup/mini_b_pu.txt"
#define USER "../backup/users.txt"
#define ABOUT "../backup/ABOUT.txt"
#define MEMBERS "../backup/membre.txt"
#define AUTHORS "../backup/auteur.txt"
#define BOOKS "../backup/livres.txt"
#define EMPRUNTS "../backup/emprunts.txt"
#define EVENTS "../backup/evenement1.txt"
#define ABOUT1 "../backup/event1.txt"
#define EVENTS2 "../backup/event2.txt"
#define ABOUT2 "../backup/evenment2.txt"
#define FILE_NAME "../backup/stock.txt"
//--------------------------------------------------------------------------------------------------




void systeme() {
    printf("Appuyez sur une touche pour continuer...\n");
    getchar(); 
}


//pavions d'entre dans unix_max ...............................................................................................................................
void bienvenue()
{
    system("clear");
    printf("\n_____________________________________\n");
    printf("||||||||||||||||||||||||||||||||||||");system("date");printf("|\n");
    printf("_____________________________________\n");
    printf("\n\n\n\n\n\n_________________________________________________________________________________________________________\n\n");
  d:  printf("\t\t\t\t\033[38;2;255;165;0m|VOUS POUVEZ APPUIYER  SUR \033[0;31m'S'\033[0m \033[38;2;255;165;0mPOUR 'SKIP' L'INTERFACE DE PRESENTATION|\033[0m\n\t\t\t\t\t\t|OU \033[0;31m'C'\033[0m POUR 'CONTINUÉ'|\n\n");
     printf("\n\t\t\t_________________________________________________________________________________________________________________\n");
     sleep(2);
     char r;
     scanf("%s",&r);
     if (r=='s'||r=='S')
     {
        system("clear");
        goto A;
     }else if (r=='C'||r=='c')
     {
        system("clear");
        logo();
    sleep(2);
   
     log1(); 
     
    int rep ;

 welcome();
printf("\t\t\t\t\t\t|THANK YOU  FOR CHOOSING US !|\n\t\t\t\t\t\t|MERCI DE VOTRE CONFIANCE    |\n\n\n");
printf("\t\t\t\t\t\t1-POUR CONTINUEZ...\n\nt\t\t\t\t\t\t2-PARAMETRE\n\t\t\t\t\t\t3-SORTIR\n\n");

 char input[20];
    INB:printf("\t\t\t\tANSWER:_");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto INB;
    }

    rep = atoi(input);

sleep(1);
if (rep==1)
{
    system("clear");
   
     GER() ;
    system("clear");

  A:  printf("\t\t\t\t§§§§§§§§§§§§§§§   CONNECTER VOUS A VOTRE COMPTE UNIX     §§§§§§§§§§§§§§§§§\n\n");
    int option;
    printf("\t\t\t\t\t\tChoisissez une option:\n");
    printf("\t\t\t\t\t\t  1. SE CONNECTER A UNIX    |<[...]\n");
    printf("\t\t\t\t\t\t  2. CRÉE UN COMPTE UNIX    |<[a;b]\n");
     
    INC:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto INC;
    }

    option = atoi(input);

    if (option == 1) 
    {
        sleep(2);
        system("clear");
        loginProcedure();
       sleep(2);
    } else if (option == 2) 
    {
         sleep(2);
        system("clear");
        registerProcedure();
        sleep(4);
    } 
    else 
    {
        printf("Option invalide.\n");
        sleep(2);
        goto A;
    }
//..............................................................................................................
}
else if(rep==3)
{
    sleep(3);
  exit(EXIT_SUCCESS);
}
else if(rep==2)
{
    sleep(1);
    system("clear");
    parametres();

}

else if (rep!=1||rep!=2||rep!=3)
{
    while (rep!=1||rep!=2||rep!=3)
    {
        printf("\t\t\t\t§§§§§§§§§§§§ ENTREZ UNE COMMANDE VALABLE !  §§§§§§§§§§§§§§§§§§§\n\n\n");
    }
    
}
sleep(1);
system("clear");
printf("\t\t\tque voulez vous faire ?\n");
printf("\t\t\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
printf("\t\t\t\t§§§§§§§§§  crée une bibliotheque [1] §§§§§§§§§§\n");
printf("\t\t\t\t§§§§§§§§§  j'en ai déja crée une [2] §§§§§§§§§§\n");
printf("\t\t\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§z\n\n");
  
    IN:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IN;
    }

    rep = atoi(input);


if (rep==1)
{
    sleep(1);
    system("clear");
   geré_bilbiotheque (); 
    
}
else if(rep==2)
{
     sleep(1);
    system("clear");
   
        FILE*cr_bil=fopen(BIBLI,"r");
       printf("connecter vous as elle \n\n");
      printf("\t\t\t\tELLE ETAIT PUBLIQUE [2] OU  PRIVÉE[1]\n\nCHOICE:");
      char input[20];
    IC:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IC;
    }

    rep = atoi(input);

if (rep==1) {
        sleep(1);
        system("clear");
        printf("\n\n\n\t\t\t\t\t\t******** VOULEZ-VOUS Y ACCEDER (1)? OU SORTIR(2) ? ********\n");
        printf("Reponse : ");
        char input[20];
    IX:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IX;
    }

    rep = atoi(input);


    if (rep ==1 ) 
    {
        int id_temp;
        int mot_de_passe_temp;

         int rep1;
        FILE* fich = NULL;
            fich = fopen(PRI_BIBLI, "r");
        if (fich == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            exit(0);
        }
         fscanf(fich, "%s %d %d\n", bio.nom, &bio.identifiant, &bio.mot_de_passe);
       f: printf("Identifiant de cette bibiotheque : ");
        scanf("%d", &id_temp);

        if (id_temp == bio.identifiant) 
        {
            printf("Mot de passe : ");
            scanf("%d", &mot_de_passe_temp);

            if (mot_de_passe_temp == bio.mot_de_passe) {
                printf("MERCI BIBLIOTHEQUE TROUVÉ\n\n");
                sleep(2);
                system("clear");
                menu_principale();
            } else {
                printf("Erreur : MOT DE PASSE INCORRECT, PLEACE TRY AIGAIN!\n");
                sleep(2);
                goto f;
            }
        } else {
            printf("Erreur : INDENTIFIANT INTROUVABLE, VEILLEZ RÉÉSAYER!\n\n");
            sleep(2);goto f;
        }

        fclose(fich);
    } else if (rep == 2) 
    {
     bienvenue();
        
    }

    }
    else if (rep==2)
    {
        sleep(1);
        system("clear");
      printf("\t\t\t\t******** VOULEZ-VOUS Y ACCEDER (1) OU SORTIR (2) ? ********\n");
       char input[20];
    I:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto I;
    }

    rep = atoi(input);


    if (rep == 1) 
    {
         sleep(1);
         system("clear");
        int id_temp;
        int mot_de_passe_temp;

         int rep1;
        FILE* fichier = NULL;
            fichier = fopen(PUB_BIBLI, "r");
        if (fichier == NULL) {
            printf("\t\t\t\tUne erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            exit(0);
        }
        fscanf(fichier, "%s %d %d\n", bio.nom, &bio.identifiant, &bio.mot_de_passe);

       g: printf("Identifiant de cette bibiotheque : ");
        scanf("%d", &id_temp);

        if (id_temp == bio.identifiant) 
        {
            printf("Mot de passe : ");
            scanf("%d", &mot_de_passe_temp);

            if (mot_de_passe_temp == bio.mot_de_passe) {
                menu_principale_publique();
            } else {
                printf("\n\n\t\t\t\tErreur : Mot de passe incorrect, veuillez reessayer!\n");
                sleep(2);
                goto g;
            }
        } else {
            printf("\n\n\t\t\t\t\t\tErreur : Identifiant non reconnue, veuillez reessayer!\n");
            sleep(2);
            goto g;
        }

        fclose(fichier);
    } else if (rep == 2) 
    {
     bienvenue();
        
    }
    }
      
      
       
        
        
}
else if(rep!=1||rep!=2)
{
    printf("\n\n\t\t\t\t\t§§§§§§§§§§§§§  entrez une commande valable  §§§§§§§§§§§§§§§§\n\n");
}
     }else
     {
        system("clear");
        goto d;
     }
     
     
    
     
     
    


}
void welcome()

{
    printf("\n");
    char*tab=(char*)malloc(sizeof(char*));
    tab="\t\t\t\t\t\t\033[38;2;255;165;0mWELCOME TO UNIX_MAX!\033[0m\n";
    int i,taille_phrase;
    taille_phrase=strlen(tab);
    for ( i = 0; i < taille_phrase; i++)
    {
       
        printf("%c",tab[i]);
        fflush(stdout);
        
        usleep(100000);
    }
    printf("\n");
       sleep(1);
}
void GER() {
    char mots[] = "\t\t\t\t\t\t\033[38;2;255;165;0mGERE LES LIVRES!\033[0m\n\t\t\t\t\t\t\033[0;32mGERE LES EMPRUNTS\033[0m\n,\t\t\t\t\t\tRESERVER DANS UNIX \n\t\t\t\t\t\t ET BIEN D'AUTRES DANS UNIX_MAX\n";
    int len = sizeof(mots);
    for (int i = 0; i < len; i++) {
        printf("%c", mots[i]);
        fflush(stdout); 
        usleep(100000);
    }
    sleep(1);
    printf("\n");

}

void geré_bilbiotheque() 
{
    int rep, rep1, id;
     bibiotheque bio;

    printf("\t|**************************************************************************************************************************************|\n");
    printf("\n\t|********************************************** WELCOME TO CREATION AND GETION HOME ***************************************************|\n");
    
    
    printf("\n\t|**************************************************************************************************************************************|\n");
    sleep(3);
    system("clear");
  c:printf("\n\t\t\t\t******** CHOISIR LE TYPE DE BIBLIOTHEQUE A GERER... ********\n");
    printf("\t\t\t[1] Mini bibliotheque \n");
    printf("\t\t\t[2] Grande bibliotheque");
    char input[20];
    IN:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IN;
    }

    rep = atoi(input);

    

    printf("\n\n\t\t\t\t********BIBLIOTHEQUE PUBLIQUE (1) OU PRIVÉE (2) ? ********\n");
    printf("Reponse : ");
    
    IX:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IX;
    }

    rep = atoi(input);


    FILE* fichier = NULL;

    if (rep1 == 1) 
    {
        fichier = fopen(PUB_BIBLI, "a+");

        if (fichier == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
             sleep(1);
             system("clear");
            exit(0);
        }
        else
        {
           printf("\n\n\t\t\t\t******** Entrez les informations de cette bibliotheque ********\n");
          
     printf(" SON NOM (EN UN SEUL MOT) : ");
     scanf("%s",bio.nom);
    getchar();
    printf("IDENTIFIANT : ");
    
    IC:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IC;
    }

    bio.identifiant = atoi(input);

    
    printf("MOT DE PASSE : ");
    
    IV:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IV;
    }

    bio.mot_de_passe = atoi(input);

    
    fprintf(fichier, "%s %d %d\n", bio.nom, bio.identifiant, bio.mot_de_passe);
   
    fclose(fichier);
    printf("\t\t\t\t******** LA BIBLIOTHEQUE EST ENREGISTRÉ ********\n\n\n");
    printf("\t\t\t\t******** VOULEZ-VOUS y ACCEDER (1) OU SORTIR (2) ? ********\n");
   char input[20];
    IR:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IR;
    }

    rep = atoi(input);

    if (rep == 1) 
    {
        int id_temp;
        int mot_de_passe_temp;


        FILE* fichier = NULL;
        printf("§§§§§§§*    ETAIT-ELLE PUBLIQUE [1] OU PRIVÉE[2]  ?  *§§§§");
        char input[20];
    IB:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IB;
    }

    rep = atoi(input);

        if (rep1 == 1) 
        {
            fichier = fopen(PUB_BIBLI, "r");
        } else if (rep1 == 2) 
        {
            fichier = fopen(PRI_BIBLI, "r");
        }

        if (fichier == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            exit(0);
        }
      
        fscanf(fichier, "%s %d %d\n", bio.nom, &bio.identifiant, &bio.mot_de_passe);
        

      h:  printf("Identifiant de cette bibiotheque : ");
        
    IL:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IL;
    }

    bio.identifiant = atoi(input);


        if (id_temp == bio.identifiant) 
        {
            printf("Mot de passe : ");
            
    IO:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IO;
    }

    bio.mot_de_passe = atoi(input);


            if (mot_de_passe_temp == bio.mot_de_passe) {sleep(1);
        system("clear");

                menu_principale_publique();
            } else {
                printf("Erreur : Mot de passe non reconnue, veuillez reessayer!\n");
                scanf("%d", &mot_de_passe_temp);
            }
        } else {
            printf("Erreur : Identifiant non reconnue comme pré-existante, veuillez reessayer!\n");
            sleep(2);
            goto h;
        }

      fclose(fichier);



        
    } else if (rep == 2) 
    {
        sleep(2);
        system("clear");
        bienvenue();
        
    }
        }
    }

    ///////////////////////////////////////////////////////////////////////////////
     else if (rep1 == 2) 
     {
        FILE*fich;
        fich = fopen(PRI_BIBLI, "a+");

        if (fich == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            exit(0);
        }
        else
        {
           printf("\t\t\t\t******** Entrez les informations de cette bibliotheque ********\n");
           fprintf(fich,"\n");
    printf("SON NOM (En un seul mot) : ");
   scanf("%s",bio.nom);
   getchar();
    
    printf("Identifiant :\n ");
    
    IP:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IP;
    }

    bio.identifiant = atoi(input);


    
    printf("Mot de passe :\n ");
     IP1:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IP1;
    }

    bio.mot_de_passe = atoi(input);

    
    fprintf(fich, "%s %d %d\n", bio.nom, bio.identifiant, bio.mot_de_passe);
    fclose(fich);
   printf("\t\t\t\t******** LA BIBLIOTHEQUE EST ENREGISTRÉ ********\n\n\n");
    printf("\t\t\t\t******** VOULEZ-VOUS y ACCEDER (1) OU SORTIR (2) ? ********\n");
    IP2:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IP2;
    }

    rep = atoi(input);

    if (rep == 1) 
    {
        int id_temp;
        int mot_de_passe_temp;


        FILE* fich = NULL;
        printf("§§§§§§§*    ETAIT ELLE PUBLIQUE [1] ou priveé[2]  ?  *§§§§\n\nreponce:");
         IP3:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IP3;
    }

    rep = atoi(input);

        if (rep1 == 1) 
        {
            fich = fopen(PUB_BIBLI, "r");
        } else if (rep1 == 2) 
        {
            fich = fopen(PRI_BIBLI, "r");
        }

        if (fich == NULL) {
            printf("Une erreur est survenue lors de l'ouverture du fichier de sauvegarde!\n");
            sleep(2);
            goto c;
        }
      
        fscanf(fich, "%s %d %d\n", bio.nom, &bio.identifiant, &bio.mot_de_passe);

       F: printf("Identifiant de cette bibiotheque\n : ");
         IP4:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IP4;
    }

    bio.identifiant = atoi(input);


        if (id_temp == bio.identifiant) {
            printf("Mot de passe :\n ");
             IP5:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto IP5;
    }

    bio.mot_de_passe = atoi(input);


            if (mot_de_passe_temp == bio.mot_de_passe ) {sleep(1);
        system("clear");

                menu_principale();
            } else {
                printf("Erreur : Mot de passe incorrect, veuillez reessayer!\n");
                sleep(2);
                goto F;
            }
        } else {
            printf("Erreur : Identifiant NON RECONNUE, veuillez reessayer!\n"); 
            sleep(2);
            goto F;
        }
      
        fclose(fich);
    } else if (rep == 2) 
    {
        sleep(2);
        system("clear");
        bienvenue();
    }
        }
    }

   
}

 
 
 void menu_principale ()
{   
   
     int choix;char rep;
  
     do
     {
       menu: printf("###############################~~~~~~~~menu_du_logiciel~~~~~~~~################################\n\n");
       
        printf("\t\t\t§§§§  vous avez consulté le menu !!!  §§§§\n\n\n");
        printf("\t\t\t[1]-voulez-vous gerer les membres de cette bilbiotheque ?\n");
        sleep(1);
        printf("\t\t\t[2]-voulez-vous edité un auteurs de dans bilbiotheque ?\n");
        sleep(1);
        printf("\t\t\t[3]-voulez-vous gerer les livre de cette bilbiotheque ?\n");
        sleep(1);
        printf("\t\t\t[4]-voulez-vous gerer les emprunts de cette bilbiotheque ?\n");
        sleep(1);
        printf("\t\t\t[5]-voulez-vous gerer les revenues de et statistiques cette bilbiotheque ?\n"); 
        sleep(1);
        printf("\t\t\t[6]-voulez-vous gerer les evenements de cette bilbiotheque ?\n ");
        sleep(1);
        printf("\t\t\t[7]-voulez-vous reinitialiser la base de donné de cette bilbiotheque ?\n\n\n");
        sleep(1);
        printf("\t\t\t[8]-about unix_max");
        printf("\t\t\t[9]-retour\n");
        printf("\t\t\t[10]-quitter le logiciel\n");
        printf("\n\n");
        do
        { 
            printf("\t\t\t§§§§  make a choise !!!  §§§§\n \t\t\t§§§§  faire un choix!!!  §§§§\n\n");
            
             char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
        } while (choix<1||choix>10);
        
        switch (choix)
        {
        case 1:  sleep(1);system("clear");menu_membres(); 
    
            
            break;
        case 2: sleep(1);system("clear");menu_auteur();
    
            break;
        case 3: sleep(1);system("clear");menu_livre(); 
   
           break;
        case 4:sleep(1);system("clear");gestion_emprunt(); 
    
           break;
        case 5:  sleep(1);system("clear");compterMembresEtRevenu(); 
   
           break; 
        case 6:sleep(1);system("clear"); eventsss();
    
           break;
        case 7:sleep(1);system("clear");supprimé_biliotheque(); 
    
           break;
        case 8 :sleep(1);system("clear");about(); 
    
           break;
        case 10 :sleep(1);system("clear");exit(0); 
    
           break;  
        case 9:sleep(1);system("clear");bienvenue(); 
    
           break;       
                   
        default:
        printf("§§§§§ entrez une commande valable !!!  §§§§§\n\n");
            break;
        }
        
        printf("\n\n\t\t\t\t\t§§§§ CONTINUEZ [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);

      } while (rep== 'o'|| rep =='O');
} 

//menu principale publique


void menu_principale_publique ()
{   
   
     int choix;char rep;
  
     do
     {
       menu: printf("###############################~~~~~~~~menu_du_logiciel~~~~~~~~################################\n\n");
       
        printf("\t\t\t§§§§  vous avez consulté le menu !!!  §§§§\n\n\n");
        sleep(1);
        printf("\t\t\t[1]-voulez-vous gerer les membres de cette bilbiotheque ?\n"); sleep(1);
        printf("\t\t\t[2]-voulez-vous gerer les auteurs de cette bilbiotheque ?\n"); sleep(1);
        printf("\t\t\t[3]-voulez-vous gerer les livre de cette bilbiotheque ?\n"); sleep(1);
        printf("\t\t\t[4]-voulez-vous gerer les emprunts de cette bilbiotheque ?\n");  sleep(1);
        printf("\t\t\t[5]-voulez-vous reinitialiser la base de donné de cette bilbiotheque ?\n\n\n"); sleep(1);
        printf("\t\t\t[6]-about unix_max");
        printf("\t\t\t[7]-retour\n");
        printf("\t\t\t[8]-quitter le logiciel\n");
        printf("\n\n");
        do
        {  sleep(1);

            printf("\t\t\t§§§§  make a choise !!!  §§§§\n \t\t\t§§§§  faire un choix!!!  §§§§\n\n");
            char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';
    getchar();
    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
        } while (choix<1||choix>8);
        
        switch (choix)
        {
        case 1:  menu_membres(); sleep(1);
    system("clear");
            
            break;
        case 2:menu_auteur(); sleep(1);
    system("clear");
            break;
        case 3:menu_livre(); sleep(1);
    system("clear");
           break;
        case 4:gestion_emprunt(); sleep(1);
    system("clear");
           break;
        case 5:  sleep(1);
    system("clear");remove_all(); 
           break; 
        case 6: about(); sleep(1);
    system("clear");
           break;
        case 7:bienvenue(); sleep(1);
    system("clear");
           break;
        case 8 :exit(0); sleep(1);
    system("clear");
           
                   
        default:
        printf("§§§§§ entrez une commande valable !!!  §§§§§\n\n");
        
            break;
        }
        
        printf("\n\n\t\t\t\t§§§§  CONTINUEZ [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);

      } while (rep== 'o'|| rep =='O');
} 

///parametres ........................................................................................................;
void add_text()
{
    char*txt;
    txt=(char*) malloc(sizeof(char*));
    FILE*f=fopen("event1.txt","a");
   if (f==NULL)
   {
     printf("fopen error !");
     EXIT_FAILURE;
   }
   printf("\n\nlaisser nous un message\n");
  fgets(txt,sizeof(txt),stdin);
  txt[strcspn(txt, "\n")] = '\0';
  fprintf(f, "%s", txt);
  fclose(f);
    
  printf("\n\n\nvotre message nous sera transmis dans de bref delait merci de votre fidelité\n\n");
   
}
void parametres()
{
    char rep;int choix;
    do
    {
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§    bienvenue dans l'espace reglage d'UNIX_MAX    §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n ");
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");

 printf("\n\t\t\tchoisir l'action a effectuée\n\n\n");
 
 
 printf("\t\t\tdeconecté un user.....................................[1]\n");
 printf("\t\t\tNous Contactés.........................................[2]\n");
 printf("\t\t\tNous encourager........................................[3]\n");
 printf("\t\t\tFaire appele a UNIX IA.................................[4]\n");
 printf("\t\t\tretour.................................................[5]\n");
 printf("\t\t\tquitter UNIX_MAX.......................................[6]\n");
 printf("\t\t\tréintialiseé le logiciel...............................[7]\n");
 printf("\t\t\tA propos d'UNIX_MAX....................................[8]\n\n\n\n");

 printf("§§§§§§§§§§§§§§§§§§     merci de nous avoir fait confiance pour gerer vos bibliotheque.§§§§§§§§§§§§§§§§§§§§§§§\n\n\n");
 

   do
        { 
              char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
            
        } while (choix<1||choix>8);
        
        switch (choix)
        {
        case 1:   
         sleep(1);
         system("clear"); 
         char usernameToDelete[50]; 
         printf("NOM DE L'USER\n\n");
         scanf("%s",usernameToDelete);
         deleteUser(usernameToDelete);
            
            break;
        case 2:  printf("\t\t\t\tAU:698695279 OU 621131802:OU maxymtene@gmail.com\n\n\t\t\t\tmerci de votre soutient\n\n\n ");
       
            break;
        case 3:   sleep(1);
   add_text();
           break;
        case 4:  
         sleep(1);
    system("clear");
           break;
        case 5:   sleep(1);
    system("clear");bienvenue();
       
           break; 
        case 6:     sleep(1);
    system("clear"); exit(EXIT_FAILURE);
    
           break;
        case 7:  sleep(1);
    system("clear");remove_all();
       
           break;
        case 8 :
         sleep(1);
    system("clear");
    about();
           break;
        default:
        printf("§§§§§   entrez une commande valable !!!  §§§§§\n\n");
            break;
        }
        
         printf("\n\n\t\t\t\t§§§§  CONTINUEZ [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);
    }while (rep== 'o'|| rep =='O');
    if (rep =='n'||rep=='N')
    {
        bienvenue();
    }

}

void rech_admin()
{
   char username[50];
    char password[50];

    printf("Nom d'utilisateur a retirer: ");
    scanf("%s", username);

    printf("Mot de passe de cette user: ");
    scanf("%s", password);

    FILE* file = fopen(USER, "r");
    if (file != NULL) {
        char line[100];
        int isLoggedIn = 0;

        while (fgets(line, sizeof(line), file)) 
        {
            char tempUsername[50];
            char tempPassword[50];
            
            sscanf(line, "%[^:]:%s\n", tempUsername, tempPassword);
            
            if (strcmp(username, tempUsername) == 0 && strcmp(password, tempPassword) == 0) {
                isLoggedIn = 1;
                break;
            }
        }

        fclose(file);

        if (isLoggedIn) 
        {
           int rep;
            printf("......................................deconnexion........................................\n\n\n");
            printf("\t\t\tvoulez-vous vraiment retirer ce user :Mr/Mm %s ?[1:oui/2:non]\n\nchoix:",username);
            
            scanf("%d",&rep);
           
            if (rep==1)
            {
                FILE*f=fopen(USER,"r");
                FILE*fich=fopen("usertemp.txt","a+");
                 if (f == NULL || fich == NULL) 
                 {
                    printf("\t\t\tErreur lors de l'ouverture des fichiers.\n");
                    sleep(2);
                    parametres();
                }
                while (fscanf(f,"%s:%s\n", username, password)==2)
                {
                    fprintf(fich, "%s:%s\n", username, password);
                }
                 fclose(fich);
                 fclose(f);
                 remove(USER);
                 rename("usertemp.txt",USER);
                 printf("\t\t\t\t\tsuccesful!");
                
            }
            else if (rep==2)
            {
                printf("\n\n\n\n\n\n\n\n\t\t_________________________________________OKEY____________________________________________________\n\n");
                sleep(2);
                system("clear");
                parametres();
            }
        } else {
            printf("§§§§§    Erreur d'identification.   §§§§\n\n \t\t\tessayer a nouveau :\n\n");
            sleep(2);
            system("clear");
            loginProcedure();
        }
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
        sleep(2);
        system("clear");
        bienvenue();
    }

}



  //............................................procedures/fonctions de gestion,.......................................................................
void menu_membres()
{
   
   int choix;char rep;
  
     do
     {
        printf("###############################~~~~~~~~menu_du_membre~~~~~~~~################################\n\n");sleep(1);
       
        printf("\t\t\t§§§§  vous avez consulté le menu !!!  §§§§\n\n\n");
        printf("\t\t\t[1]-voulez-vous ajouter un membre ?\n");
        printf("\t\t\t[2]-voulez-vous rechercher un membre  ?\n");
        printf("\t\t\t[3]-voulez-vous supprimer un membre  ?\n");
        printf("\t\t\t[4]-voulez-vous modifier  un membre ?\n");
        printf("\t\t\t[5]-voulez-vous afficher l endemble des membre de cette bibliotheque ?\n");
        printf("\t\t\t[6]-voulez-vous verifier les autorisation d emprunts d un membre ?\n ");
        printf("\t\t\t[7]-voulez-vous gerer les emprunts ?\n\n\n");sleep(1);
        printf("\t\t\t\t\t[8]-about unix_max\n");
        printf("\t\t\t[9]-retour");
        printf("\t\t\t[10]-quitter le logiciel");
        printf("\n\n#######################################################################################\n\n");
        printf("\n\n");
        do
        { 
            printf("\t\t\t§§§§  MAKE A CHOICE!!!  §§§§\n \t\t\t§§§§  FAIRE UN CHOIX!!  §§§§\n\n");
               char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
        } while (choix<1||choix>10);
        
        switch (choix)
        {
        case 1: sleep(1);
                system("clear");
        ajoutermenbre();
            
            break;
        case 2: sleep(1);
                system("clear");
        rechercher();
            break;
        case 3:sleep(1);
             system("clear");
          supprimé_membre();
           break;
        case 4:sleep(1);
             system("clear");
          modifier_membre();
           break;
        case 5: sleep(1);
             system("clear");
        afficher_tous();
           break; 
        case 6: sleep(1);
             system("clear");
        est_Autorise() ;
           break;
        case 7:sleep(1);
             system("clear");
        gestion_emprunt();
           break;
        case 8 :sleep(1);
             system("clear");
        about();
           break;
        case 10 :sleep(1);
             system("clear");
        exit(0);
           break;    
        case 9:sleep(1);
             system("clear");
        menu_principale();
           break;         
                   
        default:
        printf("§§§§§ entrez une commande valable !!!  §§§§§\n\n");
            break;
        }
        
         printf("\n\n\t\t§§§§  voulez-vous continué [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);

      } while (rep== 'o'|| rep =='O');
}

void menu_auteur()
{
int choix;char rep;
  
     do
     {
        printf("###############################~~~~~~~~menu_des_auteurs~~~~~~~~################################\n\n");sleep(1);
       
        printf("\t\t\t§§§§  vous avez consulté le menu !!!  §§§§\n\n\n");
        printf("\t\t\t[1]-voulez-vous ajouter un auteur ?\n");
        printf("\t\t\t[2]-voulez-vous rechercher un auteur  ?\n");
        printf("\t\t\t[3]-voulez-vous supprimer un auteur ?\n");
        printf("\t\t\t[4]-voulez-vous modifier  un auteur ?\n");
        printf("\t\t\t[5]-voulez-vous afficher l endemble des auteurs de cette bibliotheque ?\n"); 
        printf("\t\t\t[6]-about unix_max\n");
        printf("\t\t\t[7]-retour");
        printf("\t\t\t[8]-quitter le logiciel\n");
        printf("\n\n");
        do
        { 
            printf("\t\t\t§§§§  make a choise !!!  §§§§\n \t\t\t§§§§  faire un choix!!!  §§§§\n\n");
                char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
        } while (choix<1||choix>8);
        
        switch (choix)
        {
        case 1:  ajouterauteur();
            
            break;
        case 2:  sleep(1);
             system("clear");
        rechercher_auteur();
            break;
        case 3:  sleep(1);
             system("clear");
        supprimer_auteur();
           break;
        case 4:  sleep(1);
             system("clear");
        modifier_auteur();
           break;
        case 5: sleep(1);
             system("clear");
        afficher_tous_auteur();
           break; 
        case 6: sleep(1);
             system("clear");
        about();
           break;
        case 7:sleep(1);
             system("clear");
        menu_principale();
           break;
        case 8 :sleep(1);
             system("clear");
        exit(0);
       
        default:
        printf("§§§§§ entrez une commande valable !!!  §§§§§\n\n");
            break;
        }
        
         printf("\n\n\t\t§§§§  voulez-vous continué [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);

      } while (rep== 'o'|| rep =='O');
}
void menu_livre()
{
  int choix;char rep;
  
     do
     {
        printf("###############################~~~~~~~~menu_des_livres~~~~~~~~################################\n\n");sleep(1);
       
        printf("\t\t\t§§§§  vous avez consulté le menu !!!  §§§§\n\n\n");
        printf("\t\t\t[1]-voulez-vous ajouter un livre ?\n");
        printf("\t\t\t[2]-voulez-vous rechercher un livre  ?\n");
        printf("\t\t\t[3]-voulez-vous supprimer un livre ?\n");
        printf("\t\t\t[4]-voulez-vous modifier  un livre ?\n");
        printf("\t\t\t[5]-voulez-vous afficher l endemble des livres de cette bibliotheque ?\n");
        printf("\t\t\t[6]-voulez-vous consuter un site en ligne sur diffrents livre ?\n");
        printf("\t\t\t[7]-about unix_max\n");
        printf("\t\t\t[8]-retour");
        printf("\t\t\t[9]-quitter le logiciel");
        printf("\n\n");
        do
        { 
            printf("\t\t\t§§§§  make a choise !!!  §§§§\n \t\t\t§§§§  faire un choix!!!  §§§§\n\n");
               char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
        } while (choix<1||choix>9);
        
        switch (choix)
        {
        case 1:  sleep(1);
             system("clear");
        ajouterlivre();
            
            break;
        case 2:  sleep(1);
             system("clear");
        rechercher_livre();
            break;
        case 3:   sleep(1);
             system("clear");
        supprimer_livre();
           break;
        case 4:  sleep(1);
             system("clear");
        modifier_livre();
           break;
        case 5: sleep(1);
             system("clear");
        afficher_tous_livre();
           break; 
        case 6:  system(" xdg-open https://www.livraddict.com/");

           break;
        case 7 :sleep(1);
             system("clear");
        about();
           break;
        case 8 :sleep(1);
             system("clear");
        menu_principale();
        
           case 9 :sleep(1);
             system("clear");
        exit(0);
                   
        default:
        printf("§§§§§ entrez une commande valable !!!  §§§§§\n\n");
            break;
        }
        
        printf("\n\n\t\t§§§§  voulez-vous continué [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);

      } while (rep== 'o'|| rep =='O');

}
void supprimé_biliotheque()
{

}
void about()
{
    logo();
    sleep(2);
     FILE*rp=fopen(ABOUT,"r");
     int txt;
     if (rp == NULL) 
    {
     printf("Erreur d'ouverture du fichier.\n");
     sleep(2);
     menu_principale();
      
    }
    while ((txt = fgetc(rp)) != EOF) 
    {
        printf("%c", txt);
    }
    fclose(rp);
}
void logo()
{   printf("\n\n\n\t\t\t\t\t\t*****\n");
    printf("\t\t\t\t\t\t/\\_/\\\n");
    printf("\t\t\t\t\t\t( o.o )\n");
    printf("\t\t\t\t\t\t > v <\n");
    printf("\t\t\t\t\t\tUNIX_MAX\n\n\n");
   sleep(2);
   printf("\t\t\t\t\t\tUNIX_MAX\n\n");
   

}

int recherche_id()
{
 
}
//login systeme..........................................................................................................

void loginProcedure()
{
    char username[50];
    char password[50];
    printf("\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§>(          LOG IN          )<§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n\n");

    printf("\n\t\t\t\t\t\tNom d'utilisateur: ");
    scanf("%s", username);

    char* tempPassword = getpass("\n\t\t\t\t\t\tMot de passe: ");
    strcpy(password, tempPassword);

    FILE* file = fopen(USER, "r");
    if (file != NULL) {
        char line[100];
        int isLoggedIn = 0;

        while (fgets(line, sizeof(line), file)) 
        {
            char tempUsername[50];
            char tempPassword[50];
            
            sscanf(line, "%[^:]:%s\n", tempUsername, tempPassword);
            
            if (strcmp(username, tempUsername) == 0 && strcmp(password, tempPassword) == 0) 
            {
                isLoggedIn = 1;
                break;
            }
        }

        fclose(file);

        if (isLoggedIn) 
        {
           logi();
             printf("......................................connection reussi bravo !........................................\n\n\n");
        printf("\t\t\tbonjour Mr/Mm %s\n\n\n\n\n",username);
        } else {
            printf("§§§§§    Erreur d'identification.   §§§§\n\n \t\t\tessayer a nouveau :\n\n");

            loginProcedure();
        }
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
        bienvenue();
    }
}

void registerProcedure()
{
     printf("\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§>(          SIGN IN          )<§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n\n");
    char username[50];
    char password[50];

    printf("Nom d'utilisateur: ");
    scanf("%s", username);

    
    char* tempPassword = getpass("\nMot de passe: ");
    strcpy(password, tempPassword);
    printf("POUR CLOSE DE CONFIDENTIALITÉ VOTRE MOT DE PASSE VOUS SERA AFDIHER DURANT 4 SECONDE\n\n");
    printf("\t\t\t\t\t\tPASSWORD:[%s]\n\n",password);
    sleep(4);
    system("clear");


    FILE* file = fopen(USER, "a");
    if (file != NULL) {
        fprintf(file, "%s:%s\n", username, password);
         logi();
        printf("......................................Enregistrement réussi !........................................\n\n\n");
        printf("bonjour Mr/Mm %s\n\n\n\n\n",username);
        
        system("clear");
        fclose(file);
       
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void deleteUser(char usernameToDelete[50])
{
    FILE* file = fopen(USER, "r");
    FILE* tempFile = fopen("temp.txt", "w");
    
    if (file != NULL && tempFile != NULL) {
        char line[100];

        while (fgets(line, sizeof(line), file)) 
        {
            char tempUsername[50];
            char tempPassword[50];
            
            sscanf(line, "%[^:]:%s", tempUsername, tempPassword);
            
            if (strcmp(usernameToDelete, tempUsername) != 0) 
            {
                fprintf(tempFile, "%s:%s\n", tempUsername, tempPassword);
            }
        }

        fclose(file);
        fclose(tempFile);

        remove(USER);
        rename("temp.txt", USER);

        printf("L'utilisateur %s a été supprimé avec succès.\n", usernameToDelete);
    } else {
        printf("Erreur lors de la suppression de l'utilisateur.\n");
    }
}




/*...............................fonctions && procedures de gestion...........................................................................*/

 //gestion des membres
 
int rech(int numrech)
{
    FILE *F;
    F=fopen(MEMBERS,"r");
  
   do
   {
        fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard);
        fflush(stdin);
        if (doc.num_carte==numrech)
        {
            fclose(F);
            return 1;
        }   
    } while (!feof(F));
   fclose(F);
   return -1;
}

 void ajoutermenbre()
 {
    FILE*F;char r;
    int num;char rep,non,oui,NON,OUI;
    F=fopen(MEMBERS,"a+");
    num=gener_id();
    printf("voici votre id carte de membre, [ %d ],",num);
    doc.num_carte=num;
    printf("entrez le nom:_\n");
    scanf("%s",doc.nom);
    fflush(stdin);
    printf("\t\t\tentrez entrez le prenon !!\n ");
    scanf("%s",doc.prenom);
    fflush(stdin);
    printf("\t\t\test il-membre premium [ premium || standard ] ?\n");
    scanf("%s",doc.couleur);
    
    fflush(stdin);
    printf("\t\t\tentrez le numero de telephone du membre \n");
   
         char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    doc.contact = atoi(input);
    printf("\t\t\tentrez l adresse  du membre en toute lettre \n");
    scanf("%s",doc.mail);
    fflush(stdin);
  G:  printf("\t\t\tentrez la cotisation du Membre si premium(34 EURO OU PLUS, PAS MOIN ) Si Non Entrez '0' \n");
       if (scanf("%d", &doc.cotisation) != 1) {
        printf("Erreur: vous devez entrer un entier.\n");
        sleep(1);
        exit(1);
        goto G;
    }

    fflush(stdin);
    

    fprintf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",doc.num_carte,doc.nom,doc.prenom,doc.couleur,doc.contact,doc.mail,doc.cotisation,doc.retard);
    fclose(F);
    printf("~~~~~~~~~~~~~~~~~~~~~~§§§§§   enregistré avec succé! ! ! ~~~~~~~~~~~~~~~~~~~~~~~~~~~§§§§\n\n");

 }
  void rechercher()
{
    int numr;int rep;
    printf("entrez le numero du membre a rechercher!!\n");
    scanf("%d",&numr);
    FILE*F;
    F=fopen(MEMBERS,"r");
    do
    {
        fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard);
        if (numr==doc.num_carte)
        {
          printf("§§§§   est-il standard[1] ou premium[0]  ?  §§§§§\n\n");
          scanf("%d",&rep);
          if(rep==1)
          {
          printf(" ~~~~~~les inform@tion sur le membre  standard en question sont~~~~~~~:\n\n\n\n ");
          printf("\t\t\t_________________________________\n");
          printf("\t\t\t|numero  |     %d                 \n",doc.num_carte);
          printf("\t\t\t|________|_______________________|\n");
          printf("\t\t\t|nom     |     %s                 \n",doc.nom);
          printf("\t\t\t|________|_______________________|\n");
          printf("\t\t\t|prenom: |     %s                 \n",doc.prenom);
          printf("\t\t\t|________|_______________________|\n");
          printf("\t\t\t|statu   |     %s                 \n",doc.couleur);
          printf("\t\t\t|________|_______________________|\n");
          printf("\t\t\t|contact |     %d                 \n",doc.contact);
          printf("\t\t\t|________|_______________________|\n");
          printf("\t\t\t|adresse |     %s                 \n ",doc.mail);
          printf("\t\t\t__________________________________\n");
          
          printf(" \n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:\n\n ");
          }
          else if(rep==0)
          {
          printf(" ~~~~~~les inform@tion sur le membre  premium sont ~~~~~~~:\n\n\n\n ");
          
          printf("\t\t\t---------------------------------\n");
          printf("\t\t\t|numero  |     %d                 \n",doc.num_carte);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|nom     |     %s                 \n",doc.nom);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|prenom: |     %s                 \n",doc.prenom);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|statu   |     %s                 \n",doc.couleur);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|contact |     %d                 \n",doc.contact);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|adresse |     %s                 \n ",doc.mail);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|solde   |     %d                 \n ",doc.cotisation);
          printf("\t\t\t---------------------------------\n");
          
          printf(" \n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:\n\n ");
          }
          
        }
        
    } while (!feof(F));
    fclose(F);
    
}
   void supprimé_membre()
  {
    char rep;
    int numrech;
    printf("§§§§   entrez le numero de carte du membre a supprimer !!!  §§§§\n\n");
    scanf("%d",&numrech);
    fflush(stdin);
    if (rech(numrech)==1)
    {
       printf("\n voulez vous vraiment supprimer ce membre  O/N ???\n\n");
        scanf("%s",&rep);
        fflush(stdin);
        if (rep== 'o'|| rep =='O')
        {
            FILE*fich,*F;
            F=fopen(MEMBERS,"r");
            fich=fopen("temp_membre.txt","a");

            do
            {
                  fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard);
                if (numrech!=doc.num_carte)
                {
                   
                    fprintf(fich,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",doc.num_carte,doc.nom,doc.prenom,doc.couleur,doc.contact,doc.mail,doc.cotisation,doc.retard);
                }
               
            } while (!feof(F));
            fclose(fich);
            fclose(F);
            remove(MEMBERS);
            rename("temp_membre.txt",MEMBERS);
            printf("\n\n\t\t\tsupression effectueé avec succeés!!\n\n");
            
        }
        
    }
   else
    {
        printf("\n\t\t\tce numero de carte n existe pas veillez reésayer!!\n");
        
    }
}
void modifier_membre() 
{
    FILE *F, *fich;
    int num;
    char rep;
    membre doc;

    printf("Entrez le numéro du membre à modifier : ");
    scanf("%d", &num);
    fflush(stdin);

    if (rech(num) == 1) {
        printf("................................................\n\t\t\tVoulez-vous vraiment le modifier ?\t\t\tCette action est irréversible. (o/n) :\n............................................................. ");
        scanf(" %c", &rep);
        fflush(stdin);

        if (rep == 'o' || rep == 'O')
        {
            F = fopen(MEMBERS, "r");
            fich = fopen("temp_membre.txt", "w");

            if (F == NULL || fich == NULL) 
            {
                printf("Erreur lors de l'ouverture des fichiers.\n");
                menu_livre();
            }

            while (fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard) == 8) 
            {
                if (num == doc.num_carte) {
                  
                    //////////////////////////////////////
                     printf("Que voulez-vous modifier ?\n");
                    printf("\t\t\t\t\t\t\t\t1. IDENTIFIANT DU MEMBRE\n\t\t\t\t\t\t\t\t2. NOM DU MEMBRE\n\t\t\t\t\t\t\t\t3. PRENOM DU MEMBRE\t\t\t\t\t\t\t\t4. STATU\n\t\t\t\t\t\t\t\t5. NUMERO DE TELEPHONE\n\t\t\t\t\t\t\t\t6. TOUT MODIFIER\n\n");
                    int choice;
                    scanf("%d", &choice);
                    fflush(stdin);

                    switch(choice) {
                        case 1:
                            printf("Entrez le nouveau numéro du membre : ");
                            scanf("%d", &doc.num_carte);
                            fflush(stdin);

                            break;
                        case 2:
                            printf("Entrez le nouveau nom du membre : ");
                            scanf("%s", doc.nom);
                            fflush(stdin);

                            break;
                        case 3: printf("Entrez le nouveau prénom du membre : ");
                                scanf("%s", doc.prenom);
                                fflush(stdin);

                            
                            break;
                        case 4: printf("Entrez  son statu : ");
                                scanf("%s", doc.couleur);
                                fflush(stdin);

                           
                            break;
                        case 5:
                             printf("Entrez le nouveau numéro de téléphone du membre : ");
                             scanf("%d", &doc.contact);
                          
                            break;
                        case 6:
                     printf("Entrez le nouveau numéro du membre : ");
                    scanf("%d", &doc.num_carte);
                    fflush(stdin);

                    printf("Entrez le nouveau nom du membre : ");
                    scanf("%s", doc.nom);
                    fflush(stdin);

                    printf("Entrez le nouveau prénom du membre : ");
                    scanf("%s", doc.prenom);
                    fflush(stdin);

                    printf("Entrez  son statu : ");
                    scanf("%s", doc.couleur);
                    fflush(stdin);

                    printf("Entrez le nouveau numéro de téléphone du membre : ");
                    scanf("%d", &doc.contact);
                    fflush(stdin);

                    printf("Entrez la nouvelle adresse email du membre : ");
                    scanf("%s", doc.mail);
                    fflush(stdin);
                    break;
                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                }

             fprintf(fich,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",doc.num_carte,doc.nom,doc.prenom,doc.couleur,doc.contact,doc.mail,doc.cotisation,doc.retard);
            }

            fclose(F);
            fclose(fich);

            remove(MEMBERS);
            rename("temp_membre.txt", MEMBERS);

            printf("\t\t\tModification effectuée avec succès !\n");
        }
    } else 
        {
            printf("\t\t\tModification annulée.\n");
        }
}

}
void afficher_tous()
{
    FILE *F;
    F = fopen(MEMBERS, "r");

    printf("\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§   MEMBERS LISTE §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("Numéro\t|\tNom\t|\tPrénom\t|\tStatut\t|\tContact\t|\tAdresse\t|\tSolde mensuel\t|\tRetard\t|\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");

    do
    {
        fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n", &doc.num_carte, doc.nom, doc.prenom, doc.couleur, &doc.contact, doc.mail, &doc.cotisation, &doc.retard);
        printf("%-5d\t|%-5s\t\t|%-5s\t\t|%-5s\t|%-5d\t|%-5s\t|%-5d\t\t\t|%-5d\t\t|\n", doc.num_carte, doc.nom, doc.prenom, doc.couleur, doc.contact, doc.mail, doc.cotisation, doc.retard);
    } while (!feof(F));

    printf("______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    fclose(F);
}          


// Vérifier si le membre est autorisé à emprunter un livre
void est_Autorise() 
{
    int num;
    printf("\t\t\tEntrez le numéro de carte du membre : \n");
    printf("\t\t\trepose:");
    scanf("%d", &num);

    FILE* F;
    F = fopen(MEMBERS, "r");
    if (F == NULL) {
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
            if (strcmp(doc.couleur, "standard") == 0||strcmp(doc.couleur, "STANDARD") == 0) 
            {
                printf("Vous avez les autorisations requises pour emprunter en tant que membre standard");
            }
             else if (strcmp(doc.couleur, "premium") == 0 && doc.cotisation >= 34||strcmp(doc.couleur, "PREMIUM")==0&&doc.cotisation>=34) 
            {
                printf("Vous avez les autorisations requises pour emprunter en tant que membre premium");
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

//verification du nombre de livre deja emprunter par un membre


//gestion des auteurs...............................................................................................
int rech_auteur(int numrech)
{
   FILE *F;
    F=fopen (AUTHORS,"r");
   auteur aut;
   do
   {
        fscanf(F,"%d;%s\n;%s\n;%d\n;%s\n",&aut.num_auteur,aut.nom,aut.prenom,&aut.contact,aut.mail);
        fflush(stdin);
        if (aut.num_auteur==numrech)
        {
            fclose(F);
            return 1;
        }   
    } while (!feof(F));
   fclose(F);
   return -1;
}


void ajouterauteur()
{
    int num;char r;
    FILE*F;
     F=fopen(AUTHORS,"a+");
    num=gener_id();
    auteur aut;
    printf("voici votre id carte de auteur, [ %d ],",num);
    
    aut.num_auteur = num;

    printf("Entrez le nom du de l'auteur :\n");
    scanf(" %[^\n]", aut.nom);

    printf("Entrez le prenom :\n");
    scanf(" %[^\n]", aut.prenom);

    printf("Entrez contact :\n");
    scanf("%d", &aut.contact);

    printf("Entrez l'adressse de cet auteur :\n");
    scanf(" %[^\n]", aut.mail);

    fprintf(F, "%d;%s\n;%s\n;%d\n;%s\n", aut.num_auteur, aut.nom, aut.prenom, aut.contact, aut.mail);
    fclose(F);

    printf("\t\t\tEnregistrement effectué avec succès !\n");
}

void rechercher_auteur()
{
    int numr;
    printf("Entrez le numero de carte de cette auteur :\n");
    scanf("%d", &numr);

    if (rech_auteur(numr) == 1|| numr < 1000 || numr > 9999)
    {
        FILE *F;
        F = fopen(AUTHORS, "r");

        auteur aut;

        while (  fscanf(F,"%d;%s\n;%s\n;%d\n;%s\n",&aut.num_auteur,aut.nom,aut.prenom,&aut.contact,aut.mail)== 5)
        {
            if (numr == aut.num_auteur)
            {
               
               printf(" ~~~~~~les inform@tion sur le membre  standard en question sont~~~~~~~:\n\n\n\n ");
          printf("\t\t\t---------------------------------\n");
          printf("\t\t\t|numero  |     %d                 \n",aut.num_auteur);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|nom     |     %s                 \n",aut.nom);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|prenom  |     %s                 \n",aut.prenom);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|contact |     %d                 \n",aut.contact);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|adresse |     %s                 \n",aut.mail);
          printf("\t\t\t---------------------------------\n");
                break;
            }
        }

        fclose(F);
    }
    else
    {
        printf("auteur inexistant.\n");
    }
}

void supprimer_auteur()
{
    int numrech;
    printf("Entrez le numero de carte de l'auteur à supprimer :\nreponse:_");
    scanf("%d", &numrech);

    if (rech_auteur(numrech) == 1|| numrech < 1000 || numrech > 9999)
    {
        char rep;
        printf("Voulez-vous vraiment supprimer ce cette auteur ? \nCette action est définitive (o/n) :\nreponse:_");
        scanf(" %c", &rep);

        if (rep == 'o' || rep == 'O')
        {
            FILE *F, *fich;
            F = fopen(AUTHORS, "r");
            fich = fopen("temp_auteur.txt", "w");

            auteur aut;

            while ( fscanf(F,"%d;%s\n;%s\n;%d\n;%s\n",&aut.num_auteur,aut.nom,aut.prenom,&aut.contact,aut.mail) == 5)
            {
                if (numrech != aut.num_auteur)
                {
                    fprintf(fich, "%d;%s\n;%s\n;%d\n;%s\n", aut.num_auteur, aut.nom, aut.prenom, aut.contact, aut.mail);
                }
            }

            fclose(F);
            fclose(fich);

            remove(AUTHORS);
            rename("temp_auteur.txt", AUTHORS);

            printf("\t\t\tSuppression effectuée avec succès !\n");
        }
    }
    else
    {
        printf("Suppression échouée : numéro de carte inexistant.\n");
    }
}
void afficher_tous_auteur()
{
    FILE *F;
    F = fopen(AUTHORS, "r");

    printf("Liste des auteur :\n\n");
    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("Numéro\t|\tNom\t|\tprenom\t|\tcontact\t|\tadresse");
    printf("\n-------------------------------------------------------------------------------------------\n");

    auteur aut;

    while (fscanf(F,"%d;%s\n;%s\n;%d\n;%s\n",&aut.num_auteur,aut.nom,aut.prenom,&aut.contact,aut.mail) == 5)
    {
       fprintf(F,"\n");
        fflush(stdin);
        printf("%d\t",aut.num_auteur);
        printf("%s\t\t",aut.nom);
        printf("%s\t\t",aut.prenom);
        printf("%d\t\t",aut.contact);
        printf("%s\t\t\t\t\t\t",aut.mail);
        printf("\n");
    }

    fclose(F);
}   
void modifier_auteur() 
{
    FILE *F, *fich;
    int num;
    char rep;
    auteur aut;

    printf("\t\t\tEntrez le numéro de carte de l'auteur à modifier : ");
    scanf("%d", &num);
    fflush(stdin);

    if (rech_auteur(num) == 1|| num < 1000 || num > 9999) 
    {
        printf("Voulez-vous vraiment le modifier ? Cette action est irréversible. (o/n) :\nrepose:_ ");
        scanf(" %c", &rep);
        getchar();

        if (rep == 'o' || rep == 'O')
        {
            F = fopen(AUTHORS, "r");
            fich = fopen(AUTHORS, "w");

            if (F == NULL || fich == NULL) 
            {
                printf("§§§§§-______________________________________________________________-§§§§§\n");
                printf("§§§§§         erreur d'ouverture du fichier auteur.txt inexitant     §§§§§\n");
                printf("§§§§§-______________________________________________________________-§§§§§\n\n");
                exit(0);
            }

            while ( fscanf(F,"%d;%s\n;%s\n;%d\n;%s\n",&aut.num_auteur,aut.nom,aut.prenom,&aut.contact,aut.mail)== 5) 
            {
                if (num == aut.num_auteur) 
                {
                    printf("\t\t\tEntrez le nouveau de carte numéro de auteur :\n ");
                    scanf("%d", &aut.num_auteur);
                    fflush(stdin);

                    printf("\t\t\tEntrez le nouveau nom de l'auteur :\n ");
                    scanf("%s", aut.nom);
                    fflush(stdin);

                    printf("\t\t\tEntrez le nouveau prénom  :\n ");
                    scanf("%s", aut.prenom);
                    fflush(stdin);

                    printf("\t\t\tEntrez le nouveau numéro de téléphone  :\n ");
                    scanf("%d", &aut.contact);
                    fflush(stdin);

                    printf("Entrez la nouvelle adresse   :\n ");
                    scanf("%s", aut.mail);
                    fflush(stdin);
                }

                fprintf(fich,"%d;%s\n;%s\n;%d\n;%s\n\n",aut.num_auteur ,aut.nom,aut.prenom,aut.contact,aut.mail);
            }

            fclose(F);
            fclose(fich);

            remove(AUTHORS);
            rename("temp_auteur.txt", AUTHORS);

            printf("§§§§§___________________________________________________§§§§§\n");
            printf("§§§§§         modification effectueé avec succeé        §§§§§\n");
            printf("§§§§§___________________________________________________§§§§§\n\n");
        }
         else
        {
           printf("§§§§§___________________________________________________§§§§§");
           printf("\n§§§§§           modification annuleé                    §§§§§\n");
           printf("§§§§§___________________________________________________§§§§§\n\n");
        }
    }
    else 
    {
        printf("\t\t\tnumero de carte inexistant\n\n\n");
    }
    
}

//gestion des livres..........................................................................................................
int  rech_livre(int numrech)
{
    FILE *F;
    F=fopen (BOOKS,"r");
   livre liv;
   do
   {
       fscanf(F, "%d;%[^;];%[^;];%d;%[^;];%d\n", &liv.num_livre, liv.nom, liv.genre,
                &liv.date_creation, liv.auteur, &liv.estdispo);
        fflush(stdin);
        if (liv.num_livre==numrech)
        {
            fclose(F);
            return 1;
        }   
    } while (!feof(F));
   fclose(F);
   return -1;
}
livre rech_livres(int numrech) 
{
    FILE *F;
    F = fopen(BOOKS,"r");
    livre liv;

    while (fscanf(F, "%d;%[^;];%[^;];%d;%[^;];%d\n", &liv.num_livre, liv.nom, liv.genre,
                &liv.date_creation, liv.auteur, &liv.estdispo) == 6) {
        if (liv.num_livre == numrech) {
            fclose(F);
            return liv;
        }
    }
   
    fclose(F);
    livre not_found = { .num_livre = -1 };
    return not_found;
}

void ajouterlivre()
{ 
    int num;char r;
    FILE*F;
     F=fopen(BOOKS,"a+");
    num=gener_id();
    livre liv;
    printf("\t\t\t\t\t\tCODE ID DU LIVRE:[ %d ]\n\n,",num);
   
   
    liv.num_livre = num;

    printf("Entrez le nom du livre :\n");
    scanf(" %[^\n]", liv.nom);

    printf("Entrez le genre du livre :\n");
    scanf(" %[^\n]", liv.genre);

    printf("Entrez la date de création/publication du livre (format entier) :\n");
        char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    liv.date_creation = atoi(input);

    printf("Entrez le nom de l'auteur du livre :\n");
    scanf(" %[^\n]", liv.auteur);
    printf("DISPONIBLE [O/N]?:");
     char R;
    scanf("%s",&R);

    getchar();
    if (R=='n'||R=='N')
    {
         liv.estdispo=0;
    }
    else if (R=='O'||R=='o')
    {
         liv.estdispo=1;
    }
    fprintf(F, "%d;%s;%s;%d;%s;%d\n", liv.num_livre, liv.nom, liv.genre, liv.date_creation, liv.auteur,liv.estdispo);
    fclose(F);

    printf("Enregistrement effectué avec succès !\n");
}
void rechercher_livre() {
    int numr;
    printf("Entrez le code du livre à rechercher :\n");
         char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    numr = atoi(input);

    livre liv = rech_livres(numr);

        if (liv.num_livre != -1) {
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
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|auteur  |     %s                 \n",liv.auteur);
          printf("\t\t\t|--------|-----------------------|\n");
          printf("\t\t\t|Dispo   |     %d                 \n", liv.estdispo);
          printf("\t\t\t---------------------------------\n");
           } else {
        printf("\t\t\t\t\t\tLivre inexistant.\n");
    }
}

void supprimer_livre() {
    int numrech;
    printf("Entrez le code du livre à supprimer :\n");
         char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    numrech = atoi(input);

    livre liv = rech_livres(numrech);

    if (liv.num_livre != -1) {
        char rep;
        printf("Voulez-vous vraiment supprimer ce livre ? (o/n) :\n");
        scanf(" %c", &rep);

        if (rep == 'o' || rep == 'O') {
            FILE *F, *fich;
            F = fopen(BOOKS, "r");
            fich = fopen("temp_livre.csv", "w");

            livre temp;

            while (fscanf(F, "%d;%[^;];%[^;];%d;%[^;];%d", &temp.num_livre, temp.nom, temp.genre,
                        &temp.date_creation, temp.auteur, &temp.estdispo) == 6) {
                if (numrech != temp.num_livre) {
                    fprintf(fich, "%d;%s;%s;%d;%s;%d", temp.num_livre, temp.nom, temp.genre,
                            temp.date_creation, temp.auteur, temp.estdispo);
                }
            }

            fclose(F);
            fclose(fich);

            remove(BOOKS);
            rename("temp_livre.csv", BOOKS);

            printf("Suppression effectuée avec succès !\n");
        } else {
            printf("Suppression annulée.\n");
        }
    } else {
        printf("Suppression échouée : numéro inexistant.\n");
    }
}

void afficher_tous_livre() {
    FILE *F;
    F = fopen(BOOKS, "r");

    printf("\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§   BOOKS LIST §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("|\t Numéro \t|\t Nom \t|\t Genre\t |\t Date de création \t|\t Auteur \t|\t Disponible \t|\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    livre liv;

    while (fscanf(F, "%d;%[^;];%[^;];%d;%[^;];%d", &liv.num_livre, liv.nom, liv.genre,
                &liv.date_creation, liv.auteur, &liv.estdispo) == 6) {
        printf("| %d \t\t\t| %s \t\t| %s \t\t\t| %d \t\t| %s \t\t\t| %d \t\t|\n", liv.num_livre, liv.nom, liv.genre,
                liv.date_creation, liv.auteur, liv.estdispo);
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
                
    }

    fclose(F);
}
void  AVAILABLE_BOOKS_LIST() 
{
     FILE *F;
    F = fopen(BOOKS, "r");
printf("\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§   AVAILABLE BOOKS LIST §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
printf("|\t Numéro \t|\t Nom \t|\t Genre\t |\t Date de création \t|\t Auteur \t|\t Disponible \t|\n");
printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
livre liv;

while (fscanf(F, "%d;%[^;];%[^;];%d;%[^;];%d", &liv.num_livre, liv.nom, liv.genre,
            &liv.date_creation, liv.auteur, &liv.estdispo) == 6) {
    if(liv.estdispo) {
        printf("| %d \t\t\t| %s \t\t| %s \t\t\t| %d \t\t| %s \t\t\t| %d \t\t|\n", liv.num_livre, liv.nom, liv.genre,
            liv.date_creation, liv.auteur, liv.estdispo);
        printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    }
}

fclose(F);

}

void modifier_livre() {
    int num;
    printf("Entrez le code du livre à modifier : ");
    char input[20];
    
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    num = atoi(input);

    livre liv = rech_livres(num);

    if (liv.num_livre != -1) {
        char rep;
        printf("Voulez-vous vraiment le modifier ? (o/n) : ");
        scanf(" %c", &rep);

        if (rep == 'o' || rep == 'O') {
            FILE *F, *fich;
            F = fopen(BOOKS, "r");
            fich = fopen("temp_livre.csv", "w");

            livre temp;

            while (fscanf(F, "%d;%[^;];%[^;];%d;%[^;];%d", &temp.num_livre, temp.nom, temp.genre,
                        &temp.date_creation, temp.auteur, &temp.estdispo) == 6) {
                if (num == temp.num_livre) {
                    printf("Que voulez-vous modifier ?\n");
                    printf("\t\t\t\t\t\t\t\t1. Numéro du livre\n\t\t\t\t\t\t\t\t2. Nom du livre\n\t\t\t\t\t\t\t\t3. Genre du livre\n\t\t\t\t\t\t\t\t4. Date de création\n\t\t\t\t\t\t\t\t5. Auteur du livre\n\t\t\t\t\t\t\t\t6. Tout modifier\n\n");
                    int choice;
                    scanf("%d", &choice);
                    fflush(stdin);

                    switch(choice) {
                        case 1:
                            printf("Entrez le nouveau numéro du livre : ");
                            scanf("%d", &temp.num_livre);
                            break;
                        case 2:
                            printf("Entrez le nouveau nom du livre :\n");
                            scanf(" %[^\n]", temp.nom);
                            break;
                        case 3:
                            printf("Entrez le nouveau genre du livre :\n");
                            scanf(" %[^\n]", temp.genre);
                            break;
                        case 4:
                            printf("Entrez la nouvelle date de création/publication du livre (format entier) :\n");
                            scanf("%d", &temp.date_creation);
                            break;
                        case 5:
                            printf("Entrez le nouveau nom de l'auteur du livre :\n");
                            scanf(" %[^\n]", temp.auteur);
                            break;
                        case 6:
                            printf("Entrez le nouveau numéro du livre : ");
                            scanf("%d", &temp.num_livre);
                            printf("Entrez le nouveau nom du livre :\n");
                            scanf(" %[^\n]", temp.nom);
                            printf("Entrez le nouveau genre du livre :\n");
                            scanf(" %[^\n]", temp.genre);
                            printf("Entrez la nouvelle date de création/publication du livre (format entier) :\n");
                            scanf("%d", &temp.date_creation);
                            printf("Entrez le nouveau nom de l'auteur du livre :\n");
                            scanf(" %[^\n]", temp.auteur);
                            break;
                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                    }
                    
                    temp.estdispo = 1;
                }

                fprintf(fich, "%d;%s;%s;%d;%s;%d", temp.num_livre, temp.nom, temp.genre,
                        temp.date_creation, temp.auteur, temp.estdispo);
            }

            fclose(F);
            fclose(fich);

            remove(BOOKS);
            rename("temp_livre.csv", BOOKS);

            printf("Modification effectuée avec succès !\n");
        } else {
            printf("Modification annulée.\n");
        }
    } else {
        printf("Numéro inexistant.\n");
    }
}

//gestion des emprunts et systeme de reservation............................................................................................................................................

// 1. menu ...........................................................
void gestion_emprunt()
{
char rep;int choix;
    do
    {
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§    bienvenue dans l'espace de gestion des emprunts    §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n ");
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");

 printf("\n\t\t\tchoisir l'action a effectuée\n\n\n");
 
 printf("\t\t\t-invalide........................................................................[1]\n");
 printf("\t\t\t-AFFICHER TOUS LES EMPRUNTS......................................................[2]\n");
 printf("\t\t\t-detecteur de retard et infos sur l'emprunt......................................[3]\n");
 printf("\t\t\t-RETOUR DE LIVRE.................................................................[4]\n");
 printf("\t\t\t-ajouter un emprunt..............................................................[5]\n");
 printf("\t\t\t-not vilide......................................................................[6]\n");
 printf("\t\t\t-gestion reservations de livre...................................................[7]\n");
 printf("\t\t\t-quitter UNIX_MAX................................................................[8]\n");
 printf("\t\t\t-retour..........................................................................[9]\n\n\n\n");
 printf("§§§§§§§§§§§§§§§§§§     merci de nous avoir fait confiance pour gerer vos bibliotheque.§§§§§§§§§§§§§§§§§§§§§§§\n\n\n");
 

   do
        { 
              char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    choix = atoi(input);
            
        } while (choix<1||choix>9);
        
        switch (choix)
        {
        case 1:  livre_emp();
            
            break;
        case 2:  afficher_reservations();
            break;
        case 3:  verifier_emprunt() ;
           break;
        case 4:  gerer_retour();
           break;
        case 5: printf("\n\t\t\t\t\tCHOICE  YOUR BOOKS IN THIS LIST\n\n");
        AVAILABLE_BOOKS_LIST() ;
         printf("\n\n|Press any key to continue.........\t\t\t\t\t\t\t\t\t\t|\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    
    getchar(); 

    system("clear");  
        enregistrer_emprunt() ;
           break; 
        case 6: rechercher_emp() ;
           break;

        case 7:
         reserve();
           break;
        case 8:exit(EXIT_FAILURE);
           break;
        case 9: bienvenue();
        default:
        printf("§§§§§   entrez une commande valable !!!  §§§§§\n\n");
            break;
        }
        
         printf("\n\n\t\t§§§§  voulez-vous continué [o/n]???  §§§§\n\n");
        printf("reponse:");
        
        scanf("%s",&rep);
        fflush(stdin);
    }while (rep== 'o'|| rep =='O');
    if (rep =='n'||rep=='N')
    {
        bienvenue();
    }
 

}

// Fonction pour vérifier le statut de l'emprunt ...........................................................................
void verifier_emprunt() 
{
char membre[MAX_LENGTH]; 
printf("Membre: "); 
scanf("%s",membre);
fflush(stdin);
time_t timestamp_actuel = time(NULL);

FILE* fichier = fopen(EMPRUNTS, "r");
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
    int CODE;
    sscanf(ligne, "%[^,],%[^,],%ld,%ld,%d,%d\n", membre_emprunt, manuel, &timestamp_emprunt, &timestamp_remise, &delai_remise,&CODE);
  
    if (strcmp(membre_emprunt, membre) == 0) {
        struct tm* tm_remise = localtime(&timestamp_remise);
        time_t timestamp_remise_reelle = mktime(tm_remise);
        
        double difference_temps = difftime(timestamp_actuel, timestamp_remise_reelle);
        int jours_retard = difference_temps / (24 * 60 * 60);

        if (jours_retard > 0) {
            
            FILE* fichier_membres = fopen(MEMBERS, "a");
            if (fichier_membres == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return;
            }

            fprintf(fichier_membres, "%d\n",jours_retard); 
            fclose(fichier_membres);
            
 
            printf("Le membre %s est en retard de %d jour(s).\n", membre, jours_retard);
            printf(" \t\t\t\t\t\tles infos:\nmembre:%s\nlivre emprunter:%s\n,delait de remise:%d\n code d'emprunt %d", membre_emprunt, manuel, delai_remise,CODE);
            
            if (jours_retard >= 7) {
                printf("Le membre  doit payer une amende de 10 euros.\n");
            }
            else if (jours_retard>7&&jours_retard>=0)
            {
                printf("le membre ne peux emprunter durant un semeine\n");
            }
            
        } else {
            int jours_avance = abs(jours_retard);
            printf("Le membre %s est en avance de %d jour(s).\n", membre, jours_avance);
            printf(" \t\t\t\t\t\tles infos:\nmembre:%s\nlivre emprunter:%s\n,delait de remise:%d\n code d'emprunt %d", membre_emprunt, manuel, delai_remise,CODE);
        }

        fclose(fichier);
        return;
    }
}

printf("Aucun emprunt enregistré pour ce membre.\n");
fclose(fichier);
}

Emprunts rech_emp(int numrech)
{
    FILE *F;
    F = fopen(EMPRUNTS,"r");
    Emprunts emprunt;
    while (fscanf(F, "%[^,],%[^,],%ld,%ld,%d,%d", emprunt.membre, 
    emprunt.manuel, &emprunt.timestamp_emprunt, 
    &emprunt.timestamp_remise, &emprunt.delai_remise, &emprunt.CODES) == 6) {
        if (emprunt.CODES == numrech) {
            fclose(F);
            return emprunt;
        }
    }
    fclose(F);
    Emprunts not_found = { .CODES = -1 };
    return not_found;
}


void miseAJourLivre(int code, int disponible) {
    FILE* fichier = fopen(BOOKS, "r");
    FILE* temp = fopen("temp.txt", "w");

    if (fichier == NULL || temp == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return;
    }

    livre liv;
    liv.num_livre = code;
    liv.estdispo = disponible;

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fichier) != NULL) {
        int livreCode;
        sscanf(line, "%d;%s;%s;%d;%s;%d", &livreCode, liv.nom, liv.genre, &liv.date_creation, liv.auteur, &liv.estdispo);

        if (livreCode == code) {
            fprintf(temp, "%d;%s;%s;%d;%s;%d\n", liv.num_livre, liv.nom, liv.genre, liv.date_creation, liv.auteur, liv.estdispo);
        } else {
            fprintf(temp, "%s", line);
        }
    }

    fclose(fichier);
    fclose(temp);

    remove(BOOKS);
    rename("temp.txt", BOOKS);
}

void afficher_reservations() {
    FILE* fichier = fopen(EMPRUNTS, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
printf("MEMBRE(e)|tLIVRE_PRIS|TIMEST_PRIS |TIMEST_REMI|DELAIT|\n");
    char line[MAX_LENGTH];
    int num_lines = 0;
    while (fgets(line, MAX_LENGTH, fichier)) {
        num_lines++;
        printf("%s", line);
    }
    fclose(fichier);

    // Centrer les réservations
    const int terminal_width = 80;
    const int line_length = strlen(line);
    int padding = (terminal_width - line_length) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("RESERVATIONS");


    int remaining_padding = terminal_width - line_length - padding;
    for (int i = 0; i < remaining_padding; i++) {
        printf(" ");
    }

    
    printf("Nombre total de réservations : %d", num_lines);
}

void enregistrer_emprunt() 
{
    Emprunts emprunt;
    int num, code;
    int emprunt_trouve = 0;
    printf("ENTRER L'ID DU MEMBRE QUI EMPRUNT\n");
    char input[20];
    
    while (1) {
        printf("ID: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!isIntegerS(input)) {
            printf("La valeur entrée n'est pas un entier.\n");
            continue;
        }
        num = atoi(input);
        break;
    }

     // Vérification du membre
    
    if ( rech(num)!=1) {
        printf("Ce membre n'existe pas.\n");
        printf("ERROR: MEMBRE INTROUVABLE");
         sleep(2); 
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  5  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  4  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        
        gestion_emprunt();
    }


    char membre[MAX_LENGTH]; 
    printf("NOM DE CE MEMBRE (POUR PLUS DE VERIFICATION )\nNOM:");
    scanf("%s", membre);
    fflush(stdin);

   
    time_t timestamp = time(NULL);
    FILE* fic = fopen(EMPRUNTS, "r");
    if (fic == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        sleep(2);
        gestion_emprunt();
    }
    
    char line[MAX_LENGTH];int membre_trouve=0; 
    while (fgets(line, MAX_LENGTH, fic)) 
    {
        char membre_emprunt[MAX_LENGTH];
        char manuel[MAX_LENGTH];
        time_t timestamp_emprunt;
        time_t timestamp_remise;
        int delai_remise;
        int CODE;
        sscanf(line, "%[^,],%[^,],%ld,%ld,%d,%d", membre_emprunt, manuel, &timestamp_emprunt, &timestamp_remise, &delai_remise,&CODE);
        
        FILE* r = fopen(MEMBERS, "r");
        int g = num;
        
        while ( fscanf(r,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard)==8) 
        {
             if (doc.num_carte == num) {
               membre_trouve = 1;
            }      
        }
           fclose(r);

           if (strcmp(membre_emprunt, membre) == 0 || strcmp(doc.nom, membre) == 0) 
            {
                struct tm* tm_remise = localtime(&timestamp_remise);
                time_t real_time_remise = mktime(tm_remise);
                double diff_time = difftime(timestamp, real_time_remise);
                int delai = diff_time / (24 * 60 * 60);
                time_t sta = time(NULL);
                struct tm* emprun = localtime(&sta); 

               if (delai > 0) {
                printf("Le membre %s est en retard de %d jour(s).\n", doc.nom, delai);
                printf("Les informations:\n");
                printf("Membre: %s\nLivre emprunté: %s\nDélai de remise: %d\n", membre_emprunt, manuel, delai_remise);
                sleep(3);
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]]\t\t\t\t");
                sleep(1);
                system("clear");
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                sleep(1);
                system("clear");
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
                sleep(1);
                system("clear");
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  0  ]]]]]]]]]]]\t\t\t\t");
                sleep(1);
                system("clear");
                printf("LE LIVRE %s N'A PAS ÉTÉ RETOURNÉ À TEMPS\n", manuel);
                sleep(1);
                system("clear");
                printf("VOUS DEVEZ PAYER UNE AMENDE DE 100 FCFA\n");
                sleep(1);
                system("clear");
                printf("VOULEZ-VOUS CONTINUER L'ENREGISTREMENT ?\n1.OUI\n2.NON\nCHOIX: ");
                scanf("%d", &code);
                fflush(stdin);

                if (code == 2) {
                    gestion_emprunt();
                    return;
                }
                 emprunt_trouve = 1;
                 break;
            }
                
        }
    }
      fclose(fic);
      
        if (emprunt_trouve) 
        {
            printf("Ce membre a déjà emprunté un livre.\n");
            sleep(2);
            gestion_emprunt();
            return;
        }

             printf("Great membre trouvé!\n");
                
            printf("|========================================== Great membre trouvé! ========================================================|\n");
            printf("\t\t\t\t\tREMPLIRE CETTE FICHE D'EMPRUNT:\n");
            printf("\n\t\tNOM DU MEMBRE                                  |         :");
            scanf("%s", emprunt.membre);
            fflush(stdin);
            printf("\t\t                                                |        \n");
            printf("\t\tMANUEL A EMPRUNTER                              |       :");
            scanf("%s", emprunt.manuel);
            fflush(stdin); 
            printf("\t\t                                                |        \n");
            printf("\t\tSon code (Code du livre à emprunter)            |        :");
            scanf("%d", &code); 
            printf("\t\t                                                |        \n");

            livre liv = rech_livres(code);
            if (liv.num_livre == -1) {
                printf("Livre inexistant");
                printf("\n\t\tLIVRE INEXISTANT");
                printf("VOUS ALLEZ BIENTOT ETRE REDIRIGER DANS L ESPACE DE RESERVAION POUR LE RESERVER");
                sleep(5);
                 printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
                         sleep(1); 
                         system("clear");
                         printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                         sleep(1); 
                         system("clear");
                         printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
                         sleep(1); 
                system("clear");

                
                  
                MENU_RESERVATION();
            }

            printf("\t\t\t~~~~~~~~~~~~~~~Great livre trouvé!~~~~~~~~~~~~~~~~\n");
            if (liv.estdispo!=1)
            {
                printf("MAIS DEJA EMPRUNTER DOMAGE!\n\n");
                printf("VOUS ALLEZ BIENTOT ETRE REDIRIGER DANS L ESPACE DE RESERVAION POUR LE RESERVER");
                sleep(5);
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
                sleep(1); 
                system("clear");
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                sleep(1); 
                system("clear");
                printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
                sleep(1); 
                system("clear");
                MENU_RESERVATION();
                
            }
            
            emprunt.timestamp_emprunt = time(NULL);

            printf("\t\tDélai de remise (en jours)                  |           :");
            scanf("%d", &emprunt.delai_remise);

            struct tm* tm_remise = localtime(&emprunt.timestamp_emprunt);
            tm_remise->tm_mday += emprunt.delai_remise;
            emprunt.timestamp_remise = mktime(tm_remise);
            printf("\t\tVOUS AVEZ EMPRUNTER AUJOURD'HUIT;\n");
            printf("\t\tDATE A LA QUEL VOUS DEVEZ RENDRE:                     |[%s]                |\n", asctime(tm_remise)); 
            printf("\t\t                                                      |        \n");
            printf("\t\tTEMP RESTANT AVANT LA REMISE :                        |[-%d]jour          |\n",emprunt.delai_remise );
            printf("\t\tATTENTION : UNE DATE NON RESPECTER EQUIVAUT À DES PENALITÉS D'EMPRUNT OU JUDICIAIRES");
            printf("\t\t___________________________________________________________________________________\n");
            emprunt.CODES = genererCodeRetrait(); 
            printf("\t\t                                                      |                            \n");

            printf("\t\tVOTRE CODE DE D'EMPRUNT                               |[%d]              |\n\t\t\t\t\tce code vous sera demandé lors de la remise", genererCodeRetrait());

            FILE* fichier = fopen(EMPRUNTS, "a+");
            if (fichier == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return;
            }

            fprintf(fichier, "%s,%s,%ld,%ld,%d,%d", emprunt.membre, emprunt.manuel, emprunt.timestamp_emprunt, emprunt.timestamp_remise, emprunt.delai_remise, emprunt.CODES);
            fclose(fichier);

            printf("\t\t\t\t\tEMPRUNT ENREGISTRÉ AVEC SUCCÈS.\n");
            printf("\t\t\t\t\t_______________________________\n");
            printf("|========================================================================================================================|\n");
            miseAJourLivre(code, 0);
            liv.estdispo=0;
             emprunt_trouve = 1;
            
         
    
        

              
}

//  2. ajouter un emprunt.......................................................................................................
/*
void enregistrer_emprunt() 
{
    Emprunts emprunt;
    int num, code;
     int emprunt_trouve = 0;
    printf("ENTRER L'ID DE MEMBRE\n ");
         char input[20];
    f:printf("ID: ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }
    num = atoi(input);

        char membre[MAX_LENGTH]; 
        printf("NOM DE CE MEMBRE (POUR VERIFICATION DE RETARD POTENTIEL)\nNOM:"); 
        scanf("%s", membre);
        fflush(stdin);

         // Vérification de membre
    int membreIndex = rech(num);
    if (membreIndex == -1) {
        printf("Ce membre n'existe pas.\n");
         printf("ERROR:MEMBRE INTROUVABLE\n\n");
        sleep(2); 
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  5  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  4  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
        sleep(1); 
        system("clear");
        gestion_emprunt();
    }


        time_t timestamp = time(NULL);
        FILE* fic = fopen(EMPRUNTS, "r");
        if (fic == NULL)
        {
            printf("Erreur lors de l'ouverture du fichier.\n");
            sleep(2);
            gestion_emprunt();
        }
        char line[MAX_LENGTH];
        while (fgets(line, MAX_LENGTH, fic))
        {
            char membre_emprunt[MAX_LENGTH];
            char manuel[MAX_LENGTH];
            time_t timestamp_emprunt;
            time_t timestamp_remise;
            int delai_remise;
            int CODE;
            sscanf(line, "%[^,],%[^,],%ld,%ld,%d,%d\n", membre_emprunt, manuel, &timestamp_emprunt, &timestamp_remise, &delai_remise,&CODE);
            FILE*r=fopen(MEMBERS,"r");
             int g=num;
          while ( fscanf(r,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard)==8)
          {
             

              if (strcmp(membre_emprunt, membre) == 0||(g,doc.nom)==0)
            {
                struct tm* tm_remise = localtime(&timestamp_remise);
                time_t real_time_remise = mktime(tm_remise);
                double diff_time = difftime(timestamp, real_time_remise);
                int delai = diff_time / (24 * 60 * 60);
                time_t sta=time(NULL);
                struct tm *emprun=localtime(&sta); 
                
                if (delai > 0)
                {

                    printf("Le membre %s est en retard de %d jour(s).\n", doc.nom , delai);
                    printf("Les informations:\n");
                    printf("Membre: %sLivre emprunté: %sDélai de remise: %d", membre_emprunt, manuel, delai_remise);
                    sleep(3);
                    system("clear");
                    printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
                    printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
                    gestion_emprunt();  
                    break;  
                    
                }
                
            }
                
                
                    printf("|========================================== Great membre trouvé! ========================================================|\n");
                    printf("\t\t\t\t\tREMPLIRE CETTE FICHE D'EMPRUNT:\n\n");
                    printf("\n\t\tNOM DU MEMBRE                                  |         :");
                    scanf("%s", emprunt.membre);
                    fflush(stdin);
                    printf("\t\t                                                |        \n");
                    printf("\t\tMANUEL A EMPRUNTER                              |       :");
                    scanf("%s", emprunt.manuel);
                    fflush(stdin); 
                    printf("\t\t                                                |        \n");
                    printf("\t\tSon code (Code du livre à emprunter)            |        :");
                    scanf("%d", &code); 
                    printf("\t\t                                                |        \n");

                    
                     livre liv = rech_livres(code);
                    if (liv.num_livre ==-1)
                    {
                       printf("livre inexitant\n");
                          printf("\n\t\tLIVRE INEXISTANT OU INDISPONIBLE\n");
                         printf("VOUS ALLEZ BIENTOT ETRE REDIRIGER DANS L ESPACE DE RESERVAION POUR LE RESERVER\n");
                         sleep(5);
                         printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
                         sleep(1); 
                         system("clear");
                         printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                         sleep(1); 
                         system("clear");
                         printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
                         sleep(1); 
                         system("clear");
                         fclose(fic);
                         fclose(r);
                            
                         MENU_RESERVATION();

                    }
                        printf("\t\t\t~~~~~~~~~~~~~~~Great livre trouvé!~~~~~~~~~~~~~~~~\n");
                        emprunt.timestamp_emprunt = time(NULL);

                        printf("\t\tDélai de remise (en jours)                  |           :");
                        scanf("%d", &emprunt.delai_remise);

                      
                        struct tm* tm_remise = localtime(&emprunt.timestamp_emprunt);
                        tm_remise->tm_mday += emprunt.delai_remise;
                        emprunt.timestamp_remise = mktime(tm_remise);
                        printf("\t\tVOUS AVEZ EMPRUNTER AUJOURD'HUIT;\n");
                        printf("\t\tDATE A LA QUEL VOUS DEVEZ RENDRE:                     |[%s]                |\n",asctime(timestamp_remise)); 
                        printf("\t\t                                                      |        \n");
                        printf("\t\tTEMP RESTANT AVANT LA REMISE :                        |[%d]jour          |\n\n",delai);
                        printf("\t\tATTENTION : UNE DATE NON RESPECTER EQUIVAUX A DES PENALITÉ D EMPRUNT OU JUDICIAIRE\n");
                        printf("\t\t___________________________________________________________________________________\n");
                        emprunt.CODES=genererCodeRetrait(); 
                        printf("\t\t                                                      |                            \n");

                        printf("\t\tVOTRE CODE DE D'EMPRUNT                               |[%d]              |\n\t\t\t\t\tce code vous sera demandez lors de la remise\n\n",emprunt.CODES);
                          
                       
                        FILE* fichier = fopen(EMPRUNTS, "a+");
                        if (fichier == NULL) {
                            printf("Erreur lors de l'ouverture du fichier.\n");
                            return;
                        }

                        fprintf(fichier,  "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, emprunt.timestamp_emprunt, emprunt.timestamp_remise, emprunt.delai_remise,emprunt.CODES);
                        fclose(fichier);

                         printf("\t\t\t\t\tEMPRUNT ENREGISTRER AVEC SUCCES.\n");
                         printf("\t\t\t\t\t_______________________________\n");
                         printf("|========================================================================================================================|\n");
                         
                         emprunt_trouve = 1;
          }
          rewind(r);
          if(emprunt_trouve){
                break;
            }
          fclose(r);
        }          
}*/
// 3. delect emprunt..................................................................................................................
void gerer_retour() {
    int code;
    int retour_trouve = 0;

    printf("\n[ENTRER LE CODE D'EMPRUNT DU DOCUMENT RETOURNÉ]\nCODE: ");
    scanf("%d", &code);

    FILE* fichier = fopen(EMPRUNTS, "r");
    FILE* temp = fopen("temp.txt", "w");

    if (fichier == NULL || temp == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return;
    }
    
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fichier) != NULL) {
        char membre_emprunt[MAX_LENGTH];
        char manuel[MAX_LENGTH];
        time_t timestamp_emprunt;
        time_t timestamp_remise;
        int delai_remise;
        int CODE;

        sscanf(line, "%[^,],%[^,],%ld,%ld,%d,%d", membre_emprunt, manuel, &timestamp_emprunt, &timestamp_remise, &delai_remise, &CODE);

        if (CODE == code) {
            time_t timestamp_retour = time(NULL);
            struct tm* tm_retour = localtime(&timestamp_retour); 

            double diff_time = difftime(timestamp_retour, timestamp_remise);
            int delai = diff_time / (24 * 60 * 60);

            printf("Livre retourné par le membre %s.\n", membre_emprunt);
            printf("Date de retour: %s", asctime(tm_retour));
            printf("Délai de remise: %d jour(s)\n", delai_remise);
            printf("Retard: %d jour(s)\n", delai);

            if (delai > 0) {
                printf("Le membre est en retard.\n");
            }

            retour_trouve = 1;
        } else {
            fprintf(temp, "%s", line);
        }
    }
   miseAJourLivre(code,1);
    fclose(fichier);
    fclose(temp);

    remove(EMPRUNTS);
    rename("temp.txt", EMPRUNTS);

    if (!retour_trouve) {
        printf("Aucun emprunt avec le code donné trouvé.\n");
    }
}
/*
void delecte_emprunt()
{
  
    int numrech;
    printf("Entrez le code de l'emprunt a supprimer :\nreponse:_");
    scanf("%d", &numrech);
    Emprunts emprunt;
    if (rech_emprunt(numrech) == 1)
    {
        char rep;
        printf("Voulez-vous vraiment supprimer cet emprunt ? \nCette action est définitive (o/n) :\nreponse:_");
        scanf(" %c", &rep);

        if (rep == 'o' || rep == 'O')
        {
            FILE *F, *fich;
            F = fopen(EMPRUNTS, "r");
            fich = fopen("temp_emprunts.txt", "w");

            Emprunt em;
            em.num_emprunt=numrech;
            while (  fscanf(fich,  "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, &emprunt.timestamp_emprunt, &emprunt.timestamp_remise,& emprunt.delai_remise,&emprunt.CODES))
                        
            {
                if (numrech != emprunt.CODES)
                {
                 fprintf(fich,  "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, emprunt.timestamp_emprunt, emprunt.timestamp_remise, emprunt.delai_remise,emprunt.CODES);
                }
            }
 
            fclose(F);
            fclose(fich);

            remove(EMPRUNTS);
            rename("temp_emprunts.txt", EMPRUNTS);

            printf("Suppression effectuée avec succès !\n");
        }
        else if (rep=='N'||rep=='n')
        {
            printf("\t\t\tvous avez annuler la suppression !");
        }
    }
    else
    {
        printf("Suppression échouée : numéro inexistant.\n");
    }
}*/
// 4. membres ayant emprunrer .  ...................................................................................................
 void livre_emp()
{
  printf("Voulez Vous Voir Les Membres Ayant Deja Emprrunter ?\n\n");
  char rep;
  printf("aucune modification n'es disponible dans ce pavion\n\n");

  scanf("%s",&rep);
  getchar();
  if (rep=='o'||rep=='O')
  {
    FILE*F=fopen(EMPRUNTS,"r");
    printf("Liste des emprunt :\n\n");
    printf("\n\n\t\t\t--------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tcode emprunt\t|\tdate_emp\t|\tdat_retour\t|\tmanuel\tmembre");
    printf("\n\t\t\t\t----------------------------------------------------------------------------------\n\n\n");
    Emprunts emprunt;
    
    while ( fscanf(F,  "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, &emprunt.timestamp_emprunt, &emprunt.timestamp_remise,& emprunt.delai_remise,&emprunt.CODES)==6)
    {
       fprintf(F,"\n");
        fflush(stdin);
        printf(" %d\t",emprunt.CODES);
        printf("%ld\t",emprunt.timestamp_emprunt);
        printf("%d\t",emprunt.delai_remise);
        printf("%s\t",emprunt.manuel);
        printf("%s\t",emprunt.membre);
       
        printf("\n");
    }

    fclose(F);
  }
  else if (rep=='n'||rep=='N')
  {
    gestion_emprunt();
  }
  
  
}
// 5. reserver emprunt ..........................................................................................................................
 
//6. livre deja emprunter.....................................................................................................
void memb_emp()
{

}
//7.recherche emprunt...........................................................................................................
int rech_emprunt(int numrech)
{
   FILE *fp;
    fp=fopen (EMPRUNTS,"r");
   Emprunts emprunt;
   do
   { 
    fscanf(fp,  "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, &emprunt.timestamp_emprunt, &emprunt.timestamp_remise,& emprunt.delai_remise,&emprunt.CODES);
                       
        fflush(stdin);
        if (emprunt.CODES==numrech)
        {
            fclose(fp);
            return 1;
        }   
    } while (!feof(fp));
   fclose(fp);
   return -1;
}

//code d'empreunt.............................................................................................................
int genererCodeRetrait() 
{ 
int codeRetrait = 0; srand(time(0)); int i;
Emprunts emprunt;
 FILE* fp = fopen(EMPRUNTS,"a+");
if (fp == NULL) 
{ 
    printf("erreur fopen"); 
} else 
{
    fscanf(fp, "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, &emprunt.timestamp_emprunt, &emprunt.timestamp_remise, &emprunt.delai_remise,&emprunt.CODES);

for (i = 0; i < 8; i++) 
{
    codeRetrait = codeRetrait * 10 + (rand() % 10);
}

return codeRetrait;
}
}

void rechercher_emp() 
{ 
    int numr, num; 
    printf("\t\t\tEntrez le code de l'emprunt a rechercher :\n"); scanf("%d", &numr); 
    printf("\t\t\tEntrez le code du livre emprunte :\n"); scanf("%d", &num);

  livre liv = rech_livres(numr);

        
if (rech_emprunt(numr) == 1 &&  (liv.num_livre != -1) )
{
    FILE *F = fopen(EMPRUNTS, "r");
    FILE *f = fopen(BOOKS, "r");
    Emprunts emprunt;
    livre liv;
    
    while ( fscanf(F,  "%s,%s,%ld,%ld,%d,%d\n", emprunt.membre, emprunt.manuel, &emprunt.timestamp_emprunt, &emprunt.timestamp_remise, &emprunt.delai_remise,&emprunt.CODES)==6)
         
    { 
        if (numr == emprunt.CODES) 
        { 
            Emprunts emprunt;

        printf("\t\t\t ~~~~~~inform@tions sur l'emprunt~~~~~~~:\n"); 
        printf("\t\t\t----------------------------------\n"); 
        printf("\t\t\t|code_emp| %d \n", emprunt.CODES); 
        printf("\t\t\t|--------|-----------------------|\n"); 
        printf("\t\t\t|dalait  | %ld \n", emprunt.timestamp_emprunt); 
        printf("\t\t\t|--------|-----------------------|\n"); 
        printf("\t\t\t|dat_remi| %ld \n", emprunt.timestamp_remise); 
        printf("\t\t\t|--------|-----------------------|\n");

 
            while (fscanf(f,"%d;%s\n;%s\n;%d\n;%s\n",&liv.num_livre,liv.nom,liv.genre,&liv.date_creation,liv.auteur)==5)
            {
                if (num == liv.num_livre)
                {
                    printf("\t\t\t|livre_E |     %s                 \n ", liv.nom);
                    printf("\t\t\t|--------|-----------------------|\n");
                    printf("\t\t\t|genre   |     %s                 \n", liv.genre);
                    printf("\t\t\t---------------------------------\n");
                    break;
                }
            }
            break;
        }
    }

    fclose(f);
    fclose(F);
}
else
{
    int rep;
    printf("\t\t\t§§§§§§§§§§§§§§§§§   emprunt inexistant.   §§§§§§§§§§§§§§§§§§§§\n"); 
    printf("repartire au menu :[1] ou sortir du logiciel :[2]\n repose:_"); scanf("%d", &rep); 
    if (rep == 1) { gestion_emprunt(); } else { exit(EXIT_SUCCESS); } } }

int gener_id()
{
    loginProcedure();
    membre doc;
    FILE* fp = fopen(MEMBERS,"a+");
    if (fp == NULL)
    {
        printf("\t\t\terreur fopen !!!!!");
    } 
    else
    {
        int existingCodes[100]; // Tableau pour stocker les codes existants
        int numExistingCodes = 0; // Nombre de codes existants

        while (fscanf(fp,"%d ;%s;%s;%s;%d;%s;%d;%d" , &doc.num_carte, doc.nom, doc.prenom, doc.couleur, &doc.contact, doc.mail, &doc.cotisation, &doc.retard) == 8)
        {
            existingCodes[numExistingCodes] = doc.num_carte; // Ajouter le code existant au tableau
            numExistingCodes++;
        }

        srand(time(0));
        do {
            doc.num_carte = rand() % 10000; 
        } while(isCodeExisting(existingCodes, numExistingCodes, doc.num_carte));
        
        fclose(fp);
    }
    
  
    return doc.num_carte;
}

// Fonction pour vérifier si un code existe dans le tableau
int isCodeExisting(int codeArray[], int numCodes, int code)
{
    for (int i = 0; i < numCodes; i++)
    {
        if (codeArray[i] == code)
        {
            return 1; 
        }
    }
    
    return 0; 
}

// gestion des  revenues de la bibliotheques ........................................................................................
int calcule_revenue(int nb_me_p)
{

   int rev=0;
   return rev+=nb_me_p*34;

}

void compterMembresEtRevenu()
{
    FILE* F;
    F = fopen(MEMBERS, "r");
    if (F == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    membre doc;
    int nbMembresStandard = 0;
    int nbMembresPremium = 0;
    int revenuPremium = 0;

    while ( fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard) == 8) {

        if (strcmp(doc.couleur, "standard") == 0 || strcmp(doc.couleur, "STANDARD") == 0) {
            nbMembresStandard++;
        }
        else if (strcmp(doc.couleur, "premium") == 0 || strcmp(doc.couleur, "PREMIUM") == 0) {
            nbMembresPremium++;
            revenuPremium += doc.cotisation;
        }
    }

    fclose(F);
    printf("\n\t\t\t______________________________________________________________\n");
    printf("\n\t\t\t                statistique de la bibiotheque                 \n");
    printf("\n\t\t\t______________________________________________________________\n");
    printf("\n\t\t\t                ! informations confidentielle !               \n");
    printf("\n\t\t\t______________________________________________________________\n");
    printf("\t\t\tNombre de membres standard                | %d\n", nbMembresStandard);
    printf("\n\t\t\t______________________________________________________________\n");
    printf("\t\t\tNombre de membres premium                 | %d\n", nbMembresPremium);
    printf("\n\t\t\t______________________________________________________________\n");
    printf("\t\t\tRevenu obtenu par les membres premium     | %d € soit %d FCFA\n", revenuPremium ,revenuPremium*650);
    printf("\n\t\t\t______________________________________________________________\n");
   
}

void eventsss()
{ 
 printf("§§§§§§§§§§ §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ §§§§§§§§§§§§§§§\n");
 printf("§§§§§§§§§§§§§§§§§§§§§§§§§§§§(    bienvenue dans l'espace des evenements speciaux UNIX   )§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n ");
 printf("§§§§§§§§§§ §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ §§§§§§§§§§§§§§§\n");
   
    int num;
    printf("\t\t\tEntrez le numéro de carte du membre : \n");
        char input[20];
    f:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto f;
    }

    num = atoi(input);
    FILE* F;
    F = fopen(MEMBERS, "r");
    if (F == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        sleep(3);
        menu_principale();
    }else
    {

         membre doc;

        int choix;
               
        if (rech(num)==1) 
        {
             fscanf(F,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",&doc.num_carte,doc.nom,doc.prenom,doc.couleur,&doc.contact,doc.mail,&doc.cotisation,&doc.retard);
           
            if (strcmp(doc.couleur, "standard") == 0 || strcmp(doc.couleur, "STANDARD") == 0) 
            {
                printf("\n\t\t\tVous n'avez pas le droit de participer aux événements spéciaux UNIX\t\t\tveuillez vous faire enregistrer en tant que membre premium.");
                sleep(5);
                menu_principale();
            }
            else if (strcmp(doc.couleur, "premium") == 0 && doc.cotisation >= 34 || strcmp(doc.couleur, "PREMIUM") == 0 && doc.cotisation >= 34) 
            {
                printf("\n\t\t\tVous avez les autorisations requises pour participer aux événements spéciaux UNIX.\n");
                printf("\t\t\tVeuillez choisir un événement spécial UNIX:\n");
                printf("\t\t\t\t1.special UNIX_READING_MAX\n");
                printf("\t\t\t\t2.special UNIX_TRAINING_MAX\n");
                printf("\t\t\t\t3.special UNIX_PRESENTATION_MAX\n");
                 scanf("%d",&choix);
                
                switch (choix)
                {
                    case 1:
                        printf("\t\t\tVoulez-vous y participer ? [1]\n\t\t\tDetails [2]");
                        int rep;
                        scanf("%d",&rep);
                        if (rep == 1)
                        {
                            FILE* fp = fopen(EVENTS, "a+");
                            if (fp==NULL)
                            {
                                printf("\n\t\terreur d 'ouverture de evenement1.txt\n");
                            }else
                            {
                                fprintf(fp,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",doc.num_carte,doc.nom,doc.prenom,doc.couleur,doc.contact,doc.mail,doc.cotisation,doc.retard);
                                printf("....................................................inscrit avec succes !.......................................................................\n\n");
                                printf("\nL EVENEMENT CE TIEN CHAQUE MOIS A PARTIR DU 1ER: VOIR DETAIL\n\n\n ");
                            
                            }
                            fclose(fp);

                            
                            
                        }
                        else if (rep == 2)
                        {
                            FILE* fichier = fopen(ABOUT1, "r");
                            if (fichier == NULL) 
                            {
                                printf("Erreur lors de l'ouverture du fichier event1.txt.\n");
                                sleep(2);
                                system("clear");
                                menu_principale();
                            }else
                            {
                              FILE*rp=fopen(ABOUT1,"r");
                              int txt;
                               if (rp == NULL) 
                               {
                                  printf("Erreur d'ouverture du fichier.\n");
                                  sleep(2);
                                  menu_principale();
      
                                }
                                while ((txt = fgetc(rp)) != EOF) 
                                {
                                   printf("%c", txt);
                                }
                                fclose(rp);
                            }
                            

                            fclose(fichier); 
                        }
                    break;
                    case 2:
                        printf("\t\t\tVoulez-vous y participer ? [1]\n\t\t\tDetails [2]");
                        scanf("%d",&rep);
                        if (rep == 1)
                        {  
                           FILE* fp = fopen(EVENTS2, "a+");
                            if (fp==NULL)
                            {
                                printf("\n\t\terreur d 'ouverture de evenement2.txt\n");
                            }else
                            {
                                fprintf(fp,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",doc.num_carte,doc.nom,doc.prenom,doc.couleur,doc.contact,doc.mail,doc.cotisation,doc.retard);
                                printf("....................................................inscrit avec succes !.......................................................................\n\n");
                            
                            }
                            fclose(fp);
                        }
                        else if (rep == 2)
                        {
                            FILE* fichier2 = fopen(ABOUT2, "r+");
                            if (fichier2 == NULL) 
                            {
                                printf("Erreur lors de l'ouverture du fichier.\n");
                                sleep(2);
                                system("clear");
                                menu_membres();
                            }
                            else
                            {
                                
                            printf("\t\t\tNOUS SOMME DESOLÉ MAIS CETTE EVENNEMENT N ES PAS ENCORE DISPONIBLE\n");
                            //LECTURE DE EVENT2
                          

                            }
                            fclose(fichier2); 
                        }
                    break;
                    case 3:
                        printf("\t\t\tVoulez-vous y participer ? [1]\n\t\t\tDetails [2]");
                        scanf("%d",&rep);
                        if (rep == 1)
                        {  
                           FILE* fp = fopen("evenement3.txt", "a+");
                            if (fp==NULL)
                            {
                                printf("\n\t\terreur d 'ouverture de evenement.txt\n");
                            }else
                            {
                                fprintf(fp,"%d ;%s\n ;%s\n;%s\n;%d\n;%s\n;%d\n;%d\n",doc.num_carte,doc.nom,doc.prenom,doc.couleur,doc.contact,doc.mail,doc.cotisation,doc.retard);
                                printf("....................................................inscrit avec succes !.......................................................................\n\n");
                            
                            }
                            fclose(fp);
                        }
                        else if (rep == 2)
                        {
                            FILE *fichier3 = fopen("event3.txt", "r+");
                            if (fichier3 == NULL) 
                            {
                                printf("Erreur lors de l'ouverture du fichier.\n");
                                sleep(2);
                                system("clear");
                                menu_principale();
                            }
                            else
                            {
                           

                             printf("\t\t\tNOUS SOMME DESOLÉ MAIS CETTE EVENNEMENT N ES PAS ENCORE DISPONIBLE\n");
                            }
                            
  
                           
                        }
                    break;
                
                    default:
                        printf("\n\t\t\tChoix invalide.\n");
                    break;
                }
            } 
        }
        else
        {
            printf("\t\t\t inexistant\n");
        }
    fclose(F);
}
}


void log1() 
{
    
    
    printf("\t\t\t\t#############################################################\n"); 
    printf("\t\t\t\t###################################################   #######\n"); 
    printf("\t\t\t\t###############################################   /~\\   #####\n");
    printf("#\t\t\t\t###########################################   _- `~~~', ####\n");
    printf("\t\t\t\t##########################################  _-~       )  ####\n");
    printf("\t\t\t\t#######################################  _-~          |  ####\n");
    printf("\t\t\t\t####################################  _-~            ;  #####\n");
    printf("\033[0;31m");
    printf("\t\t\t\t##########################  __---___-~              |   #####\n");
    printf("\t\t\t\t#######################   _~   ,,                  ;  `,,  ##\n");
    printf("\t\t\t\t#####################  _-~    ;'                  |  ,'  ; ##\n");
    printf("\t\t\t\t###################  _~      '                    `~'   ; ###\n");
    printf("\t\t\t\t############   __---;                                 ,' ####\n");
    printf("\t\t\t\t########   __~~  ___                                ,' ######\n");
    printf("\t\t\t\t#####  _-~~   -~~ _                               ,' ########\n");
    printf("\t\t\t\t##### `-_         _          \033[38;2;255;165;0mUNIX_MAX \t         ; ##########\033[0m\n");
  printf("\033[0m");   printf("\033[38;2;255;165;0m");;
    printf("\t\t\t\t#######  ~~----~~~   ;                          ; ###########\n");
    printf("\t\t\t\t#########  /          ;                        ; ############\n");
    printf("\t\t\t\t#######  /             ;                      ; #############\n");
    printf("\t\t\t\t#####  /                `                    ; ##############\n");
    printf("\t\t\t\t###  /                                      ; ###############\n");
    printf("\t\t\t\t#                                            ################\n");
    printf("\033[0m");

}

void logi() {
    printf("        .\n");
    printf("    /\\ /l");
    printf("   ((.Y(!\n");
    printf("    \\ |/\n");
    printf("    /  6~6,\n");
    printf("    \\ _    +-. \n");
    printf("     \\`-=--^-'\n");
    printf("      \\ \\\n");
    printf("     _/  \\\n");
    printf("    (  .  Y");
    printf("   /\"\\ `--^--v--.\n");
    printf("  / _ `--\"T~\\/\\/ \n");
    printf(" / \" ~\\.  ! \n");
    printf("Y    Y./' \n");
    printf("|   /./' \n");
    printf("|   Y | \n");
    printf("| |/| |          -UNIX_MAX \n");
    printf("| Y | ! \n");
    printf("! | |/| | \n");
    printf("j l j_L______ \n");
    printf(",____{ __\"~ __ ,\\_,\\_ \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   
}


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
    printf("\n\t\t\t____________________________________________________________________________\n");
    printf("\t\t\t\t\t\t|LISTE DES RESERVATIONS|                                  \n");
    printf("\n\n\t\t\t\t____________________________________________________________________________\n");
    printf("\t\t\t\t\t\t|ID|\t\tNOM|\t\tDATE ET HEURE DE RESERVATION|\n");                         
    printf("\t\t\t\t____________________________________________________________________________|\n");

    int ID_MEMBERS;
    char NOM[50];
    char date_reservation[20];

    while (fscanf(f, "%d,%[^,],%[^\n]\n", &ID_MEMBERS, NOM, date_reservation) != EOF) {
        printf("\t\t\t\t\t\t |%d\t\t%s|\t\t%s|\n", ID_MEMBERS, NOM, date_reservation);
    } 
    printf("\t\t\t\t |________________________________________________________________________|\n");
    printf("\t\t\t\t |________________________________________________________________________|\n\n\n");

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

void MENU_RESERVATION() {
    int choix;
    int ID;
    char nom[MAX_BUFFER];
    first = NULL;
    last = NULL;
    
    do {
        printf("\t\t\t\t_______________________________________________________________________\n");
        printf("\n\t\t\t\t\t\t|OPTION SUR LA FILE DE RESERVATION.|\n\n");
        printf("\t\t\t\t_______________________________________________________________________\n");
        printf("\t\t\t\t[1]. Ajouter un élément à la file...................................|U|\n");
        printf("\t\t\t\t[2]. traiter une reservation dans la file...........................|N|\n");
        printf("\t\t\t\t[3]. Afficher le premier élément de la file.........................|I|\n");
        printf("\t\t\t\t[4]. Afficher le dernier élément de la file.........................|X|\n");
        printf("\t\t\t\t[5]. Afficher le nombre total d'éléments dans la file...............| |\n"); 
        printf("\t\t\t\t[6]. Vider la file..................................................|M|\n"); 
        printf("\t\t\t\t[7]. Afficher toutes les réservations...............................|A|\n"); 
        printf("\t\t\t\t[8]. Quitter le programme...........................................|X|\n"); 
        printf("\t\t\t\t_______________________________________________________________________\n");
        printf("\t\t\t\t-->>Entrez votre choix[1-8]: "); 
        fflush(stdout);

 
    char input[MAX_BUFFER];
    scanf(" %[^\n]", input);
    getchar();
    if (!validate_int(input, &choix)) {
        print_error(INPUT_ERROR);
        continue;
    }

    switch (choix) {
        case 1:
            printf("\t\t\t\t\t\tEntrez l'ID de la réservation: ");
            fflush(stdout);
            scanf(" %[^\n]", input);
            if (!validate_int(input, &ID)) {
                print_error(INPUT_ERROR);
                break;
            }

            printf("\t\t\t\t\t\tENTREZ LE NOM DU LIVRE LIVRE: ");
            fflush(stdout);
            scanf(" %[^\n]", nom);
        f:  printf("\n\n\t\t\t\t\t\tID DE L'EMPRUNTEUR:");
            
            int id; int trouve = 0;

             scanf(" %[^\n]", input);
             getchar();
             if (!validate_int(input, &id)) {
                print_error(INPUT_ERROR);
                break;
            }
            livre liv;
            if (!validate_int(input, &id)) 
            { 
                print_error(INPUT_ERROR); break; }

                if (rech(id) == 1) 
                {
                     trouve = 1;
                   
                    push_file(ID, nom); 
                    printf("\t\t\t\t\t\t\tLIVRE RESERVÉ.\n"); 
                    miseAJourLivre(ID, 0);
                    liv.estdispo=0;
                    break;
                   
                   
                } else 
                {
                     printf("\n\n \t\t\t\t\t\tmembre non trouvé"); 
                     goto f;
                }
               


           
            break;

        case 2:
            pop_file();
            printf("\t\t\t\t\t\tRESERVATION  EN TETE TRAITÉ!.\n");
            break;

        case 3:
            if (is_empty_file()) {
                printf("\t\t\t\t\t\tLa file est vide.\n");
            } else {
                printf("\t\t\t\t\t\tLe premier élément dans la file est: ID = %d, Nom = %s, Date de réservation = %s", first_reservation(), first->NOM, first->date_reservation); } break;

 
        case 4:
            if (is_empty_file()) {
                printf("\t\t\t\t\t\tLa file est vide.\n");
            } else {
                printf("\t\t\t\t\t\tLe dernier élément dans la file est: ID = %d, Nom = %s, Date de réservation = %s", last_reservation(), last->NOM, last->date_reservation); } break;

 
        case 5:
            printf("\t\t\t\t\t\tLe nombre total d'éléments dans la file est: %d", nb_reservation); break;

 
        case 6:
            printf("VOULEZ- VOUS VRAIMENT LE FAIRE, CETTE ACTION EST IRREVERSIBLE[O/N]");
            char p;
            scanf("%s",&p);
            
            if(p=='n'||p=='N')
            {
                printf("t\t\t\t\t\tsupression annué!\n");
            }else if(p=='o'||p=='O')
            {
                clear_file();
            printf("\t\t\t\t\t\tLa file a été vidée avec succès.\n");
            }
            break;

        case 7:
            display_all_reservations();
            break;

        case 8:
            printf("\t\t\t\t\t\tSortie du programme...\n");
            sleep(2);
            gestion_emprunt();
            
            break;

        default:
            printf("\t\t\t\t\t\tChoix invalide. Veuillez réessayer.\n");
    }
} while (choix != 8);

}



void reserve ()
{
    char action;
    
    int code;
    printf("                             WELCOME TO RESERVATION SYSTEM\n\n                          CHOISE:");
    printf("\n\n\t\t\t\t\t\t[A]ACTIONS SUR LA FILE DE RESERATION\n\t\t\t\t\t\t[B]AJOUTER UNE RESERVATION A LA FILE\n\n");
    scanf("%s",&action);
    getchar();
    if (action=='A'||action=='a')
    {
        MENU_RESERVATION();
    }
    else if(action=='B'||action=='b')
    {
     printf("                           QUEL LIVRE VOUS SOUHAITEZ RESERVER (CODE) :");
         char input[20];
    fFF:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto fFF;
    }

    code = atoi(input);
    livre liv = rech_livres(code);
  
    if(liv.num_livre != -1)
    {
        printf("COOL, LIVRE TROUVÉ!\n");
        if (liv.estdispo != 1)
        {
            printf("                     MAIS NON DISPONIBLE:'VOUS AVEZ LE CHOIX ENTRE:\n'");
            printf("                    1. ADHERER A UNE FILE DE RESERVATION \n                         2. ATTENDRE QU'IL SOIT A NOUVEAU DISPONIBLE");
            int rep;
                 
    fF:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto fF;
    }

    rep = atoi(input);
            if (rep==2)
            {
                printf("\t\t\t\tVEUILLEZ PATIENTER QUELQUES INSTANTS !");
                printf("\t\t\t\tPLEACE WAIT FOR FEW SECOND!");
                sleep(2);
                printf("\n\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
                sleep(1); 
                system("clear");
                printf("\n\n\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                sleep(1); 
                system("clear");
                printf("\n\n\n\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t\n");
                sleep(1); 
                system("clear");
                gestion_emprunt();
            }
            else if (rep==1)
            {  int ID;
              char nom[MAX_BUFFER];
                
                sleep(1);
                system("clear");
                char input[MAX_BUFFER];
                 printf("\t\t\t\t\t\tEntrez l'ID de la réservation: ");
            fflush(stdout);
                 
    fD:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto fD;
    }

    ID = atoi(input);

            printf("\t\t\t\t\t\tENTREZ LE NOM DU LIVRE LIVRE: ");
            fflush(stdout);
            scanf(" %[^\n]", nom);
        f:  printf("\n\t\t\t\t\t\tID DE L'EMPRUNTEUR:\n");
            int id;
                 
    fC:printf("ENTREZ UNE SAISI : ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!isIntegerS(input)) {
        printf("La valeur entrée n'est pas un entier.\n");
        goto fC;
    }

    id = atoi(input);
            
            if (rech(id)==1)
            {
            push_file(ID, nom);
            printf("\t\t\t\t\t\t\tLIVRE RESERVÉ.\n");
             
            }else
            {
                printf("\n\t\t\t\t\t\tmembre non trouvé");
                goto f;
            }
            
            


            }   
        }
        else
        {
             printf("IL EST DISPONIBLE A L'EMPRUNT:");
             printf("VOUS SEREZ REDIRIGER VERS L'ESPACE DE RESERVATION DANS 5 SECONDES");
             printf("\n\t\t\t\t\t\t[[[[[[[[[[[  5  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
                    printf("\n\t\t\t\t\t\t[[[[[[[[[[[  4  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
                    printf("\n\t\t\t\t\t\t[[[[[[[[[[[  3  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
                    printf("\n\t\t\t\t\t\t[[[[[[[[[[[  2  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
                    printf("\n\t\t\t\t\t\t[[[[[[[[[[[  1  ]]]]]]]]]]]\t\t\t\t");
                    sleep(1); 
                    system("clear");
             enregistrer_emprunt();
        }
    }
    else
    {
        printf("\nLIVRE INEXISTANT.\n");
    }
    
    
    }
   
}
// entiere ou pas..................................................................................................µ.................*
int isIntegerS(const char* str) {
    int len = strlen(str);

    if (len == 0) {
        return 0;  
    }

    int i = 0;

    if (str[0] == '-' || str[0] == '+') {
        if (len == 1) {
            return 0;  
        }
        i = 1;
    }

    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;  
        }
    }

    return 1;  
}
void remove_all()
{
    printf("WARNING:    CETTE OPERATION SUPPRIMERA TOUTES LES DONNÉES DES(LIVRES,AUTEURS ,MEMBRES)\n\n");
   printf("PRESS 'o' KEY TO CONFIRM OR 'N' KEY TO CANCEL....");
    char rep;
    scanf("%c",&rep);
    getchar();
    if (rep=='o'||rep=='O')
    {
       supprimer_livre();
       supprimer_auteur();
       supprimé_membre();

    }else if(rep=='n'||rep=='N')
    {
        system("clear");
        printf("cette action n'es pas a prendre a la legère!!\n");
        sleep(3);
        system("clear");
        loginProcedure();
    }
}
