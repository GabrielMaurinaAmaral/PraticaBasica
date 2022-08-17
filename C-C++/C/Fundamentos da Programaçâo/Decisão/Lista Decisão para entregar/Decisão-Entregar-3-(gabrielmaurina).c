
/*3) A figura a seguir representa uma árvore de decisão para identificar se um paciente está saudável ou doente. Elabore um programa que implementa essa árvore de decisão.*/

#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void)
{
    char x, y;
    int num;
    printf("PacieNte se sente bem(S/s/N/n):");
    scanf("%c",&x);

    if(x=='S' || x=='s')
    {
        printf("Paciente saudavel");  
    }
    else if(x=='N' || x=='n')
    {

        setbuf(stdin,NULL);

        printf("Paciente tem dorn(S/s/N/n):");
        scanf("%c",&y);

        if(y=='S' || y=='s')
        {
            printf("Doente");
        }
        else if(y=='N' || y=='n')
        {
            printf("Qual a temperatura do paciente (celsius):");
            scanf("%d",&num);

            if(num<=37)
            {
                printf("Saudavel");
            }
            else if
            {
                printf("Doente");
            }
        }
        else
        {
            printf("caracter errado");
        }
    }
    else
    {
        printf("caracter errado");
    }
    
 return 0;
}

