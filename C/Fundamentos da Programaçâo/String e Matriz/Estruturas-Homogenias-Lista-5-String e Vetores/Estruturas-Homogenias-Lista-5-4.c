/*4) Ler uma string e contar quantas palavras a mesma possui. Considerar o seguinte contexto:
O usuário pode informar apenas uma palavra, com ou sem espaços no início ou no final da mesma.
O usuário pode informar mais de um espaço entre palavras.
O usuário pode não informar nenhuma palavra (simplesmente pressionar ENTER).*/
#include <stdio.h>

int main(void)
{
    char opcRepetir, strTexto[150];
    int i, contP;

    do
    {
        printf("\n Informe um texto: ");
        setbuf(stdin, NULL);
        gets(strTexto);

        i = 0;
        contP = 0;
        while (strTexto[i] != '\0')
        {
            if ((strTexto[i] == ' ' && strTexto[i + 1] != ' ') || strTexto[i+1]=='\0')
            {
                contP++;
            }

            i++;
        }

        printf(" '%s' contem %d palavras \n", strTexto, contP);

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}