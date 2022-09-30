#include <iostream>
using namespace std;
/*
int distancia_Manhattan(int *v1, int *v2, int len, int i, int soma)
{
    int r;

    if (i >= len)
        return soma;
    else
        r = distancia_Manhattan(v1, v2, len, i + 1, soma + abs(v1[i] - v2[i]));
// else if (0 > v1[i] - v2[i])
//     r = distancia_Manhattan(v1, v2, len, i + 1, soma - (v1[i] - v2[i]));
// else
//     r = distancia_Manhattan(v1, v2, len, i + 1, soma + (v1[i] - v2[i]));
    return r;
}*/

int manhattan(int v1[], int v2[], int i, int len)
{
    int m;

    if (i >= len)
        return abs(v1[i] - v2[i]);
    else
    {
        m = (i + len);

        return manhattan(v1, v2, i, m) + manhattan(v1, v2, m + 1, len);
    }
}

int main()
{
    int len, *v1, *v2;
    scanf("%d", &len);
    v1 = (int *)malloc(sizeof(int) * len);
    v2 = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
        scanf("%d", &v1[i]);
    for (int i = 0; i < len; i++)
        scanf("%d", &v2[i]);

    printf("%d", manhattan(v1, v2, 0, len));

    return 0;
}