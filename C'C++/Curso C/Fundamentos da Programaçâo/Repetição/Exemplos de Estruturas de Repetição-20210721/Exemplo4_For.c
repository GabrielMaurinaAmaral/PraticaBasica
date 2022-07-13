//Incremento e decremento.

#include <stdio.h>

int main(void)
{
    int X, Y;

    for(X=0, Y=10; X<=10 && Y>=0; X++, Y--)
    {
        printf("X = %d\t Y = %d\n", X, Y);
    }

    return 0;
}
