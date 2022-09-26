#include <iostream>
using namespace std;

int mochila_bkt(int *peso, int *custo, int len, int capacidade, int item, int max)
{
    int c1, c2;

    if (capacidade < 0)
        return 0;
    else if (item < len)
    {
        c1 = mochila_bkt(peso, custo, len, capacidade, item + 1, max);
        c2 = mochila_bkt(peso, custo, len, capacidade - peso[item], item + 1, max + custo[item]);

        return c1 > c2 ? c1 : c2;
    }
    else
        return max;
}

int main()
{
    int item, len, capacidade;
    int *peso, *custo;

    scanf("%d", &capacidade);
    scanf("%d", &len);

    peso = (int *)malloc(sizeof(int) * len);
    custo = (int *)malloc(sizeof(int) * len);

    for (item = 0; item < len; item++)
        scanf("%d %d", &peso[item], &custo[item]);

    printf("%d", mochila_bkt(peso, custo, len, capacidade, 0, 0));

    free(peso);
    free(custo);
    return 0;
}
