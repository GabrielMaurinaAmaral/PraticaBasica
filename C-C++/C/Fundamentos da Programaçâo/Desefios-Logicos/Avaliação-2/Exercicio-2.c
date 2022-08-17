/*Questão
( 3,3 pontos) Ler uma string com até 100 caract eres e fa zer uma função que receba a string e retorne quantas palavras tem na string.
 Cri ar uma segunda função para contar quantas letras tem em cada palavra da string, armazenando essa contagem em um vetor passado por parâmetro para a função (esse vetor ter á como tamanho o número de palavras da string).
 Na sequência, criar uma matriz com 2 colunas e o número de linhas igual ao tamanho do vetor.
 Na primeira coluna da matriz armazenar o elemento do vetor e na segunda coluna da matriz armazenar a quantidade de divisores que esse elemento tem*/

#include <stdio.h>

int contPalavras(char str[])
{
    int cont = 0, i = 0, aux = 0;

    while (str[i] != '\0')
    {
        if (aux == 0)
        {
            if (str[i] != ' ')
            {
                cont++;
                aux = 1;
            }
        }

        if (str[i] != ' ' && str[i - 1] == ' ')
        {
            cont++;
        }

        i++;
    }

    return cont;
}

void contCaract(char str[])
{

    
}

int main(void)
{
    char str[100];

    printf("Informe um texto: ");
    gets(str);

    printf(" Contem %d palavras ", contPalavras(str));

    return 0;
}