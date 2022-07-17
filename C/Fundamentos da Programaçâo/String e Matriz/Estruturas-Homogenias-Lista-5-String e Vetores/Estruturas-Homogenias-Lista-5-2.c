/*2) Elaborar um programa que leia uma frase e determine se a mesma representa um palíndromo. Em frases
de palíndromos os espaços não são considerados, então é necessário inicialmente retirar os espaços em
brancos do texto. Para comparar as strSemEspacongs use a função int comparaStrings(char str1[],
char str2[]) criada na Lista 4 de exercícios.
Exemplos de frases palíndromos:
Socorram-me, subi no ônibus em Marrocos
Anotaram a data da maratona
A mala nada na lama
A torre da derrota
A cara rajada da jararaca*/

#include<stdio.h>
#include"Funcoes-Lista-estruturais-5.h"

int main(void)
{
    char strTex[150], strSemEsp[150], strInvet[150], opcRepetir;
    int i, k, j;

    do
    {
        i = 0;
        k = 0;

        printf("Informe um texto com ate 150 caracteres: ");
        setbuf(stdin, NULL);
        gets(strTex);

        while (strTex[i] != '\0')
        {
            if (strTex[i] != ' ')
            {
                strSemEsp[k] = strTex[i];
                k++;
            }

            i++;
        }

         printf("\n Testo sem espaço: %s \n", strSemEsp);
         
        k=k-1;
        j=0;

        while(k>=0)
        {
           strInvet[j]=strSemEsp[k];
           j++;
           k--;
        }

        strInvet[j+1]='\0';
        printf("\n Testo invertido: %s \n", strInvet);

        if(comparaString(strSemEsp, strInvet)==1)
        {
            printf("eh palindromo");
        }
        else
        {
            printf("nao eh palindromo");
        }

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}
