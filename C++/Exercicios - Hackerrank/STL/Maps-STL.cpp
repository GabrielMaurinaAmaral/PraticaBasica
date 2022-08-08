#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, int> m;
    int size, opcao, num;
    string str;

    cin >> size;

    while (size--)
    {
        cin >> opcao >> str;

        if (opcao == 1)
            cin >> num, m[str] += num;
        else if (opcao == 2)
            m[str] = 0;
        else
            cout << m[str] << "\n";
    }

    return 0;
}