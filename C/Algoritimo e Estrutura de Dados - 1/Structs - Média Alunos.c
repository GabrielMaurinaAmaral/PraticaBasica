#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct aluno_t
{
    int cod;
    char nome[255];
    float notas[3];
    float media;
} aluno_t;

void calculaMedia(aluno_t aluno[], int n)
{
    for (int i = 0; i < n; i++)
    {
        aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3;

        if (aluno[i].media >= 6)
        {
            printf("Aprovado!\n");
        }
        else
        {
            printf("Reprovado!\n");
        }
    }
}

void encontraMaiorMedia(aluno_t aluno[], int n)
{
    int i, j = 0;
    float maior;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            maior = aluno[i].media;
        }
        if (maior < aluno[i].media)
        {
            maior = aluno[i].media;
            j = i;
        }
    }
    printf("O aluno com maior media e: %d %s %0.1f\n", aluno[j].cod, aluno[j].nome, maior);
}

void encontraMenorMedia(aluno_t aluno[], int n)
{
    int i, j = 0;
    float menor;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            menor = aluno[i].media;
        }
        if (menor > aluno[i].media)
        {
            menor = aluno[i].media;
            j = i;
        }
    }
    printf("O aluno com menor media e: %d %s %0.1f\n", aluno[j].cod, aluno[j].nome, menor);
}

void encontraMaiorP1(aluno_t aluno[], int n)
{
    int i, j;
    float maior;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            maior = aluno[i].notas[0];
        }
        if (maior < aluno[i].notas[0])
        {
            maior = aluno[i].notas[0];
            j = i;
        }
    }
    printf("O aluno com maior P1 e: %d %s %0.1f", aluno[j].cod, aluno[j].nome, maior);
}

int main()
{
    int n;
    scanf("%d", &n);
    aluno_t aluno[n - 1];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %f %f %f", &aluno[i].cod, aluno[i].nome, &aluno[i].notas[0], &aluno[i].notas[1], &aluno[i].notas[2]);
    }

    calculaMedia(aluno, n);
    encontraMaiorMedia(aluno, n);
    encontraMenorMedia(aluno, n);
    encontraMaiorP1(aluno, n);

    return 0;
}