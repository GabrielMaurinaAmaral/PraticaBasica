/* Questão 1 (3,3 pontos) - Num sorteio que distribui prêmios, um participante inicialmente sorteia um inteiro x entre os valores 1 e 15 e depois informa n valores inteiros.
   O número de pontos do participante é o tamanho da maior sequência de valores consecutivos iguais. 
   Por exemplo, suponhamos que um participante sorteia x = 11 e informa os n valores nesta ordem: 30; 30; 30; 30; 40; 40; 40; 40; 40; 30; 30. Então, o participante ganha 5 pontos, correspondentes aos 5 valores 40 consecutivos. Note que o participante sorteou 6 valores iguais a 30, mas não são todos consecutivos. São contados apenas os consecutivos. Escreva um programa que sorteie um valor para x e em seguida leia os n valores que correspondem a essa quantidade x. Para se obter o valor de x, em uma faixa de valores entre 1 e 15, deve ser utilizada a função rand(). Os n valores são informados pelo usuário na execução do programa.
   Calcule a pontuação do participante. */

#include <stdio.h>
#include <time.h>

int main(void)
{
    int numRand, num, antes = 0, i, cont = 0, maior = 0, aux = 0, numAux;

    srand(time(NULL));
    numRand = rand() % 15 + 1;
    printf(" sorteio: %d \n", numRand);

    for (i = 1; i <= numRand; i++)
    {
        printf(" %d: ", i);
        scanf("%d", &num);

        if (aux == 0)
        {
            antes = num;
            aux = 1;
        }

        if (num == antes)
        {
            cont++;
        }
        else if (num != antes)
        {
            cont = 0;
            aux = 0;
        }

        if (cont > maior)
        {
            maior = cont;
            numAux = num;
        }

        antes = num;
    }

    printf("Maior sequencia %d foi com o numeor %d ", maior, numAux);

    return 0;
}