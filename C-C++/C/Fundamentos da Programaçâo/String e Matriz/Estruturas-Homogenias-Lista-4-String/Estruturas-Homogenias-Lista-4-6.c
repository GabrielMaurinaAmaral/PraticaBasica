/*6) Ler um texto e imprimir o texto na vertical com uma palavra por linha.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char strTexto[150], opcRepetir;

    do
    {
        i = 0;

        printf("Informe um texto com ate 150 caracteres: ");
        gets(strTexto);

        printf("\n====TEXTO NA VERTICAL====");
        while (strTexto[i] != '\0')
        {
            if (strTexto[i] != ' ')
            {
                printf("%c", strTexto[i]);
            }
            else if (strTexto[i] == ' ' && strTexto[i + 1] != ' ')
            {
                printf("\n");
            }

            i++;
        }

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}