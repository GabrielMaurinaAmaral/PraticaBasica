import java.io.Serializable;

public class Aula_6_Pessoa_1 implements Serializable {
    private String nome;
    private String cpf;
    private String telefone;

    public Aula_6_Pessoa_1(String nome, String cpf, String telefone) {
        this.nome = nome;
        this.cpf = cpf;
        this.telefone = telefone;
    }

    public void imprimirDados() {
        System.out.println("Nome: " + nome);
        System.out.println("CPF: " + cpf);
        System.out.println("Telefone: " + telefone);
    }
}
