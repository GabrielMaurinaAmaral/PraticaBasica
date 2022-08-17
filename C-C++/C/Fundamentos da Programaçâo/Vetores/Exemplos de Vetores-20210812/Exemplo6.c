#include <stdio.h>

int main(void)
{
    int i, numeros[10];

    for(i=0; i<10; i++)
    {
        printf("Informe o valor para a posicao %d do vetor: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\nValores pares: ");

    for(i=0; i<10; i++)
    {
        if (numeros[i]%2 == 0)
        {
            printf("%d\t", numeros[i]);
        }
    }

    return 0;
}
