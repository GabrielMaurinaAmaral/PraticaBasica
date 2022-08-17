


/*5) Escreva um programa que leia um n�mero e verifique se ele se encontra fora do intervalo entre 5 e 20.
Mostre uma mensagem se o n�mero est� fora desse intervalo*/

#include<stdio.h>

int main (void)
{
    int x;
    printf("Informe um numero:");
    scanf("%d",&x);

    if(x<5 && x>20)
    {
       printf("Numero esta  fora do intervalo ");
    }

    return 0;
}
