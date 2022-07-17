/*2) Fazer uma função que verifica se um número é retangular. Um número é retangular se ele pode ser obtido a partir da soma de uma sequência de números pares, iniciando em 2. Por exemplo: 30 é retangular porque resulta da soma de 2 + 4 + 6 + 8 + 10. Utilizar essa função para:
a) Verificar se um número, informado pelo usuário, é retangular.
b) Mostrar quais números de um intervalo são retangulares.
Use menu de opções (com switch-case) e implemente a repetição de programa.
Exemplo:*/

#include <stdio.h>
#include "codeFuncoesEntregar.h"

int main(void)
{
    int num1, opc, inter1, inter2, j;
    char opcRepetir;

    do
    {
        printf("\n 1 - Verificar se o numero e retangular\n");
        printf(" 2 - Mostrar numero retangulares num determinado intervalo\n");
        printf(" Escolha a opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Informe um numero: ");
            scanf("%d", &num1);
            if (retangular(num1) == 0)
            {
                printf("%d nao eh retangular\n", num1);
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
                retangular(j);
            }
            break;
        default:
            printf("ocpcao nao existente");
        }

        printf("\n Quer repetir o programa(S/s): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);
        

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}