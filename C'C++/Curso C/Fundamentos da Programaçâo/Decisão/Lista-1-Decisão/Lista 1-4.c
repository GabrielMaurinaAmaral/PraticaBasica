/*4) Escreva um programa que leia um número e verifique se ele se encontra no intervalo entre 5 e 20. Mostre
uma mensagem se o número estiver nesse intervalo.
5)*/

#include<stdio.h>

int main (void)
{
    int x;
    printf("Informe um numero:");
    scanf("%d",&x);

    if(x>5 && x<20)
    {
       printf("Numero esta no intervalo");
    }

    return 0;
}
