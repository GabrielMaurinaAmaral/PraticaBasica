#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char *nome;
    char *curso;
    float coef;
} Aluno;

int comparar_char(char c1, char c2)
{
    if (c1 == c2)
        return 0;
    else if (c1 < c2)
        return -1;
    else
        return 1;
}

int comparar(char s1[], char s2[])
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++)
        ;

    return comparar_char(s1[i], s2[i]);
}

void troca(Aluno aluno[], int p1, int p2)
{
    Aluno aux;

    aux = aluno[p1];
    aluno[p1] = aluno[p2];
    aluno[p2] = aux;
}

void ordenar_Struct(Aluno aluno[], int tam)
{
    int i, j, t = 1;

    for (i = 0; (i < tam - 1) && t; i++)
    {
        t = 0;

        for (j = 0; j < tam - i - 1; j++)
            if (comparar(aluno[j].nome, aluno[j + 1].nome) > -1)
            {
                troca(aluno, j, j + 1);
                t = 1;
            }
    }
}

int main()
{
    int tam, i;
    scanf("%d", &tam);
    Aluno aluno[tam];

    for (i = 0; i < tam; i++)
    {
        aluno[i].nome = (char *)malloc(100 * sizeof(char));
        aluno[i].curso = (char *)malloc(100 * sizeof(char));
        scanf("%d %s %s %f", &aluno[i].matricula, aluno[i].nome, aluno[i].curso, &aluno[i].coef);
    }

    ordenar_Struct(aluno, tam);

    for (i = 0; i < tam; i++)
    {
        printf("%s %d %s %0.2f\n", aluno[i].nome, aluno[i].matricula, aluno[i].curso, aluno[i].coef);
    }
    return 0;
}