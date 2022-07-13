/*1) Use a biblioteca "Fatorial.h" (criada no Exercício 3 da Lista 1) para:
a) Calcular e mostrar o fatorial de um número informado pelo usuário.
b) Calcular e mostrar o fatorial dos números de 1 a 12.*/

#include <stdio.h>
#include ".funcoesLista2.h"

int main(void)
{
    int num1, i;

    printf("Informe um numero: ");
    scanf("%d", &num1);

    printf("\n==== FATORIAL DE %d ====\n", num1);
    fatorial(num1);

    printf("\n==== FATORIAL DE 1 A 12 ====\n");
    for(i=1; i<=12; i++)
    {
        num1=i;
        fatorial(num1);
    }

    return 0;
}