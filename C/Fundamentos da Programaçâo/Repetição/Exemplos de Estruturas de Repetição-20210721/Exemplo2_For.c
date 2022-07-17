//Números pares e ímpares.
#include <stdio.h>

int main(void)
{
    int num, cont;

    for(cont=0; cont<10; cont++)
    {
        printf("Informe um numero: ");
        scanf("%d", &num);

        if(num%2 == 0)
        {
            printf("O numero eh par\n");
        }
        else
        {
            printf("O numero eh impar\n");
        }
    }

    return 0;
}
