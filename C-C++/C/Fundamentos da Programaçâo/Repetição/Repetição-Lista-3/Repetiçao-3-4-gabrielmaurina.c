/*4) Leia dois valores que representam os limites de um intervalo. O usuário pode informar os valores em ordem crescente ou decrescente.
    Validar para que o programa não aceite valores iguais para os limites do intervalo.
    Mostre os divisíveis por x e não divisíveis por y nesse intervalo. x e y são variáveis informadas pelo usuário.*/

#include<stdio.h>

int main (void)
{
    float inf, sup;
    int x, y, i;

    do
    {
    printf("Informe o limite inferior: ");
    scanf("%f", &inf);
    printf("Informe o limite superior: ");
    scanf("%f", &sup);
    }while(inf==sup);

    printf("Informe o valor de x: ");
    scanf("%d", &x);
    printf("Informe o valor de y: ");
    scanf("%d", &y);

    

    for(i=inf; inf<=i && i<=sup; i++ )
    {
        if(i%x==0 && i%y!=0)
        {
            printf("%d\t", i);
        }
    }
    
 return 0;
}