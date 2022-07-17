/*Elaborar um programa para mostrar os números pares entre 20 e 100. Fazer a média dos valores desse intervalo que são
divisíveis por 5.
*/

#include<stdio.h>

int main (void)
{
    int i, soma=0, cont=0;

    for(i=20; 20<=i && i<=100; i++)
    {
        if(i%5==0)
        {
            printf(" %d ",i);
            soma=soma+i;
            cont++;
        }
    }

    printf("Media: %f", (float)soma/cont);
}