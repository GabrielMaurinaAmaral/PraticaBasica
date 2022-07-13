/*5) Elaborar uma função que recebe o número de linhas, o número de colunas, um determinado caractere e desenha um quadrado ou retângulo na tela utilizando o caractere.*/

#include <stdio.h>
#include "codeFuncoesEntregar.h"

int main(void)
{
    int coluna, linha;
    char opcRepet, caract;

    do
    {

        printf("\nInforme o numero de coluna: ");
        scanf("%d", &coluna);
        printf("Informe o numero de linha: ");
        scanf("%d", &linha);
        printf("Informe um caracter: ");
        setbuf(stdin, NULL);
        scanf("%c", &caract);

        quadroCaract(coluna, linha, caract);

        printf("\nDejesa repetir o programa: ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepet);

    } while (opcRepet == 'S' || opcRepet == 's');
}