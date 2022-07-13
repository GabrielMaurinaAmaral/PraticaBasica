/*   3) Completar e corrigir o código a seguir para:
a) Ler a quantidade somente se a categoria é válida.
b) Garantir que a quantidade seja maior que 0.
c) Validar para que não seja realizada uma divisão por zero no cálculo da média.
d) Permitir a leitura da categoria nas execuções sucessivas do programa.
e) Garantir que a média seja float.*/

#include<stdio.h>

int main(void)
{
    char categoria;
    int quantidade, soma=0, total=0;
    float media;

do
{
       setbuf(stdin, NULL);
        printf("Informe a categoria: ");
        scanf("%c", &categoria);
   
    if(categoria == 'A' || categoria == 'B' || categoria == 'a' || categoria == 'b')
    {
    do    
    {
        printf("Informe a quantidade: ");
        scanf("%d", &quantidade);

        if(quantidade<=0)
        {
            printf("quantidade deve ser positiva");
        }
    }while(quantidade<=0);    
    }

        soma = soma + quantidade;
        total++;
        media = (float)soma / total;


}while(categoria == 'A' || categoria == 'B' || categoria == 'a' || categoria == 'b');    
  

    printf("A media dos produtos eh %.2f", media);

return 0;
}