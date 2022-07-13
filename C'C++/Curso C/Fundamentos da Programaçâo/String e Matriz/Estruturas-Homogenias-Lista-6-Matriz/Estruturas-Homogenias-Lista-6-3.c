/*3) Gerar uma matriz 10x10 preenchida com o número 1 e mostrar a matriz. Em seguida, preencher com 0 as
diagonais principal e secundária e mostrar a matriz*/

#include <stdio.h>

int main(void)
{
    int matriz[10][10], linha, coluna, contLinha, contColuna;

    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            matriz[linha][coluna] = 1;
            printf(" %d\t", matriz[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            if (coluna == linha)
            {
                matriz[linha][coluna] = 0;
                printf(" %d\t", matriz[linha][coluna]);
            }
            else
            {
                matriz[linha][coluna] = 1;
                printf(" %d\t", matriz[linha][coluna]);
            }
        }
        printf("\n");
    }

    contLinha = 0;
    contColuna = 9;
    printf("\n");
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            if (linha == contLinha && coluna == contColuna)
            {
                matriz[linha][coluna] = 0;
                printf(" %d\t", matriz[linha][coluna]);
            }

            else if (coluna == linha)
            {
                matriz[linha][coluna] = 0;
                printf(" %d\t", matriz[linha][coluna]);
            }

            else
            {
                matriz[linha][coluna] = 1;
                printf(" %d\t", matriz[linha][coluna]);
            }
        }
        contColuna--;
        contLinha++;

        printf("\n");
    }

    return 0;
}
