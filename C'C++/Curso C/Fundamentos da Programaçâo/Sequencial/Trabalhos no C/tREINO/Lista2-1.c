/*1) Ler dois números float e apresentar, sem utilizar funções matemáticas prontas:
a) A divisão do primeiro número pelo segundo, armazenando somente a parte inteira do número.
b) A soma dos dois números com o resultado arredondado para o próximo número inteiro.
Obs.: As variáveis de resultados devem ser do tipo int.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
    float x, y;
    int a;

    printf("Informe o valor de x em float:");
    scanf("%f",&x);
    printf("Informe o valor de y em float:");
    scanf("%f",&y);

    a=x/y;
    printf("%f/%f=%i\n",x, y, a);

    a=ceil(x)+y;
    printf("%f+%f=%i",x,y,a);

    return 0;
}
