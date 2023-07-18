#include "Carro_Esportivo.h"

Carro_Esportivo::Carro_Esportivo(int id, int rodas) : Veiculo_Motorizado(id, rodas), tipo('E')
{
    tipo = 'E';
    std::cout << "Carro Esportivo com ID " << get_id() << " foi construído" << endl;
}

char Carro_Esportivo::get_tipo()
{
    return tipo;
}

void Carro_Esportivo::mover()
{
    if (get_ipva())
    {
        if (get_combustivel() >= gasto_carro_esportivo)
        {
            if (verificar_pneu())
            {
                consumir(gasto_carro_esportivo);
                int new_distancia = get_distancia_percorrida() + 10;
                set_distancia_percorrida(new_distancia);
                std::cout << "Carro Esportivo - ID:" << get_id() << " andou  bloco +10 e está com " << get_combustivel() << " litros de gasolina" << endl;
            }
            else
                std::cout << "Carro Esportivo com ID " << get_id() << " não possui todos os pneus calibrados" << endl;
        }
        else
            std::cout << "Carro Esportivo com ID " << get_id() << " não possui combustível suficiente" << endl;
    }
    else
        std::cout << "Carro Esportivo com ID " << get_id() << " não está com IPVA em dia" << endl;
}

void Carro_Esportivo::desenhar()
{
    string espacos(get_distancia_percorrida(), ' ');
    std::cout << espacos << "        __" << endl;
    std::cout << espacos << "      ~( @\\ \\" << endl;
    std::cout << espacos << "   _____]_[_/_>__" << endl;
    std::cout << espacos << "  / __ \\<> |  __ \\" << endl;
    std::cout << espacos << "=\\_/__\\_\\__|_/__\\" << endl;
    std::cout << espacos << "   (__)      (__)" << endl;
}
