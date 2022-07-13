#include <stdio.h>

int calculaFatorial(int x)
{
    int fat=1, i;

    for(i=x; i>=2; i--)
    {
        fat = fat * i;
    }

    return fat;
}

int mostraFatorial(int x, int fat)
{
    int i;

    printf("%d! = ", x);

    for(i=x; i>=2; i--)
    {
        printf("%d * ", i);
    }

    printf("1 = %d\n", fat);
}

int main(void)
{
    int num, i;

    //Calcula o fatorial de um número
    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Fatorial do numero: %d\n", calculaFatorial(num));

    printf("\nFatorial de 1 a 10\n");
    for(i=1; i<=10; i++)
    {
        mostraFatorial(i, calculaFatorial(i));
    }

    return 0;
}
