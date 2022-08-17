/* Questão 3 (3,3 pontos) – Fazer um programa que lê n números inteiros e informa se os números lidos estão ou não em ordem crescente.
  n é informado pelo usuário e é um valor positivo e maior que 0.
  Caso a sequência não esteja ordenada, o programa deverá interromper o processo de repetição no momento em que a sequência deixar de ser ordenada.
  Além disso, o programa deverá encontrar o maior e o menor elemento da sequência e imprimi-los na tela.
Exemplo da saída: */

#include <stdio.h>

int main(void)
{
    int i, num1, num2, antes, aux = 0, result, menor, maior;

    do
    {
        printf(" Digite a quantidade de repeticao: ");
        scanf("%d", &num1);

    } while (num1 <= 0);

    for (i = 1; i <= num1; i++)
    {
        printf(" Digite um valor %d: ", i);
        scanf("%d", &num2);

        if (aux == 0)
        {
            antes = num2;
            maior = num2;
            menor = num2;
            aux = 1;
        }

        if (num2 >= antes)
        {
            result = 0;
        }
        else if (num2 < antes)
        {
            i = num1 + 1;
            result = 1;
        }

        antes = num2;

        if (num2 > maior)
        {
            maior = num2;
        }
        else if (num2 < menor)
        {
            menor = num2;
        }
    }

    if (result == 0)
    {
        printf(" Sequencia ordenada");
    }

    else if (result == 1)
    {
        printf(" Sequencia nao ordenada");
    }

    printf(" Maior numeros foi %d \n", maior);
    printf(" Maior numeros foi %d ", menor);

    return 0;
}
