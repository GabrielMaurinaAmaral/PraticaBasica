/*8) Ler um texto (pode ser composto por uma ou mais palavras), copiar para um vetor somente a primeira palavra. 
     Mostrar a string armazenada.
     Observação: Não esquecer de finalizar a string gerada (copiada).*/

#include <string.h>
#include <stdio.h>

int main(void)
{
    char strTexto[150], strCopia[150], strInvet, opcRepetir;
    int i;

    do
    {
        printf("Informe um texto com ate 150 caracteres: ");
        gets(strTexto);

        i=0;
        while(strTexto!='\0')
        {
            if(strTexto[i]==' ')
            {
                break;
            }

            strCopia[i]=strTexto[i];
            i++;
        }
         
        printf(" String copiada: %s", strCopia);

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}