//Exemplo: Ler e imprimir 5 notas para cada aluno de duas turmas. Cada turma tem 3 alunos.

#include <stdio.h>

int main(void)
{
    int turmas=2, alunos=3, notas=5, i, j, k;
    float matriz[turmas][alunos][notas];

    for(i=0; i<turmas; i++)
    {
        for(j=0; j<alunos; j++)
        {
            for(k=0; k<notas; k++)
            {
                printf("Informe a nota %d do aluno %d da turma %d: ", k+1, j+1, i+1);
                scanf("%f", &matriz[i][j][k]);
            }
        }
    }
    printf("\n=== NOTAS ===\n");
    for(i=0; i<turmas; i++)
    {
        printf("Turma %d\n", i+1);
        for(j=0; j<alunos; j++)
        {
            printf("Aluno %d ==> ", j+1);
            for(k=0; k<notas; k++)
            {
                printf("%.1f  ", matriz[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
