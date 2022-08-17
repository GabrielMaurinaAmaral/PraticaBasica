#include "Aula-06-Heranca.1.h"
#include <iostream>
using namespace std;

// PESSOA
Pessoa::Pessoa(string n, string e) : nome{n}, endereco{e}
{
    cout << "\nPESSOA CRIADO\n";
}
Pessoa::~Pessoa()
{
    cout << "\nPESSOA DESTRUIDO\n";
}
void Pessoa::set_nome(string n)
{
    nome = n;
}
void Pessoa::set_endereco(string e)
{
    endereco = e;
}
string Pessoa::get_nome()
{
    return nome;
}
string Pessoa::get_endereco()
{
    return endereco;
}
void Pessoa::print()
{
    cout << "\n\nNome....:" << nome;
    cout << "\nEndereco:" << endereco;
}

// ALUNO
Aluno::Aluno(string n, string e, string c, int m) : Pessoa{n, e}, curso{c}, matricula{m}
{
    cout << "\nALUNO CRIADO\n";
}
Aluno::~Aluno()
{
    cout << "\nALUNO DESTRUIDO\n";
}
void Aluno::set_curso(string c)
{
    curso = c;
}
void Aluno::set_matricula(int m)
{
    matricula = m;
}
string Aluno::get_curso()
{
    return curso;
}
int Aluno::get_matricula()
{
    return matricula;
}
void Aluno::print()
{
    cout << "\n\nNome....:" << nome;
    cout << "\nEndereco:" << endereco;
    cout << "\nCurso....:" << curso;
    cout << "\nMatricula:" << matricula;
}

// PROFESSOR
Professor::Professor(string n, string e, int s, int c, string i) : Pessoa{n, e}, siape{s}, categoria{c}, instituto{i}
{
    cout << "\nPROFESSOR CRIADO\n";
}
Professor::~Professor()
{
    cout << "\nPROFESSOR DESTRUIDO\n";
}
void Professor::set_siape(int s)
{
    siape = s;
}
void Professor::set_categoria(int c)
{
    categoria = c;
}
void Professor::set_instituicao(string i)
{
    instituto = i;
}
int Professor::get_siape()
{
    return siape;
}
int Professor::get_categoria()
{
    return categoria;
}
string Professor::get_instituicao()
{
    return instituto;
}
void Professor::print()
{
    Pessoa::print();
    cout << "\nSiape.....:" << siape;
    cout << "\nCategoria.:" << categoria;
    cout << "\nInstituicao:" << instituto;
}