/*5) Uma árvore de decisão obtém a decisão pela execução de uma sequência de testes. Cada nó interno da árvore corresponde a um teste do valor de uma das propriedades e os ramos deste nó são identificados com os possíveis valores do teste. Cada nó folha da árvore especifica o valor de retorno se a folha for atingida. A figura a seguir apresenta um exemplo fictício de árvore de decisão, tomando atributos de clientes de uma instituição financeira. Elabore um programa que implemente essa árvore de decisão. As entradas podem ser do tipo char, portanto, considere a primeira letra de cada palavra como entrada. Caso o usuário informe um caractere diferente dos aceitáveis, apresente a mensagem "Caractere inválido".*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void)
{
    int i;
    char a;
    float x;

    for(i=1; 1<=4; i++)
    {
        printf("Saldo da conta bancaria: ");
        scanf("%f",&x);
        setbuf(stdin,NULL);

        if(x>0)
        {
            printf("Cliente sem risco");
        }
        else if(x<0)
        {
            printf("Contem aplicacoes (s/n): ");
            scanf("%c",&a);
            a=toupper(a);

            if(a='s')
            {
                printf("Cliente sem risco \n");
            }
            else if(a='n')
            {
                printf("Cliente com risco\n");
            }
            else
            {
                printf("Opcao invalida\n");
            }
        }    
    }

return 0;    
}    