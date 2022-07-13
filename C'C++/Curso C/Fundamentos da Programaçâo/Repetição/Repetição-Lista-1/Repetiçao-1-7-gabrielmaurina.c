/*7) Ler uma série de números indicados pelo usuário até ser informado o valor zero. Encontrar e mostrar o maior e o menor dos valores informados pelo usuário. O valor zero indica o final da leitura e não deve ser considerado.
Exemplo:*/

int main (void)
{
    int num=1; //inicializa a variável num com 1 para poder entrar no while
    int maior, menor, primeiro = 0; //a variável primeiro é inicializada com 0

    while(num != 0)//verifica se num é diferente de 0
    {
        printf("Informe um numero: "); //solicita um número
       scanf("%d", &num);

        if(num != 0) //se esse número for diferente de 0 continua, senão saí do while
        {


            if(primeiro == 0)//esse if serve somente para inicializar o maior e o menor com o primeiro número que o usuário digitar
            {
                maior = num; //inicializa maior com num
                menor = num; //inicializa menor com num
                primeiro = 1; //a variável primeiro recebe 1 para que nas próximas repetições entre no else ao invés do if
            }
            if(primeiro == 0)//esse if serve somente para inicializar o maior e o menor com o primeiro número que o usuário digitar
            {
                maior = num; //inicializa maior com num
                menor = num; //inicializa menor com num
                primeiro = 1; //a variável primeiro recebe 1 para que nas próximas repetições entre no else ao invés do if
            }
            else
            {
                if(num > maior) //se num for maior que maior, atualiza o valor da variável maior com num
                {
                    maior = num;
                }
                else if (num < menor) //se num for menor que menor, atualiza o valor da variável menor com num
                {
                    menor = num;
                }
            }
        }
    }

    printf("Menor: %d         Maior: %d", menor, maior);
    }










    if(aux==0)
        {
            maior=num;
            menor=num;
            aux=1;
        }
        else if(aux==1)
        {
            if(num>maior)
            {
                maior=num;
            }
            else if (num<menor)
            {
                menor = num;
            }
        }
