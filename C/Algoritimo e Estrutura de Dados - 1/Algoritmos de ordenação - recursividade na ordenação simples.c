#include <stdio.h>
#include <stdlib.h>

int ordenar(int v[], int tam, int i)
{
    int j, p, aux, k;

    i--;
    if (i == 0)
    {
        for (k = 0; k < tam; printf("%d ", v[k]), k++);
        return 1;
    }

    p = i;

    for (j = 0; j < i; j++)
        if (v[j] > v[p])
            p = j;

    aux = v[i];
    v[i] = v[p];
    v[p] = aux;

    return ordenar(v, tam, i);
}

int main()
{
    int tam;
    scanf("%d", &tam);

    int v[tam];
    for (int i = 0; i < tam; scanf("%d", &v[i]), i++)
        ;

    ordenar(v, tam, tam);

    return 0;
}