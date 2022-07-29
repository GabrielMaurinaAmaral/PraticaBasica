#include "Aula03-Classes-Parte2.2.cpp"
#include <iostream>
using namespace std;

int main()
{
    Date hoje;
    hoje.set_day(29).set_month(7).set_year(2022);
    cout << "\nSeu aniversario: ", hoje.print();
    cout << "\nDia do aniversario:  " << hoje.get_day();
    cout << "\nMes do aniversario:  " << hoje.get_month();
    cout << "\nAno do aniversario:  " << hoje.get_year() << endl;

    Date aniversario;
    int dia, mes, ano;
    cin >> dia >> mes >> ano;
    aniversario.set_day(dia).set_month(mes).set_year(ano);
    cout << "\nSeu aniversario: ", aniversario.print();

    cout << "\nquantas instanciasa ativas aniversario ? " << aniversario.get_count();
    cout << "\nquantas instanciasa ativas hoje? " << hoje.get_count();

    cout << "\nnumero de instancias: " << Date::how_many_instances() << endl;

    return 0;
}