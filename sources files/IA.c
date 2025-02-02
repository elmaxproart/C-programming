#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nom[50];
    float frais;
} MembrePremium;

void ia() {
    
    MembrePremium membresPremium[3];

    strcpy(membresPremium[0].nom, "maxym");
    membresPremium[0].frais = 50.0;

    strcpy(membresPremium[1].nom, "mboa");
    membresPremium[1].frais = 75.0;

    strcpy(membresPremium[2].nom, "miguel");
    membresPremium[2].frais = 100.0;

    char question[100];
    printf("Posez une question à l'IA : ");
    fgets(question, sizeof(question), stdin);

    // Convertir la question en minuscules pour une comparaison insensible à la casse
    for(int i = 0; question[i]; i++){
        question[i] = tolower(question[i]);
    }

    if (strcmp(question, "revenue") == 0) {
        
        float totalRevenus = membresPremium[0].frais + membresPremium[1].frais + membresPremium[2].frais;
        float pourcentageRevenus = (totalRevenus / 1000.0) * 100.0;
        printf("Les membres premium contribuent à %.2f%% des revenus de la bibliothèque.\n", pourcentageRevenus);
    } else if (strcmp(question, "donne-moi des informations sur le livre 'moby dick'\n") == 0) {
        
        printf("Le livre 'Moby Dick' a été écrit par Herman Melville en 1851. Vous pouvez en savoir plus sur ce livre en consultant le lien suivant : https://fr.wikipedia.org/wiki/Moby_Dick");
    } else if (strcmp(question, "quel est le nombre total de membres premium actuels?\n") == 0) {
        
        int totalMembresPremium = sizeof(membresPremium) / sizeof(MembrePremium);
        printf("Le nombre total de membres premium actuels est : %d", totalMembresPremium);
    } else if (strcmp(question, "quelles sont les noms des membres premium?\n") == 0) {
      
        for (int i = 0; i < sizeof(membresPremium) / sizeof(MembrePremium); i++) {
            printf("Nom du membre premium %d : %s", i+1, membresPremium[i].nom);
        }
    } else {
        printf("Désolé, je ne peux pas répondre à cette question pour le moment.\n");
    }

}

int main()
{
    ia();
    return 0;
}
