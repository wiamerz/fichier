#include <stdio.h>
#include <string.h>

// D�claration des structures
typedef struct {
    int jour;
    int mois;
    int annee;
} date;

// Structure imbriqu�e
typedef struct {
    char name[30];
    char description[100];
    char priorite[30];
    date date;
} tache;

// Fonction de cr�ation des t�ches
void creation(tache tab[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Entrer le titre de cette tache: ");
        scanf(" %[^\n]", tab[i].name); // Utilisation de %[^\n] pour lire la ligne compl�te
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

int main(void) {
    tache tab[100];
    int choix, n;

    printf("Combien de t�ches voulez-vous cr�er ? ");
    scanf("%d", &n);

    while (choix != 6) {
        printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n");
        printf("1. Cr�er\n");
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





        case 6:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    }

    return 0;
}
