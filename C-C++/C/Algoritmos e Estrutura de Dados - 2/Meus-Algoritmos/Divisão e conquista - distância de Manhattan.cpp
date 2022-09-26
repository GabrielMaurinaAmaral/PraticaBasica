#include <iostream>
using namespace std;

int distancia_Manhattan(int *v1, int *v2, int len, int i, int soma)
{
    int r;

    if (i >= len)
        return soma;
    else if (0 > v1[i] - v2[i])
        r = distancia_Manhattan(v1, v2, len, i + 1, soma - (v1[i] - v2[i]));
    else
        r = distancia_Manhattan(v1, v2, len, i + 1, soma + (v1[i] - v2[i]));

    return r;
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

    printf("%d", distancia_Manhattan(v1, v2, len, 0, 0));

    return 0;
}