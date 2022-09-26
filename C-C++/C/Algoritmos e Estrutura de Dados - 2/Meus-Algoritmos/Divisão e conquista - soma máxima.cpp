#include <iostream>
using namespace std;

int soma_maxima(int *v, int len, int i, int soma)
{
    int r;

    if (i >= len)
        return soma;
    else if (v[i] < 0)
        r = soma_maxima(v, len, i + 1, soma);
    else
        r = soma_maxima(v, len, i + 1, soma + v[i]);

    return r;
}

int main()
{
    int len, *vetor;
    scanf("%d", &len);
    vetor = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("%d", soma_maxima(vetor, len, 0, 0));

    return 0;
}