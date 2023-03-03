/*#include <iostream>
using namespace std;
int main()
{
    int h_i, m_i, h_f, m_f, h, m;
    scanf("%d %d %d %d", &h_i, &m_i, &h_f, &m_f);
    h = h_f - h_i;
    m = m_f - m_i;

    if (m < 0)
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", h--, 60 + m);
    else
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", h, m);

    return 0;
}*/
#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    scanf("%f %f", &a, &b);
    c = ((b / a) - 1) * 100;
    printf("%.2f%%", c);
    return 0;
}
