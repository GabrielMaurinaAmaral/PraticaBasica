#include<stdlib.h>
#include<stdio.h>

void concatenar(char *o1, char *o2, char *o3, char *d)
{
    char str[100];

    FILE *arq1 = fopen(o1, "r");
    FILE *arq2 = fopen(o2, "r");
    FILE *arq3 = fopen(o3, "r");
    FILE *dest = fopen(d, "w");

    if (arq1 != NULL)
    {
        while (!feof(arq1))
        {
            fgets(str, 100, arq1);
            fputs(str, dest);
        }
        fclose(arq1);
    }

    if (arq2 != NULL)
    {
        while (!feof(arq2))
        {
            fgets(str, 100, arq2);
            fputs(str, dest);
        }
        fclose(arq2);
    }

    if (arq3 != NULL)
    {
        while (!feof(arq3))
        {
            fgets(str, 100, arq3);
            fputs(str, dest);
        }
        fclose(dest);
    }
}