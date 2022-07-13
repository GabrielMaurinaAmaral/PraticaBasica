/*2) Gerar um vetor com 50 elementos (valores aleatórios), com valor até 100. Armazenar em um vetor os números pares e em outro os números ímpares. Mostrar os três vetores. Dica: Declarar os três vetores com tamanho 50, na pior hipótese todos os números gerados seriam pares ou ímpares.
Uma solução mais otimizada: primeiro percorrer o vetor e contar quantos valores há de cada tipo e em seguida declarar os vetores com o tamanho exato, obtido da contagem.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int vetorRand[49], i, coluna;
    char opcRepetir;

    do
    {
        srand(time(NULL));
        coluna = 0;
        printf("\n====VETOR===\n");
        for (i = 0; i <= 49; i++)
        {
            vetorRand[i] = rand() % 100 + 1;
            printf(" %2.0d\t ", vetorRand[i]);

            coluna++;
            if (coluna % 10 == 0)
            {
                printf("\n");
            }
        }

        coluna = 0;
        printf("\n====VETOR PAR====\n");
        for (i = 0; i <= 49; i++)
        {
            if (vetorRand[i] % 2 == 0)
            {
                printf("%2.0d\t", vetorRand[i]);
                coluna++;
                if (coluna % 10 == 0)
                {
                    printf("\n");
                }
            }
        }

        coluna = 0;
        printf("\n====VETOR IMPAR====\n");
        for (i = 0; i <= 49; i++)
        {
            if (vetorRand[i] % 2 != 0)
            {
                printf("%2.0d\t", vetorRand[i]);
                coluna++;
                if (coluna % 10 == 0)
                {
                    printf("\n");
                }
            }
        }

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}