#include <stdio.h>

int main(void)
{
    int i, numeros[10], soma=0;
    float media;

    for(i=0; i<10; i++)
    {
        printf("Informe o valor para a posicao %d do vetor: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\nValores menores que 7: ");

    for(i=0; i<10; i++)
    {
        soma = soma + numeros[i];

        if(numeros[i] < 7)
        {
            printf("%d\t", numeros[i]);
        }
    }

    media = soma / 10.0;
    printf("\nMedia dos valores do vetor: %.2f\n", media);

    return 0;
}
