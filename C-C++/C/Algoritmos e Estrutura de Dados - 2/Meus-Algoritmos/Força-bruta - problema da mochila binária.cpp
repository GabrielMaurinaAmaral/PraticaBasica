#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int capacidade, objetos, mochila = 0;

    scanf("%d %d", &capacidade, &objetos);

    int items[objetos][2];
    float items_maior[objetos], maior = 0.0;

    for (int i = 0; i < objetos; i++)
    {
        scanf("%d %d", &items[i][0], &items[i][1]);
        items_maior[i] = items[i][0] / items[i][1]; 
    }

    for (int i = 0; i < objetos; i++)
    {
        printf("%f\n", items_maior[i]);
        for (int j = 0; j < objetos; j++)
        {
            if (maior < items_maior[j])
            {
                maior = items_maior[j];
                printf("%f\n", maior);
            }
        }
        for (int j = 0; j < objetos; j++)
        {
            if (maior == items_maior[j])
            {
                mochila += items[j][1];
                items_maior[j] = 0;
                j = objetos;
            }
        }
    }

    printf("%d", mochila);
    return 0;
}

int mochila_fb(int c[], int p[], int n, int b, int i, int max)
{
    int c1, c2;

    if (i >= n)
    { // Verificar se todos os objetos foram explorados
        if (b < 0)
            return 0; // se b tiver valor negativo, então será retornado 0, já que a capacidade da mochila foi extrapolada.
        else
            return max; // caso contrário, será retornado o custo máximo acumulado
    }
    else
    {
        c1 = mochila_fb(c, p, n, b, i + 1, max); // o objeto na posição i não foi colocado na solução

        c2 = mochila_fb(c, p, n, b - p[i], i + 1, max + c[i]); // o objeto na posição i foi colocado na solução

        return c1 > c2 ? c1 : c2;
    }
}

int mochila(int c[], int p[], int n, int b)
{
    return mochila_fb(c, p, n, b, 0, 0);
}