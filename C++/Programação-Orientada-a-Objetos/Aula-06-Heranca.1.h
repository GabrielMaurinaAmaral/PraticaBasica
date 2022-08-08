#include <iostream>
using namespace std;

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa
{
    // private:
protected: //é uma private que abre excesso para subclasses dessa classe
    string nome, endereco;

public:
    Pessoa(string, string);
    ~Pessoa();
    void set_nome(string);
    void set_endereco(string);
    string get_nome();
    string get_endereco();
    void print();
};

#ifndef Professor_H
#define ALUNO_H

class Aluno : public Pessoa
{
private:
    string curso;
    int matricula;

public:
    Aluno(string, string, string, int);
    ~Aluno();
    void set_curso(string);
    void set_matricula(int);
    string get_curso();
    int get_matricula();
    void print();

};

#ifndef PROFESSOR_H
#define PROFESSOR_H

class Professor : public Pessoa
{
private:
    int siape, categoria;
    string instituto;

public:
    Professor(string, string, int, int, string);
    ~Professor();
    void set_siape(int);
    void set_categoria(int);
    void set_instituicao(string);
    int get_siape();
    int get_categoria();
    string get_instituicao();
    void print();

};

#endif
#endif
#endif
