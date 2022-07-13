/*Questão 3 (3,3 pontos) – Fazer um programa que lê n números inteiros e informa se os números lidos estão ou não em ordem crescente. n é informado pelo usuário e é um valor positivo e maior que 0. Caso a sequência não esteja ordenada, o programa deverá interromper o processo de repetição no momento em que a sequência deixar de ser ordenada. Além disso, o programa deverá encontrar o maior e o menor elemento da sequência e imprimi-los na tela.*/

#include <stdio.h>

int main(void)
{
    int i, n, atual, anterior, ordenado=1, maior, menor;

    do //validação de n
    {
        printf("Digite o valor de n: ");
        scanf("%d", &n);

        if(n < 0)
        {
            printf("Valor invalido\n");
        }
    }while(n < 0);

    printf("\nInforme o valor 1: "); //solicita o primeiro valor da sequência
    scanf("%d", &anterior);

    maior = anterior; //inicializa a variável maior com o primeiro valor da sequência
    menor = anterior; //inicializa a variável menor com o primeiro valor da sequência

    i = 2; //inicializa i com 2 pois o primeiro valor da sequência já foi solicitado
    ordenado = 1; //considera que a sequência está ordenada

    while(i <= n)
    {
        printf("Informe o valor %d: ", i); //solicita o próximo valore grava em atual
        scanf("%d", &atual);

        if(atual > maior) //se atual for maior que maior, maior armazena atual
        {
            maior = atual;
        }
        else if(atual < menor) //se atual for menor que menor, menor armazena atual
        {
            menor = atual;
        }

        if(atual < anterior) //significa que a sequência não está ordenada
        {
           ordenado = 0;
           break; //sai da estrutura de repetição
        }

        anterior = atual; //atualiza o valor de anterior
        i++;
    }
    if(ordenado == 1)
    {
        printf("Sequencia ordenada!\n");
    }
    else
    {
        printf("Sequencia nao ordenada!\n");
    }

    printf("\nMaior valor da sequencia: %d\n", maior);
    printf("Menor valor da sequencia: %d\n", menor);

    return 0;
}
