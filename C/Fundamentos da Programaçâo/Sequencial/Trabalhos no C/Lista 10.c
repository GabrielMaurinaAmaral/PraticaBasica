/*10) Resolva as seguintes expressões matemáticas. X e Y são valores fornecidos pelo usuário. Calcule e mostre o resultado de cada expressão. Reutilize variáveis, ou seja, terá apenas uma variável para armazenar os resultados do tipo int e outra para armazenar o resultado do tipo float. Faz a primeira operação e já imprime o resultado e assim para todas as demais operações. Atenção para os resultados que podem ser valores float e para a prioridade dos operadores. Primeiro deve-se linearizar as expressões e depois implementar o algoritmo para calcular os resultados.*/

#include<stdio.h>
#include<math.h>

int main(voide)
{

    int x, y;
    float a;

    printf("Informe o valor de x:");
    scanf("%d", &x);
    printf("Informe o valor de y:");
    scanf("%d", &y);

    a=(x*x)*(((float)x+y)/y);
    printf("a)%f \n",a);

    a=(((float)x)+y)/(x-y);
    printf("b)%f \n",a);

    a=((((float)x)*x)+(y*y*y))/2;
    printf("c)%f \n",a);

    a=(((float)x)*x*x)/(x*x);
    printf("d)%f\n",a);

    a=x%y;
    printf("e1)%.0f\n",a);

    a=x%3;
    printf("e2)%.0f\n",a);

    a=y%5;
    printf("e3)%.0f\n",a);

    return 0;
}
