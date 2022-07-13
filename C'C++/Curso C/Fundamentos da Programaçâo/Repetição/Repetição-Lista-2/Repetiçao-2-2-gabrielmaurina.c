/*3) Em um intervalo de 0 a 100, apresentar:
a) Os números divisíveis por 3.
b) O quadrado dos números divisíveis por 3.
c) Os números divisíveis por 5 ou por 7.
d) A raiz quadrada dos números divisíveis por 5 ou por 7.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
     int i;

    printf(" a) Os numeros divisiveis por 3: \n");
    for(i=0; i<=100; i++)
    {
        if(i%3==0)
        {
            printf(" %d\t", i);
        }
    }

    printf("\nOs nUmeros divisIveis por 5 ou por 7: \n");
    for(i=0; i<=100; i++)
    {
        if(i%5==0 || i%7==0)
        {
            printf(" %d\t", i);
        }
    }

    printf("\nO quadrado dos números divisíveis por 3: \n");
    for(i=0; i<=100; i++)
    {
        if(i%3==0)
        {
            printf(" %d\t", sqrt(i));
        }
    }

    printf("\nA raiz quadrada dos números divisíveis por 5 ou por 7: \n");
    for(i=0; i<=100; i++)
    {
        if(i%5==0 || i%7==0)
        {
            printf(" %d\t", sqrt(i));
        }
    }

    return 0;
}
