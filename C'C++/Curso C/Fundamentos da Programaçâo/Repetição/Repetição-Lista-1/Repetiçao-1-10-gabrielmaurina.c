/*10) Uma indústria fabrica roupas categorizadas em masculinas, femininas e infantis. Ler a quantidade e a respectiva
 categoria (M, F ou I). Após o loop, calcular e mostrar o percentual de produtos por categoria. Validar para que seja 
 informada uma categoria válida. Finalizar a leitura quando informado um valor 0 ou negativo para a quantidade. 
 er inicialmente a quantidade e depois a categoria. Se informada uma quantidade negativa, não ler a categoria.*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    int   num2, numI=0, numM=0, numF=0, num, porcF, porcM, porcI;
    char op;

    do
    {
        printf("Infomre a quantidade: ");
        scanf("%d", &num);

        num2=1;
        while(num2>0)
        {   
            setbuf(stdin, NULL);
            printf("Informe a categoria - femenini(f), masculino(m) ou infantil(i): ");
            scanf("%c", &op);

            if(op=='f' || op=='F' )
            {
                numF++;
                num2=0;
            }
            else if(op=='m' || op=='M')
             {
                 numM++;
                  num2=0;
            }
            else if(op=='i' || op=='I')
            {
                 numI++;
                  num2=0;
            }
            else
            {
                  printf("caracter errado \n");
            }
        }    
    } while (num>0);

    porcF=100*numF/(numF+numI+numM);
    porcM=100*numM/(numF+numI+numM);
    porcI=100*numI/(numF+numI+numM);

    printf("%d%% femenino\n", porcF);
    printf("%d%% masculino\n", porcM);
    printf("%d%% infantil\n", porcI);    

  return 0;
}