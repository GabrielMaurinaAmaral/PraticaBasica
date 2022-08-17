#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n, soma = 0;
    scanf("%d", &n);
    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        soma += v[i];
    }
    printf("%d", soma);

    return 0;
}