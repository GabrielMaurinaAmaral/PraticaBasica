/*2) Considerando que para um consórcio sabe-se o número total de prestações, a quantidade de prestações pagas e o valor de cada prestação (que é fixo). Escreva um programa que determine o valor total já pago pelo consorciado e o saldo devedor8*/

#include<stdio.h>

int main (void)
{
    int x,y,z,a,b;
    printf("Informe a quantidade total de prestacoes: ");
    scanf("%d",&x);
    printf("Informe a quantidade de prestações pagas: ");
    scanf("%d",&y);
    printf("Inforeme o valor(fixo) da prestacao: ");
    scanf("%d",&z);

    a=y*z;
    printf("Valor total ja pago: R$%d\n",a);

    b=(x-y)*z;
    printf("Saldo devedor: R$%d",b);

    return 0;
}
