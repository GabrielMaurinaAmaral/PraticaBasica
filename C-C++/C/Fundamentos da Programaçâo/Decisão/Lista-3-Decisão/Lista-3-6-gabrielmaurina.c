/*8) Implemente um programa que adivinhe o "número mágico" entre 0 e 10. O programa deverá imprimir a mensagem "Certo! %d é o número mágico" quando o jogador acerta o número mágico, a mensagem "Errado, muito alto", caso o jogador tenha digitado um número maior que o número mágico e a mensagem "Errado, muito baixo", caso o jogador tenha digitado um número menor que o número mágico. O número mágico é produzido usando o gerador de números randômicos de C (função rand(), que exige o uso da biblioteca stdlib.h).*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
    int x, y, i;
    printf("Voce tem 10 tentativas\n");
    printf("Adivinhe qual eh o numero de 1 a 100\n");
   
    srand(time(NULL));
    y = (rand() %100)+1;   

    for(i=1; i<=10; i++)
    {
        printf("digite um numero: ");
        scanf("%d",&x);
        
        if(x==y && x<=100 && x>=1)
        {
            printf("voce acertou o numnero era %d parNabens", y);
            i=11;
        }
        else if(x<y  && x<=100 && x>=1)
        {
            printf("errado, muito baixo\n");
        }
        else if(x>y && x<=100 && x>=1)
        {
            printf("errado, muito alto\n");
        }
        else 
        {
            printf("esse numero nao esta entre 1 e 100\n");
        }
    }
    return 0;
}