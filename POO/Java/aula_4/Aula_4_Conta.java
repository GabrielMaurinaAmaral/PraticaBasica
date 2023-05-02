package aula_4;
public class Aula_4_Conta {
    private String nomeCorrentista;
    private double saldo;
    // construtor
    
    public Aula_4_Conta(String n, double s) {
        nomeCorrentista = n;
        saldo = s;
    }
    //mostrar
    public double getSaldo() {
        return saldo;
    }
    public String getNome() {
        return nomeCorrentista;
    }
    // alterar
    public void deposita(double quantia) {
        saldo = saldo + quantia;
    }
    public void retira(double quantia) {
        if (quantia <= saldo)
            saldo = saldo - quantia;
    }
    // outras funções
    public void transfereDe(Aula_4_Conta this, double quanto) {
        deposita(quanto);
        this.retira(quanto);
    }
    // mostrar funcionalidade
    public String toString() {
        return "Conta de " + nomeCorrentista + " tem saldo " + saldo;
    }
}
