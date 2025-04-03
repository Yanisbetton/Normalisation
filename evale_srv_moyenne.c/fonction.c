//yanis antoine
#include "evale_srv_moyenne.h"
#include <stdio.h>

 
// Supprime un élément à l'index et décale le tableau
void supprimer(int tab[], int *taille, int index) {
    for (int i = index; i < (*taille - 1); i++) {
        tab[i] = tab[i + 1];
    }
    (*taille)--;
}
 
// Trouve l’indice du max
int trouverMax(int tab[], int taille) {
    int max = 0;
    for (int i = 1; i < taille; i++) {
        if (tab[i] > tab[max]) {
            max = i;
        }
    }
    return max;
}
 
// Trouve l’indice du min
int trouverMin(int tab[], int taille) {
    int min = 0;
    for (int i = 1; i < taille; i++) {
        if (tab[i] < tab[min]) {
            min = i;
        }
    }
    return min;
}
 
// Lire les valeurs depuis le fichier
int lireValeurs(int tab[]) {
    FILE *f = fopen("Valeurs.txt", "r");
    if (!f) return 0;
 
    int i = 0;
    while (fscanf(f, "%d,", &tab[i]) == 1 && i < TAILLE) {
        i++;
    }
    fclose(f);
    return (i == TAILLE);
}