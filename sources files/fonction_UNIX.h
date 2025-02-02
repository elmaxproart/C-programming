#ifndef FUNCTION_H
#define  FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define MAX_LENGTH 1000
#define MAX_BUFFER 1000


//structures
typedef struct 
{
    char nom[MAX_LENGTH];
    int  identifiant;
    int  mot_de_passe;

}bibiotheque;

//procedures
void systeme();
void bienvenue();
void logo();
void remove_all();
void geré_bilbiotheque ();
void menu_principale ();
void menu_principale_publique();
void menu_membres();
void menu_auteur();
void menu_livre();
void supprimé_biliotheque();
void about();
void registerProcedure();
void loginProcedure();
void parametres();
void rech_admin();
void deleteUser(char usernameToDelete[50]);
//fonctions
int recherche_id();

typedef  struct 
{
  int num_carte ;
    char nom [MAX_LENGTH];
    char prenom[MAX_LENGTH];
    char couleur[MAX_LENGTH];
    int  contact;
    char mail[MAX_LENGTH];
    int cotisation ;
    int retard;
} membre;
  int rech(int numrech);
  void ajoutermenbre();
  void rechercher();
  void supprimé_membre();
  void modifier_membre();
  void afficher_tous();
  void est_Autorise();
  void gestion_emprunt();
typedef struct
{
    int num_auteur;
    char nom[100];
    char prenom[50];
    int  contact;
    char mail[100];

}auteur;
int rech_auteur(int numrech);
void ajouterauteur();
void rechercher_auteur();
void supprimer_auteur();
void afficher_tous_auteur();
void modifier_auteur() ;
typedef struct
{
    int num_livre;
    char nom[100];
    char genre[50];
    int date_creation;
    char auteur[100];
    int estdispo;
}livre;
int  rech_livre(int numrech);
livre rech_livres(int numrech);
void ajouterlivre();
void rechercher_livre();
void supprimer_livre();
void modifier_livre() ;
void afficher_tous_livre();
typedef struct
{
    int num_livre;
    char nom[100];
    char gerne[50];
    int  date_debut;
    int date_fin;
}event;

typedef struct Emprunt
{
    int num_emprunt;
    char date_emprunt[50];  
    char date_Retour[50];  
   
} Emprunt;
typedef struct
{ 
    char membre[MAX_LENGTH]; 
    char manuel[MAX_LENGTH]; 
    time_t timestamp_emprunt; 
    time_t timestamp_remise;
int delai_remise;
int CODES;
} Emprunts;
int isCodeExisting(int codeArray[], int numCodes, int code);
void welcome();
void GER() ;
void verifier_emprunt() ;
void enregistrer_emprunt();
int genererCodeRetrait();
void delecte_emprunt();
int rech_emprunt(int numrech);
void rechercher_emp();
void livre_emp();
void memb_emp();

int gener_id();
typedef struct 
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct 
{
    int heure;
    int minute;
    int seconde;
} Heure;

int calcule_revenue(int nb_me_p);
void compterMembresEtRevenu();
void eventsss();


void log1() ;
void logi();
void reserve();
bool isInteger(char* inputString);
int convertToInt(char* inputString);
void interger();
Emprunts rech_emp(int numrech);
void miseAJourLivre(int code, int disponible);
void gerer_retour() ;
void afficher_reservations();
void  AVAILABLE_BOOKS_LIST() ;
//................;;;........................;.;;;;.fifo && liste chainée..................;;;....;;;........................

typedef struct file {
    struct file *next;
    int ID_MEMBERS;
    char NOM[MAX_BUFFER];
    char date_reservation[MAX_BUFFER];
} file;

typedef enum {
    FILE_ERROR,
    INPUT_ERROR,
} ErrorCode;
void MENU_RESERVATION();
////////////////////////////////// ENTIER OU PAS /////////////////////////////////////////////////////////////////////////////////
int isIntegerS(const char* str) ;

#endif
