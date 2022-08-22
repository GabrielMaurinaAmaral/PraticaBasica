#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    int casos, size;
    scanf("%d", &casos);

    for (int _ = 0; _ < casos; _++)
    {
        scanf("%d", &size);
        string str[size], result = "YES", aux;

        for (int i = 0; i < casos; i++)
            scanf("%s", &str[i]);

        for (int i = 0; i < size; i++)
        {
            aux = str[i];
            sort(str[i].begin(), str[i].end());
            if (aux != str[i])
            {
                result = "NO";
                break;
            }
        }
        printf("%s", result);
    }
}