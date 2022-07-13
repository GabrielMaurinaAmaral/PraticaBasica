/*5) O que faz o algoritmo a seguir:
declare vetA[30], vetB[30], i, j como inteiro
repetir i = 0, até i < 30, passo 1
leia vetA[i]
fim-repetir
repetir i = 0, até i < 30, passo 1
escreva vetA[i]
fim-repetir
j=0;
repetir i = 0, até i < 30, passo 1
se ( vetA[i] % 2 == 0 ) then
vetB[j] ← vetA[i]
j ← j + 1
fim-se
fim-repetir
repetir i = 0, até i < j, passo 1
escreva vetB[j]
fim-repetir
Implemente uma solução na linguagem C para esse algoritmo.*/

#include <stdio.h>

int main(void)
{
    int vetA[30], vetB[30], i, j, k;
    char opcRepetir;

    do
    {
        for (i = 0; i < 30; i++)
        {
            printf("Informe um numero: ", vetA[i]);
            scanf("%d", &vetA[i]);
        }

        printf("\n====VETOR A====\n");
        for (i = 0; i < 30; i++)
        {
            printf(" %2.2d\t ", vetA[i]);
        }

        j = 0;
        for (i = 0; i < 30; i++)
        {
            if (vetA[i] % 2 == 0)
            {
                vetB[j] = vetA[i];
                j = j + 1;
            }
        }

        k = j;
        printf("\n====VETOR B====\n");
        for (i = 0; i < k; i++)
        {
            j--;
            printf(" %2.2d\t ", vetB[j]);
            i++;
        }

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}