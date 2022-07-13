/*FOR
3) Apresentar os números entre 0 e 4, com intervalo de 0.25 entre eles, separados por tabulação.*/

#include<stdio.h>

int main (void)
{
    int i;
    float x;
    for(i=1; 400>=i; i++)
    {
        if(i%25==0)
        {
            x=float(i)/100;
            printf("%f\n", i);
        }    
    }
    return 0;
}