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

// EX4 //

int verifListe(int liste[9], int n)
{
    int parcourus[9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(parcourus); j++)
        {
            if (liste[i] == parcourus[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int verifGrille(int grille[9][9], int n)
{
    int colonne[9][9];
    for (int i = 0; i < n; i++)
    {
        if (verifListe(grille[i], n) == 0)
        {
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            colonne[j][i] = grille[i][j];
            if (grille[i][j] < 1 || grille[i][j] > n)
            {
                return 0;
            }
        }
    }
    for (int i1 = 0; i1 < n; i1++)
    {
        if (verifListe(colonne[i1], n) == 0)
        {
            return 0;
        }
    }
    return 1;
}
// Fin EX4 //

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

    printf("Verif grille_facile = %d\n", verifGrille(grille_facile, n));

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