//Criar um vetor números com 10 elementos inteiros.

#include <stdio.h>

int main(void)
{
    int i, numeros[10], contPares, contImpares;
    float percPares, percImpares;
    char opcao;

    do
    {
        for(i=0; i<10; i++)
        {
            printf("Informe o valor para a posicao %d do vetor: ", i);
            scanf("%d", &numeros[i]);
        }

        contPares=0;
        printf("\n==== PARES ====\n");
        for(i=0; i<10; i++)
        {
            if (numeros[i]%2 == 0)
            {
                contPares++;
                printf("numeros[%d] = %2d <--- %do. nro par\n", i, numeros[i], contPares);
            }
        }

        contImpares=0;
        printf("\n==== IMPARES ====\n");
        for(i=0; i<10; i++)
        {
            if (numeros[i]%2 != 0)
            {
                contImpares++;
                printf("numeros[%d] = %2d <--- %do. nro impar\n", i, numeros[i], contImpares);
            }
        }

        percPares = contPares * 100 / 10.0;
        percImpares = contImpares * 100 / 10.0;
        printf("\nExistem %d numeros pares no vetor, ou seja, %.2f%%", contPares, percPares);
        printf("\nExistem %d numeros impares no vetor, ou seja, %.2f%%\n", contImpares, percImpares);

        printf("\n\nDeseja continuar no programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    }while(opcao == 'S' || opcao == 's');

    return 0;
}
