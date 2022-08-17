#include <time.h>
#include <stdlib.h>
srand(time(NULL));

int gerarVeoresInteiros(int inter1, int inter2, int i)
{
    int vetor[i];
    for (i = inter2 - inter1; i >= 0; i--)
    {
        vetor[i] = rand() % inter2 + inter1;
        return vetor[i];
    }
}
void mostrarVeoresInteiros(int inter1, int inter2, int i)
{
    int vetor[i];
    for (i = inter2 - inter1; i >= 0; i--)
    {
        vetor[i] = rand() % inter2 + inter1;
        printf(" %d\t ", vetor[i]);
    }
}
