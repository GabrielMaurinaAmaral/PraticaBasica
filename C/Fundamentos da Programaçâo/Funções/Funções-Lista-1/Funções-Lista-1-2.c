/*2) Fazer uma função para verificar se um número é ou não primo.
     A função será implementada em um arquivo de cabeçalho "primo.h" e deverá retornar 0 se o número for primo ou 1, 
    caso o número não seja primo. Elaborar um programa para usar essa função para:

a) Verificar se um número informado pelo usuário é ou não um número primo. Validar a entrada para que o usuário informe um número positivo.
b) Mostrar os primos no intervalo entre 1 e 100.
c) Fazer a média dos primos entre 200 e 100.*/

#include <stdio.h>
#include "codeFuncoes.h"

int main(void)
{
    int num1, inf, sup;
    char opc, opcRepetir;

    do
    {

        printf("\n A - Verificar se um numero eh primo \n");
        printf(" B - Primos no intervalo entre 1 e 100 \n");
        printf(" C - Media dos primos entre 200 e 100 \n");
        printf(" Escolha a opcao: ");
        setbuf(stdin, NULL);
        scanf("%c", &opc);

        switch (opc)
        {
        case 'A':
            printf(" Informe um numero: ");
            scanf("%d", &num1);
            if (primo(num1) == 0)
            {
                printf(" %d eh primo\n", num1);
            }
            else
            {
                printf(" %d nao eh primo\n", num1);
            }
            break;
        case 'B':
            inf = 1;
            sup = 100;
            primoLimitado(inf, sup);
            break;
        case 'C':   
            inf=100;
            sup=200;
            primoMedia(inf, sup);
            break;
        default:
            printf("\nOpcao errada");
        }

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}