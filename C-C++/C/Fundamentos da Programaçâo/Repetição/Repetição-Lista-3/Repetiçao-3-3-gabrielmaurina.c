/*3) Faça um programa que mostre o resultado da seguinte soma, sendo n o valor informado pelo usuário:
Soma = 1 + 1/2 + 1/3 + 1/4 + 1/5 + … + 1/n*/

#include<stdio.h>

int main (void)
{
    int i, num;
    float soma=0;
    
    printf("Informe um numeros: ");
    scanf("%d", &num);
    printf("soma: ");
    i=num;

    do
    {
        printf(" 1/%d +", i);
        
        soma=((float)1/i)+soma;
        i--;

    }while(i>=2);

    printf(" 1 = %f", soma+1);
    
    
}