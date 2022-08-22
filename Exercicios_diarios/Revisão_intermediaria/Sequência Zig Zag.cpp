#include <bits/stdc++.h>
using namespace std;

void findZigZagSequence(vector<int> vetor, int len)
{
    int meio = (len + 1) / 2;
    int esquerda = meio + 1;
    int direita = len - 2;

    sort(vetor.begin(), vetor.end());
    swap(vetor[--meio], vetor[len - 1]);

    while (esquerda <= direita)
    {
        swap(vetor[esquerda], vetor[direita]);
        esquerda += 1;
        direita -= 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (i > 0)
            cout << " ";
        cout << vetor[i];
    }
    cout << endl;

}

int main()
{
    int len, num, cont_casos;
    cin >> cont_casos;

    for (int i = 1; i <= cont_casos; i++)
    {
        cin >> len;
        vector<int> vetor;

        for (int i = 0; i < len; i++)
        {
            cin >> num;
            vetor.push_back(num);
        }
        findZigZagSequence(vetor, len);
    }

    return 0;
}
