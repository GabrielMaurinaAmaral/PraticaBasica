/*6) Gerar um vetor A com 100 elementos entre 10 e 400, inclusive, mostrar o vetor gerado. Em seguida percorrer o vetor A e contar quantos elementos estão entre 10 e 100, quantos estão entre 101 e 200, quantos estão entre 201 e 300 e quantos estão entre 301 e 400. A quantidade será armazenada no vetor B com tamanho 4, para cada uma das respectivas quantidades. Por exemplo, vetorB[0] conterá a quantidade de valores entre 10 e 100 no vetor A.
Observação: É indispensável que os valores sejam contados à medida que o vetor A é percorrido.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int vetorA[100], i, coluna, contA, contB, contC, contD;
    char opcRepetir;

    do
    {
        coluna = 0;
        contA = 0;
        contB = 0;
        contC = 0;
        contD = 0;
        srand(time(NULL));
        printf("\n====VETOR A===\n");
        for (i = 0; i < 100; i++)
        {
            vetorA[i] = rand() % 400 + 10;
            printf(" %3.0d\t ", vetorA[i]);

            coluna++;
            if (coluna % 10 == 0)
            {
                printf("\n");
            }

            if (10 <= vetorA[i] && vetorA[i] <= 100)
            {
                contA++;
            }

            if (101 <= vetorA[i] && vetorA[i] <= 200)
            {
                contB++;
            }

            if (201 <= vetorA[i] && vetorA[i] <= 300)
            {
                contC++;
            }

            if (301 <= vetorA[i] && vetorA[i] <= 400)
            {
                contD++;
            }
        }

        printf("\n====VETOR B===\n");
        printf(" %d    %d    %d    %d", contA, contB, contC, contD);

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}