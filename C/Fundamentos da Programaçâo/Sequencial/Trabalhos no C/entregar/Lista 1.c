/*1) Faça um programa que receba o custo de um espetáculo teatral e o preço do convite desse espetáculo. Esse programa deve calcular e mostrar:
a) A quantidade de convites que devem ser vendidos para cobrir o custo do espetáculo.
b) A quantidade de convites que devem ser vendidos para cobrir o custo do espetáculo e ainda obter um lucro de 25%. Obs.: A função ceil() da biblioteca math.h arredonda o número para cima.
Exemplo:*/
#include<stdio.h>
#include<math.h100213
543

int main (void)
{
    int num1, num2, x, y;

    printf("Informe o valor de custo do espetaculo: ");
    scanf("%i", &num1);
    printf("Informe o valor do covite:");
    scanf("%i", &num2);

    x=num1/num2;
    y=(num1*1.25)/num2;

    printf("Para cobrir o custo to espetaculo eh necessario vender %i ingressos \n", x);
    printf("Para cobrir o custo to espetaculo e ter lucro de 25 porcento eh necessario vender %.2i", y);
}
