/*Leia 10 números e desses contar quantos são pares, quantos são ímpares e quantos são divisíveis por 7. Apresente essas quantidades.*/

#include<stdio.h>

int main (void)
{
    int i, contP, contI, contD;

    for(i=1; i<=10; i++)
    {
        printf("Informe um numero: ");

        if(i%2==0)
        {
            contP++;
        }
        if(i%2!=0)
        {
            contI++;
        }
        if(i%7==0)
        {
            contD++;
        }
    }

    printf("quantidade pares: %d", contP);
    printf("quantidade impares: %d", contI);
    printf("quantidade divisives por 7: %d", contD);


}