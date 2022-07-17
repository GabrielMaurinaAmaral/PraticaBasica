/*4) Elaborar uma função que verifica se um número é palíndromo. Um número é palíndromo quando ele não muda 
    se lido da esquerda para a direita ou da direita para a esquerda. Por exemplo, 2112 é palíndromo. 
    Elaborar uma função que verifica se um número, que contenha entre 2 e 9 dígitos, é palíndromo. Utilizar essa função para:
a) Verificar se um número informado pelo usuário é palíndromo.
b) Apresentar os números palíndromos que pertencem a um intervalo informado pelo usuário.
Use menu de opções (com switch-case) e implemente a repetição de programa.
Exemplo:*/

#include <stdio.h>
#include "codeFuncoesEntregar.h"

int main(void)
{
    int opc, num1, inter2, inter1, j;
    char opcRepetir;

    do
    {
        printf("\n 1 - Verificar se um numero eh um palindromo\n");
        printf(" 2 - Mostrar quais numeros de um intervalo são palindromos\n");
        printf(" Informe a opcao: ");
        setbuf(stdin, NULL);
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Informe um numero:");
            scanf("%d", &num1);
            if (palindromo(num1) == 0)
            {
                printf("%d nao eh um palindromo", num1);
            }
            break;
        case 2:
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
                palindromo(j);
            }
            break;
        default:
            printf("\nOpcao nao encontreda\n");
        }

        printf("\nQuer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}