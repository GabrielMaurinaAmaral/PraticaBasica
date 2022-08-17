#include <stdio.h>

int main(void)
{
    float nota0, nota1, nota2, nota3, nota4, media;

    printf("Digite a nota do aluno 1: ");
    scanf("%f", &nota0);
    printf("Digite a nota do aluno 2: ");
    scanf("%f", &nota1);
    printf("Digite a nota do aluno 3: ");
    scanf("%f", &nota2);
    printf("Digite a nota do aluno 4: ");
    scanf("%f", &nota3);
    printf("Digite a nota do aluno 5: ");
    scanf("%f", &nota4);

    media = (nota0 + nota1 + nota2 + nota3 + nota4)/5;

    printf("\nMedia das notas: %.1f\n", media);

    return 0;
}
