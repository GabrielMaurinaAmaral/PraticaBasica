#include <time.h>

void gerarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna], int inferior, int superior)
{
    int l, c;

    srand(time(NULL));

    for (l = 0; l < linha; l++)
    {
        for (c = 0; c < coluna; c++)
        {
            matriz[l][c] = rand() % superior + inferior;
        }
    }
}

void mostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna])
{
    int l, c;

    for (l = 0; l < linha; l++)
    {
        for (c = 0; c < coluna; c++)
        {
            printf(" %d   ", matriz[l][c]);
        }
        printf(" \n ");
    }
}

void gerarVetor(int vetor[], int i, int inferior, int superior)
{
    int j;

    srand(time(NULL));

    for ( j= 0; j <= i; j++)
    {
        vetor[j]= rand() % superior + inferior;
    }
}

void mostrarVetor(int vetor[], int i)
{
    int j;

    for ( j= 0; j <= i; j++)
    {
        printf(" %d\t", vetor[j]);   
    }
}