//Copia o conteúdo de uma string para outra

#include <stdio.h>

int main(void)
{
    char string1[20] = "Hello world";
    char string2[20];

    //string1 = string2 //Errado!

    int i=0;

    while(string1[i] != '\0')
    {
        string2[i] = string1[i];
        i++;
    }

    string2[i] = '\0';

    printf("String1: %s\n", string1);
    printf("String2: %s\n", string2);

    return 0;
}
