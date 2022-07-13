/*1) Fazer um programa que permite aplicar as operações de soma, subtração, multiplicação, divisão e resto em dois números fornecidos pelo usuário. Cada operação é uma função e deve ser acessada a partir de um menu (use switch case). As funções são implementadas no próprio programa.
a) Soma sem parâmetros e sem retorno
b) Subtração com parâmetros e sem retorno
c) Multiplicação sem parâmetros e com retorno
d) Divisão com parâmetros e com retorno.
e) Resto com parâmetros e com retorno.
Exemplo de entrada e saída:*/

#include <stdio.h>
#include "codeFuncoes.h"

int main(void)
{
    int num1, num2;
    char opc, opcRepetir;

    do
    {
        printf(" \n A - Adicao\n");
        printf(" B - Subtrecao\n");
        printf(" C - Multiplicao\n");
        printf(" D - Divisao\n");
        printf(" E - Resto\n");
        printf(" opcoes do menu: ");
        setbuf(stdin, NULL);
        scanf("%c", &opc);

        printf(" Digite o primero numero: ");
        scanf("%d", &num1);
        printf(" Digite o segundo numero: ");
        scanf("%d", &num2);

        switch (opc)
        {
            case 'A':
                printf(" Soma: %d\n", soma(num1, num2));
            break;

            case 'B':
                printf(" Subtracao: %d\n", subtracao(num1, num2));
            break;

            case 'C':
                printf(" Multiplica: %d\n", produto(num1, num2));
            break;

            case 'D':
                printf(" Divisao: %d\n", divisao(num1, num2));
            break;

            case 'E':
                printf(" Resto: %d\n", resto(num1, num2));
            break;

            default:
                printf("Esta opcao nao esta disponivel\n");
        }
        
    setbuf(stdin, NULL);
    printf("\n Quer repetir o programa(S/s ou N/n): ");
    scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

        return 0;
}
