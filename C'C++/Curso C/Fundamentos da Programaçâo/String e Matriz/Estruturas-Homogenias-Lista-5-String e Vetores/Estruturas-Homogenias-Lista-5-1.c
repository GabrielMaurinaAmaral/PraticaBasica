/*1 Ler uma string e copiá-la para outra string sem os possíveis espaços em branco no início e no final.
    Também devem ser eliminados dois ou mais espaços sucessivos entre as palavras.*/

#include <stdio.h>

int main(void)
{
    char strT[150], strI[150], opcRepetir;
    int i = 0, k = 0;

    do
    {
        printf("Informe um texto com ate 150 caracteres: ");
        gets(strT);

        while (strT[i] != '\0')
        {
            if (strT[i] != ' ')
            {
                strI[k] = strT[i];
                k++;
            }

            i++;
        }

        printf("\n Texto sem espaco: %s", strI);

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}