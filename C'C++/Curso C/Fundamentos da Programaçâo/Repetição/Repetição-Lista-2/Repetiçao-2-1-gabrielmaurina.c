/*1) Apresentar a tabuada de um número informado pelo usuário. A tabuada deve ser apresentada na forma a seguir:*/
#include<stdio.h>
#include<math.h>

int main (void)
{
    int mult=0, num;
    printf("Informe um numero: ");
        scanf("%d", &num);

    while(mult<=10)
    {
        printf("\n%d * %d = %2d\n ",num, mult, num*mult);
        mult++;

    }
}