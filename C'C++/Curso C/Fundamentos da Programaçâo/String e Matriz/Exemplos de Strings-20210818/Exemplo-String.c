#include <stdio.h>

int main(void)
{
    int i=0, j=0;
    char str1[30], str2[30];

    printf("Informe uma string: ");
    gets(str1);

    while(str1[i] != '\0')
    {
        i++;
    }

    printf("String1: %s\n", str1);
    printf("Valor de i: %d\n", i);

    i--;

    while(str1[i] >= 0)
    {
        str2[j] = str1[i];
        i--;
        j++;
    }

    str2[j] = '\0';

    printf("String2: %s\n", str2);

    return 0;
}

#include <stdio.h>

int tamanhoDaString(char str[]);
int qtdeEspacos(char str[]);

int main(void)
{
    char string[30];

    printf("Informe uma string: ");
    gets(string);

    printf("\nA string \"%s\" tem tamanho %d\n", string, tamanhoDaString(string));
    printf("A string \"%s\" tem %d espacos em branco\n", string, qtdeEspacos(string));

    return 0;
}

int tamanhoDaString(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

int qtdeEspacos(char str[])
{
    int i=0, cont=0;

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            cont++;
        }
        i++;
    }
    return(cont);
}