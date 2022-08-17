/*1) Fazer uma função que verifica se um número é triangular. Um número natural é triangular quando o produto de três números naturais consecutivos for igual ao próprio número. Por exemplo: 120 é triangular, pois 4 * 5 * 6 = 120. Use essa função para:
a) Verificar se um número, informado pelo usuário, é triangular.
b) Mostrar quais números de um intervalo são triangulares.
Use menu de opções (com switch-case) e implemente a repetição de programa.*/

#include <stdio.h>
#include "codeFuncoesEntregar.h"

int main(void)
{
    int num1, opc, inter1, inter2, j;
    char opcRepetir;

    do
    {
        printf("\n 1 - Verificar se o numero e triangular\n");
        printf(" 2 - Mostrar numero triangularesnum determinado intervalo\n");
        printf(" Escolha a opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
           printf("Informe um numero: ");
            scanf("%d", &num1);
            if (triangular(num1) == 0)
            {
                printf("%d nao eh triangular\n", num1);
            }
            break;
        case 2:
            printf("Informe o primeiro numero: ");
            scanf("%d", &inter1);
            printf("Informe o segundo numero: ");
            scanf("%d", &inter2);

            if (inter2 < inter1)
            {
                j = inter2;
                inter2 = inter1;
                inter1 = j;
            }
            for (j = inter1; j <= inter2; j++)
            {
                triangular(j);
            }
            break;
        default:
            printf("Opcao nao existente");
        }

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');
    
    return 0;
}