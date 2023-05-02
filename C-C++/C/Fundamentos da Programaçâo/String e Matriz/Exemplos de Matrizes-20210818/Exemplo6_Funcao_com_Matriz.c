0#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarMatrizInteiroDe0aLimite(int linha, int coluna, int matriz[linha][coluna], int limite); //Prot�tipo da fun��o
void mostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna]); //Prot�tipo da fun��o

int main(void)
{
    int matriz[3][2];

    gerarMatrizInteiroDe0aLimite(3, 2, matriz, 10);
    printf("\n=== MATRIZ ===\n");
    mostrarMatrizInteiro(3, 2, matriz);

    return 0;
}

void gerarMatrizInteiroDe0aLimite(int linha, int coluna, int matriz[linha][coluna], int limite)
{
    int i, j;

    srand(time(NULL));

    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            matriz[i][j] = rand() % limite + 1;
        }
    }
}

void mostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            printf("%d   ", matriz[i][j]);
        }
        printf("\n");
    }
}
