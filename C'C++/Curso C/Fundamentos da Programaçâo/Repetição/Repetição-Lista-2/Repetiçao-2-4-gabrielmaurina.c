/*4) Apresentar os números divisíveis por 4 ou múltiplos de 10 entre 500 e 0 e a média desses múltiplos.*/

#include<stdio.h>

int main (void)
{
    int i, soma=0;

    for(i=0; 0<=i && i<=500; i++)
    {
        if(i%4==0 || i%10==0)
        {
            printf("%d\t", i);
            soma=soma+i;
        }
    }

    printf("media: %f", (float)soma/i);
}
 