#include <iostream>
using namespace std;

#define min(a, capacidade) a < capacidade ? a : capacidade

int mochila_progamacao_dinamicad(int *peso, int *custo, int len, int capacidade)
{
    int i, j, mat[capacidade + 1][len + 1];

    for (i = 0; i <= capacidade; i++)
        mat[i][0] = 0;

    // coluna
    for (j = 1; j <= len; j++)
    {
        // linha
        for (i = 0; i <= capacidade; i++)
            if (i - peso[j - 1] < 0)
                mat[i][j] = mat[i][j - 1];
            else
                mat[i][j] = max(mat[i][j - 1], custo[j - 1] + mat[i - peso[j - 1]][j - 1]);
    }

    return mat[capacidade][len];
}

int main()
{
    int i, len, capacidade;
    int *peso, *custo;

    scanf("%d", &capacidade);
    scanf("%d", &len);

    peso = (int *)malloc(sizeof(int) * len);
    custo = (int *)malloc(sizeof(int) * len);

    for (i = 0; i < len; i++)
        scanf("%d %d", &peso[i], &custo[i]);

    printf("%d", mochila_progamacao_dinamicad(peso, custo, len, capacidade));

    free(peso);
    free(custo);
    return 0;
}
