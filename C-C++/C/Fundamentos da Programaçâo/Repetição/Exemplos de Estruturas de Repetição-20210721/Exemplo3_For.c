//Tabuada

#include <stdio.h>

int main(void)
{
    int num, cont;

    printf("Informe um numero: ");
    scanf("%d", &num);

    for(cont=0; cont <= 10; cont++)
    {
        printf("%2d * %2d = %2d\n", num, cont, num*cont);
    }

    return 0;
}
