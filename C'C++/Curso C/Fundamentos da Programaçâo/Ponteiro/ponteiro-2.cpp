#include <iostream>
using namespace std;

int main(void)
{
    int *p;
    int vetor[10];

    p=&vetor[0];  // mesmo code que p=veiculo;
    *p=10;
    cout<<"\n"<<p<<"\n"<<vetor[0]<<"\n"<<*p<<"\n"<<&vetor[0];

    p=&vetor[1]; 
    *p=20;
    cout<<"\n"<<p<<"\n"<<vetor[1]<<"\n"<<*p<<"\n"<<&vetor[1];

    return 0;
}