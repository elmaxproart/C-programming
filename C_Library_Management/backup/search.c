#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
   FILE *file;
   char searchKey[MAX_LENGTH];
   char line[MAX_LENGTH];
   char *bookName;

   // Ouvrir le fichier "livre.txt" en mode lecture
   file = fopen("livres.csv", "r");
   if (file == NULL) {
      printf("Erreur lors de l'ouverture du fichier.\n");
      return 1;
   }

   // Demander à l'utilisateur de saisir une lettre ou un mot clé
   printf("Entrez une lettre ou un mot clé pour la recherche : ");
   fgets(searchKey, MAX_LENGTH, stdin);

   // Parcourir le fichier ligne par ligne
   while (fgets(line, MAX_LENGTH, file) != NULL) {
      // Vérifier si le nom du livre commence par la lettre ou le mot clé saisi
      bookName = strtok(line, ":");
      if (strncmp(bookName, searchKey, strlen(searchKey)) == 0) {
         printf("%s", bookName);
      }
  }

   // Fermer le fichier
   fclose(file);

   // Proposer la sélection d'un livre à partir de la position actuelle du curseur de la souris
   // TODO: Ajouter le code de sélection ou d'autres actions nécessaires

   return 0;
}
