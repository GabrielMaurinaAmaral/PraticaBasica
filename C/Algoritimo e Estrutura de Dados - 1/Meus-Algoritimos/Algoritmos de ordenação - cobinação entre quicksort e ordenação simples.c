#include <stdio.h>
#include <stdlib.h>

void quicksortEinsertsort(int v[], int esq, int dir, int m)
{
    int i = esq, j = dir, pivo = v[(i + j) / 2], aux, k, l;

    if (esq - dir + 1 > m)
    {
        do
        {
            while (v[i] < pivo)
                i++;

            while (v[j] > pivo)
                j--;

            if (i <= j)
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);

        if (j > esq)
            quicksortEinsertsort(v, esq, j, m);
        if (i < dir)
            quicksortEinsertsort(v, i, dir, m);
    }
    else
    {
        for (k = i; k < j; k++)
        {
            aux = v[k];

            for (l = k - 1; (l >= 0) && (aux < v[l]); l--)
                v[l + 1] = v[l];

            v[l + 1] = aux;
        }
    }
}

int main()
{
    int tam, m;
    scanf("%d", &tam);
    int v[tam];
    for (int i = 0; i < tam; i++)
        scanf("%d", &v[i]);
    scanf("%d", &m);

    quicksortEinsertsort(v, 0, tam, m);
    for (int i = 0; i < tam; i++)
        printf("%d ", v[i]);

    return 0;
}