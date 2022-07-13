/*9) Números palíndromos são aqueles que escritos da direita para a esquerda ou da esquerda para a direita tem o mesmo valor. Ex.: 9229, 4554, 9779. Fazer um programa que dado um número de 4 dígitos, calcular e escrever se este número é ou não palíndromo.*/

#include<stdio.h>

int main (void)
{
    int x, a, b, c, d;
    printf("Escreva um numero de 4 digitos: ");
    scanf("%d",&x);

    a=x/1000;
    b=(x%1000)/100;
    c=(x%100)/10;
    d=x%10;

    if(a==d && b==c)
    {
        printf("Esse numero eh polindromo");
    }
    else
    {
        printf("Esse numero nao eh polindromo");
    }
 return 0;
}
