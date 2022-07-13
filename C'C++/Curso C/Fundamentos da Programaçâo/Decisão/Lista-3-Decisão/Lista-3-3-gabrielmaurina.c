/*3) Elabore um programa que leia o dia e o mês de nascimento de uma pessoa e determine o seu signo conforme a tabela a seguir:
Intervalo
Signo
de 22/12 até 20/1
Capricórnio
de 21/1 até 19/2
Aquário
de 20/2 até 20/3
Peixes
de 21/3 até 20/4
Áries
de 21/4 até 20/5
Touro
de 21/5 até 20/6
Gêmeos
de 21/6 até 21/7
Câncer
de 22/7 até 22/8
Leão
de 23/8 até 22/9
Virgem
de 23/9 até 22/10
Libra
de 23/10 até 21/11
Escorpião
de 22/11 até 21/12
Sagitário
Se informada uma data que não corresponde aos intervalos indicados, informar que a data é inválida.*/

#include<stdio.h>
#include<math.h>

int main(void)
{
    int d,m;
    printf("Informe o dia do seu nacimento:");
    scanf("%d",&d);
    printf("Informe o mes do seu nacimento:");
    scanf("%d",&m);

    if ((22<=d && m==12 && 31>=d) || (1<=d && m==1 && 20>=d))
    {
        printf("Signo de Capricornio");
    }
    else if ((21<=d && m==1 && 31>=d) || (1<=d && m==2 && 19>=d))
    {
        printf("Signo de Aquario");
    }
    else if ((20<=d && m==2 && 28>=d) || (1<=d && m==3 && 20>=d))
    {
        printf("Signo de Peixes");
    }
    else if ((21<=d && m==3 && 31>=d) || (1<=d && m==4 && 20>=d))
    {
        printf("Signo de Aries");
    }
    else if ((21<=d && m==4 && 30>=d) || (1<=d && m==5 && 20>=d))
    {
        printf("Signo de Touro");
    }
    else if ((21<=d && m==5 && 31>=d) || (1<=d && m==6 && 20>=d))
    {
        printf("Signo de Gemeos");
    }
    else if ((21<=d && m==6 && 30>=d) || (1<=d && m==7 && 21>=d))
    {
        printf("Signo de Cancer");
    }
    else if ((22<=d && m==7 && 31>=d) || (1<=d && m==8 && 22>=d))
    {
        printf("Signo de Leao");
    }
    else if ((23<=d && m==8 && 31>=d) || (1<=d && m==9 && 22>=d))
    {
        printf("Signo de Virgem");
    } 
    else if ((23<=d && m==9 && 30>=d) || (1<=d && m==10 && 22>=d))
    {
        printf("Signo de Libra");
    } 
    else if ((23<=d && m==10 && 31>=d) || (1<=d && m==11 && 21>=d))
    {
        printf("Signo de Escorpiao");        
    }
    else if ((23<=d && m==11 && 30>=d) || (1<=d && m==11 && 21>=d))
    {
        printf("Signo de Sargitario");          
    }
    return 0;  
}
