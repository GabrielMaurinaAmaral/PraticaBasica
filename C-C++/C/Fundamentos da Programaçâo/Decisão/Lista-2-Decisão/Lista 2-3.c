/*3) Ler tr�s valores inteiros diferentes e coloc�-los em ordem crescente. Os valores devem ser apresentados com uma instru��o:
printf("Menor: %d Meio: %d Maior: %d\n", menor, meio, maior);
Sugest�o: Dividir o problema em partes: encontrar o maior, o menor e o do meio separadamente. Armazenar os valores em vari�vel e mostr�-los com uma �nica instru��o.*/

#include <stdio.h>

int main()
{
   int x, y, z, menor, meio, maior;
   printf("Informe um numero:");
   scanf("%d", &x);
   printf("Informe um numero:");
   scanf("%d", &y);
   printf("Informe um numero:");
   scanf("%d", &z);

   if (y > z && x > z)
      menor = z;
   else if (x > y && z > y)
      menor = y;
   else
      menor = x;

   if (z < y && z > x || z > y && z < x)
      meio = z;
   else if (y < z && y > x || y > z && y < x)
      meio = y;
   else
      meio = x;
   
   if (z > x && z > y)
      maior = z;
   else if (y > x && y > z)
      maior = y;
   else
      maior = x;

   printf("Menor: %d Meio: %d Maior: %d\n", menor, meio, maior);

   return 0;
}
