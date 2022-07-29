#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct triangle
{
    int a, b, c;

} triangle;

int square(triangle t)
{
    int a = t.a, b = t.b, c = t.c;
    return (a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c);
}

void sort_by_area(triangle *tr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (square(tr[i]) > square(tr[j]))
            {
                triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));

    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);

    sort_by_area(tr, n);

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);

    return 0;
}