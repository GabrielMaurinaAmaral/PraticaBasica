#include <stdio.h>

int main(void)
{
    int i;

    //12 meses com três caracteres cada
    char meses[12][4] = {"jan", "fev", "mar", "abr", "mai", "jun", "jul", "ago", "set", "out", "nov", "dez"};

    printf("MES\tNOME\n");
    for (i=0; i<12; i++)
    {
        printf("%d\t%s\n", i+1, meses[i]);
    }

    return 0;
}

