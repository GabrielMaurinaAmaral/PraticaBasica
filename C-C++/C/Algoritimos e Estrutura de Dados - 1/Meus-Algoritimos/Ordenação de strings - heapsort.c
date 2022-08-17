#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar_char(char c1, char c2)
{
    if (c1 == c2)
        return 0;
    else if (c1 < c2)
        return -1;
    else
        return 1;
}

int comparar_String(char s1[], char s2[])
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

    return comparar_char(s1[i], s2[i]);
}

void troca_Char(char **strV, int p1, int p2)
{
    char *str;

    str = strV[p1];
    strV[p1] = strV[p2];
    strV[p2] = str;
}

static void refazer_Heap(char **v, int esq, int dir)
{
    int j = (esq + 1) * 2 - 1;
    char *x = (char *)malloc(100 * sizeof(char));
    x = v[esq];

    while (j <= dir)
    {
        if ((j < dir) && (comparar_String(v[j], v[j + 1]) < 0))
            j++;
        if (comparar_String(x, v[j]) > 0)
            break;

        v[esq] = v[j];
        esq = j;
        j = (esq + 1) * 2 - 1;
    }

    v[esq] = x;
}

static void gerarHeap_String(char **v, int tam)
{
    int esq = tam / 2;

    while (esq >= 0)
    {
        refazer_Heap(v, esq, tam - 1);
        esq--;
    }
}

void heapsort_String(char **v, int tam)
{
    int dir = tam - 1;

    gerarHeap_String(tam, n);

    while (dir > 0)
    {
        troca_Char(v, 0, dir);
        dir--;
        refazer_Heap(v, 0, dir);
    }
}

int main()
{
    int tam, i;
    scanf("%d", &tam);
    char **strV = (char **)malloc(tam * sizeof(char *));

    for (i = 0; i < tam; i++)
    {
        strV[i] = (char *)malloc(12 * sizeof(char));
        scanf("%s", strV[i]);
    }

    heapsort_String(strV, tam);

    for (i = 0; i < tam; i++)
        printf("%s\n", strV[i]);

    return 0;
}