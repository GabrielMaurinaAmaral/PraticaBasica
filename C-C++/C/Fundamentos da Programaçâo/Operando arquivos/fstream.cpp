#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    fstream arquivo;
    char opc = "s";
    string nome, linha;

    arquivo.open << ("nome.txt", ios::out | ios::app);

    while ((opc == "s") or (opc = "S"))
    {
        cout << "nome: ";
        cin >> nome;
        arquivo << nome << "\n";

        cout << "\ncontinuar? ";
        cin >> opc;
        system("CLS");
    }

    arquivo.close();

    arquivo.open("nome.txt", ios::in);
    cout << "nome digitados" << endl;

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            cout << linha << endl;
        }
    }
    else
    {
        cout << "não pode abrir porra" << endl;
    }

    return 0;
}