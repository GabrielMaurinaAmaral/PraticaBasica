#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vetor;
    int num, size;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> num;
        vetor.push_back(num);
    }

    cin >> num;
    vetor.erase(vetor.begin() + (num - 1));

    cin >> num >> size;
    vetor.erase(vetor.begin() + (num - 1), vetor.begin() + (size - 1));

    cout << vetor.size() << endl;
    for (int i = 0; i < vetor.size(); i++)
        cout << vetor[i] << " ";

    return 0;
}
