/*2) Gerar uma matriz 5x5 com números randômicos, no intervalo de 1 a 5. Em seguida criar dois vetores que contenham, respectivamente, as somas das linhas e das colunas da matriz. Mostrar os vetores criados.*/

#include <stdio.h>
#include "Funcoes-Matriz-Lista-6.h"

int main(void)
{
    int matriz[5][5], linha, coluna, somaLinha, somaColuna;
    char opcRepetir;

    do
    {
        gerarMatrizInteiro(5, 5, matriz, 1, 5);
        printf("\n=====MATRIZ=====\n");
        mostrarMatrizInteiro(5, 5, matriz);

        somaLinha=0;
        printf("\n=====SOMA LINHA=====\n");
        for (linha = 0; linha < 5; linha++)
        {
            for (coluna = 0; coluna < 5; coluna++)
            {
                somaLinha=somaLinha+matriz[linha][coluna];
            }

            printf(" %d\t ", somaLinha);
            somaLinha=0;
        }

        somaColuna=0;
        printf("\n=====SOMA LINHA=====\n");
        for (coluna = 0; coluna < 5; coluna++)
        {
            for (linha = 0; linha < 5; linha++)
            {
                somaColuna=somaColuna+matriz[linha][coluna];
            }

            printf(" %d\t ", somaColuna);
            somaColuna=0;
        }


        printf("\n Repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}