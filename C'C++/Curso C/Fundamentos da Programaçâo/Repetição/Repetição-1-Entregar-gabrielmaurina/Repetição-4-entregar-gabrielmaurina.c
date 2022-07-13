/*) Apresentar os números primos entre dois valores, que r epresentam os limites inferior e superior,
respectivamente, de um intervalo, informados pelo usuário. Apresentá los com n números por linha. n é
informado pelo usuário. Validar n para que seja maior que 0. Validar o limite inferior para seja maior que 1 e o
limite superior para que seja maior ou igual ao limite inferior. Implementar a repetição de programa.
Exemplo de entrada e saída:*/

#include <stdio.h>

int main(void)
{
    int inf, sup, i, linha, contPrimo = 0, k, contDiv, aux;
    char opc;

    do
    {
        do
        {
            printf("Informe o limite inferior: ");
            scanf("%d", &inf);
            if (inf <= 1)
            {
                printf("Limite inferior deveser maior que 0\n");
            }

        } while (inf <= 1);

        do
        {
            printf("Informe o limite superior: ");
            scanf("%d", &sup);
            if (inf >= sup)
            {
                printf("Limite superior deveser maior qou igual ao limite inferior\n");
            }

        } while (inf >= sup);

        do
        {
            printf("Informe quantos numeros que imprimir na linha: ");
            scanf("%d", &linha);


        } while (linha <= 0);

        for (i = inf; i <= sup; i++)
        {
            contDiv = 0;

            for (k = 1; k <= i; k++)
            {
                if (i % k == 0)
                {
                    contDiv++;
                }
            }

            if (contDiv == 2)
            {
                printf("%5.d ", i);
                contPrimo++;

                if (contPrimo % linha == 0)
                {
                    printf("\n");
                }
            }  
        }

    setbuf(stdin, NULL);
    printf("\nDeseja repetir o programa: ");
    scanf("%c", &opc);
    
    }while (opc == 'S' || opc == 's');

 return 0;
}