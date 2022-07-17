#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void num(int *pa, int *pb, int *pc)
{
    *pc = abs(*pa - *pb);
    *pa = (*pa + *pc);
    *pb = (*pb - *pc);
}

int main()
{
    int a, b, c, *pa = &a, *pb = &b, *pc = &c;

    scanf("%d %d", pa, pb);
    num(pa, pb, pc);

    printf("A=%d B=%d C=%d", a, b, c);

    return 0;
}
