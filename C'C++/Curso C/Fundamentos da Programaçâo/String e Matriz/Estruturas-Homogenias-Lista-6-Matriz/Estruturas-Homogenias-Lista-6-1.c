/* 1) Criar um arquivo "matrizes.h". Dentro desse arquivo incluir função para:
a) Gerar uma matriz de elementos inteiros randômicos entre 1 e limite com o protótipo:
void gerarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna], int limite)
b) Mostrar uma matriz com o protótipo:
void mostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna])
Usar as funções para:
a) Gerar uma matriz de 3x3 com números aleatórios entre 1 e 10.
b) Somar todos os elementos da matriz.
c) Somar os elementos da diagonal principal da matriz.
d) Somar os elementos da diagonal secundária da matriz.
e) Mostrar a matriz e as somas. */

#include <stdio.h>
#include "Funcoes-Matriz-Lista-6.h"

int main(void)
{
    int matriz[3][3], inferior, superior, somaMatriz, l, c;
    char opcRepetir;

    do
    {
        inferior = 1;
        superior = 10;

        gerarMatrizInteiro(3, 3, matriz, inferior, superior);
        printf("\n====MATRIZ====\n");
        mostrarMatrizInteiro(3, 3, matriz);

        somaMatriz = 0;
        for (l = 0; l < 3; l++)
        {
            for (c = 0; c < 3; c++)
            {
                somaMatriz = somaMatriz + matriz[l][c];
            }
        }
        printf("\nSoma de todos os elementos da matriz: %d", somaMatriz);

        somaMatriz = 0;
        for (l = 0; l < 3; l++)
        {
            c=l;

            somaMatriz = somaMatriz + matriz[l][c];
        }
        printf("\nSoma dos elementos da diagonal principal: %d", somaMatriz);

        somaMatriz = 0;
        for (l = 0; l < 2; l++)
        {
            c=l;

            somaMatriz = somaMatriz + matriz[l][c];
        }
        printf("\nSoma dos elementos da diagonal secundaria: %d", somaMatriz);

        printf("\n Repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}