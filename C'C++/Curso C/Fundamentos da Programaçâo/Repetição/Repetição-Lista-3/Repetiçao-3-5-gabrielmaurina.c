/*5) Mostre os valores ímpares e não divisíveis por 5 entre 200 e 1. Apresente os valores em ordem decrescente.
     Faça a média dos valores desse intervalo que são divisíveis por 3 e por 5.*/

#include<stdio.h>

int main (void)
{
    int i, soma=0, cont=0;

    for(i=200; i>=1; i--)
    {
        if(i%2!=0 && i%5!=0)
        {
            printf(" %d\t ", i);
        }

        if(i%3==0 && i%5==0)
        {
            soma=soma+i;
            cont++;
        }
    }

    printf(" \n Média dos valores desse intervalo que são divisíveis por 3 e por 5: %d", soma/cont);

 return 0;   
}