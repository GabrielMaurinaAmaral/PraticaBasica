/*3) Fazer duas funções: uma para calcular o fatorial de um número e a outra para mostrar o fatorial de um número. Ambas as funções devem ser implementadas em um arquivo de cabeçalho chamado "fatorial.h". Elaborar um programa que use essas funções para:
a) Calcular e mostrar o fatorial dos números entre 1 e 8.
b) Calcular e mostrar o fatorial de um valor informado pelo usuário. Continuar a leitura enquanto forem informados valores positivos.
Exemplo de entrada e saída:*/

#include <stdio.h>
#include "codeFuncoes.h"

int main(void)
{
    int num1, j;
    char opc, opcRepetir;

    do
    {
        printf("\n A - Fatorial entre 1 e 8\n");
        printf(" B - Fatorial de um numero\n");
        printf(" Escolha a opcao: ");
        setbuf(stdin, NULL);
        scanf("%c", &opc);

        switch (opc)
        {
        case 'A':
            for(j=1; j<=8; j++)
            {
                num1=j;
                fatorialMostrar(num1);
                fatorialCalculo(num1);
            }
            
            break;
        case 'B':
            printf("Informe uma numero:");
            scanf("%d", &num1);
            fatorialMostrar(num1);
            fatorialCalculo(num1);

            break;
        default:
            printf("Opcao invalida");
        }
        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}