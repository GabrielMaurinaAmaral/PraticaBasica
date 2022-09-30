#include <stdio.h>
#include <math.h>

int manhattan(int v1[], int v2[], int i, int len)
{
    if (i >= len)
        return abs(v1[i] - v2[i]);
    else
    {
        int m = (i + len);

        return manhattan(v1, v2, i, m) + manhattan(v1, v2, m + 1, len);
    }
}

int main()
{

    return 0;
}

//  n=1 -> 5
//  2.T(n/2) + 8
