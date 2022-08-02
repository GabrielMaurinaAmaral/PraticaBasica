#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* descodificar(char *alfabeto, int *codigo)
{
    char *descodificado;
    descodificado=(char*)malloc(100*sizeof(char));
    
    for(int i=0; i<100; i++)
    {
        descodificado[i]=alfabeto[codigo[i]-1];
    }
    
    return descodificado;
}

int main() 
{
    char *alfabeto, *resultado; 
    int *codigo, i=0;
    
    alfabeto=(char*)malloc(100*sizeof(char));
    codigo=(int*)malloc(100*sizeof(int));

    scanf("%s", alfabeto);
    
    while(codigo[i]!=-1)
    {
        scanf("%d", &codigo[i]);
        
        if(codigo[i]==-1)
        {
            break;
        }
        else
        {
            i++;    
        }
    }
    
    resultado=descodificar(alfabeto, codigo);
    
    printf("%s", resultado);
    
    return 0;
}