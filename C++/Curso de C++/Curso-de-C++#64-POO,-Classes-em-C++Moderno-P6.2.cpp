#include "Curso-de-C++#64-POO,-Classes-em-C++Moderno-P6.1.h"
#include <iostream>
using namespace std;
#include <memory> // ponteiro inteligente usa #include <memory.h>
// se usar o "new" deve se usar o "delete"

int main()
{
    // metodo 1
    Pessoa p1{true, "Gabriel", 19, 1.85};
    cout << p1.nome << endl;
    cout << p1.vivo << endl;
    cout << p1.idade << endl;
    cout << p1.altura << endl;

    // metodo 2
    unique_ptr<Pessoa>p2(new Pessoa{false, "Breno", 32, 1.75});
    cout << p2.nome << endl;
    cout << p2.vivo << endl;
    cout << p2.idade << endl;
    cout << p2.altura << endl;

    return 0;
}