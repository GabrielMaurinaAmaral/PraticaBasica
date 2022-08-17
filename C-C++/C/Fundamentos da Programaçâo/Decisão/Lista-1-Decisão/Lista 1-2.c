/*2) Escreva um programa que leia um n�mero e verifique se ele � maior, menor ou igual a 10.*/

#include<stdio.h>

int main(void)
{
    int x;
    printf("Informe un numero: ");
    scanf("%d",&x);

    if(x==10)
    {
       printf("x eh igual a 10");
    }

    if(x>10)
    {
       printf("x eh maior que 10");
    }

    if(x<10)
    {
        printf("x eh menor que 10");
    }
    

    return 0;
}

