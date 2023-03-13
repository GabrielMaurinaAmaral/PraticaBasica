#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    char nome[100];
    int idade, notas;

} Aluno;

int main()
{
    FILE *arq1 = fopen("text-1.txt", "wb");
    Aluno a[3];

    if (arq1 != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%s %d %d", a[i].nome, a[i].idade, a[i].notas);
        }
        fwrite(a, sizeof(Aluno), 3, arq1);

        fclose(arq1);
    }

    return 0;
}