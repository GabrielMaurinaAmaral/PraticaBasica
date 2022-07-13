#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ofstram ifstream fstream
    
    ofstream arquivoO;

    arquivoO.open("pratica.txt");
    arquivoO<<("MINHA PIKA\n");
    arquivoO.close();

    ifstream arquivoI;
    string linha;

    arquivoI.open("pratica.txt");

    if(arquivoI.is_open())
    {
       while(getline(arquivoI,linha))
       {
           cout<<linha<<endl;
       }
    }
    else
    {
        cout<<"não pode abrir porra"<<endl;
    }
    
    return 0;
}