/*Escreva um programa que calcule o valor da conversão para dólares de um valor lido em reais.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
   float x, y, a;
   printf("Valor do dolar atual:R$");
   scanf("%f",&x);
   printf("Informe um valor em reias:R$");
   scanf("%f",&y);

   a=y/x;

   printf("R$%.2f equivalente U$%.2f", y, a);

   return 0;
}
