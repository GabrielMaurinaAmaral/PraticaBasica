#include <iostream>
using namespace std;

class Aviao
{
public:
    int vel;
    int name;
    void imp();
    bool get_ligado();
    void set_ligado(int prw);
    int get_velmax();
    void set_velmax(int rk);
    int get_blind();
    void set_blind(int ek);

private:
    int velmax;
    int tipo;
    int blind;
    std::string nome = "safra";
    bool ligad;
};
class Moto : public Aviao
{
public:
    Moto();
};
Moto::Moto()
{
    vel = 288;
    name = 282;
}
bool Aviao::get_ligado()
{
    return ligad;
};
void Aviao::set_ligado(int prw)
{
    ligad = prw;

    if (ligad == 1)
        ligad = true;
    
    else if (ligad == 0)
        ligad = false;
}
int Aviao::get_velmax()
{
    return velmax;
}
void Aviao::set_velmax(int rk)
{
    velmax = rk;
    if (velmax == 1)
        velmax = 50;
    
    else if (velmax == 2)
        velmax = 60;
    
    else if (velmax == 3)
        velmax = 70;
}
class carro : public Aviao
{
public:
    carro();
};
carro::carro()
{
    vel = 99;
    name = 292;
}
class astuna : public Aviao
{
public:
    astuna();
};
astuna::astuna()
{
    name = 9999;
    vel = 10;
}
int Aviao::get_blind()
{
    return blind;
}
void Aviao::set_blind(int ek)
{
    blind = ek;
    if (blind == 1)
        blind = 29;
    
    else if (blind == 2)
        blind = 12;
}
void Aviao::imp()
{
    std::cout << "\nvel...:" << vel << endl;
    std::cout << "name..:" << name << endl;
    std::cout << "ligad.:" << get_ligado() << endl;
    std::cout << "velmax:" << get_velmax() << endl;
    std::cout << "blind.:" << get_blind() << endl;
}

int main()
{
    Moto *mo1 = new Moto();
    Moto *mo2 = new Moto();

    mo1->vel;
    mo2->name;
    mo1->imp();
    mo2->imp();
    mo1->set_ligado(0);
    mo1->set_ligado(0);
    if (mo1->get_ligado())
        cout << "\nconectado" << endl;
    
    else
        cout << "\ndisconectado" << endl;

    cout << mo1->vel;
    cout << mo2->name;

    carro *car1 = new carro();
    carro *car2 = new carro();

    car1->vel;
    car2->name;

    car1->imp();
    car2->imp();

    car1->get_velmax();
    car2->get_velmax();

    car1->set_ligado(1);
    car2->set_ligado(1);
    if (car1->get_ligado())
    {
        cout << "\nconect" << endl;
    }
    else
    {
        cout << "\ndisconect" << endl;
    }
    cout << car1->get_velmax();
    cout << car2->get_velmax();

    cout << car1->vel;
    cout << car2->name;
    cout << "----------------------------------------------" << endl;
    astuna *atu1 = new astuna();
    astuna *atu2 = new astuna();

    atu1->imp();
    atu2->imp();
    atu2->get_blind();
    atu2->get_blind();
}
