/*7) O que faz o algoritmo a seguir?
declare i, s como inteiro
s ← 0
repetir i = 0 até i < 10 passo 1
            s ← s + i
fim-repetir
escreva s
Implemente o algoritmo utilizando a linguagem C.
Responda: Por que a variável s foi inicializada com 0?*/

#include<stdio.h>

int main (void)
{
    int i, s=0;

    for(i=0; i<10; i++)
    {
        s=s+i;
    }

    printf(" %d", s);

  return 0;  
}