/*3) Dado um vetor de n números reais, informar os elementos que compõem o vetor e o número de vezes que
cada um deles ocorre no vetor. Sugestão: Ordenar o vetor antes de verificar a ocorrência dos elementos no
mesmo.*/

#include <stdio.h>

void ordenaVetor(int vetor[], int tam)
{
    int aux, i, j;
    for (j = tam - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

int main(void)
{
    int aux;

    printf(" Informe a quantidade de elementos da matriz: ");
    scanf("%d", &aux);

    int i, j, cont;
    float vetor[aux];

    for (i = 0; i < aux; i++)
    {
        printf(" Valor do elementos %d do vetor: ", i);
        scanf("%f", &vetor[i]);
    }

    printf("\n=====VETOR====\n");
    for (i = 0; i < aux; i++)
    {
        printf(" %0.2f\t ", vetor[i]);
    }

    printf("\nVetor em ordem\n");
    ordenaVetor(vetor, aux);
    for (i = 0; i < aux; i++)
    {
        printf("%0.2f\t ", vetor[i]);
    }

    cont = 0;
    printf("\n");
    for (i = 0; i < aux; i++)
    {
        for (j = 0; j < aux; j++)
        {
            if (vetor[i] == vetor[j])
            {
                cont++;
            }
        }

        cont = 0;
    }

    int a = 0;
    printf("\n");
    for (i = 0; i < aux; i++)
    {
        if (a == 0)
        {
            if (vetor[i] != vetor[i + 1])
            {
                printf(" %0.2f vez %d\n ", vetor[i], cont);
                a = 1;
            }
        }

        else if (vetor[i] != vetor[i - 1])
        {
            printf(" %0.2f vez %d\n ", vetor[i], cont);
        }
    }
    return 0;
}