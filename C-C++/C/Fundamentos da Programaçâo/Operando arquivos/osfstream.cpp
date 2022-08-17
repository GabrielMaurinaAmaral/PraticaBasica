#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ofstram ifstream fstream

    ofstream arquivo;

    arquivo.open("texte.txt",ios::app);

    arquivo<<"MINHA PIKA \n";

    arquivo.close();

    return 0;
}