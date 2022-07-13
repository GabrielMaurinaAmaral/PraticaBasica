/*) Fazer um programa que faça o levantamento dos candidatos que se inscreveram para vagas em uma empresa. Considerando que para cada candidato, a empresa tenha obtido as seguintes informações:
- Idade
- Nacionalidade (B - Brasileiro ou E - Estrangeiro)
- Possui curso superior (S - Sim ou N - Não)
Determinar:
a) A quantidade de brasileiros.
b) A quantidade de estrangeiros.
c) A idade média dos brasileiros sem curso superior.
d) A menor idade entre os estrangeiros com curso superior.
Estabelecer uma condição para finalizar a entrada de dados do programa. Por exemplo, igual a 0 ou idade negativa. Se a idade for igual a 0 ou negativa, não ler as informações de nacionalidade e se possui curso superior, e sair do programa.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (void)
{
    int idade=1, menorIdade, contMaior=0, somaMaior=0, contB=0, contE=0;
    char local, curso;
    while(idade>0)
    {
        printf("Idade: ");
        scanf("%d", &idade);
        
        if(idade>0)
        {       
            setbuf(stdin, NULL);
            printf("Informe a nacionalidade( B=brasileiro e E=estrangeiro): ");
            scanf("%c", &local);
             
            if(local=='b' || local=='B')
            {
                contB++;
            }
            else if(local=='E' || local=='e')
            {
                contE++;
            }

            setbuf(stdin, NULL);
            printf("Posssui curso superior( S=sim e N=não): ");
            scanf("%c", &curso);

            
            if((curso=='S' || curso=='s') && (local=='E' || local=='e'))
            {
                if (idade < menorIdade)
                {
                    menorIdade=idade;
                }
            }
            else if((curso=='N' || curso=='n')  && (local=='b' || local=='B'))
            {
                somaMaior=somaMaior+idade;
                contMaior++;
            }
        }
    }


    printf("A quantidade de brasileiros; %d\n",  contB);
    printf("A quantidade de estrageiros; %d\n",  contE);
    printf("A idade média dos brasileiros sem curso superior: %d\n", somaMaior/contMaior);
    printf(" A menor idade entre os estrangeiros com curso superior: %d\n", menorIdade);
 return 0;

}