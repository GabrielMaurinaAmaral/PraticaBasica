#include "Aula_4_Pessoa1.cpp"

int main()
{
    Pessoa Ana;
    Pessoa Bete;
    Pessoa Carlos("Carlos", "222.333.444-55", 2000, 23, 81.3, 1.84);

    Ana.set_nome("Ana");
    Bete.set_ano(2003);
    Bete.set_idade(20);
    Carlos.set_cpf("444.555.666-77");
    Carlos.set_altura(1.67);

    Ana.imprimir_dados();
    Bete.imprimir_dados();
    Carlos.imprimir_dados();

    return 0;
}