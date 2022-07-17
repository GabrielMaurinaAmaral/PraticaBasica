#include <stdio.h>
#include "minhas_funcoes.h"

int main(void)
{

    int num, i;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Quadrado do numero: %d\n", quadrado(num));

    printf("\nNUMERO\tQUADRADO\n");
    for(i=1; i<=15; i++)
    {
        printf("%d\t%d\n", i, quadrado(i));
    }

    return 0;
}
