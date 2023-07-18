#include "Motocicleta.h"


Motocicleta::Motocicleta(int id, int rodas) : Veiculo_Motorizado(id, rodas), tipo("M")
{
    cout << "Motocicleta com ID " << get_id() << " foi construída" << endl;
}

 string Motocicleta::get_tipo() const
{
    return tipo;
}

 void mover() override
{
    if (get_ipva())
    {
        if (get_combustivel() >= gasto_motocicleta)
        {
            if (verificar_pneu())
            {
                consumir(gasto_motocicleta);
                int new_distancia = get_distancia_percorrida() + 2;
                set_distancia_percorrida(new_distancia);
                cout << "Motocicleta - ID:" << get_id() << " andou +2 blocos e está com " << get_combustivel() << " litros de gasolina" << endl;
            }
            else
                cout << "Motocicleta com ID " << get_id() << " não possui todos os pneus calibrados" << endl;
        }
        else
            cout << "Motocicleta com ID " << get_id() << " não possui combustível suficiente" << endl;
    }
    else
        cout << "Motocicleta com ID " << get_id() << " não está com o IPVA em dia" << endl;
}

 void desenhar() override
{
    string espacos(get_distancia_percorrida(), ' ');
    cout << espacos << "  , _oo" << endl;
    cout << espacos << ".-/c-//: :" << endl;
    cout << espacos << "(_)'=='(_)" << endl;
}