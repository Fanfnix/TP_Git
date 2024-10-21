#include <stdio.h>
#include <string.h>


// EX1 //

void initGrille(int grille[9][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grille[i][j] = 0;
        }
    }
}
// Fin EX1 //

// EX2 //

void remplirGrille(int grille[9][9], int n)
{
    int run = 1;
    int l, c, valeur;
    while (run)
    {
        afficherGrille(grille, n);
        do 
        {
            printf("Ligne : ");
            scanf(" %d", &l);
            printf("Colonne : ");
            scanf(" %d", &c);
        } while (c > 8 || c < 0 || l > 8 || l < 0);
        printf("Valeur : ");
        scanf(" %d", &valeur);

        grille[l][c] = valeur;

        printf("Entrez une autre valeur ? (1/0) ");
        scanf(" %d", &run);
    }
}
// Fin EX2 //

// EX3 //

void afficherGrille(int grille[9][9], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("---");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grille[i][j] != 0)
            {
                printf(" %d ", grille[i][j]);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        printf("---");
    }
    printf("\n");
}
// Fin EX3 //

int main()
{
	int n = 9;
    int grille[9][9];

    initGrille(grille, n);

    afficherGrille(grille, n);

    remplirGrille(grille, n);
    
    int grille_facile[9][9] = {
		{6, 0, 4, 9, 0, 0, 3, 0, 8},
		{3, 2, 0, 8, 0, 0, 4, 0, 0},
		{0, 0, 0, 6, 0, 4, 5, 2, 1},
		{1, 0, 2, 7, 4, 3, 8, 9, 6},
		{8, 0, 0, 0, 0, 0, 0, 0, 0},
		{9, 4, 7, 5, 8, 0, 0, 0, 0},
		{4, 9, 0, 2, 0, 8, 6, 0, 3},
		{0, 3, 6, 4, 0, 0, 0, 0, 0},
		{0, 7, 0, 0, 6, 9, 0, 0, 4}
	};

	int grille_moyenne[9][9] = {
		{1, 0, 0, 7, 0, 6, 0, 0, 0},
		{0, 0, 0, 0, 0, 8, 5, 6, 0},
		{6, 0, 8, 0, 5, 3, 4, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 3, 0, 0, 0, 0, 0, 0, 0},
		{8, 4, 0, 3, 0, 1, 0, 5, 9}
	};

	return 0;
}