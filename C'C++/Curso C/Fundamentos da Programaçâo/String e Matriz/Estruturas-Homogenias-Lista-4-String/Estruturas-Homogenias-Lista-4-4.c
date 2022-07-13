/*4) Fazer uma função para contar a quantidade de caracteres de uma string, incluindo espaços, e outra função não incluindo espaços.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, contCarac, contCaracSem;
    char strTexto[150], opcRepetir;

    do
    {
        i = 0;
        contCarac = 0;
        contCaracSem = 0;

        printf("Informe um texto com ate 150 caracteres: ");
        gets(strTexto);

        while (strTexto[i] != '\0')
        {
            contCarac++;

            if (strTexto[i] != ' ')
            {
                contCaracSem++;
            }

            i++;
        }

        printf("\n Numero de caracteres com espaco: %d ", contCarac);
        printf("\n Numero de caracteres sem espaco: %d \n", contCaracSem);

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}
