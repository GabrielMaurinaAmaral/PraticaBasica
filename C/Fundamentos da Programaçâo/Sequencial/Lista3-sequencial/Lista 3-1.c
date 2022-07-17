/*1) Ler um n�mero double. Separar a parte inteira e a parte decimal desse n�mero. Apresentar a parte decimal como um valor double e como um inteiro de tr�s d�gitos. Da parte inteira separar o n�mero que representa unidade, dezena e centena e mostrar.*/

#include<stdio.h>

int main(void)
{
    double x, b;
    int a, c, d, e, f;
    printf("Informe um valor double: ");
    scanf("%lf",&x);

    printf("Numero informal: %lf\n",x);

    a=(int)x;
    printf("Parte inteira: %d\n",a);

    b=x-a;
    printf("Parte decimal: %lf\n",b);

    c=b*1000;
    printf("Parte como inteiro de tres digitos: %d\n",c);

    d=a/100;
    printf("centena: %d\n",d);

    e=(b%100)/10;
    printf("dezena: %d\n",e);

    f=b=%10;
    printf("unidade: %d",f);
}
