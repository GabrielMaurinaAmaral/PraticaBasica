#include <iostream>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string str_1, string str_2)
    {
        int aux_1[256] = {0}, aux_2[256] = {0};

        for (int i = 0; i < str_1.size(); ++i)
        {
            if (aux_1[str_1[i]] != aux_2[str_2[i]])
                return false;

            aux_1[str_1[i]] = i + 1;
            aux_2[str_2[i]] = i + 1;
        }
        
        return true;
    }
};