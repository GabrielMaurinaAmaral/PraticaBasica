#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
    int v[3] = {b, c, d}, maior = a;
    for (int i = 0; i < 3; i++)
        if (maior < v[i])
            maior = v[i];

    return maior;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}