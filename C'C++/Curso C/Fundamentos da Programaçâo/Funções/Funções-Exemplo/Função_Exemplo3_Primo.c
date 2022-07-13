#include <stdio.h>

int primo(int x);

int main(void)
{
    int num, i;

    //Verifica se o número é primo
    printf("Digite um numero: ");
    scanf("%d", &num);

    if(primo(num) == 0)
    {
        printf("%d eh primo\n", num);
    }
    else
    {
        printf("%d nao eh primo\n", num);
    }

    printf("\nPrimos no intervalo de 1 ate %d\n", num);
    for(i=1; i<=num; i++)
    {
        if(primo(i) == 0)
        {
            printf("%d\t", i);
        }
    }

    return 0;
}

int primo(int x)
{
    int i, contDiv=0;

    for(i=2; i<x; i++)
    {
        if(x%i == 0)
        {
            contDiv++;
            break;
        }
    }
    return contDiv;
}
