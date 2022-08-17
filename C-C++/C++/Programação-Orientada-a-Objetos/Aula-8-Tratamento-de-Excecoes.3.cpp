#include "Aula-8-Tratamento-de-Excecoes.2.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;

class Divide_por_zero : public runtime_error
{
public:
    Divide_por_zero() : runtime_error("Tentativa de divisaopor zero") {}
};
int quonciente(int n, int m)
{
    if (m == 0)
        throw Divide_por_zero();
    // throw runtime_error("Tentativa de divisaopor zero");
    return n / m;
}

int main()
{
    int x = 0, y = 0;

    cout << "\nEntre com os valores de x e y: ";
    cin >> x >> y;

    try
    {
        cout << "Resultado: " << quonciente(x, y) << endl;
    }
    catch (runtime_error &ex)
    {
        cout << "Ocorreru um erro: " << ex.what() << endl;
    }
    /*   catch (Divide_por_zero &ex)
   {
       cout << "Ocorreru um erro: " << ex.what() << endl;
   }*/
    cout << "Programa finaizado";

    return 0;
}