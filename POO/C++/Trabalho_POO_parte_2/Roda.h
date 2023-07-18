#ifndef RODA_H
#define RODA_H

#include <string>

class Roda
{
private:
    bool calibragem_pneu;

public:
    Roda();
    void set_calibragem(bool);
    bool get_calibragem();
    string to_string();
};

#endif // RODA_H
