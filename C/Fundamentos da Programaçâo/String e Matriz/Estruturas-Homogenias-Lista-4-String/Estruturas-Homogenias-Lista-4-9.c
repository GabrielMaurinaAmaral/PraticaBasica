/*9) Fazer uma função que recebe duas strings e retorna 1 se elas são iguais ou 0, caso sejam diferentes.
Elaborar um programa que leia uma palavra, armazene o seu inverso em outra string e determine se a mesma
representa um palíndromo ou não, usando a função que compara strings. Exemplos de palavras palíndromos: 
ovo, natan, sos, arara, mirim, anilina, ana.*/

#include <stdio.h>

int stringPalin(char strTexto[], char strInvert[])
{
    int contT = 0, contI = 0, i = 0, k = 0;

    while (strSenha[j] != '\0')
    {
        contS++;
        j++;
    }

    while (strCompa[k] != '\0')
    {
        if (strCompa[k] == strSenha[k])
        {
            contC++;
        }
        k++;
    }

    if (contC == contS)
    {
        return 1;
    }
    else
    {}

}

int main(void)
{
    char opcRepetir, strTexto[150], strInvert[150];
    int i, j;

    do
    {
        printf("Informe um texto com ate 150 caracteres: ");
        gets(strTexto);

        i = 0;
        while (strTexto[i] != '\0')
        {
            i++;
        }

        i = i - 1;
        j = 0;

        while (i >= 0)
        {
            strInvert[j] = strTexto[i];
            j++;
            i--;
        }
        strInvert[j] = '\0';

        printf("\n Inverso do texto: %s\n", strInvert);

        if (stringPalin(strTexto[150], strInvert[150]) == 1)
        {
            printf("eh PALINDROMO");
        }
        else
        {
            printf("nao eh PALINDROMO");
        }

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}
