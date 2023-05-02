package aula_4;
public class Aula_4_Pessoa {
    private String nome, cpf;
    private int anoNasc;

    // Construtores
    public Aula_4_Pessoa() {
        nome = "";
        cpf = "";
        anoNasc = 0;
    }

    public Aula_4_Pessoa(String no) {
        nome = no;
        cpf = "";
        anoNasc = 0;
    }

    public Aula_4_Pessoa(String no, String c, int a) {
        nome = no;
        cpf = c;
        anoNasc = a;
    }

    // alterar variavel - set
    public void setNome(String n) {
        nome = n;
    }

    public void setCPF(String c) {
        cpf = c;
    }

    public void setAno(int a) {
        anoNasc = a;
    }

    // mostrar variaveis - get
    public void imprimirDados() {
        System.out.println("\nNome: " + nome);
        System.out.println("CPF: " + cpf);
        System.out.println("Ano: " + anoNasc);

    }
}
