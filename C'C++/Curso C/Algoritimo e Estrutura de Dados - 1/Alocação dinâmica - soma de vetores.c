#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma(int *v1, int n1, int *v2, int n2)
{
    int maior = 0, menor = 0, *vsoma;
    vsoma = malloc(maior * sizeof(int));

    if (n1 > n2)
    {
        maior = n1;
        menor = n2;
    }

    else
    {
        maior = n2;
        menor = n1;
    }

    for (int i = 0; i < menor; i++)
    {
        vsoma[i] = v1[i] + v2[i];
    }
    for (int j = menor; j < n1; j++)
    {
        vsoma[j] = v1[j];
    }
    for (int k = menor; k < n2; k++)
    {
        vsoma[k] = v2[k];
    }

    return vsoma;
}

int main()
{
    int n1, n2, maior = 0, *v1, *v2, *vsoma;

    scanf("%d", &n1);
    v1 = (int *)malloc(n1 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &v1[i]);
    }

    scanf("%d", &n2);
    v2 = (int *)malloc(n2 * sizeof(int));

    for (int j = 0; j < n2; j++)
    {
        scanf("%d", &v2[j]);
    }

    if (n1 > n2)
    {
        maior = n1;
    }

    else if (n2 > n1)
    {
        maior = n2;
    }
    else
    {
        maior = n1;
    }

    vsoma = (int *)malloc(maior * sizeof(int));
    vsoma = soma(v1, n1, v2, n2);

    for (int k = 0; k < maior; k++)
    {
        printf("%d ", vsoma[k]);
    }

    free(v1);
    free(v2);
    free(vsoma);
    return 0;
}