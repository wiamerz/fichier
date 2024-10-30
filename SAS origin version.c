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
        scanf(" %[^\n]", tab[i].name); // Utilisation de %[^\n] pour lire l'espace est afficher la phrase complet
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
void affichage(tache tab[],int n){
    int i;

    for (i = 0; i < n; i++) {
      printf("Tritre:%s\n",tab[i].name);
      printf("description:%s\n",tab[i].description);
      printf("date:%d/%d/%d\n",tab[i].date.jour,tab[i].date.mois,tab[i].date.annee);
      printf("priorite:%s\n",tab[i].priorite);

}}

// fonction de modification d'une tache
void modification(tache tab[],int n){
    int i;
    printf("entrer l'indice de la tache que vouler modifier:");
    scanf("%d",&i);
    if (i<=0||i>n) //l'indice il faut pas depasse n et pas moins ou egale  0
        printf("Indice non trouve, veuillez entrer un autre :");
    else {
         printf("Entrer un autre titre pour cette tache: ");
        scanf(" %[^\n]", tab[i-1].name);
        printf("Entrer une autre description pour cette tache: ");
        scanf(" %[^\n]", tab[i-1].description);
        printf("Entrer le jour: ");
        scanf("%d", &tab[i-1].date.jour);
        printf("Entrer le mois: ");
        scanf("%d", &tab[i-1].date.mois);
        printf("Entrer l'annee: ");
        scanf("%d", &tab[i-1].date.annee);
        printf("Entrer la priorite de cette tache: ");
        scanf(" %[^\n]", tab[i-1].priorite);
    }
}



// fonction de supression d'une tache
void supression(tache tab[],int n){
       int pos,i;
       printf ("entrer la position de la tache que vouler supprimer :");
       scanf ("%d",&pos);

    if ( pos <= 0 || pos > n ){
        printf("Position non trouve, veuillez entrer une autre :");
        } else {
           for (i =pos-1 ; i<n-1 ; i++){
            tab[i]=tab[i+1];
           }
           n--;
        printf("La tache a ete supprimée avec succes.\n");
        printf("Les taches restantes sont :\n");
        affichage(tab, n);
    }
}
// Fonction de filtrage par priorité
void filtragepriorite(tache tab[], int n) {
    char priorite;
    int i;
    printf("Entrer une priorité : 'H' pour high, 'L' pour low : ");
    scanf(" %c", &priorite);  // Utiliser %c pour un char
    switch (priorite) {
        case 'L':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].priorite, "low") == 0) {  // pour comparer la chaîne de caractères stockée dans tab[i].priorite avec la chaîne "low".
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorité : %s\n", tab[i].priorite);
                }
            }
            break;

        case 'H':
            for (i = 0; i < n; i++) {
                if (strcmp(tab[i].priorite, "high") == 0) {  // pour comparer la chaîne de caractères stockée dans tab[i].priorite avec la chaîne "high".
                    printf("Titre : %s\n", tab[i].name);
                    printf("Description : %s\n", tab[i].description);
                    printf("Date : %d/%d/%d\n", tab[i].date.jour, tab[i].date.mois, tab[i].date.annee);
                    printf("Priorité : %s\n", tab[i].priorite);
                }
            }
            break;

        default:
            printf("Priorité non reconnue. Veuillez entrer 'H' ou 'L'.\n");
    }

}


int main() {
    tache tab[100];
    int choix , n ;

    printf("Combien des taches voulez-vous creer ?: ");
    scanf("%d", &n);

    while (choix != 6) {
        printf("\n~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n");
        printf("1. Creer\n");
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
            case 3:
                modification(tab,n);
            break;
            case 4:
                supression(tab,n);
             break;
            case 5:
                filtragepriorite(tab,n);
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
