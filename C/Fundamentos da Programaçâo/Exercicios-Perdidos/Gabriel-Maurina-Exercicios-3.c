/*Questão 3 (3,3 pontos)*/
#include<stdio.h>

int main(void)
{
    int n, i=1, num, aux=0, cont=0, antes, maior=0, menor=0;
    do
    {

        printf("Digite o valor de n: ");
        scanf("%d", &n);

    }while(n<=0);

    do
    {
        printf("informe o valor: ");
        scanf("%d", &num);

        if(antes<num)
        {
            i++;
            cont++;
        }
        else
        {
            i=n+1;
        }

        antes=num;

        if(i==2)
        {
            menor=num;
        }
        if(i==n+1)
        {
            maior=num;
        }

    }while(i<=n);

    if(cont%n==0)
    {
        printf("Sequencia ordenada\n");
    }
    else if(cont%n!=0)
    {
        printf("Sequencia nao ordenada\n");
    }

    printf("Maior numero da sequencia: %d \n", maior);
    printf("Menor numero da sequencia: %d", menor);

 return 0;
}
