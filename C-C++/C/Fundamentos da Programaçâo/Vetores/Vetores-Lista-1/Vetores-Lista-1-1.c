/*1) Ler 10 números inteiros e armazenar em um vetor. Validar as entradas para que sejam informados valores positivos. Em listagens separadas:
a) Mostrar e contar os valores pares do vetor;
b) Mostrar os valores do vetor que divisíveis por 3 e por 5, contar a quantidade deles e mostrar essa quantidade.
c) Mostrar e contar os valores do vetor que são menores que 10 ou maiores do que 100.
d) Mostrar e contar os valores do vetor que são maiores que 10 e os menores que 100.
e) Mostrar os ímpares e a quantidade de ímpares. Calcular o percentual dos ímpares em relação a quantidade total de números.
O programa permanecerá em execução até que seja escolhida a opção sair.
Exemplo:*/

#include <stdio.h>

int main(void)
{
    int num1[9], i, contPar, contDiv3e5, contC, contD, contImpar;
    char opcRepetir;

    do
    {
        contPar = 0;
        contDiv3e5 = 0;
        contC = 0;
        contD = 0;
        contImpar = 0;

        for (i = 0; i <= 9; i++)
        {
            do
            {
                printf("Informe o numero que esta na posicao %d: ", i);
                scanf("%d", &num1[i]);

            } while (num1[i] < 0);
        }

        printf("\n===NUMEROS PAR===\n");
        for (i = 0; i <= 9; i++)
        {
            if (num1[i] % 2 == 0)
            {
                printf(" %d\t", num1[i]);
                contPar++;
            }
        }
        printf("\n Quantidae de numeros pares no vetor: %d\n", contPar);

        printf("\n===NUMEROS DIVISIVEIS PO 3 E 5===\n");
        for (i = 0; i <= 9; i++)
        {
            if (num1[i] % 3 == 0 && num1[i] % 5 == 0)
            {
                printf(" %d\t", num1[i]);
                contDiv3e5++;
            }
        }
        printf("\n Quantidae de numeros divisiveis por 3 e 5 no vetor: %d\n", contDiv3e5);

        printf("\n===MENORE QUE 10 E MAIORES QUE 100===\n");
        for (i = 0; i <= 9; i++)
        {
            if (num1[i] < 10 || num1[i] > 100)
            {
                printf(" %d\t", num1[i]);
                contC++;
            }
        }
        printf("\n Quantidae de numeros menor que 10 e maior que 100 no vetor: %d\n", contC);

        printf("\n===NUMEROS ENTRE 10 E 100===\n");
        for (i = 0; i <= 9; i++)
        {
            if (num1[i] > 10 && num1[i] < 100)
            {
                printf(" %d\t", num1[i]);
                contD++;
            }
        }
        printf("\n Quantidae de numeros entre 10 e 100 no vetor: %d\n", contD);

        printf("\n===NUMEROS IMPAR===\n");
        for (i = 0; i <= 9; i++)
        {
            if (num1[i] % 2 != 0)
            {
                printf(" %d\t", num1[i]);
                contImpar++;
            }
        }
        printf("\nQuantidade de numeros impars: %d\n", contImpar);

        printf("\nDeseja repetir o programa(s/S): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 's' || opcRepetir == 'S');

    return 0;
}