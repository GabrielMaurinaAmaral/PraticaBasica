/*2) Faça um programa que apresente uma tabela de lucro esperado, em decorrência do número de pessoas e valor do ingresso.
 O valor do ingresso vai de R$ 15,00 até R$ 20,00 aumentando de R$ 0,50 centavos. É informada a quantidade de pessoas.
Exemplo: */

#include<stdio.h>

int main (void)
{
    float i;
    int num;

    printf("Informe o numero de pessoas: ");
    scanf("%d", &num);

    printf("Valor do Ingresso\t");
    printf("Valor total do recebidos\n");

    for(i=15.00; i<=20.00; i)
    {
        printf("         %0.1f\t", i);
        printf("              %0.1f\n", i*num);
        i=i+0.5;
    }
 return 0;   
}