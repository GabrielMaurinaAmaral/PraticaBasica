#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void frac(float num, int *pont_i, float *pont_j)
{
    *pont_i = num;
    *pont_j = num - *pont_i;
}

int main()
{
    int tam, i, *pont_i = &i;
    float num, j, *pont_j = &j;

    cin >> tam;

    for (int k = 0; k < tam; k++)
    {
        cin >> num;
        frac(num, pont_i, pont_j);
        printf("N=%.3f I=%d F=%.3f\n", num, i, j);
    }

    return 0;
}
