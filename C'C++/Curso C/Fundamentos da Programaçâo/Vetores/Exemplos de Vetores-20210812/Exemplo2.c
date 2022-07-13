#include <stdio.h>

int main(void)
{
    int i;
    float notas[5], media=0;

    for(i=0; i<5; i++)
    {
        printf("Digite a nota do aluno %d: ", i);
        scanf("%f", &notas[i]);

        media = media + notas[i];
    }
    media = media / 5;

    printf("\nMedia das notas: %.1f\n", media);

    return 0;
}
