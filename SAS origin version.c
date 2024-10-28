#include <stdio.h>
#include <string.h>

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
    date date;
} tache;

// Fonction de création des tâches
void creation(tache tab[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Entrer le titre de cette tache: ");
        scanf(" %[^\n]", tab[i].name); // Utilisation de %[^\n] pour lire la ligne complète
        printf("Entrer une description pour cette tache: ");
        scanf(" %[^\n]", tab[i].description);
        printf("Entrer le jour: ");
        scanf("%d", &tab[i].date.jour);
        printf("Entrer le mois: ");
        scanf("%d", &tab[i].date.mois);
        printf("Entrer l'annee: ");
        scanf("%d", &tab[i].date.annee);
        printf("Entrer la priorite de cette tache: ");
        scanf(" %[^\n]", tab[i].priorite);
    }
}
// fonction d'affichade d'une tache 
voide afficher()




int main(void) {
    tache tab[100];
    int choix, n;

    printf("Combien de tâches voulez-vous créer ? ");
    scanf("%d", &n);

    while (choix != 6) {
        printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n");
        printf("1. Créer\n");
        printf("2. Afficher\n");
        printf("3. Modifier\n");
        printf("4. Supprimer\n");
        printf("5. Filtrer\n");
        printf("6. Quitter\n");

        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creation(tab, n);
                break;
            case 2:
               affichage(tab,n);
               break;



        case 6:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
