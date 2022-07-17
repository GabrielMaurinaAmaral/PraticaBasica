#include<iostream>
using namespace std;

void somar(float *var, float valor)
{
    *var+=valor;
}

void veto(float *v)
{
    v[0]=0;
    v[1]=1;
    v[2]=2;
    v[3]=3;
    v[4]=4;
}

int main(void)
{
    float num=0;
    float vetor[5];

    somar(&num,15);
    veto(vetor);

    cout<<num<<"\n";
    for(int i=0; i<5; i++)
    {
     cout<<vetor[i]<<"\n";
    }

    return 0;
}