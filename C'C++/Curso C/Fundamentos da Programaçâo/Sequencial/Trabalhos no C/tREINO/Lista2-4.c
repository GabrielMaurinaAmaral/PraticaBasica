/*4) Escreva um programa que, dados a quantidade de litros de combustível utilizada, os quilômetros percorridos por um automóvel e o valor do litro de combustível, calcule quantos quilômetros o veículo percorreu por litro de combustível e o valor gasto em reais por km.*/

#include<stdio.h>
#include<math.h>

int main (void)
{
    float x, y, z, a, b;

    printf("Informe os Km percorrido:");
    scanf("%f",&x);
    printf("Combustivel consumido(em L):");
    scanf("%f",&y);
    printf("Valor do livro de combustivel:");
    scanf("%f",&z);

    a=x/y;
    b=a/z;

    printf("o carro fez
