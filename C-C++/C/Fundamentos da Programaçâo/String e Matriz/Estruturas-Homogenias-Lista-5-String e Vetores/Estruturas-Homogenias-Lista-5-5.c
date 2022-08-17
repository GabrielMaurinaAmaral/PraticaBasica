/*5) Gerar um vetor com 10 valores inteiros aleatórios entre 1 e 100. Para os elementos pares do vetor, verificar
se são números perfeitos. Para os elementos ímpares do vetor, somar os seus dígitos. Utilizar uma função
para verificar se um número é perfeito e outra função para somar os seus dígitos de um número. Um número
é perfeito quando a soma dos seus divisores (exceto ele próprio) é igual ao próprio número (por exemplo 6 é
perfeito porque possui 1, 2 e 3 como divisores que somam 6).*/

#include <stdio.h>
#include "Funcoes-Lista-estruturais-5.h"
#include <time.h>

int main(void)
{
    int vetorR[10], i;
    char opcRepetir;

    do
    {
        srand(time(NULL));

        printf("\n====VETOR====\n");
        for (i = 0; i < 10; i++)
        {
            vetorR[i] = rand() % 100 + 1;
            printf(" %d\t", vetorR[i]);
        }

        printf("\n====VETOR PARES====\n");
        for (i = 0; i < 10; i++)
        {
            if(vetorR[i]%2==0)
            {
               numPerfeito(vetor[i], i);
            }
        }
        

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');
}