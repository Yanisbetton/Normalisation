//yanis
#include <stdio.h>
#include "evale_srv_moyenne.h"

int main() {
    int valeurs[TAILLE];
    if (!lireValeurs(valeurs)) {
        printf("Erreur : lecture du fichier ou valeurs manquantes.\n");
        return 1;
    }
 
    // Copier les valeurs dans un tableau modifiable
    int temp[TAILLE];
    for (int i = 0; i < TAILLE; i++) temp[i] = valeurs[i];
    int taille = TAILLE;
 
    // Supprimer les 2 plus grands
    for (int i = 0; i < 2; i++) {
        int maxIndex = trouverMax(temp, taille);
        supprimer(temp, &taille, maxIndex);
    }
 
    // Supprimer les 2 plus petits
    for (int i = 0; i < 2; i++) {
        int minIndex = trouverMin(temp, taille);
        supprimer(temp, &taille, minIndex);
    }
 
    // Afficher les valeurs restantes
    printf("Valeurs finales :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
 
    return 0;
}