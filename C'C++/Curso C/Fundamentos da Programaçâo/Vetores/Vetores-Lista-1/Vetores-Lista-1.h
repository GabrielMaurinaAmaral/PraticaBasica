#include <time.h>
#include <stdlib.h>
int vetorRand(int inter1, int tam)
{
    int i, vetor[tam - 1], menor, maior;

    menor = vetor[0];

    srand(time(NULL));
    printf("\n====VETOR GERADO====\n");
    for (i = 0; i <= tam - 1; i++)
    {
        vetor[i] = rand() % inter1;
        printf(" %d\t ", vetor[i]);

        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
}

