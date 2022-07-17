/*3) Deseja-se publicar o número de acertos de cada aluno em uma prova. A prova consta de 10 questões, cada uma com cinco alternativas identificadas por A, B, C, D e E. Para isso são dados:
- O cartão gabarito;
- O número de alunos da turma;
- O cartão de respostas para cada aluno, contendo o seu número e suas respostas.*/

#include <stdio.h>

int main(void)
{
    char vetorGabarito[10], vetorResposta[10], opcRepetir; //São 10 questões
    int i, j, contAcerto, contAluno;


    do
    {
        printf("Quantos alunos vao fazer a prova: ");
        scanf("%d", &contAluno);

        printf("\n ====GABARITO==== \n");
        for (i = 0; i < 10; i++)
        {
            do
            {
                printf("\n Gabarito da prova na questao %d: ", i + 1);
                setbuf(stdin, NULL);
                scanf("%c", &vetorGabarito[i]);

                if(vetorGabarito[i] < 'A' || vetorGabarito[i] > 'E' && vetorGabarito[i] < 'a' || vetorGabarito[i] > 'e')//ponto e vírgula
                    {
                        printf("Caracter errado");
                    }

                } while (vetorGabarito[i] < 'A' || vetorGabarito[i] > 'E' && vetorGabarito[i] < 'a' || vetorGabarito[i] > 'e');
        }

        printf("\n==== RESPOSTAS DOS ALUNOS ====\n");
        for (j = 1; j <= contAluno; j++)
        {
            contAcerto = 0;

            printf("\n ==== RESPOSTA DO ALUNO %d ==== \n", j);
            for (i = 0; i < 10; i++)
            {
                do
                {
                    printf("\n Gabarito da prova na questao %d: ", i + 1);
                    setbuf(stdin, NULL);
                    scanf("%c", &vetorResposta[i]);

                    if(vetorResposta[i] < 'A' || vetorResposta[i] > 'E' && vetorResposta[i] < 'a' || vetorResposta[i] > 'e')//ponto e vírgula
                    {
                        printf("Caracter errado");
                    }

                } while (vetorResposta[i] < 'A' || vetorResposta[i] > 'E' && vetorResposta[i] < 'a' || vetorResposta[i] > 'e');

                if (vetorGabarito[i] == vetorResposta[i])
                {
                    contAcerto++;
                }
            }

            printf("\n O aluno acertou %d de 10 \n", contAcerto);

        }

        printf("\n Quer repetir o programa(S/s ou N/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &opcRepetir);

    } while (opcRepetir == 'S' || opcRepetir == 's');

    return 0;
}
