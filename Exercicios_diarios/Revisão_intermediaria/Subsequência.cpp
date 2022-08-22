#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;

        if (s.size() > t.size())
            return false;
        if (s.size() == 0)
            return true;

        for (int j = 0; j < t.size(); j++)
            if (i <= s.size() - 1)
                if (s[i] == t[j])
                    i ++;

        return i == s.size();
    }
};