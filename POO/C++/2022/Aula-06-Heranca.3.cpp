#include "Aula-06-Heranca.2.cpp"
#include <iostream>
using namespace std;

int main()
{
    Pessoa p1{"Gabriel", "Brasil"};
    Aluno p2{"Pedro", "Brasilia", "CP", 123456};
    Professor p3{"Pedro", "Brasilia", 432134, 2, "UTFPR"};

    p1.print();
    p2.print();
    p3.print();
    return 0;
}