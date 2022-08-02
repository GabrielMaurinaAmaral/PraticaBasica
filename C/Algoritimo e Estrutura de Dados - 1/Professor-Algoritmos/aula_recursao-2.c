#include <stdio.h>

int fatorial_it(int n)
{
    int i, aux = 1;

    for (i = n; i > 0; i--)
    {
        aux *= i;
    }

    return aux;
}

int fatorial_rec(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    else
    {
        return n * fatorial_rec(n - 1);
    }
}

int fib(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    printf("===> iterativo: %d\n", fatorial_it(5));
    printf("===> iterativo: %d\n", fatorial_rec(5));
    printf("==> %d\n", fib(8));

    return 0;
}