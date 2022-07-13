/*3) Leia um valor double que representa o troco a ser fornecido por um caixa. Separe a parte inteira (reais) da parte decimal (centavos) e apresente na forma: 123 reais e 18 centavos. Use a função round, da biblioteca math.h, para o arredondamento da parte decimal).*/

#include<stdio.h>

int main (void)
{
    double x;
    int y,z;
    printf("Informe o valor do troco: ");
    scanf("%lf",&x);

    y=(int)x;
    z=(x-y)*100;
    printf("O valor informado eh %d reis e %d centavos", y,z);

    return 0;
}
