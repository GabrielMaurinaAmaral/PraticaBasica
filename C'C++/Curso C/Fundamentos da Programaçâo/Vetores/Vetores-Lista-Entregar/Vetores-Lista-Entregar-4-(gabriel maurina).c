/*4) Gerar um vetor aleatório com 10 elementos entre 0 e 50. Verificar se cada um dos elementos armazenados no vetor é primo. Utilizar, obrigatoriamente, uma função para verificar se o número é primo. Essa função retorna 0 para indicar que o número é primo e 1 para indicar que não é primo. Tratar esse retorno na função chamadora. Mostrar da seguinte forma:*/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include"Vetores-Lista-Entregar.h"

int main (void)
{
    int  i, vetorRand[10];
    char opcRepetir;

    do
    {
        srand(time(NULL));
        printf("\n====Vetor====\n");
        printf("INDICE         NUMERO         PRIMO\n");
        for(i=0; i<=9; i++)
        {
            vetorRand[i] = rand() % 50;        

            printf(" %2.1d              %2.2d            ", i, vetorRand[i]);

            primo(vetorRand[i]);
            if(primo(vetorRand[i])==0)
            {
                printf("Sim\n");
            }   
            else
            {
                printf("Nao\n");
            }
        }

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;    
}    