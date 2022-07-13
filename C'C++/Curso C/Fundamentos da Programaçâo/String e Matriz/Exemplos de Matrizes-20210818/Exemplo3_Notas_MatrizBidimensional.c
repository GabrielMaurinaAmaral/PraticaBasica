//Exemplo: Ler e imprimir 5 notas de 3 alunos

#include <stdio.h>

int main(void)
{
      int alunos=3, notas=5, i, j;
      float matriz[alunos][notas];

      for(i=0; i<alunos; i++)
      {
          for(j=0; j<notas; j++)
          {
              printf("Informe a nota %d do aluno %d: ", j, i);
              scanf("%f", &matriz[i][j]);
          }
      }
      printf("\n=== NOTAS ===\n");
      for(i=0; i<alunos; i++)
      {
          printf("Aluno %d ==> ", i);

          for(j=0; j<notas; j++)
          {
              printf("%.1f  ", matriz[i][j]);
          }
          printf("\n");
      }
      return 0;
}
