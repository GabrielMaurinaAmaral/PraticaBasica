#include <iostream>
#include <fstream> /// biblioteca parar usar arquivos

using namespace std;

int main()
{
    // ofstream arquivo de entrada
    // ifstream arquivo de saida
    // fstream arquivo pode ser os dois
    ofstream arquivo;

    arquivo.open("arquivo.txt");

    if (arquivo.is_open())
    {
        arquivo << "aberto porra" << endl;
    }
    arquivo.close();

    return 0;
}