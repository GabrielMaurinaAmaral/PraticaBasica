/*2) Faça um programa que apresente o menu a seguir e permita ao usuário escolher a opção desejada, receba os dados necessários para executar a operação e mostre o resultado.
Menu de opções:
1 – Mostra os números em ordem crescente
2 – Mostra os números em ordem decrescente
3 - Mostra os números que são múltiplos de 2
Digite a opção desejada:*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main (void)
{   
    int opcao, x, y, z;
    printf("1 = Mostra os numeros em ordem crescente\n");
    printf("2 = Mostra os numeros em ordem decrescente\n");
    printf("3 = Mostra os numeros que sao multiplos de 2\n");
    printf("Digite a opcao desejada:");
    scanf("%d", &opcao);
    printf("Informe o primeiro numero:");
      scanf("%d", &x);
      printf("Informe o segundo numero:");
      scanf("%d", &y);
      printf("Informe o terceiro numero:");
      scanf("%d", &z);
    opcao=

    switch (opcao)
    {

      case 1:
          if(x<y && y<z)
          {
              printf("%d, %d, %d", x, y, z);
          }
          else if(x<z && z<y)
          {
              printf("%d, %d, %d", x, z, y);
          }
          else if(y<x && x<z)
          {
              printf("%d, %d, %d", y, x, z);
          }
          else if(y<z && z<x)
          {
              printf("%d, %d, %d", y, z, x);
          }
          else if(z<x && x<y)
          {
              printf("%d, %d, %d", z, x, y);
          }
          else
          {
              printf("%d, %d, %d", z, y, x);
          }
        break;
    
      case 2:
      
          if(x>y && y>z)
          {
              printf("%d, %d, %d", x, y, z);
          }
          else if(x>z && z>y)
          {
              printf("%d, %d, %d", x, z, y);
          }
          else if(y>x && x>z)
          {
              printf("%d, %d, %d", y, x, z);
          }
          else if(y>z && z>x)
          {
              printf("%d, %d, %d", y, z, x);
          }
           else if(z>x && x>y)
          {
              printf("%d, %d, %d", z, x, y);
          }
          else
          {
              printf("%d, %d, %d", z, y, x);
          }
        break;

      case 3:
          if((x%2)!=0 && (z%2)!=0 && (y%2)!=0 )
          {
              printf("Nem um dos numeros eh multiplo de 2");
          }
          else if ((x%2)==0 && (z%2)==0 && (y%2)==0)
          {
               printf("Sao multiplos de 2 o %d, %d e %d", x, y, z);
          }
          
          else
          {
              printf("Sao multiplos de 2 apenas ");

            if((x%2)==0 ) 
            {
                printf("%d,  ", x);
            }
            if((y%2)==0 ) 
            {
                printf("%d,  ", y);
            }
            if((z%2)==0 ) 
            {
                printf("%d,  ", z);
            }
          }
        break;

    default:
        printf("Opcao Invalida");  
     
         
    }
  
  return 0;  
}