//Pares e ímpares

#include <stdio.h>

int main(void)
{
    int num, cont=0;

    do
    {
        printf("Informe um numero: ");
        scanf("%d", &num);

        if (num%2 == 0)
        {
            printf("O numero eh par\n");
        }
        else
        {
            printf("O numero eh impar\n");
        }
        cont++;
    }while(cont < 10);

    return 0;
}

