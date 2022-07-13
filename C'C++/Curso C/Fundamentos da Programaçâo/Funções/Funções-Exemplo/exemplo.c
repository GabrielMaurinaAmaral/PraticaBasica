#include <stdio.h>
#include "D:\funcoes.h"

int potencia(void);

int num, num1;

int main(void)
{
    int i, opcao;
    char repete;

    do
    {
        printf("1 - Quadrado de um numero\n");
        printf("2 - Verifica se um numero eh ou nao primo\n");
        printf("3 - Quadrado dos numeros de 1 a 10\n");
        printf("4 - Primos no intervalo de 1 a 10\n");
        printf("5 - Media de duas notas\n");
        printf("6 - Multiplica dois numeros\n");
        printf("7 - Soma dois numeros\n");
        printf("8 - Calcula e mostra o fatorial de um numero\n");
        printf("9 - Fatorial dos numeros de 1 a 10\n");
        printf("10 - Potencia de um numero\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Informe um numero: ");
                scanf("%d", &num);//armazena em variável global

                printf("Quadrado do numero: %d\n", quadrado(num));//chama a função e passa o parâmetro num
                break;
            case 2:
                printf("Informe um numero: ");
                scanf("%d", &num); //armazena em variável global

                if(primo(num) == 2) //chama a função e passa o parâmetro num
                {
                    printf("%d eh primo\n", num);
                }
                else
                {
                    printf("%d nao eh primo\n", num);
                }
                break;
            case 3:
                printf("\nNUMERO\tQUADRADO\n");
                for(i=1; i<=10; i++)
                {
                    printf("%d\t%d\n", i, quadrado(i)); //chama a função e passa o parâmetro i
                }
                break;
            case 4:
                printf("\nPRIMOS\n");
                for(i=1; i<=10; i++)
                {
                    if(primo(i) == 2) //chama a função e passa o parâmetro i
                    {
                        printf("%d   ", i);
                    }
                }
                break;
            case 5:
                printf("\nMedia de duas notas: %.2f\n", media());//chama a função e não passa nenhum parâmetro num
                break;
            case 6:
                printf("\nInforme um numero: ");
                scanf("%d", &num);//armazena em variável global
                printf("Informe outro numero: ");
                scanf("%d", &num1);//armazena em variável global
                multiplica(num, num1);//chama a função e passa os parâmetro num e num1
                break;
            case 7:
                soma();
                break;
            case 8:
                printf("\nInforme um numero: ");
                scanf("%d", &num);//armazena em variável global

                mostraFatorial(num, calculaFatorial(num)); //chama a função e como parâmetro passa num e a função calculaFatorial(num)
                break;
            case 9:
                for(i=1; i<=10; i++)
                {
                    mostraFatorial(i, calculaFatorial(i));//chama a função e como parâmetro passa i e a função calculaFatorial(i)
                }
                break;
            case 10:
                printf("Potencia: %d\n", potencia()); //chama a função e não passa nenhum parâmetro
                break;
            default:
                printf("Opcao invalida\n");
        }

        printf("\nDeseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &repete);
    }while(repete == 'S' || repete == 's');

    return 0;
}

//Exemplo do uso de variável global
int potencia(void)//função com retorno e sem parâmetros
{
    int i, resultado=1;

    printf("Informe a base: ");
    scanf("%d", &num);//armazena em variável global
    printf("Informe o expoente: ");//armazena em variável global
    scanf("%d", &num1);

    for(i=1; i<=num1; i++)
    {
        resultado = resultado * num;
    }
    return(resultado);
}

