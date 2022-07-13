/*Questão 2 (3,4 pontos)*/
#include<stdio.h>

int main(void)
{
    int i, contTotal=0, contMinu=0, porc;
     char caracter;
    do
    {
         printf("Informe um numero");
         scanf("%c", &caracter);

         contTotal++;

         if('a' || 'b'|| 'c'||'d'||'e'||'f'||'g' || 'h'|| 'i'||'j'||'k'||'l'|| 'm'|| 'n'||'o'||'p'||'q'||'r' || 's'|| 'u'||'v'||'w'||'y'||'x'||'z')
         {
             contMinu++;
         }

    }while(caracter!=0);

    porc=100*((float)contMinu/contTotal);
    printf("Pencentual de minusculas: %0.2f", porc);

 return 0;
}
