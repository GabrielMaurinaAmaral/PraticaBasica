#include <stdio.h>
#include <stdlib.h>

int juntar_Arquivos(FILE *arq1, FILE *arq2, FILE *arq3)
{
    char str[100];

    if (arq1 != NULL)
    {
        while (!feof(arq1))
        {
            fgets(str, 100, arq1);
            fputs(str, arq3);
        }
        fclose(arq1);
    }

    if (arq2 != NULL)
    {
        while (!feof(arq2))
        {
            fgets(str, 100, arq2);
            fputs(str, arq3);
        }
        fclose(arq2);
    }

    fclose(arq3);

    return 0;
}

int main()
{
    FILE *arq1 = fopen("text-1.txt", "w");
    FILE *arq2 = fopen("text-2.txt", "w");
    FILE *arq3 = fopen("text-3.txt", "w");
    char str[100];

    if ((arq1 && arq2) != NULL)
    {
        scanf("%s", str);
        fputs(str, arq1);
        scanf("%s", str);
        fputs(str, arq2);
    }

    juntar_Arquivos(arq1, arq2, arq3);

    return 0;
}