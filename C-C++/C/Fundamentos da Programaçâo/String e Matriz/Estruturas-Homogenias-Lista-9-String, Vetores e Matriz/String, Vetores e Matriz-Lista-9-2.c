/*2) Fazer funções para:
a) Contar as palavras de uma string.
b) Mostrar o primeiro caractere de cada palavra de uma string.
c) Mostrar o último caractere de cada palavra de uma string.
Usando as funções criadas, elabore um programa que receba uma string de até 100 caracteres e forneça a
quantidade de palavras da string, mostre o primeiro caractere de cada palavra da string e mostre o último
caractere de cada palavra da string.
O programa também deverá copiar a primeira palavra da string para uma outra string e imprimi-la.*/

#include <stdio.h>

int stringPalavras(char strTexto[])
{
    int i = 0, result = 0, contP=0;

    while (strTexto[i] != '\0')
    {
        if (result == 0)
        {
            if (strTexto[i] != ' ')
            {
                contP++;
                result = 1;
            }
        }

        else
        {
            if (strTexto[i] != ' ' && strTexto[i - 1] == ' ')
            {
                contP++;
            }
        }
        i++;

        return contP;
    }
}

void first_char(char strTexto[])
{
    int i = 0, result = 0, cont=0;

    while (strTexto[i] != '\0')
    {
        if (result == 0)
        {
            if (strTexto[i] != ' ')
            {
                printf("%c\t",strTexto[i]);
                result = 1;
                                cont++;

            }
        }

        else
        {
            if (strTexto[i] != ' ' && strTexto[i - 1] == ' ')
            {
                printf("%c\t", strTexto[i]);
                cont++;
            }
        }
        i++;
    }

    printf("\n %d \n", cont);
}

int main(void)
{
    char strTexto[100];

    printf(" Informe um texto com ate 100 caracteres: ");
    gets(strTexto);

    printf("\n%d\n", stringPalavras(strTexto));

    first_char(strTexto);


    return 0;
}