/*Quest�o 1 (3,3 pontos) - Num sorteio que distribui pr�mios, um participante inicialmente sorteia um inteiro x entre os valores 1 e 15 e depois informa n valores inteiros. O n�mero de pontos do participante � o tamanho da maior sequ�ncia de valores consecutivos iguais. Por exemplo, suponhamos que um participante sorteia x = 11 e informa os n valores nesta ordem: 30; 30; 30; 30; 40; 40; 40; 40; 40; 30; 30. Ent�o, o participante ganha 5 pontos, correspondentes aos 5 valores 40 consecutivos. Note que o participante sorteou 6 valores iguais a 30, mas n�o s�o todos consecutivos. S�o contados apenas os consecutivos. Escreva um programa que sorteie um valor para x e em seguida leia os n valores que correspondem a essa quantidade x. Para se obter o valor de x, em uma faixa de valores entre 1 e 15, deve ser utilizada a fun��o rand(). Os n valores s�o informados pelo usu�rio na execu��o do programa. Calcule a pontua��o do participante. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num, x, qtdeSequenciaAnterior=0, valor, valorAnterior, qtdeSequencia=1, i;

    srand(time(NULL));

    x = rand() % 15 + 1;
    printf("Sorteio de x: %d\n", x);

    printf("1: "); //imprimi o indicador do primeiro elemento a ser digitado
    scanf("%d", &num); //imprime o primeiro elemento digitado pelo usu�rio
    valor = num; //a vari�vel valor recebe o primeiro elemento digitado

    for(i=2; i<=x; i++) //faz um loop de 2 at� o valor de x
    {
        printf("%d: ", i); //indicador do elemento
        scanf("%d", &num); //elemento digitado pelo usu�rio

        if(num == valor) //se o n�mero digitado for igual a valor, significa uma sequ�ncia de n�meros iguais, ent�o conta
        {
            qtdeSequencia++; //contador de elementos iguais consecutivos
        }
        else //se o n�mero digitado n�o for igual a valor, significa que ser� iniciada uma nova sequ�ncia de valores
        {
            if(qtdeSequencia >= qtdeSequenciaAnterior) //esse if vai permitir a inicializa��o das vari�veis
            {
                valorAnterior=valor; //para preservar o valor anterior da sequ�ncia
                qtdeSequenciaAnterior = qtdeSequencia;//para preservar o valor da quantidade da sequ�ncia anterior
                valor=num; //para atualizar o valor com o novo elemento da sequ�ncia
                qtdeSequencia=1; //inicializa a nova sequ�ncia
            }
        }
    }

    if(qtdeSequencia > qtdeSequenciaAnterior)//se a sequ�ncia de consecutivos ocorrer no final, mostra o que est� no if, se ocorrer no in�cio, mostra o que est� no else
    {
        printf("Pontuacao: %d pontos\n", qtdeSequencia);
        printf("Valor que se repete mais vezes em sequencia: %d\n", valor);
    }
    else
    {
        printf("Pontuacao: %d pontos\n", qtdeSequenciaAnterior);
        printf("Valor que se repete mais vezes em sequencia: %d\n", valorAnterior);
    }

    return 0;
}
