/*5) Gerar um vetor com 10 valores inteiros aleatórios entre 1 e 100. Para os elementos pares do vetor, verificar
se são números perfeitos. Para os elementos ímpares do vetor, somar os seus dígitos. Utilizar uma função
para verificar se um número é perfeito e outra função para somar os seus dígitos de um número. Um número
é perfeito quando a soma dos seus divisores (exceto ele próprio) é igual ao próprio número (por exemplo 6 é
perfeito porque possui 1, 2 e 3 como divisores que somam 6).*/

#include<stdio.h>
#include<time.h>

void somaInpDiv(int vetor[], int i);

int main(void)
{
    int vetor[10], i;
    char opcRepetir;

    srand(time, NULL);
    do
    {
        printf("\n====VETORES====\n");
        for(i=0; i<10; i++)
        {
            vetor[i]= rand() % 100 + 1;
            printf("%d\t", vetor[i] );

        }

        printf("\n====INPAR====\n");
        for(i=0; i<10; i++)
        {
            somaInpDiv(vetor[], i);
        }
       
        printf("\n");
        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}

void somaInpDiv(int vetor[], int i)
{
    int somaDiv=0, j;

    for(j=1; j<vetor[i]; j++)
    {
        if(vetor[i]%j==0)
        {
            somaDiv=somaDiv+j;
        }
    }

    printf(" %d - soma dos seus divisore: %d \n", vetor[i], somaDiv);
}