#include <stdio.h>

void somaMaisUm(int x);

int main(void)
{
    int num;

    printf("Digite um valor para a variavel num: ");
    scanf("%d", &num);

    printf("\nVariavel num antes de passar pela funcao: %d\n", num);

    somaMaisUm(num);

    printf("Variavel num depois de passar pela funcao: %d\n", num);

    return 0;
}

void somaMaisUm(int x)
{
    x++;
    printf("Variavel num dentro da funcao: %d\n", x);
}
