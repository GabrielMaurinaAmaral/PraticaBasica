/*4) Um ano é bissexto se for divisível por 4 e não for divisível por 100. Também são bissextos os divisíveis por 400. Escreva um programa que determina se um ano informado pelo usuário é bissexto.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
    int x;
    printf("Informe um ano: ");
    scanf("%d",&x);

    if (x%4==0 && x%100!=0)
    {
        printf("O ano informado eh bissesxo");
    }   
    else if (x%4==0 && x%100==0 && x%400==0)
    {
        printf("O ano informado eh bissesxo");
    }
    else 
    {
        printf("O ano informado nao eh bissesxo");
    } 

}