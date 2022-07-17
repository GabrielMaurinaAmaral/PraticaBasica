#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar_char(char c1, char c2)
{
    if (c1 == c2)
        return 0;
    else if (c1 < c2)
        return -1;
    else
        return 1;
}

int comparar(char s1[], char s2[])
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++)
        ;

    return comparar_char(s1[i], s2[i]);
}

void troca(char **strV, int p1, int p2)
{
    char *str;

    str = strV[p1];
    strV[p1] = strV[p2];
    strV[p2] = str;
}

void selectsort_Str(char **strV, int tam)
{
    int i, j, p;

    for (i = tam - 1; i >= 1; i--)
    {
        p = i;

        for (j = 0; j < i; j++)
            if (comparar(strV[j], strV[p]) > 0)
                p = j;

        troca(strV, j, p);
    }
}

int main()
{
    int tam, i;
    scanf("%d", &tam);
    char **strV = (char **)malloc(tam * sizeof(char *));

    for (i = 0; i < tam; i++)
    {
        strV[i] = (char *)malloc(10 * sizeof(char));
        scanf("%s", strV[i]);
    }

    selectsort_Str(strV, tam);

    for (i = 0; i < tam; i++)
        printf("%s\n", strV[i]);

    return 0;
}
