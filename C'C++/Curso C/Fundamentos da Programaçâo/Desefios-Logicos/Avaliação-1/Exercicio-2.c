/* Questão 2 (3,4 pontos) - Ler caracteres. Parar a leitura quando informado o caractere ‘0’, que não deve ser considerado no processamento.
a) Se o caractere estiver entre '1' e '9', mostrar o processo de cálculo do fatorial do valor decimal ASCII do caractere. Não precisa calcular o fatorial, apenas apresentar o processo de cálculo.
b) Se o caractere estiver entre 'a' e 'z' ou entre 'A' e 'Z', mostrar todos os números primos, sendo 6 números por linha, no intervalo de 1 até o valor decimal ASCII do caractere e somar todos os números primos desse intervalo.
c) Contar os caracteres que são letras minúsculas e a quantidade total de caracteres informados e calcular e mostrar o percentual de letras minúsculas em relação ao total de caracteres válidos informados. Validar para que não seja possível ocorrercaraca divisão por 0.
d) Implementar a repetição de programa. */

#include <stdio.h>

int main(void)
{
    int i, aux;
    char carac;


    printf("Informe caracter: ");
    scanf("%c", &carac);
    aux=carac;

    if (aux >= 1 && aux <= 9)
    {
        for (i = aux + 48; i > 1; i--)
        {
            printf(" %d *", i);
        }
        printf(" 1");
    }
  
    printf(" %c ", aux);

    return 0;
}
