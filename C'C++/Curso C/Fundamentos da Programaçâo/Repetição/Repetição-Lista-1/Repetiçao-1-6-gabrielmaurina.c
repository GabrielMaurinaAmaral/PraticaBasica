/*6) Ler dois números que representam os limites de um intervalo e ler o incremento. Mostrar os números desse intervalo de acordo com o incremento indicado e em ordem crescente. O usuário pode informar os valores que representam os limites do intervalo em ordem crescente ou decrescente. Fazer a média dos ímpares e divisíveis por 35 do intervalo.
Exemplo:*/

#include<stdio.h>

int main (void)
{
    int x, y, z, i, cont=0, soma, media;
    printf("Infome o valor inicial do intervalo: ");
    scanf("%d",&x);
    printf("Infome o valor final do intervalo: ");
    scanf("%d",&y);
    printf("Infome o valor do incremento: ");
    scanf("%d",&z);
    
    for (i=x; y<=i && i<=x; i)
        {
        printf("%d\n", i );
        soma=soma+i;
        i=i-z;
        cont++;
    }   

    media=soma/cont;
    printf("Media: %d", media);

 return 0;   
}