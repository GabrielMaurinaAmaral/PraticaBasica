/*3) Fazer uma função que verifica se um número é um quadrado perfeito. Um número é quadrado perfeito se
possui como raiz quadrada um valor inteiro. A função para obter a raiz quadrada é sqrt() e está na biblioteca
math.h. Por exemplo, 25 é um quadrado perfeito porque raiz quadrada de 25 é 5. Utilizar essa função para:
a) Verificar se um número, informado pelo usuário, é um quadrado perfeito.
b) Mostrar quais números de um intervalo são quadrados perfeitos.
Use menu de opções (com switch-case) e implemente a repetição de programa.
Exemplo:*/

#include <stdio.h>
#include "codeFuncoesEntregar.h"

int main(void)
{
    int num1, inter1, inter2, auxInter, j;
    char opc, opcRepetir;

    do
    {
        printf("\n A - Verificar se um numero eh um quadrado perfeito\n");
        printf(" B - Mostrar quais numeros de um intervalo são quadrados perfeitos\n");
        printf(" Informe a opcao: ");
        setbuf(stdin, NULL); 
        scanf("%c", &opc);

        switch (opc)
        {
            case 'A':
            case 'a':
                printf("\n Informe um numero: ");
                scanf("%d", &num1);

                if (quadrado(num1) == 0)
                {
                    printf("\n %d nao eh quadrado perfeito", num1);
                }
                break;

            case 'B':
            case 'b': 
                printf("\n Informe o primeiro intervalo: ");
                scanf("%d", &inter1);
                printf("\n Informe o segundo intervalo: ");
                scanf("%d", &inter2);

                if (inter1 > inter2) 
                {
                    j = inter1;
                    inter1 = inter2;
                    inter2 = j;
                }
                for (j = inter1; j <= inter2; j++)
                {
                    quadrado(j);
                }
                break;
            default:
                printf("\nOpcao nao encomtrada\n");
        }

        printf("\nQuer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}