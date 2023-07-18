#include "Bicicleta.h"

Bicicleta::Bicicleta(int id, int rodas) : Veiculo(id, rodas)
{
    tipo = 'B';
    std::cout << "Bicicleta com ID " << get_id() << " foi construída" << endl;
}

char Bicicleta::get_tipo() 
{
    return tipo;

}
void Bicicleta::mover() 
{
    if (verificar_pneu())
    {
        int new_distancia = get_distancia_percorrida() + 2;
        set_distancia_percorrida(new_distancia);
        std::cout << "Bicicleta - ID:" << get_id() << " andou +2 blocos" << endl;
    }
    else
        std::cout << "Bicicleta com ID " << get_id() << " não possui todos os pneus calibrados" << endl;
}

void Bicicleta::desenhar() 
{
    string espacos(get_distancia_percorrida(), ' ');
    std::cout << espacos << "   __o" << endl;
    std::cout << espacos << " _`\\<,_: " << endl;
    std::cout << espacos << " (*)/ (*)" << endl;
}