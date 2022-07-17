/*1) O c�digo a seguir tem o objetivo de obter o resto da divis�o do n�mero maior pelo menor informados (independentemente da ordem informada) e informar que n�o � poss�vel realizar a divis�o caso o divisor seja zero. Fa�a os ajustes necess�rios no c�digo para que esses objetivos sejam alcan�ados.*/

#include <stdio.h>
int main(void)
{
float num1;
int num2, resto;
printf("Informe o primeiro valor: ");
scanf("%d", &num1);
printf("Informe o segundo valor: ");
scanf("%d", &num2);

if(num1 > num2)
{
resto = num1 % num2;
}
else if(num1==0 || num2==0)
{
printf("Nao eh possivel realizar divisao por zero\n");
}
else
{
resto = num2 % num1;
}
printf("O resto da divisao eh %d \n", resto);
return 0;
}
