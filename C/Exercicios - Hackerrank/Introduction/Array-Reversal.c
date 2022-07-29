#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam, *vetor, i, j;
    scanf("%d", &tam);
    vetor = (int *)malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        scanf("%d", &vetor[i]);

    for (j = i-1; - 1 < j; j--)
        printf("%d ", vetor[j]);

    return 0;
} 