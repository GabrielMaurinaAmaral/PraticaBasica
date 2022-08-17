/*11) Mostrar os números entre 10 e 0 (ordem decrescente) com intervalo de 0.5.*/

#include<stdio.h>

int main (void)
{
    float i=10;

    do
    {
        printf("%0.1f \t", i);
        i=i-0.5;

    }while(i>=0);

    return 0;
}
