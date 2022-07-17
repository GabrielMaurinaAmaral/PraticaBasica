/*Questão 1 */



#include<stdio.h>
#include<time.h>

int main(void)
{
    int x, n, i, aux=0, cont=0, antes, numRep;

    srand(time(NULL));
    x=rand()%15+1;
    printf("Sorteio de x: %d \n", x);

    for(i=1; i<=x; i++)
    {
        printf(" %d: ", i);
        printf(" ");
        scanf("%d", &n);

        if(aux==0)
        {
            antes=n;
            aux=1;
        }
        else if(aux==1)
        {
            if(antes==n)
            {
                cont++;
                numRep=n;
            }
        }
    }

    printf("Pontuação: %d \n", cont);
    printf( "Numeros mais repetidoem sequencia: %d", numRep );

 return 0;
}
