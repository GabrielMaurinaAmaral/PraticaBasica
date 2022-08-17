/*1) Gerar um vetor de inteiros com 15 elementos
aleatórios entre 1 e 25 . Gerar outros dois vetores um
contendo os valores pares e outro os ímpares Mostrar os três vetores.
Exemplo:*/

#include <stdio.h>
#include"Vetores-Lista-2.h"

int main(void)
{
    int inter2, inter1, i;
    char opcRepetir;

    do
    {
        inter1 = 1;
        inter2 = 25;
        i = inter2 - inter1;

        printf("\n====VETORE GERADOS====\n"); 
           mostrarVeoresInteiros(inter1, inter2, i);

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}