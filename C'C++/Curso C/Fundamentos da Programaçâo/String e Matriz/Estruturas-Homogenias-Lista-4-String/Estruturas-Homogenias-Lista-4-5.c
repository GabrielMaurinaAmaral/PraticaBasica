/*5) Ler um texto e imprimir o inverso do texto.*/

#include <string.h>
#include <stdio.h>

int main(void)
{
    char strTexto[150], opcRepetir;
    int i;

    do
    {
        i = 0;
         printf("Informe um texto com nomaximo 150 carcteres: ");
        gets(strTexto);

        while (strTexto[i] != '\0')
        {
            i++;
        }

        i = i - 1;

        printf("\nString invertida: ");
        while (i >= 0)
        {
            printf("%c\n", strTexto[i]);
            i--;
        }

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}