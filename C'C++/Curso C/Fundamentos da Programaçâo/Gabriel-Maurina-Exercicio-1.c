/*Questão 1 (3,4 pontos) - Gerar dois vetores com 5 elementos cada, os elementos devem ser distintos (não repetidos). Os valores para o
vetor devem ser gerados de forma aleatória entre 1 e 15 para o primeiro vetor e entre 1 e 10 para o segundo vetor. Gerar um terceiro vetor
cujos valores será o resultado da interseção dos elementos dos dois primeiros vetores. Gerar também um quarto vetor que terá como valores
o resultado da união dos elementos dos dois primeiros vetores. Utilizar o conceito matemático de interseção e união entre conjuntos. Mostrar
os quatro vetores.
 Interseção dos conjuntos A e B é o conjunto de todos os objetos que são membros de ambos A e B. A interseção de {1, 2, 3} e {2, 3, 4}
é o conjunto {2, 3}.
 União dos conjuntos A e B é o conjunto de todos os objetos que são membros de A, ou B, ou ambos. A união de {1, 2, 3} e {2, 3, 4} é o
conjunto {1, 2, 3, 4}.*/

#include <stdio.h>
#include <time.h>/*biblioteca para a funcao rand*/

void vetorRand(int vetor[], int tam, int lim) /*gerar um vetor aleatorio*/
{
    int i, aux=0;

    srand(time(NULL));
    for (i = 0; i < tam; i++)
    {

        do
        {
            vetor[i] = rand() % lim + 1;

        } while (aux == vetor[i]);

        aux=vetor[i];/*aux para não repetir o munero aleatorio*/
    }
}

int mostrarVetor(int vetor[], int tam) /*mfuncao pra mostrar o vetor*/
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf(" %d\t", vetor[i]);
    }
}

int main(void)
{
    int vetor1[5], vetor2[5], i, j, cont;

    vetorRand(vetor1, 5, 15);
    printf("\n==== Vetor 1 ====\n");
    mostrarVetor(vetor1, 5);

    vetorRand(vetor2, 5, 10);
    printf("\n==== Vetor 2 ====\n");
    mostrarVetor(vetor2, 5);

    printf("\n==== VETOR INTERCECAO====\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (vetor1[i] == vetor2[j]) /*parameto se for igual printa*/
            {
                printf(" %d\t", vetor1[i]);
            }
        }
    }

    printf("\n==== VETOR contunção====\n");
    for (i = 0; i < 5; i++)
    {
        printf(" %d\t", vetor1[i]); /* print todo o primerio str e so print os difetentes na str2 logo a baixo*/
    }
    for (i = 0; i < 5; i++)
    {
        cont=0;

        for (j = 0; j < 5; j++)
        {
            if(vetor2[i]!=vetor1[j])
            {
                cont++;
            }
        }
        if(cont==5)
        {
            printf(" %d\t", vetor2[i]);
        }
    }

    return 0;
}