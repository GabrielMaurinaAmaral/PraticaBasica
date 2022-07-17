/*2) Criar função para:
a) Receber, por parâmetro, um número inteiro e positivo e retornar a quantidade de divisores que esse número possui.
b) Mostrar os divisores de um número. Essa função recebe como parâmetro o número e mostra os divisores de 1 até o número passado como parâmetro da função.
c) Receber, por parâmetro, um número positivo e retornar a soma dos divisores que esse número possui.
d) Receber, por parâmetro, dois números e retornar o Máximo Divisor Comum dos dois números.
Salvar todas as funções dentro de uma biblioteca chamada Divisores.h. Use a biblioteca "Divisores.h" em um programa para gerar o seguinte menu:
1 - Quantidade de divisores de um número
2 - Divisores de um número
3 - Divisores, quantidade e soma de um intervalo
4 - Maximo Divisor Comum de dois números*/

#include <stdio.h>
#include ".funcoesLista2.h"

int main(void)
{
    int num1, num2, opc, j, inter1, inter2;
    char opcRepetir;

    do
    {

        printf("\n 1 - Quantidade de divisores de um numero\n");
        printf(" 2 - Divisores de um numero\n");
        printf(" 3 - Divisores, quantidade e soma de um intervalo\n");
        printf(" 4 - Maximo Divisor Comum de dois numeros\n");
        printf(" Informe a opcao:");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf(" Informe um numero:");
            scanf("%d", &num1);
            printf(" %d divisores", divisorQuant(num1));
            break;
        case 2:
            printf(" Informe um numero:");
            scanf("%d", &num1);
            divisorMostrar(num1);
            break;
        case 3:
            printf("Informe o primeiro intervalo: ");
            scanf("%d", &inter1);
            printf("Informe o segundo intervalo: ");
            scanf("%d", &inter2);

            if (inter1 > inter2)
            {
                j = inter1;
                inter1 = inter2;
                inter2 = j;
            }
            for (j = inter1; j <= inter2; j++)
            {
                printf(" %d - ", j);
                divisorSoma(j);
                printf("\n");
            }
            break;
        case 4:
            printf("Informe o primeiro numero: ");
            scanf("%d", &num1);
            printf("Informe o segundo numero: ");
            scanf("%d", &num2);

            printf("MDC: %d", mdc(num1, num2));
            break;
        default:
            printf("\n Opcao nao encontreda\n");
        }

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}
