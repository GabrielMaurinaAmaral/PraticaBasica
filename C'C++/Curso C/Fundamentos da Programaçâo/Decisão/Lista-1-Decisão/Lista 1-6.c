/*6) Elaborar um programa que leia um valor que se refere � altura de uma pessoa e mostre uma mensagem
conforme a tabela a seguir. Utilizar vari�vel do tipo float.
Altura Mensagem
Menor que 1,50 "Altura abaixo de um metro e cinquenta cent�metros"
De 1,50 a 1,80 "Altura entre um metro e cinquenta e um metro e oitenta cent�metros"
Maior que 1,80 "Altura acima de um metro e oitenta cent�metros"*/

#include <stdio.h>

int main (void)
{
    float x;
    printf("Informe sua latura em metros:");
    scanf("%f",&x);

    if(x<1.50)
    {
       printf("Altura abaixo de um metro e cinquenta cent�metros");
    }
    if(x>=1.50 && x<=1.80)
    {
        printf("Altura entre um metro e cinquenta e um metro e oitenta cent�metros");
    }
    if(x>1.80)
    {
        printf("Altura acima de um metro e oitenta cent�metros");
    }

    return 0;
}
