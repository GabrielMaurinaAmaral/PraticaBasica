#include <iostream>
using namespace std;
#include <limits.h>

int proximo_passo(int **mat, int linha, int coluna, int *linha_p, int *coluna_p)
{
    int i, menor = INT_MAX;
    int al, ac;
    int ml = *linha_p, mc = *coluna_p;
    int movX[] = {-1, 0, 1, 0};
    int movY[] = {0, -1, 0, 1};

    for (i = 0; i < 4; i++)
    {
        al = *linha_p + movX[i];
        ac = *coluna_p + movY[i];

        if ((al >= 0) && (al < linha) && (ac >= 0) && (ac < coluna) && (menor > mat[al][ac]))
        {
            ml = al;
            mc = ac;
            menor = mat[al][ac];
        }
    }

    *linha_p = ml;
    *coluna_p = mc;

    return menor;
}

int percurso(int **mat, int linha, int coluna, int linha_p, int coluna_p, int custo)
{
    int aux;

    if ((linha_p == linha - 1) && (coluna_p == coluna - 1))
        return custo;
    else
    {
        mat[linha_p][coluna_p] = INT_MAX;

        aux = proximo_passo(mat, linha, coluna, &linha_p, &coluna_p);

        if (aux < INT_MAX)
        {
            return percurso(mat, linha, coluna, linha_p, coluna_p, custo + mat[linha_p][coluna_p]);
        }
        else
            return INT_MAX;
    }
}

int main()
{
    int **mat, linha, coluna, i, j, res;

    scanf("%d %d", &linha, &coluna);

    mat = (int **)malloc(sizeof(int *) * linha);

    for (i = 0; i < coluna; i++)
        mat[i] = (int *)malloc(sizeof(int) * coluna);

    for (i = 0; i < linha; i++)
        for (j = 0; j < linha; j++)
            scanf("%d", &mat[i][j]);

    res = percurso(mat, linha, coluna, 0, 0, 0);

    if (res < INT_MAX)
        printf("%d", res);
    else
        printf("sem solucao");

    free(mat);

    return 0;
}
