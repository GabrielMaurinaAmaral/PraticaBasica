#include <stdio.h>
#include <limits.h>

int soma_sequencial(int vetor[], int size)
{
    int k, max = INT_MIN;

    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            int soma = 0;
            for (int k = i; k < j; k++)
            {
                soma += vetor[k];
                if (soma <= 0)
                    break;
            }
            if (soma > max)
                max = soma;
        }
    return max;
}

int main()
{
    int size;
    scanf("%d", &size);

    int vetor[size];
    for (int i = 0; i < size; i++)
        scanf("%d", &vetor[i]);

    printf("%d", soma_sequencial(vetor, size));

    return 0;
}