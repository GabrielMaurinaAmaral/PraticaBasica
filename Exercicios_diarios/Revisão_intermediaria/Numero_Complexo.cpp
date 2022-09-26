#include <iostream>
using namespace std;

class Numero_Complexo
{
protected:
    float real, imaginario;

public:
    Numero_Complexo(float r, float i) : real{r}, imaginario{i} {}
    Numero_Complexo() { real = 0, imaginario = 0; }
    void print()
    {
        printf("\n%0.1f + %0.1fi\n", this->real, this->imaginario);
    }
    bool comparar(Numero_Complexo &parametro)
    {
        if (this->real == parametro.real && this->imaginario == parametro.imaginario)
            return true;
        else
            return false;
    }
    void soma(Numero_Complexo &parametro)
    {
        this->real += parametro.real;
        this->imaginario += parametro.imaginario;
    }
    void soma(Numero_Complexo &parametro)
    {
        this->real = this
        this->imaginario += parametro.imaginario;
    }
    
};

int main()
{
    Numero_Complexo a1{};
    Numero_Complexo a2{5, 10};

    a1.print();
    a2.print();
    a1.soma(a2);
    a1.print();
    return 0;
}