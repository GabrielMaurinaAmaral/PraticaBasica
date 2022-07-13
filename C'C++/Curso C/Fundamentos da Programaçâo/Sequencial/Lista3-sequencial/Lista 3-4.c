/*4) Fazer um programa que leia um número inteiro de até três dígitos (considere que será fornecido um número de até 3 dígitos), calcule e imprima a soma dos seus dígitos.*/

#include<stdio.h>

int main (void)
{
    int x,a,b,c,d;
    printf("Informe um numero inteiro com ate tres digitos: ");
    scanf("%d",&x);

    a=x/100;
    b=(x%100)/10;
    c=x%10;
    d=a+b+c;
    printf("%d = %d + %d + %d = %d",x,a,b,c,d);

}
