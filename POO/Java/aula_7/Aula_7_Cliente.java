
public class Aula_7_Cliente {
    private String nome;
    private char sexo;

    public Aula_7_Cliente() {
        String nome=" ";
        char sexo=' ';
    }

    public Aula_7_Cliente(String n, char s) {
        this.nome = n;
        this.sexo = s;
    }

    public String getNome() {
        return nome;
    }

    public String toString() {
        return "\nnome = " + nome + "\nsexo = " + sexo;
    }    
}
