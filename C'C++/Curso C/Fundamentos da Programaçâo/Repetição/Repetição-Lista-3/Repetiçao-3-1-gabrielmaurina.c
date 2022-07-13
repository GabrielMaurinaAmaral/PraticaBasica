/*1) Apresente (separados por tabulação) os números entre 1 e 1000 que são divisíveis por 11 e ímpares.
*/

#include <stdio.h>

int main(void)
{
    int i;

    printf("\n divisiveis por 11: \n");
    for (i = 1; 1 <= i && i <= 1000; i++)
    {
        if (i % 11 == 0)
        {
            printf("%d\t", i);
        }
    }

    printf("\n numeros impar: \n");
    for (i = 1; 1 <= i && i <= 1000; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d\t", i);
        }
    }
}