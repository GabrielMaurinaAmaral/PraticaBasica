#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int f;

} Real;

Real *criar(int i, int f)
{
    Real *r = (Real *)malloc(sizeof(Real));

    r->i = i;
    r->f = f;

    return r;
}

void imprimir(Real *r)
{
    if (r->f < 10)
    {
        printf("%d.0%d\n", r->i, r->f);
    }
    else
    {
        printf("%d.%d\n", r->i, r->f);
    }
}

Real *soma(Real *r1, Real *r2)
{
    Real *r = (Real *)malloc(sizeof(Real));

    r->f = r1->f + r2->f;
    r->i = r1->i + r2->i;

    if (r->f > 99)
    {
        r->i++;
        r->f -= 100;
    }

    return r;
}

Real *subtracao(Real *r1, Real *r2)
{
    Real *r = (Real *)malloc(sizeof(Real));

    r->f = r1->f - r2->f;
    r->i = r1->i - r2->i;

    return r;
}

int arredondar(Real *r)
{
    int n;

    n = r->i + 1;

    return n;
}
int main()
{
    Real *r1, *r2, *r;
    int f, i;

    scanf("%d %d", &i, &f);
    r1 = criar(i, f);
    imprimir(r1);

    scanf("%d %d", &i, &f);
    r2 = criar(i, f);
    imprimir(r2);

    r = criar(0, 0);

    r = soma(r1, r2);
    imprimir(r);

    r = subtracao(r1, r2);
    imprimir(r);

    i = arredondar(r1);
    f = arredondar(r2);
    printf("%d %d", i, f);

    return 0;
}
