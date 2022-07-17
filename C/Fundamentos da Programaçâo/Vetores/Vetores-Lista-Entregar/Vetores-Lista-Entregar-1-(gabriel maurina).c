/*1) Ler a altura de 5 pessoas, armazenar em um vetor. Validar para que seja informado um valor positivo para a altura.
     Identificar e mostrar a maior altura e o índice do vetor que essa altura corresponde. 
     Calcular a média das alturas acima de 1,50 e mostrar essa média. 
    Validar para que não seja realizada uma divisão por zero no cálculo da média.*/

#include <stdio.h>

int main(void)
{
    int i = 4, posicao, contAlturaMaior;
    float vetorAltura[i], maior, somaAltura;
    char opcRepetir;

    do
    {
        maior = 0;
        somaAltura = 0;
        contAlturaMaior = 0;

        for (i = 4; i >= 0; i--)
        {
            do
            {
                printf("\n Informe a altura da pessoa %d: ", i + 1);
                scanf("%f", &vetorAltura[i]);

            } while (vetorAltura[i] <= 0);

            if (vetorAltura[i] > maior)
            {
                maior = vetorAltura[i];
                posicao = i;
            }

            if (vetorAltura[i] > 1.50)
            {
                somaAltura = somaAltura + vetorAltura[i];
                contAlturaMaior++;
            }
        }

        printf("\n Maior altura do grupo eh %0.2f esta na posicao %d", maior, posicao);
        printf("\n Medias das alturas maior que 1.50: %0.2f\n", somaAltura / contAlturaMaior);

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}