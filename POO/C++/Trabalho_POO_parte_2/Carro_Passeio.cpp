#include "Veiculo_Motorizado.cpp"
#include "Interface_IPVA.h"

class Carro_Passeio : public Veiculo_Motorizado, public Interface_IPVA
{
private:
    static constexpr float gasto_carro_passeio = 0.75;
    char tipo = 'P';

public:
    Carro_Passeio(int id, int rodas) : Veiculo_Motorizado(id, rodas), tipo('C')
    {
        std::cout << "Carro de Passeio com ID " << get_id() << " foi construído" << std::endl;
    }

    char get_tipo()
    {
        return tipo;
    }

    void mover()
    {
        if (get_ipva())
        {
            if (get_combustivel() >= gasto_carro_passeio)
            {
                if (verificar_pneu())
                {
                    consumir(gasto_carro_passeio);
                    int new_distancia = get_distancia_percorrida() + 2;
                    set_distancia_percorrida(new_distancia);
                    std::cout << "Carro de passeio - ID:" << get_id() << " andou  bloco +5 e está com " << get_combustivel() << " litros de gasolina" << std::endl;
                }
                else
                    std::cout << "Carro de passeio com ID " << get_id() << " não possui todos os pneus calibrados" << std::endl;
            }
            else
                std::cout << "Carro de passeio com ID " << get_id() << " não possui combustível suficiente" << std::endl;
        }
        else
            std::cout << "Carro de passeio com ID " << get_id() << " não está com IPVA em dia" << std::endl;
    }
    void desenhar()
    {
        std::string espacos(get_distancia_percorrida(), ' ');
        std::cout << espacos << "    ____" << std::endl;
        std::cout << espacos << " __/  |_ \\_" << std::endl;
        std::cout << espacos << "|  _     _``-." << std::endl;
        std::cout << espacos << "'-(_)---(_)--'" << std::endl;
    }
};
