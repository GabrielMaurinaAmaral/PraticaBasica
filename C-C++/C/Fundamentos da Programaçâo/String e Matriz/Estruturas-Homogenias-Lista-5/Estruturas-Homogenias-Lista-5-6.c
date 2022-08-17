/*6) Utilizar uma função para gerar um vetor com 10 valores entre 5 e 50. Utilizar uma função para verificar se
cada elemento do vetor é ou não um número primo. Armazenar em outro vetor somente os números que são
primos. Mostrar os dois vetores utilizando função.*/
#include <stdio.h>
#include <time.h>

int vetorRand(int inter1, int inter2, int i);
int vetorPrimo(int vetor[], int i);

int main(void)
{
    int inter1, inter2, i;
    char opcRepetir;

    do
    {
        inter1 = 1;
        inter2 = 50;
        i = 10;
        srand(time, NULL);

        printf("=====VETOR=====\n");
        for (i = 0; i < 10; i++)
        {
            printf(" %d\t", vetorRand(inter1, inter2, i));

            if (vetorPrimo(vetorRand(inter1, inter2, i), i) == 1)
            {
                printf(" %d eh primo",  vetorRand(inter1, inter2, i));
            }
            else if (vetorPrimo(vetorRand(inter1, inter2, i), i) == 0)
            {
                printf(" %d nao eh primo",  vetorRand(inter1, inter2, i));
            }
        }

        printf("\n");
        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}

int vetorRand(int inter1, int inter2, int i)
{
    int vetorR[i];

    vetorR[i] = rand() % inter2 + inter1;

    return vetorR[i];
}

int vetorPrimo(int vetor[], int i)
{
    int contDiv, j, contP, vetorP[contP];

    contDiv = 0;
    contP = 0;

    for (j = 1; j <= vetor[i]; j++)
    {
        if (vetor[i] % j == 0)
        {
            contDiv++;
        }

        if (contDiv == 2)
        {
            return 1;
            vetorP[contP] = vetor[i];
            contP++;
        }
        else
        {
            return 0;
        }
    }
}