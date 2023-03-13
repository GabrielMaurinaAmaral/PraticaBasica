#include "Aula-04-Sobrecarga-de-Operadores-Parte1.2.cpp"

int main()
{
    Complexo n1{10, 20};
    Complexo n2{5, 15};
    cout << "\nn1 = ", n1.print();
    cout << "\nn2 = ", n2.print();

    Complexo n3, n4;
    n3 = n1 + n2; // n1.operator+(n2) ou n1.add(n2)
    n4 = n1 - n2; // n1.operator-(n2) ou n1.sub(n2)
    cout << "\nn3 (add) = ", n3.print();
    cout << "\nn4 (sub) = ", n4.print();

    n1 = ++n2; // n1= 1 + n2;
    cout << "\nDepois do incremento de n1: ", n1.print();
    cout << "\nDepois do incremento de n2: ", n2.print();

    n3 = n4++; // n3=n4; n3++;
    cout << "\nAntes do incremento de n3: ", n3.print();
    cout << "\nAntes do incremento de n4: ", n4.print();

    return 0;
}