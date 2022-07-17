/*3) Ler uma string, contar e exibir a quantidade de cada uma das vogais existentes nessa string. Armazenar essas quantidades em um vetor. É indispensável armazenar a quantidade no vetor à medida que a string é percorrida na forma vetVogais[indice]++. Portanto, o vetor que armazena a quantidade de vogais deve ser inicializado com zero antes de ser utilizado. Mostrar os resultados da seguinte forma.
Vogal Quantidade
===================
A/a 5
E/e 0
I/i 1
O/o 2
U/u 0
Exemplo:*/

#include <string.h>
#include <stdio.h>

int main(void)
{
    char opcRepetir, strTexto[150];
    int vetor[5], i;

    do
    {
        i = 0;
        vetor[0] = 0;
        vetor[1] = 0;
        vetor[2] = 0;
        vetor[3] = 0;
        vetor[4] = 0; 
        printf("\n Informe um texto de 150 caracteres: ");
        gets(strTexto);

        while (strTexto[i] != '\0')
        {
            if (strTexto[i] == 'A' || strTexto[i] == 'a')
            {
                vetor[0] = vetor[0] + 1;
            }
            if (strTexto[i] == 'E' || strTexto[i] == 'e')
            {
                vetor[1] = vetor[1] + 1;
            }
            if (strTexto[i] == 'I' || strTexto[i] == 'i')
            {
                vetor[2] = vetor[2] + 1;
            }
            if (strTexto[i] == 'O' || strTexto[i] == 'o')
            {
                vetor[3] = vetor[3] + 1;
            }
            if (strTexto[i] == 'U' || strTexto[i] == 'u')
            {
                vetor[4] = vetor[4] + 1;
            }

            i++;
        }

        printf("\n VOGAL       QUANTIDADE ");
        printf("\n============================");
        printf("\n A/a            %d", vetor[0]);
        printf("\n E/e            %d", vetor[1]);
        printf("\n I/i            %d", vetor[2]);
        printf("\n O/o            %d", vetor[3]);
        printf("\n U/u            %d", vetor[4]);

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}