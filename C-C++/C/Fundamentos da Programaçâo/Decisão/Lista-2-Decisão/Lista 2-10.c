/*10) Faça um programa que solicite ao usuário o valor do salário de um funcionário e apresente o menu a seguir e permita ao usuário escolher a opção desejada e mostre o resultado. Verifique a possibilidade de opção inválida e não se preocupe com restrições, como salário negativo. Use switch - case, if e if - else para a solução.*/

#include<stdio.h>

int main(void)
{
    int num;
    float salario;
    printf("Menu de opcoes \n");
    printf("1 = Imposto \n");
    printf("2 = Novo salario \n");
    printf("3 = Classificacao \n");
    printf ("Escolha uma nas opcoes: ");
    scanf("%d", &num);
    printf("Informe seu salario: ");
    scanf("%f", &salario);

    switch(num)
    {
          case 1:
          {
              if(salario>1000)
              {
                  printf("Imposto sobre o salario:%0.2f", (salario*1.05)-salario);
              }
              else if(salario>=1000 && salario<=1500)
              {
                  printf("Imposto sobre o salario:%0.2f", (salario*1.1)-salario);
              }
              else
              {
                  printf("Imposto sobre o salario:%0.2f", (salario*1.15)-salario);
              }
              break;
          }

          case 2:
          {
              if(salario>1000)
              {
                  printf("Valor sobre o novo salario eh %0.2f", salario+75);
              }
              else if(salario>=1000 && salario<=1500)
              {
                  printf("Valor sobre o novo salario eh %0.2f", salario+100);
              }
              else
              {
                  printf("Valor sobre o novo salario eh %0.2f", salario+150);
              }
              break;
          }

          case 3:
          {
              if(salario<=1000)
              {
                  printf("Categoria A");
              }
              else
              {
                  printf("categoria B");
              }
              break;
          }
          default:
          {
              printf("opcao incorreta");
          }

    }
 return 0;
}
