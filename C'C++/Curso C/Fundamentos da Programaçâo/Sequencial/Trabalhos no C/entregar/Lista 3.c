/*Cada degrau de uma escada tem uma altura X. Faça um programa para ler essa altura e a altura que o usuário deseja alcançar subindo a escada. Calcule e mostre quantos degraus o usuário deverá subir para atingir o seu objetivo.*/

#include<stdio.h>
#include<math.h>

int main(void)
{
    int x;
    float num1, num2;

    printf("Informe a altura que deseja subir");
    scanf("%f", &num1);
    printf("Informe a altura dos degraus");
    scanf("%f", &num2);

    x=ceil(num1/num2);

    printf("Sera necessario %i para subir", x);

    return 0;

 }
