/*Criar função que gere elementos aleatórios dentro de um vetor.
Criar função que mostre os elementos de um vetor.*/

#include <stdio.h>
#include <stdlib.h> //necessária para as funções rand e srand
#include <time.h> //necessária para a função time

void mostrarVetorDeInteiros(int vetor[], int tamanho);
void gerarVetorDeInteirosDe0aLimite(int vetor[], int tamanho, int limite);
void gerarVetorDeInteirosDe1aLimite(int vetor[], int tamanho, int limite);
void gerarVetorDeInteirosEntreLimites(int vetor[], int tamanho, int limInf, int limSup);

int main(void)
{
    int vet[30];

    gerarVetorDeInteirosDe0aLimite(vet, 30, 15);
    printf("\n==== VETOR DE 0 A 15 ====\n");
    mostrarVetorDeInteiros(vet, 30);

    gerarVetorDeInteirosDe1aLimite(vet, 30, 15);
    printf("\n\n==== VETOR DE 1 A 15 ====\n");
    mostrarVetorDeInteiros(vet, 30);

    gerarVetorDeInteirosEntreLimites(vet, 30, 5, 45);
    printf("\n\n==== VETOR DE 5 A 45 ====\n");
    mostrarVetorDeInteiros(vet, 30);

    return 0;
}

//Função que mostra os elementos de um vetor.
void mostrarVetorDeInteiros(int vetor[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d\t", vetor[i]);
    }
}

/*Gera elementos aleatórios no intervalo de 0 até o limite.*/
void gerarVetorDeInteirosDe0aLimite(int vetor[], int tamanho, int limite)
{
    int i;

    srand(time(NULL));

    for(i=0; i<tamanho; i++)
    {
        vetor[i] = rand() % (limite+1);
    }
}

/*Gera elementos aleatórios no intervalo de 1 até o limite.*/
void gerarVetorDeInteirosDe1aLimite(int vetor[], int tamanho, int limite)
{
    int i;

    srand(time(NULL));

    for(i=0; i<tamanho; i++)
    {
        vetor[i] = rand() % limite + 1;
    }
}

/*Gera elementos aleatórios no intervalo de dois limites informados*/
void gerarVetorDeInteirosEntreLimites(int vetor[], int tamanho, int limInf, int limSup)
{
    int i;

    srand(time(NULL));

    for(i=0; i<tamanho; i++)
    {
        vetor[i] = (rand() % ((limSup - limInf)+1)) + limInf;
    }
}
