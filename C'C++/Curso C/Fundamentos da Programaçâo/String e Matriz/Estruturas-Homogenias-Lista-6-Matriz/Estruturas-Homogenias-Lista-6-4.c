/*4) Gerar uma matriz 50x10 que se refere as respostas de 10 questões de múltipla escolha referentes a 50
alunos. Gerar um vetor de 10 posições contendo o gabarito de respostas que podem ser 1, 2, 3, 4, ou 5. Em
seguida comparar as respostas de cada candidato com o gabarito e mostrar e mostrar a pontuação
correspondente.*/
#include <stdio.h>
#include "Funcoes-Matriz-Lista-6.h"

int main(void)
{
    int matriz[50][10], vetor[10], aluno, nota, ponto;

    gerarMatrizInteiro(50, 10, matriz, 1, 5);
    printf("\n RESPOSTAS DOS ALUNOS \n");
    mostrarMatrizInteiro(50, 10, matriz);

    gerarVetor(vetor, 10, 1, 5);
    printf("\n GABARITO DA PROVA \n");
    mostrarVetor(vetor, 10);

    ponto=0;
    for(aluno=0; aluno<50; aluno++)
    {
        for(nota=0; nota<10; nota++)
        {
            if(matriz[aluno][nota]==vetor[nota])
            {
                ponto++;
            }
        }
        printf("\nAluno %d tirou %d pontos\n", aluno+1, ponto);
        ponto=0;
    }
    return 0;
}