#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frac(float n, int *pi, float *pf)
{
    *pi = n;
    *pf = n - *pi;
}

int main()
{
    int j, i, *pi = &i;
    float n, f, *pf = &f;
    scanf("%d", &j);

    for (int k = 0; k < j; k++)
    {
        scanf("%f", &n);
        frac(n, pi, pf);
        printf("N=%.3f I=%d F=%.3f\n", n, i, f);
    }

    return 0;
}
