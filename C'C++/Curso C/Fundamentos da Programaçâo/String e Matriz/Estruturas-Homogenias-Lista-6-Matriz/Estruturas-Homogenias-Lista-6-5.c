/* Gerar uma matriz 10x2 com valores de 1 a 6. A primeira coluna da matriz é a base e a segunda o expoente. 
   Utilizando a função potência, gerar um vetor que armazena a potência obtida a partir dos valores da matriz. 
   A função potência será utilizada para calcular a potência (base elevada a um expoente) e não para gerar o vetor.
   O valor obtido do cálculo será armazenado no vetor.*/

#include <stdio.h>
#include "Funcoes-Matriz-Lista-6.h"

int main(void)
{
    char opcRepetir, matriz[10][2], l, c, cont, matrizAux[10][2];

    do
    {
        gerarMatrizInteiro(10, 2, matriz, 1, 6);
        printf("\n====MATRIZ====\n");
        mostrarMatrizInteiro(10, 2, matriz);

        for (l = 0; l < 10; l++)
        {
            for (c = 0; c < 2; c++)
            {
                matrizAux[l][c] = matriz[l][c];
            }
        }
 
        printf("\n");
        mostrarMatrizInteiro(10, 2, matrizAux);

        for (l = 0; l < 10; l++)
        {
            for (cont = 1; cont <= matriz[l][2]; cont++)
            {
                matriz[l][1] = matriz[l][1] * matrizAux[l][1];
            }

            printf("\n %d \n", matriz[l][1]);
        }

        printf("Repetir o programa(S/s): ");
        setbuf(stdin, NULL);
        scanf("%d", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}