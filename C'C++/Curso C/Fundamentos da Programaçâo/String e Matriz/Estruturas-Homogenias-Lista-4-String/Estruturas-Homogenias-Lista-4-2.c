/*2) Elaborar um programa que aceita e valida uma senha com 6 dígitos numéricos, que deve ser armazenada em uma string. O usuário tem três tentativas para acertar a senha, se ultrapassar esse limite, ele deve ser informado. O usuário também deve ser informado se ele acertou a senha em até três tentativas.
Dica: Considere que já existe uma senha armazenada na string senhaArmazenada[7]="123456";*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, contS, j, k, contC;
    char opcRepetir, strSenha[7] = "123456", strCompa[7];

    do
    {

        for (i = 0; i < 3; i++)
        {
            printf(" Informe a senha: ");
            setbuf(stdin, NULL);
            gets(strCompa);

            contS = 0;
            contC = 0;
            j = 0;
            k = 0;

            while (strSenha[j] != '\0')
            {
                contS++;
                j++;
            }

            while (strCompa[k] != '\0')
            {
                if (strCompa[k] == strSenha[k])
                {
                    contC++;
                }
                k++;
            }

            if (contC == contS)
            {
                printf(" Senha valida\n");
                break;
            }
        }

        if (contC != contS)
        {
            printf(" Senha invalida\n");
        }

        printf("\n Quer repetir o programa(S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}