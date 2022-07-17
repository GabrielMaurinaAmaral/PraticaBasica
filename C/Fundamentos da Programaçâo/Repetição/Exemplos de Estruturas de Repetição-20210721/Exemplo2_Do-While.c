//Lê números positivos.

#include <stdio.h>

int main(void)
{
    int num;

    do
    {
        printf("Digite um numero positivo (0 para sair): ");
        scanf("%d", &num);

        if(num<=0)
        {
            printf("Numero invalido\n");
        }
    }while(num <= 0);

    return 0;
}
