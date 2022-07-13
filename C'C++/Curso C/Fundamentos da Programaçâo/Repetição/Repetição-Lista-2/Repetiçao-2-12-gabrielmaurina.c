/*12) Elaborar um programa que permita ao usuário fornecer 30 números quaisquer e apresente:
a) A soma dos 10 primeiros números.
b) A soma do 11º número até o 20º número.
c) A soma do 21º número até o 30º número.
d) A soma de todos os números*/

#include<stdio.h>

int main (void)
{
    int i, num, somaA=0, somaB=0, somaC=0, somaT;

    for(i=1; i<=30; i++)
    {
        printf("Informe um numero: ");
        scanf("%d", &num);

        if(i<=10)
        {
            somaA=somaA+num;
        }
        else if(11<=i && i<=20)
        {
             somaB=somaB+num;
        }
        else if(21<=i && i<=30)
        {
            somaC=somaC+num;
        }
        
    }

    somaT=somaA+somaB+somaC;
    printf("a %d\n", somaA);
    printf("b %d\n", somaB);
    printf("c %d\n", somaC);
    printf("d %d\n", somaT);


 return 0;
}