#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vetor;
    int size, num;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        vetor.push_back(num);
    }

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        vector<int>::iterator low = lower_bound(vetor.begin(), vetor.end(), num);

        if (vetor[low - vetor.begin()] == num)
            cout << "Yes " << (low - vetor.begin() + 1) << endl;
        else
            cout << "No " << (low - vetor.begin() + 1) << endl;
    }
    
    return 0;
}