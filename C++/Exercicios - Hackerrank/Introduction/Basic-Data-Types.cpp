#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i;
    long long int l;
    char c;
    float f;
    double d;

    scanf("%d %lld %c %f %lf", &i, &l, &c, &f, &d);
    printf("%d\n%lld\n%c\n%f\n%lf", i, l, c, f, d);

    return 0;
}