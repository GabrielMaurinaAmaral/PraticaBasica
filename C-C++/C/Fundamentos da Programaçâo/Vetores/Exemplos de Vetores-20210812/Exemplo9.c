//Soma elementos de um vetor de inteiros positivos

#include <stdio.h>

int main(void)
{
    int i, vetor[5], soma=0;

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

    printf("\n==== VETOR ====\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t", vetor[i]);//Imprime na tela o vetor de inteiros positivos
        soma = soma + vetor[i]; //soma os elementos do vetor
    }

    printf("\n\nSoma dos elementos do vetor: %d\n", soma);

    return 0;
}
