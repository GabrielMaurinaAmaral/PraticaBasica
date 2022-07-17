/*11) Um número é primo quando é divisível de maneira exata somente por 1 e por ele mesmo. Na figura a seguir, os números destacados são primos:
Elabore um programa que leia um número inteiro e determine se o mesmo é ou não um número primo.*/

#include<stdio.h>

int main(void)
{
    int num, i, resultado=0;

    do
    {
        printf("Digite um numero: ");
        scanf("%d", &num);
 
        for (i = 2; i <= num / 2; i++) 
        {
            if (num%i==0 && i!=1)
            {
                resultado++;
            }
        }
 
        if (resultado==0)
        {
            printf("%d eh um numero primo\n", num);
        }
        else
        {
            printf("%d nao eh um numero primo\n", num);
        }

    }while( num>0);
}