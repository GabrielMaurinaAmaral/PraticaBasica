#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int resto, soma = 0;

    while (n > 0)
    {
        resto = n % 10;
        soma = soma + resto;
        n = n / 10;
    }

    printf("%d\n", soma);
    return 0;
}