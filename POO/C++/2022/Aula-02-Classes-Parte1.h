// arquivo de cabeçalho(header)
#ifndef TEMPO_H // SE NÃO FOI DEFINIDA AINDA, ela o define agora
#define TEMPO_H

class Tempo
{
private:
    int hora, minuto, segundo; // mesbros de dadso

public:
    Tempo(); // contruir - inicializar
    Tempo(int, int, int);
    void set_Tempo(int, int, int);
    void imprimir();
    ~Tempo() {} // destruindo
};

#endif
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    float radius;
    int x, y;

public:
    Circle();
    Circle(float = 0.0, int = 0, int = 0);
    ~Circle() {}

    // funções membros interface
    float area();
    float diameter();
    void set_radius(float); // setter
    void set_origin(int, int);
    void imprimir();
    float get_radius(); // getter
}; 

#endif
