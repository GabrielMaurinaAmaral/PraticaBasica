#include "Aula_4_Complexo1.cpp"

int main()
{
    Complexo c1;
    Complexo c2(4);
    Complexo c3(6, 9);

    c1.inicializarNumero(2, 5);
    c2.inicializarNumero(2, 5);

    c1.imprimirNumero();
    c2.imprimirNumero();
    c3.imprimirNumero();

    cout << c1.elgual(c2);
    cout << c1.elgual(c3);

    c1.somar(c2);
    c1.imprimirNumero();

    c2.subtrair(c3);
    c2.imprimirNumero();

    c1.multiplicar(c2);
    c1.imprimirNumero();

    c1.dividir(c3);
    c1.imprimirNumero();
    return 0;
}