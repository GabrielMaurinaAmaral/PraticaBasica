#include <iostream>
using namespace std;

int mochila_bnb(int *peso, int *custo, int len, int capacidade, int item)
{
    int c1, c2;

    if ((capacidade > 0) && (item < len))
    {
        c1 = mochila_bnb(peso, custo, len, capacidade, item + 1);

        if (capacidade - peso[item] >= 0)
            c2 = custo[item] + mochila_bnb(peso, custo, len, capacidade - peso[item], item + 1);
        else
            c2 = 0;

        return c1 > c2 ? c1 : c2;
    }

    return 0;
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

    printf("%d", mochila_bnb(peso, custo, len, capacidade, 0));

    free(peso);
    free(custo);

    return 0;
}