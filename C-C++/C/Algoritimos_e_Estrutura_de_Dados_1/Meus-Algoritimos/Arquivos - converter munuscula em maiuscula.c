#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *arquivo1 = fopen("text-1.txt", "w");
    FILE *arquivo2 = fopen("text-2.txt", "w");
    char str[100];

    if ((arquivo1 && arquivo2) != NULL)
    {

        scanf("%s", str);
        fputs(str, arquivo1);
        fclose(arquivo1);
        arquivo1 = fopen("text-1.txt", "r");

        char c = fgetc(arquivo1);
        while (c != EOF)
        {
            fputc(toupper(c), arquivo2);
            c = fgetc(arquivo1);
        }
    }

    fclose(arquivo1);
    fclose(arquivo2);

    return 0;
}