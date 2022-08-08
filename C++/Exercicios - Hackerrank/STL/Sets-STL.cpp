#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> conjunto;
    int num, size, opcao;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> opcao >> num;

        if (opcao == 1)
            conjunto.insert(num);
        else if (opcao == 2)
            conjunto.erase(num);
        else
        {
            set<int>::iterator itr = conjunto.find(num);

            if (itr == conjunto.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }

    return 0;
}
