/*1) Ler uma matriz 5x5 com valores entre 1 e 50. A seguir, ler um número inteiro x e escrever uma mensagem indicando se o valor
     de x existe ou não na matriz.*/

#include <stdio.h>

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

int main(void)
{
    int matriz[5][5], num, l, c, cont;

    gerarMatrizInteiro(5, 5, matriz, 1, 50);
    printf("\n====MATRIZ====\n");
    mostrarMatrizInteiro(5, 5, matriz);

    printf("\n Informa um numero: ");
    scanf("%d", &num);

    cont = 0;
    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 5; c++)
        {
            if (num == matriz[l][c])
            {
                cont = 1;
            }
        }
    }

    if (cont == 1)
    {
        printf("\n %d existe na matriz\n", num);
    }
    else
    {
        printf("\n %d nao existe na matriz\n", num);
    }

    return 0;
}
