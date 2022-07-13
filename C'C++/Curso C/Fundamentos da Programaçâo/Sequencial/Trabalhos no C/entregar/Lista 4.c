/*Faça um programa que receba o peso e a altura de uma pessoa e calcule o índice de massa corpórea.
Esse índice mede a relação entre peso e altura (peso em quilogramas dividido pelo quadrado da altura em
metros). Use a função pow() da biblioteca math.h para calcular a potência.*/

#include<stdio.h>
#include<math.h>

int main(void)
{
    float a, p, imc;

    printf("Infome sua altura(m):");
    scanf("%f",&a);
    printf("Infome seu peso(Kg):");
    scanf("%f",&p);

    imc=p/pow(a,2);

    printf("Seu imc eh:%.2f", imc);

    return 0;

}
