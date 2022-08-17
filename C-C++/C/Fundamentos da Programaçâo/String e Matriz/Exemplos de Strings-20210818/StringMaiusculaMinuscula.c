#include <stdio.h>

int main(void)
{
    char string[20], maius[20], minus[20];
    int i=0;

    printf("Informe uma string: ");
    gets(string);

    //converter para maiuscula e minuscula
    while(string[i] != '\0')
    {
        if(string[i] >= 97 && string[i] <= 122)
        {
            maius[i] = string[i] - 32;
            minus[i] = string[i];
        }
        else if(string[i] >= 65 && string[i] <= 90)
        {
            maius[i] = string[i];
            minus[i] = string[i] + 32;
        }
        else
        {
            maius[i] = string[i];
            minus[i] = string[i];
        }

        i++;
    }

    maius[i] = '\0';
    minus[i] = '\0';

    printf("String maiuscula: %s\n", maius);
    printf("String minuscula: %s\n", minus);

    return 0;
}
