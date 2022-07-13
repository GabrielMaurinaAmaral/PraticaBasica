//Pares e ímpares

#include <stdio.h>

int main(void)
{
    int num, cont=0;

    while(cont < 10)
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
        cont++;
    }
    return 0;
}
