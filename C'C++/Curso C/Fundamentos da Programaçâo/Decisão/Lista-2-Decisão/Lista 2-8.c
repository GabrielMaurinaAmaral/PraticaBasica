/*8) Fazer o programa para o algoritmo representado no fluxograma a seguir:*/

#include<stdio.h>

int main (void)
{
    float x, y, a, b, c;
    printf("Informe o salario base: ");
    scanf("%f",&x);
    printf("Informe o valor da gratificacao: ");
    scanf("%f",&y);

    a=x+y;
    b=a*((float)15/100);
    c=a*((float)20/100);

    if(a<1000)
    {
        printf("Salario liquido: %0.2f",b);
    }
    else
    {
        printf("Salario liquido: %0.2f",c);
    }
 return 0;
}
