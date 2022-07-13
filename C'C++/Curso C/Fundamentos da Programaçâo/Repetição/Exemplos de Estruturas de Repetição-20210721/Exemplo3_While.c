//Tabuada
#include <stdio.h>

int main(void)
{
    int num, cont=0;

    printf("Informe um numero: ");
    scanf("%d", &num);

    while(cont <= 10)
    {
        printf("%d * %d = %d\n", num, cont, num*cont);
        cont++;
    }

    return 0;

}
