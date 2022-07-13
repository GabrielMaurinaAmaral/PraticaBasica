/*4) Ler o g�nero (F ou f para feminino, M ou m para masculino. Para qualquer outro caractere informar que � inv�lido e finalizar o programa). Se informado um caractere v�lido, ler a altura da pessoa e calcular e mostrar o seu peso ideal, utilizando as seguintes f�rmulas:
a) Para homens: (72.7 * h) - 58;
b) Para mulheres: (62.1 * h) - 44.7.*/


#include<stdio.h>

int main(void)
{
    char g;
    int p, h;
    printf("Informe seu genero(F/M)");
    scanf("%c", &g);

    if(g=='f' || g=='F')
    {
       printf("Informe a sua altura(m):");
       scanf("%d", &h);
       p=(62.1 * h)-44.7;
    }
    else if (g=='m' || g=='M')
    {
       printf("Informe a sua altura(m):");
       scanf("%d", &h);
       p=(72.7 * h) - 58;
    }
    else
    {
       printf("Caractei invalido");
    }

    printf("Seu peso ideala eh %d", p);

 return 0;
}
