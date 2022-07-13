/*5) O que faz o algoritmo a seguir?

declare valor, maior como inteiro
leia valor
maior ← valor
para j = 0 até j < 4 passo 1
leia valor
se valor > maior então
maior ← valor
fim-se
fim-para
escreva maior

Implemente o algoritmo utilizando a linguagem C.
Responda: Como alterar o algoritmo para não ser necessário fazer uma leitura do valor antes da estrutura for?*/

#include<stdio.h>

int main (void)
{
    for(j=0; j<4; j++)
    {
        printf("Informe um valor: ");
        scanf("%d", &num);

        if(num> maior)
        {
            maior=num;
        }
    } 

    printf("%d", maior);
}