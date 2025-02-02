void enregistrer_emprunt() {
    Emprunts emprunt;
    int num, code;
    int emprunt_trouve = 0;
    printf("ENTRER L'ID DU MEMBRE QUI EMPRUNTE\n");
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
    int membreIndex = rech(num);
    if (membreIndex == -1) {
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
        return;
    }

    char membre[MAX_LENGTH];
    printf("NOM DE CE MEMBRE (POUR VÉRIFICATION DE RETARD POTENTIEL)\nNOM: ");
    scanf("%s", membre);
    fflush(stdin);

    time_t timestamp = time(NULL);
    FILE* fic = fopen(EMPRUNTS, "r");
    if (fic == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        sleep(2);
        gestion_emprunt();
        return;
    }

    char line[MAX_LENGTH];
    int membre_trouve = 0;
    while (fgets(line, MAX_LENGTH, fic)) 
    {
        char membre_emprunt[MAX_LENGTH];
        char manuel[MAX_LENGTH];
        time_t timestamp_emprunt;
        time_t timestamp_remise;
        int delai_remise;
        int CODE;
        sscanf(line, "%[^,],%[^,],%ld,%ld,%d,%d", membre_emprunt, manuel, &timestamp_emprunt, &timestamp_remise, &delai_remise, &CODE);

        FILE* r = fopen(MEMBERS, "r");
        Membre doc;

        while (fscanf(r, "%d;%[^;];%[^;];%[^;];%d;%[^;];%d;%d\n", &doc.num_carte, doc.nom, doc.prenom, doc.couleur, &doc.contact, doc.mail, &doc.cotisation, &doc.retard) == 8) {
            if (doc.num_carte == num) {
                membre_trouve = 1;
                break;
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
            }
            emprunt_trouve = 1;
            break;
        }
    }
    fclose(fic);

    if (emprunt_trouve) {
        printf("Ce membre a déjà emprunté un livre.\n");
        gestion_emprunt();
        return;
    }

    printf("ENTRER LE CODE DU LIVRE EMPRUNTÉ\n");

    while (1) {
        printf("CODE: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!isIntegerS(input)) {
            printf("La valeur entrée n'est pas un entier.\n");
            continue;
        }
        code = atoi(input);
        break;
    }

    int livre_trouve = rech_liv(code);
    if (livre_trouve == -1) {
        printf("Ce livre n'existe pas.\n");
        gestion_emprunt();
        return;
    }

    FILE* file = fopen(EMPRUNTS, "a");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        sleep(2);
        gestion_emprunt();
        return;
    }

    fprintf(file, "%s,%s,%ld,%ld,%d,%d\n", membre, livre[livre_trouve].nom, timestamp, -1, livre[livre_trouve].duree, livre[livre_trouve].code);
    fclose(file);

    printf("L'emprunt a été enregistré avec succès.\n");
    gestion_emprunt();
}