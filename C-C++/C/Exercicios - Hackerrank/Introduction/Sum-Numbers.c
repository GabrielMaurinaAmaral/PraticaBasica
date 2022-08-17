#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    float num3, num4;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%f", &num3);
    scanf("%f", &num4);

    printf("%i %i\n", num1 + num2, num1 - num2);
    printf("%0.1f %0.1f", num3 + num4, num3 - num4);

    return 0;
}