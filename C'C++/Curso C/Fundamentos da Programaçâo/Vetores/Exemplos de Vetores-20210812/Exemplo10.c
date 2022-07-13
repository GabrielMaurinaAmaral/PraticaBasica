//Acha o maior e o menor valor em um vetor de inteiros positivos

#include <stdio.h>

int main(void)
{
    int i, vetor[5], maior, menor;

    //Adicionando elementos positivos no vetor
    for(i=0; i<5; i++)
    {
        do //valida o elemento do vetor para ser positivo
        {
            printf("Informe o elemento %d do vetor: ", i);
            scanf("%d", &vetor[i]);

            if(vetor[i] < 0)
            {
                printf("Valor invalido\n");
            }
        }while(vetor[i] < 0);
    }

    maior = vetor[0];
    menor = vetor[0];

    printf("\n==== VETOR ====\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t", vetor[i]);//Imprime na tela o vetor de inteiros positivos

        if(vetor[i] > maior)
        {
            maior = vetor[i];
        }
        else if(vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }

    printf("\n\nMaior valor do vetor: %d\n", maior);
    printf("Menor valor do vetor: %d\n", menor);

    return 0;
}
