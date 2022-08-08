#include "Aula-7-Polimorfismo.2.cpp"
#include <iostream>
using namespace std;

int main()
{ // METODO 1
    Forma f{5, 4};
    f.print_dados();

    Retangulo r{6, 3, 10, 5};
    r.print_dados();

    // METODO 2
    Forma *ponto_1 = new Forma{10.0, 20.0};
    cout << "\nForma: ";
    ponto_1->print_dados();

    Forma *ret_1 = new Retangulo{0, 0, 10, 12};
    cout << "\n\nRetangulo: ";
    ret_1->print_dados();

    Forma *cir_1 = new Circulo{0, 0, 10};
    cout << "\nCirculo: ";
    cir_1->print_dados();

    // METODO 3
    Forma *vetor_formas[4];
    vetor_formas[0] = new Forma{8, 6};
    vetor_formas[1] = new Retangulo{4, 8, 5, 10};
    vetor_formas[2] = new Circulo{10, 20, 1};
    vetor_formas[3] = new Forma{0, 0};

    for(auto x: vetor_formas)
        x->print_dados();
        
    return 0;
}