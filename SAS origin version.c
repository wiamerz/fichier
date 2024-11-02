#include <stdio.h>
#include <string.h>
#include <stdbool.h>


 int choix  ;
 int n=0;  // Initialisatio n de n à 0 pour indiquer aucune tâche

// Déclaration des structures
typedef struct {
    int jour;
    int mois;
    int annee;
} date;

// Structure imbriquée
typedef struct {
    char name[30];
    char description[100];
    int  priorite; // 0 pour low 1 pour high
    int  statue; // 0 pour incomplete 1 pour complete
    date date;
} tache;


// Fonction pour enregistrer les tâches
int save(tache tab[], int n) {
    if (n == 0) {
        printf("Aucune tâche à enregistrer, ajoutez des tâches d'abord.\n");
    } else {
        FILE *fichier;
        fichier = fopen("gestiontaches.txt", "a"); // Nom du fichier modifié pour correspondre au message
        if (fichier == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            fprintf(fichier, "~~~~~~~~~~~~ La tâche %d ~~~~~~~~~~~~\n", i + 1);
            fprintf(fichier, "Titre : %s\n", tab[i].name);
            fprintf(fichier, "Description : %s\n", tab[i].description);
            fprintf(fichier, "Date de fin jj/mm/aaaa : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
            fprintf(fichier, "Priorité : %d\n", tab[i].priorite);
            fprintf(fichier, "Statue : %d\n\n", tab[i].statue);
        }

        fclose(fichier);
        printf("Les tâches ont été enregistrées dans gestiontaches.txt.\n");
    }
    return 0;
}


// Fonction de validation de la date pour s'assurer que l'utilisateur n'entre pas une date non valide.
bool validationdate (int jour, int mois, int annee)
{
    if (annee<2024) return false;
    if (mois<1 || mois>12) return false;


    int lesjoursdemois [] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mois == 2)
    {
        if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)  //Si l'année est divisible par 4 et non par 100, elle est bissextile.
        {                                                              //Si l'année est divisible par 400, elle est également bissextile.
           lesjoursdemois[2] = 29; // si le mois est 2 ne depasse pas 29
        }
        }
    return (jour > 0 && jour <= lesjoursdemois[mois]);  //L'utilisateur a le droit d'entrer le nombre de jours qui dépend du mois saisi.
}



// Fonction de création des tâches
void creation(tache tab[], int maxTaches) {
    int i, nouveaunombre;    // Si l'utilisateur peut ajouter d'autres nouvelles tâches en plus de celles déjà données.

    printf("Combien de taches voulez-vous creer : ");
    scanf("%d", &nouveaunombre);

    // Vérifier que le nombre des taches ne dépasse pas la capacité que le tableau peut obtenu
    if (n + nouveaunombre > maxTaches) {
        printf("Erreur : nombre de taches depassant la capacite maximale (%d).\n", maxTaches - n);
        return;
    }

    for (i = n; i < nouveaunombre+n; i++) {
        printf("\n---- Tache %d ----\n", i + 1 );

        printf("Entrer le titre de cette tache : ");
        scanf(" %[^\n]s", tab[i].name);

        printf("Entrer une description pour cette tache : ");
        scanf(" %[^\n]s", tab[i].description);

        printf("Entrer date de fin (jj/mm/aaaa) : ");
        scanf("%d/%d/%d", &tab[i].date.jour, &tab[i].date.mois, &tab[i].date.annee  );

                while (!validationdate(tab[i].date.jour, tab[i].date.mois  , tab[i].date.annee))
                    {
                printf("invalide, entrer une autre date (jj/mm/aaaa):");
               scanf("%d / %d / %d", &tab[i].date.jour, &tab[i].date.mois  , &tab[i].date.annee  );
               }

        printf("Entrer la priorite de cette tache (0 pour low / 1 pour high) : ");
        scanf("%d", &tab[i].priorite);
        while (tab[i].priorite != 0 && tab[i].priorite != 1){
            printf("invalide, saisie 0 pour low ou 1 pour high :");
            scanf("%d", &tab[i].priorite);
        }

        printf("Entrer le statue de cette tache (0 pour incomplete/1 pour complete) : ");
        scanf("%d", &tab[i].statue);
        while (tab[i].statue != 0 && tab[i].statue != 1){
        printf("invalide, saisie 0 pour incomplete et 1 pour complete: ");
        scanf("%d", &tab[i].statue);
        }
    }

    n = n + nouveaunombre;
}

// fonction d'affichade d'une tache
void affichage(tache tab[]) {
    if (n <= 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\n---- Tache %d ----\n", i + 1);
        printf("Titre : %s\n", tab[i].name);
        printf("Description : %s\n", tab[i].description);
        printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
        printf("Priorite (0 pour low ou 1 pour high) : %d\n", tab[i].priorite);
        printf("Statut (0 pour incomplete/1 pour complete): %d\n", tab[i].statue);
    }
}


// fonction de modification d'une tache
void modification(tache tab[], int n) {
    int i, choice = 0;

    printf("Entrer l'indice de la tache que vous voulez modifier: ");
    scanf("%d", &i);

    // Vérification de la validité de l'indice
    if (i <= 0 || i > n) {
        printf("Indice non trouvé, veuillez entrer un indice valide.\n");
        return;
    }

    while (choice != 7) {
        printf("\n~~~~~~~~~~LISTE~~~~~~~~~~~~~~~\n");
        printf("1. Nom\n");
        printf("2. Description\n");
        printf("3. Date\n");
        printf("4. Priorite \n");
        printf("5. statue\n");
        printf("6. Modifier tous\n");
        printf("7. Retour au menu\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrer le nouveau nom: ");
                scanf(" %[^\n]s", tab[i - 1].name);
                break;
            case 2:
                printf("Entrer la nouvelle description: ");
                scanf(" %[^\n]s", tab[i - 1].description);
                break;
            case 3:
                printf("Entrer la nouvelle date (jour /mois /annee): ");
                scanf("%d/%d/%d", &tab[i - 1].date.jour, &tab[i - 1].date.mois, &tab[i - 1].date.annee);
                break;
            case 4:
                printf("Entrer la nouvelle priorite (0 pour low ou 1 pour high): ");
                scanf("%d", &tab[i - 1].priorite);
                break;
            case 5:
                printf("Entrer la nouvelle statue (0 pour incomplete/1 pour complete): ");
                scanf("%d", &tab[i - 1].statue);
                break;
            case 6:
                printf("Entrer un autre titre pour cette tache: ");
                scanf(" %[^\n]s", tab[i - 1].name);
                printf("Entrer une autre description pour cette tache: ");
                scanf(" %[^\n]s", tab[i - 1].description);
                printf("Entrer la nouvelle date (jour mois annee): ");
                scanf("%d/%d/%d", &tab[i - 1].date.jour, &tab[i - 1].date.mois, &tab[i - 1].date.annee);
                printf("Entrer la priorité de cette tache (0 pour low ou 1 pour high): ");
               scanf("%d", &tab[i - 1].priorite);
                 printf("Entrer la statue de cette tache(0 pour incomplete/1 pour complete): ");
               scanf("%d", &tab[i - 1].statue);
                break;
            case 7:
                printf("Quitter la liste.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
}

// fonction de supression d'une tache
void supression(tache tab[]){
       int pos,i;
       printf ("entrer la position de la tache que vouler supprimer :");
       scanf ("%d",&pos);

    if ( pos <= 0 || pos > n ){
        printf("Position non trouve, veuillez entrer une autre ");
        } else {
           for (i =pos-1 ; i<n-1 ; i++){
            tab[i]=tab[i+1];
           }
           n--;
        printf("La tache a ete supprimee avec succes.\n");
        printf("Les taches restantes sont :\n");
        affichage(tab);
    }
}
// Fonction de filtrage par priorité
void filtragepriorite(tache tab[]) {
    int priorite;
    int i, found = 0;
    printf("Entrer une priorite : 1 pour high, 0 pour low : ");
    scanf("%d", &priorite);

     if (priorite != 0 && priorite != 1) {
        printf("Priorite non reconnue. Veuillez entrer 0 ou 1.\n");
        return;
    }

            for (i = 0; i < n; i++) {
                    if (tab[i].priorite == priorite)  {
                    printf("\n---- Tache %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %d\n", tab[i].priorite );
                    printf("statue : %d\n", tab[i].statue );
                    found =1; //tache trouve
                }
            }
            if (!(found)) {
                printf("Aucune tache avec cette priorite.\n");
            }
}



// Fonction de filtrage des tâches par statue
void filtragestatut(tache tab[]) {
    int statue ;
    int i, found = 0;
    printf("Entrer un statue : 1 pour complete, 0 pour incomplete : ");
    scanf("%d", &statue);

     if (statue != 0 && statue != 1) {
        printf("statue non reconnue. Veuillez entrer 0 ou 1.\n");
        return;
    }

            for (i = 0; i < n; i++) {
                    if (tab[i].statue == statue)  {
                    printf("\n---- Tache %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %d\n", tab[i].priorite );
                    printf("statue : %d\n", tab[i].statue );
                    found =1; //tache trouve
                }
            }
            if (!(found)) {
                printf("Aucune tache avec cet statue.\n");
            }
}


/*void filtragestatut(tache tab[]) {
    int statue;
    int i, found = 0;
    printf("Entrer une statue: 0 pour incomplete, 1 pour complete : ");
    scanf("%d", &statue);

     if (statue != 0 && statue != 1) {
        printf("Priorite non reconnue. Veuillez entrer 0 ou 1.\n");
        return;
    }
            for (i = 0; i < n; i++) {
                if (tab[i].statue= statue) {
                   printf("\n---- Tache %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %d\n", tab[i].priorite);
                    printf("statue : %d\n", tab[i].statue);
                    found =1; //statue trouve
                }
            }if (!found) {
                printf("Aucune tache avec cette statue.\n");
            }

}*/


int main() {
    int maxTaches = 100;
    tache tab[maxTaches];



    while (choix != 8) {
        printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n");
        printf("1. Creer\n");
        printf("2. Afficher\n");
        printf("3. Modifier\n");
        printf("4. Supprimer\n");
        printf("5. Filtrer par priorite\n");
        printf("6. Filtrer par statue\n");
        printf("7. Save\n");
        printf("8. Quitter\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creation(tab,maxTaches);
                break;
            case 2:
               affichage(tab);
               break;
            case 3:
                modification(tab,n);
            break;
            case 4:
                supression(tab);
             break;
            case 5:
                filtragepriorite(tab);
            break;
            case 6:
                filtragestatut(tab);
            break;
            case 7:
                save(tab,n);
            break;
            case 8:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}
