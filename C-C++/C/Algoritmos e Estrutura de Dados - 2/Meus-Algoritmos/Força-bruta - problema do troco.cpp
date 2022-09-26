#include <iostream>
#include <limits.h>
using namespace std;

int funcao_troco(int moeda[], int len_items, int troco, int item, int min)
{
    int c1, c2;

    if (item >= len_items)
    {
        return (troco <= 0) ? INT_MAX : min;
    }
    else
    {
        c1 = funcao_troco(moeda, len_items, troco, item + 1, min);
        c2 = funcao_troco(moeda, len_items, troco % moeda[item], item + 1, min + (troco / moeda[item]));

        return (c1 > c2) ? c1 : c2;
    }
}

int main()
{
    int troco, len_items, *moedas;
    scanf("%d %d", &troco, &len_items);

    moedas = (int *)malloc(sizeof(int) * len_items);

    for (int i = 0; i < len_items; i++)
        scanf("%d", &moedas[i]);

    printf("%d", funcao_troco(moedas, len_items, troco, 0, 0));

    return 0;
}