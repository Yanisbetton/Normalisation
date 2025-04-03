//yanis
#include <stdio.h>
#include "evale_srv_moyenne.h"

// Fonction pour lire les valeurs depuis un fichier
int lire_valeurs(const char *nom_fichier, int valeurs[]) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return 0; // Erreur
    }

    int i = 0;
    while (fscanf(fichier, "%d,", &valeurs[i]) == 1) {
        i++;
        if (i >= TAILLE) break;
    }

    fclose(fichier);

    if (i != TAILLE) {
        printf("Erreur : nombre de valeurs incorrect (il faut exactement %d valeurs).\n", TAILLE);
        return 0; // Erreur
    }

    return 1; // Succès
}

// Fonction pour trouver les deux plus petits nombres et leurs indices
void trouver_deux_plus_petits(int valeurs[], int *min1, int *min2, int *i1, int *i2) {
    *min1 = valeurs[0]; 
    *min2 = valeurs[0]; 
    *i1 = 0; 
    *i2 = 0;

    for (int i = 1; i < TAILLE; i++) {
        if (valeurs[i] < *min1) {
            *min2 = *min1; *i2 = *i1;
            *min1 = valeurs[i]; *i1 = i;
        } else if (valeurs[i] < *min2 || *i1 == *i2) {
            *min2 = valeurs[i]; *i2 = i;
        }
    }
}

// Fonction pour afficher les valeurs sans les deux plus petites
void afficher_valeurs_sans_deux_plus_petits(int valeurs[], int i1, int i2) {
    printf("Valeurs sans les deux plus petites :\n");
    for (int i = 0; i < TAILLE; i++) {
        if (i != i1 && i != i2) {
            printf("%d ", valeurs[i]);
        }
    }
    printf("\n");
}