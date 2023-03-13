#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binario(int tam, int vetor[tam], int cont, int result)
{
    result += vetor[tam] * pow(2, cont);

    if (t == 0)
    {
        return result;
    }

    return binario(tam - 1, vetor, cont + 1, result);
}

int main()
{
    int tam;
    scanf("%d", &tam);
    int vetor[tam];

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("%d", binario(tam - 1, vetor, 0, 0));

    return 0;
}