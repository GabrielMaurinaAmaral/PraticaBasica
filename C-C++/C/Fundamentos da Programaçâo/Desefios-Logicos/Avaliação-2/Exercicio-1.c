/*Questão 1
( 4 pontos) Gerar dois vetores com 5 elementos cada, os elementos devem ser distintos (não repetidos).
 Os valores para o vetor devem ser gerados de forma aleatória entre 1 e 15 para o primeiro vetor e entre 1 e 10 para o segundo vetor.
 Gerar um terceiro vetor cujos valores será o resultado da interseção dos elementos dos dois primeiros vetores.
 Gerar também um quarto vetor que terá como val ores o resultado da união dos elementos dos doi s primeiros vetores.
 Utilizar o conceito matemático de interseção e união entre conjuntos.
 Mostrar os quatro vetores.

 Interseção dos conjuntos A e B é o conjunto de todos os objetos que são membros de ambos A e B. A interseção de {1, 2, 3} e {2, 3, 4} é o conjunto {2, 3}.
 União dos conjuntos A e B é o conjunto de todos os objeto s que são membros de A, ou B, ou ambos. A união de {1, 2, 3} e {2, 3, 4} é o conjunto {1, 2, 3, 4}.
Exemplo:*/

#include <stdio.h>
#include <time.h>

void vetorRand(int tam, int vetor[], int lim)
{
    int i, j;

    srand(time(NULL));

    vetor[0] = rand() % lim + 1;

    for (i = 1; i < tam; i++)
    {
        vetor[i] = rand() % lim + 1;

        for (j = 0; j < i; j++)
        {
            if (vetor[j] == vetor[i])
            {
                vetor[i] = rand() % lim + 1;
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
    int vetor1[5], vetor2[5], cont = 0, i, j, aux = 0, vetorU[10];

    vetorRand(5, vetor1, 15);
    printf("\n==== VETOR 1 ====\n");
    vetorMostrar(5, vetor1);

    vetorRand(5, vetor2, 10);
    printf("\n==== VETOR 2 ====\n");
    vetorMostrar(5, vetor2);

    printf("\n==== VETOR INTERCECAO ====\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (vetor1[j] == vetor2[i])
            {
                printf(" %d\t", vetor1[i]);
            }
        }
    }

    printf("\n\n===UNIAO===\n ");
    for (i = 0; i < 5; i++) 
    {
        printf("%d\t", vetor1[i]); 
        
        for (j = 0; j < 5; j++)    
        {
            if (vetor2[j] == vetor1[i])
            {

                vetor2[j] = 11; 
            }
        }
    }

    for (j = 0; j < 5; j++) 
    {
        if (vetor2[j] != 11)
        {
            printf("%d\t", vetor2[j]); 
        }
    }


return 0;
}