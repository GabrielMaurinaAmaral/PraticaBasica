public class Aula_5_Banco {
    private Aula_4_Conta[] Banco;

    public Aula_5_Banco(int tamanho) {
        Banco = new Aula_4_Conta[tamanho];
    }

    public void inserir_Banco(int posição, String nome, double saldo) {
        if ((posição >= 0) && (posição < Banco.length))
            Banco[posição] = new Aula_4_Conta(nome, saldo);
    }

    public int total() {
        int result = 0;
        for (int i = 0; i < Banco.length; i++) {
            result += Banco[i].getSaldo();
        }
        return result;
    }
}
