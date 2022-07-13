/*Questão 1 (3,3 pontos) - Gerar um vetor com 10 valores gerados randomicamente entre 0 e 10. Ordenar o vetor e mostrar o 
vetor ordenado. Gerar um novo vetor com os valores que não se repetem no primeiro vetor. Gerar um novo vetor com os valores 
que se repetem no primeiro vetor (atenção para não repetir os elementos neste vetor). Mostrar os três vetores. Gerar uma matriz 
que armazena na primeira coluna os elementos do vetor de repetidos e na segunda coluna o número de vezes que cada 
elemento se repete no vetor principal.
Exemplo*/

#include <stdio.h>
#include <time.h>

void vetorRand(int tam, int vetor[])/*gerar vetor randomico*/
{
    int i;

    srand(time(NULL));
    for (i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 11;
    }
}

void vetorOrdenar(int tam, int vetor[])/*deixar em ordem*/
{
    int i, j, aux;

    for (i = tam - 1; i > 0; i--)/*bagulho da bolha(esqueci o nome)*/
    {
        for (j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[i])/*pegar omaior numero e leva para frente*/
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void vetorMostrar(int tam, int vetor[])
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf(" %d\t", vetor[i]);
    }
}

int main(void)
{
    int vetor[10], i, j, tam, aux, tamR;

    vetorRand(10, vetor);
    printf("\n==== VETOR ====\n");
    vetorOrdenar(10, vetor);
    vetorMostrar(10, vetor);

    tam = 0;
    j = 0;
    printf("\n==== VETOR NAO REPETIRAM ====\n");
    for (i = 0; i < 10; i++)
    {
        if (vetor[i] != vetor[i + 1] && vetor[i] != vetor[i - 1])
        {
            tam++;
        }
    }

    int vetorNR[tam];

    for (i = 0; i < 10; i++)
    {
        if (vetor[i] != vetor[i + 1] && vetor[i] != vetor[i - 1])
        {
            vetorNR[j] = vetor[i];
            printf(" %d\t", vetorNR[j]);
            j++;
        }
    }

    j = 0;
    tam = 0;
    printf("\n==== VETOR REPETIRAM ====\n");
    for (i = 0; i < 10; i++)/*pegar o tamanho dao vetor primo*/
    {
        if (vetor[i] == vetor[i + 1] || vetor[i] == vetor[i - 1])
        {
            if (vetor[i] != vetor[i + 1] && vetor[i] != vetor[i - 1])
            { 
                tam++;
            }
        }
    }

    int vetorR[tam], tamMatriz;

    for (i = 0; i < 10; i++)
    {
        if (vetor[i] == vetor[i + 1] || vetor[i] == vetor[i - 1])
        {
            if(vetor[i] == vetor[i - 1])
            {
                vetorR[j] = vetor[i];
                printf(" %d\t", vetorR[j]);
                tamMatriz++;
                j++;
            }                 
        }
    }

    int matriz[tamMatriz][2];
    return 0;
}