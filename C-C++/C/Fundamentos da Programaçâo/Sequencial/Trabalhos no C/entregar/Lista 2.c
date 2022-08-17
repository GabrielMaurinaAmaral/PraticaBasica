/*Elabore um programa que leia via teclado uma quantidade de segundos (tipo int) e transforme este tempo em dias, horas e minutos (as três últimas em tipo float).
Exemplo:*/

int main (void)
{
    int num1;
    float x, y, z;

    printf("Imfome o tempo em segundos:");
    scanf("%i",&num1);

    x=num1/60;
    y=num1/3600;
    z=num1/86400;

    printf("Tempo em minutos:%.2f \n",x);
    printf("Tempo em horas:%.2f \n",y);
    printf("Tempo em dias:%.2f \n",z);

    return 0;
}
