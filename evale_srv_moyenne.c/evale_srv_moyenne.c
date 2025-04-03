//yanis
#include <stdio.h>
#include "evale_srv_moyenne.h"

// Fonction principale
int main() {
    int valeurs[TAILLE];

    if (!lire_valeurs("Valeurs.txt", valeurs)) {
        return 1;
    }

    int min1, min2, i1, i2;
    trouver_deux_plus_petits(valeurs, &min1, &min2, &i1, &i2);

    printf("Les deux plus petites valeurs sont : %d et %d\n", min1, min2);

    afficher_valeurs_sans_deux_plus_petits(valeurs, i1, i2);

    return 0;
}