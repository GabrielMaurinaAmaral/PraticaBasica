#include <stdio.h>

int main(void)
{
    int i;

	//declaração dos vetores
    int vetA[10], vetB[10];

	//atribuição por entrada de dados
	 for(i=0; i<10; i++)
     {
         printf("Informe um valor para a posicao %d do vetor: ", i);
         scanf("%d", &vetA[i]);
     }

	//atribuição por operação de valor de outro vetor
	for(i=0; i<10; i++)
    {
        vetB[i] = vetA[i] * 2;
    }

	//saída de dados
	for(i=0; i<10; i++)
    {
        printf("%d\t", vetB[i]);
    }

	return 0;
}
