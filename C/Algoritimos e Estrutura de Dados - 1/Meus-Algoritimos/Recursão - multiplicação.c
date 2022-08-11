#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int multiplicacao(int num1, int num2)
{
    if (num2 == 1)
    {
        return num1;
    }

    return num1 + multiplicacao(num1, num2 - 1);
}

int main()
{
    int num1, num2;

    scanf("%d %d", &num1, &num2);
    printf("%d", multiplicacao(num1, num2));

    return 0;
}