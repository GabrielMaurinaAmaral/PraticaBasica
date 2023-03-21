#include "Aula_4_Rotacional1.cpp"

int main()
{

        Fracao f1;
        Fracao f2(3);
        Fracao f3(3, 9);
        Fracao f4(12, 24);

        f1.imprimirFracao();
        f2.imprimirFracao();
        f3.imprimirFracao();
        f4.imprimirFracao();
        cout << "\n---------------SOMA--------------";
        f1.somar(f2);
        f3.somar(f4);
        f1.imprimirFracao();
        f3.imprimirFracao();

        cout << "\n------------SUBTRAIR-------------";
        f2.subtrair(f1);
        f4.subtrair(f3);
        f2.imprimirFracao();
        f4.imprimirFracao();

        cout << "\n------------MULTIPLICAR----------";
        f1.multiplicar(f3);
        f2.multiplicar(f4);
        f1.imprimirFracao();
        f2.imprimirFracao();

        cout << "\n------------DIVIDIR--------------";
        f3.dividir(f1);
        f4.dividir(f2);
        f3.imprimirFracao();
        f4.imprimirFracao();
        cout << "\n---------------------------------";

        f1.imprimirNumero();
        f2.imprimirNumero();
        f3.imprimirNumero();
        f4.imprimirNumero();
    return 0;
}