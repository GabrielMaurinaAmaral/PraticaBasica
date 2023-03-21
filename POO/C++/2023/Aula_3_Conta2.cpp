#include "Aula_4_Conta1.cpp"

int main()
{
    Conta fred;
    Conta richard("Richard", 1234.56);

    fred.depositar(500);
    richard.retirar(2000);

    fred.mostrarConta();
    richard.mostrarConta();

    richard.setNome("Paulo");
    fred.setSaldo(300);

    cout << richard.getNome() << endl;
    cout << fred.getSaldo() << endl;

    fred.mostrarConta();
    richard.mostrarConta();

    return 0;
}