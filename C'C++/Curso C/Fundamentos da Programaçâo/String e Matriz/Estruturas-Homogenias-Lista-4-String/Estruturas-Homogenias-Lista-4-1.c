/*1) Ler um texto com até 100 caracteres. Se o primeiro caractere for 'a' imprimir esse texto, caso contrário contar quantos caracteres 'o' o texto possui.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char texto[100], opcRepetir;
    int contO, i;

    do
    {
        printf("Informe um texto com ate 100 caracteres: ");
        gets(texto);

        contO = 0;

        for (i = 0; i < 100; i++)
        {
            if (texto[i] == 'o')
            {
                contO++;
            }
        }

        printf("O texto ( %s ) contem %d caracteres o ", texto, contO);

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}