#include <iostream>
using namespace std;

int mochila_forca_bruta(int peso[], int custo[], int len_items, int capacidade, int item, int max)
{
    int c1, c2;

    if (item >= len_items)
        return (capacidade < 0) ? 0 : max;
    else
    {
        c1 = mochila_forca_bruta(peso, custo, len_items, capacidade, item + 1, max);
        c2 = mochila_forca_bruta(peso, custo, len_items, capacidade - peso[item], item + 1, max + custo[item]);

        return (c1 > c2) ? c1 : c2;
    }
}

int main()
{
    int capacidade, len_items, *peso, *custo;
    scanf("%d %d", &capacidade, &len_items);

    peso = (int *)malloc(sizeof(int) * len_items);
    custo = (int *)malloc(sizeof(int) * len_items);

    for (int i = 0; i < len_items; i++)
        scanf("%d %d", &peso[i], &custo[i]);

    printf("%d", mochila_forca_bruta(custo, peso, len_items, capacidade, 0, 0));

    free(peso);
    free(custo);

    return 0;
}