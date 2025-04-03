#define TAILLE 8
int lire_valeurs(const char *nom_fichier, int valeurs[]);
void afficher_valeurs_sans_deux_plus_petits(int valeurs[], int i1, int i2);
void trouver_deux_plus_petits(int valeurs[], int *min1, int *min2, int *i1, int *i2);