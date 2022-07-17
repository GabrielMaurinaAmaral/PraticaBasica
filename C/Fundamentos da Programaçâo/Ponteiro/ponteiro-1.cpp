#include<iostream>
using namespace std;

int main(void)
{
   string veiculo="carro";
   string *pv;

   pv=&veiculo; //ponteiro pv recebe endereço de veiculoo

   cout<<pv<<"\n"<<veiculo<<"\n"<<*pv<<"\n"<<&veiculo<<"\n \n";
   
   *pv="moto";

   cout<<pv<<"\n"<<veiculo<<"\n"<<*pv<<"\n"<<&veiculo<<"\n";
    return 0;
}