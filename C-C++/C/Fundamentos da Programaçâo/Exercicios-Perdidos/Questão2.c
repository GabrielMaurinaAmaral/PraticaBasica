/*Questão 2 (3,4 pontos) - Ler caracteres. Parar a leitura quando informado o caractere ‘0’, que não deve ser considerado no processamento.
a) Se o caractere estiver entre '1' e '9', mostrar o processo de cálculo do fatorial do valor decimal ASCII do caractere. Não precisa calcular o fatorial, apenas apresentar o processo de cálculo.
b) Se o caractere estiver entre 'a' e 'z' ou entre 'A' e 'Z', mostrar todos os números primos, sendo 6 números por linha, no intervalo de 1 até o valor decimal ASCII do caractere e somar todos os números primos desse intervalo.
c) Contar os caracteres que são letras minúsculas e a quantidade total de caracteres informados e calcular e mostrar o percentual de letras minúsculas em relação ao total de caracteres válidos informados. Validar para que não seja possível ocorrer uma divisão por 0.
d) Implementar a repetição de programa. */

#include <stdio.h>

int main(void)
{
    int num, i, j, contMinusculas, contTodos, contDiv, contPrimos, somaPrimos;
    float percentual;
    char opcao, ch;

    do //repetição de programa
    {
        contMinusculas=0; //inicializa o contador de letras minúsculas
        contTodos=0; //inicializa o contador de todos os caracteres

        do //repetição dos caracteres
        {
            printf("Informe um caractere: ");
            setbuf(stdin, NULL);
            scanf("%c", &ch);

            if(ch != '0')
            {
                contTodos++; //conta todos os caracteres

                if(ch >= '1' && ch <= '9') //verifica se o caractere digitado está entre '1' a '9'
                {
                    for(i=ch; i>=2; i--) //mostra o processo do fatorial
                    {
                        printf("%d * ", i);
                    }

                    printf("1\n");
                }
                else if(ch >= 'a' && ch <= 'z'|| ch >= 'A' && ch <= 'Z') //verifica se o caractere digitado está entre 'a' a 'z' ou entre 'A' a 'Z'
                {
                    contPrimos=0; //inicializa o contador de primos
                    somaPrimos=0; //inicializa o somatório de primos

                    for(i=1; i<=ch; i++) //verifica se os números de 1 até o valor decimal de ch são primos
                    {
                        contDiv = 0; //inicializa o contador de divisores
                        for(j=1; j<=i; j++)//verifica se cada elemento do for anterior é primo
                        {
                            if(i%j == 0)
                            {
                                contDiv++;
                            }
                        }
                        if(contDiv == 2) //se for primo
                        {
                            printf("%d\t", i); //imprime o número primo
                            contPrimos++; //conta os primos
                            somaPrimos = somaPrimos + i; //soma os primos

                            if(contPrimos % 6 == 0) //se a quantidade de primos for múliplo de 6, quebra linha
                            {
                                printf("\n");
                            }
                        }
                    }
                    printf("\nSoma dos primos: %d\n", somaPrimos);

                    if(ch >= 'a' && ch <= 'z')
                    {
                        contMinusculas++; //conta as letras minúsculas do alfabeto
                    }
                }
            }
        }while(ch != '0');

        if(contMinusculas > 0)
        {
            percentual = contMinusculas * 100 / (float)contTodos;
            printf("\nPercentual de minusculas: %.2f%%\n", percentual);
        }
        else
        {
            printf("Nao foi digitado nenhuma letra minuscula\n");
        }

        printf("\nDeseja continuar no programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c",&opcao);

    }while(opcao == 'S' || opcao == 's');

    return 0;
}
