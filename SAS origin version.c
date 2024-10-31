#include <stdio.h>
#include <string.h>



 int choix  ;
 int n=0;  // Initialisation de n à 0 pour indiquer aucune tâche

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
    char priorite[30];
    char statut[30];
    date date;
} tache;

// Fonction de création des tâches
void creation(tache tab[], int maxTaches) {
    int i, nouveaunombre;

    printf("Combien de tâches voulez-vous créer : ");
    scanf("%d", &nouveaunombre);

    // Vérifier que le nombre des taches ne dépasse pas la capacité que le tableau peut obtenu
    if (n + nouveaunombre > maxTaches) {
        printf("Erreur : nombre de taches depassant la capacite maximale (%d).\n", maxTaches - n);
        return;
    }

    for (i = 0; i < nouveaunombre; i++) {
        printf("\n---- Tâche %d ----\n", i + 1 + n);

        printf("Entrer le titre de cette tâche : ");
        scanf(" %[^\n]", tab[n + i].name);

        printf("Entrer une description pour cette tâche : ");
        scanf(" %[^\n]", tab[n + i].description);

        printf("Entrer le jour : ");
        scanf("%d", &tab[n + i].date.jour);

        printf("Entrer le mois : ");
        scanf("%d", &tab[n + i].date.mois);

        printf("Entrer l'année : ");
        scanf("%d", &tab[n + i].date.annee);

        printf("Entrer la priorité de cette tâche (high/low) : ");
        scanf(" %[^\n]", tab[n + i].priorite);

        printf("Entrer le statut de cette tâche (complète/incomplète) : ");
        scanf(" %[^\n]", tab[n + i].statut);
    }

    n += nouveaunombre;
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
        printf("Priorite : %s\n", tab[i].priorite);
        printf("Statut : %s\n", tab[i].statut);
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
        printf("4. Priorite\n");
        printf("5. statut\n");
        printf("6. Modifier tous\n");
        printf("7. Retour au menu\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrer le nouveau nom: ");
                scanf(" %[^\n]", tab[i - 1].name);
                break;
            case 2:
                printf("Entrer la nouvelle description: ");
                scanf(" %[^\n]", tab[i - 1].description);
                break;
            case 3:
                printf("Entrer la nouvelle date (jour /mois /annee): ");
                scanf("%d/%d/%d", &tab[i - 1].date.jour, &tab[i - 1].date.mois, &tab[i - 1].date.annee);
                break;
            case 4:
                printf("Entrer la nouvelle priorite: ");
                scanf(" %[^\n]", &tab[i - 1].priorite);
                break;
            case 5:
                printf("Entrer la nouvelle statut: ");
                scanf(" %[^\n]", &tab[i - 1].statut);
                break;
            case 6:
                printf("Entrer un autre titre pour cette tache: ");
                scanf(" %[^\n]", tab[i - 1].name);
                printf("Entrer une autre description pour cette tache: ");
                scanf(" %[^\n]", tab[i - 1].description);
                printf("Entrer la nouvelle date (jour mois annee): ");
                scanf("%d/%d/%d", &tab[i - 1].date.jour, &tab[i - 1].date.mois, &tab[i - 1].date.annee);
                printf("Entrer la priorité de cette tache: ");
               scanf(" %[^\n]", tab[i - 1].priorite);
                 printf("Entrer la statut de cette tache: ");
               scanf(" %[^\n]", tab[i - 1].statut);
                break;
            case 7:
                printf("Quitter la liste.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
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
    char priorite;
    int i, found = 0;
    printf("Entrer une priorité : 'H' pour high, 'L' pour low : ");
    scanf(" %c", &priorite);
    switch (priorite) {
        case 'L':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].priorite, "low") == 0) {  //strcmp pour comparer la chaîne de caractères stockée dans tab[i].priorite avec la chaîne "low".
                    printf("\n---- Tâche %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %s\n", tab[i].priorite);
                    printf("statut : %s\n", tab[i].statut);
                    found =1; //tache trouve

                }if (!found) {
                printf("Aucune tache avec cette priorité.\n");
            }
            }
            break;

        case 'H':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].priorite, "high") == 0) {  // pour comparer la chaîne de caractères stockée dans tab[i].priorite avec la chaîne "high".
                    printf("\n---- Tâche %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %s\n", tab[i].priorite);
                    printf("statut : %s\n", tab[i].statut);
                    found =1; //tache trouve
                }
            if (!found) {
                printf("Aucune tche avec cette priorité.\n");
            }
            }
            break;

        default:
            printf("Priorite non reconnue. Veuillez entrer 'H' ou 'L'.\n");
    }

}



// Fonction de filtrage des tâches par statue
void filtragestatut(tache tab[]) {
    char statut;
    int i, found = 0;
    printf("Entrer une statue: 'I' pour incomplete, 'C' pour complete : ");
    scanf(" %c", &statut);
    switch (statut) {
        case 'I':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].statut, "incomplete") == 0) {
                   printf("\n---- Tache %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %s\n", tab[i].priorite);
                    printf("statut : %s\n", tab[i].statut);
                    found =1; //statut trouve
                }

            if (!found) {
                printf("Aucune tache avec cette statut.\n");
            }
            }
            break;

        case 'C':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].statut, "complete") == 0) {
                    printf("\n---- Tache %d ----\n", i + 1);
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorite : %s\n", tab[i].priorite);
                     printf("statut : %s\n", tab[i].statut);
                     found =1; //statut trouve
                }


           if (!found) {
                printf("Aucune tache avec cette statut.\n");
            }
            }
            break;

        default:
            printf("Priorite non reconnue. Veuillez entrer 'I' ou 'C'.\n");
    }

}


int main() {
    int maxTaches = 100;
    tache tab[maxTaches];



    while (choix != 7) {
        printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n");
        printf("1. Creer\n");
        printf("2. Afficher\n");
        printf("3. Modifier\n");
        printf("4. Supprimer\n");
        printf("5. Filtrer par priorite\n");
        printf("6. Filtrer par statue\n");
        printf("7. Quitter\n");

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
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}
