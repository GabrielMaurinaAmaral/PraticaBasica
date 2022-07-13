#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct aluno_t{
    int cod;
    char nome[255];
    float notas[3];
    float media;
}aluno_t;

void calculaMedia(aluno_t aluno[], int n)
{ 
    for(int i=0; i<n; i++)
    {
        aluno[i].media=(aluno[i].notas[0]+aluno[i].notas[1]+aluno[i].notas[2])/3;
        
        if(aluno[i].media>=6)
        {
            printf("Aprovado!\n");
        }
        else
        {
            printf("Reprovado!\n");
        }
    }
}

int encontraMaiorMedia(aluno_t aluno[], int n)
{
    int aux=0, i, j;
    float maior;
    
    for(i=0; i<n; i++)
    {
        if(aux==0)
        {
            maior=aluno[i].media;
            aux=1;
        }
        else if(maior<aluno[i].media)
        {
            maior=aluno[i].media;
            j=i;
        }    
    }
    printf("O aluno com maior media e: %d %s %0.1f", aluno[j].cod, aluno[j].nome, aluno[j].media);
}

int main()
{
    int n;
    scanf("%d", &n);
    aluno_t aluno[n-1];
    
    for(int i=0; i<n; i++)
    {
        scanf("%d %s %f %f %f", &aluno[i].cod, aluno[i].nome, &aluno[i].notas[0], &aluno[i].notas[1], &aluno[i].notas[2]);
    }
    
    calculaMedia(aluno, n);
    encontraMaiorMedia(aluno, n);
    
    return 0;
}
