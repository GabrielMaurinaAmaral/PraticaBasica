#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int recursividade(int num1, int num2)
{
    if (num2 == 0)
    {
        return 1;
    }
    else if (num2 == 1)
    {
        return num1 * num2;
    }

    return num1 * recursividade(num1, num2 - 1);
}

int main()
{
    int num1, num2;

    scanf("%d %d", &num1, &num2);
    printf("%d", recursividade(num1, num2));

    return 0;
}