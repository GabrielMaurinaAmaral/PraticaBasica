/*2) Gerar um arquivo de cabeçalho chamado vetores.h com uma função para gerar um vetor com números aleatórios, com determinado tamanho e que os valores aleatórios variem entre 0 e n e com outra função para mostrar um vetor com tamanho não fixo.
Utilizar essas funções para:
a) Gerar um vetor de valores randômicos com a quantidade de elementos e o valor de n informada pelo usuário. Validar as entradas para que sejam informados valores positivos.
b) Mostrar o vetor.
c) Encontrar e mostrar o menor elemento armazenado no vetor.
d) Fazer a média dos pares que estão armazenados no vetor. Validar para que não seja realizada divisão por zero no cálculo da média.
O programa permanecerá em execução até que seja escolhida a opção sair.
Exemplo:*/

#include <stdio.h>
#include "Vetores-Lista.h"

int main(void)
{
    int tam, inter1;
    char opcRepetir;
    do
    {
        printf("Informe o tamanho do vetor: ");
        scanf("%d", &tam);
        printf("Informe o valor de n: ");
        scanf("%d", &inter1);

        vetorRand(inter1, tam);

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}