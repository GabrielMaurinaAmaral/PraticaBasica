#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> produtos = {"mouse", "monito", "pc", "gabinete", "mesa"};
    vector<string>::iterator it;

    // it = produtos.end();
    //  advance(it,2); cout << *it << endl;
    //  cout << *next(it,2) << endl;
    //  cout << *prev(it,2) << endl;
    for (it = produtos.begin(); it != produtos.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}