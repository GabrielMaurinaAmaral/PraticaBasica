/*8) Faça um programa que leia três notas de um aluno e calcule a média ponderada, com os pesos 1, 3 e 4,
respectivamente, e:
a) Se a média obtida está entre 6 a 10 informar que o aluno está aprovado;
b) Se a média obtida está entre 4 e 5,9 informar que o aluno está em recuperação. Nesse caso, ler a nota de
recuperação e calcular a média final (que é a média entre a média anual e a nota de recuperação);
b.1) Se a média final é menor que 5 informar que o aluno está reprovado após recuperação;
b.2) Se é igual ou maior que 5 informar que o aluno está aprovado após recuperação;
c) Se a média obtida é menor que 4 informar que o aluno está reprovado antes da recuperação.*/

#include<stdio.h>

int main(void)
{
    int x, y, z, w;
    float a, b;
    printf("Primeira nota: ");
    scanf("%d",&x);
    printf("Segunda nota: ");
    scanf("%d",&y);
    printf("Terceira nota: ");
    scanf("%d",&z);

    a=(float)(x+(y*3)+(z*4))/8;

    if(a>=6 && a<=10)
    {
        printf("Aluno aprovado");
    }
    if(a>=4 && a<6)
    {
        printf("Aluno esta de recuperacao\n");
        printf("Nota da Recuperacao: ");
        scanf("%d", &w);

        b=(w+a)/2;

        if(b<5)
        {
            printf("Aluno reprovado");
        }
        else if(b>=5)
        {
            printf("Aluno aprovado");
        }
    }
    if(a<4)
    {
         printf("Aluno reprovado");
    }



 return 0;
}
