#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size, i, num;
    cin >> size;

    vector<int> v;

    for (i = 0; i < size; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
