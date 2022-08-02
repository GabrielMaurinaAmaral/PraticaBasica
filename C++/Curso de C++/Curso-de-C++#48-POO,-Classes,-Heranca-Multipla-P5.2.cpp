#include "Curso-de-C++#48-POO,-Classes,-Heranca-Multipla-P5.1.h"
#include <iostream>
using namespace std;

int main()
{
    Base_1 *obj_1 = new Base_1;
    Base_2 *obj_2 = new Base_2;
    Principal *obj_3 = new Principal;

    obj_1->print_base_1();
    obj_2->print_base_2();

    obj_3->print_base_1();
    obj_3->print_base_2();

    return 0;
}