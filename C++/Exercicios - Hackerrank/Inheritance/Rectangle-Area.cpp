#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int base, altura;

public:
    void display()
    {
        cout << base << " " << altura << endl;
    }
};

class RectangleArea : public Rectangle
{
public:
    void read_input()
    {
        cin >> base >> altura;
    }
    void display()
    {
        cout << base * altura;
    }
};

int main()
{
    RectangleArea r_area;

    r_area.read_input();
    r_area.Rectangle::display();
    r_area.display();

    return 0;
}