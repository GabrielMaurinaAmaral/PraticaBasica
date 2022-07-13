#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct fracao
{
    int num;
    int den;
}fracao;

int main() 
{
    fracao a, b, c;
    
    scanf("%d %d", &a.num, &a.den);    
    scanf("%d %d", &b.num, &b.den);    

    c.num=a.num*b.den;
    c.den=b.num*a.den;
    printf("%d %d", c.num, c.den);
        
    return 0;
}
