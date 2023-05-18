public class Aula_7_FilaCliente {
    private Aula_7_Cliente[] clientes;
    private int tamanho, inicio, fim;

    public Aula_7_FilaCliente(int t) {
        clientes = new Aula_7_Cliente[t];
        tamanho = t;
        inicio = -1;
        fim = -1;
    }

    public boolean Fila_Cheia() {
        return fim == tamanho - 1;
    }

    public boolean Fila_Vazia() {
        return inicio == -1;
    }

    public void Enfileirar(Aula_7_Cliente cliente) {
        if (Fila_Cheia()) {
            System.out.println("A fila esta cheia");
        } else {
            if (Fila_Vazia()) {
                inicio = 0;
            }
            fim++;
            clientes[fim] = cliente;
            System.out.println(clientes[fim].getNome() + " add na fila.");
        }
    }

    public void Desenfileirar() {
        if (Fila_Vazia()) {
            System.out.println("A clientes está vazia");
        } else {
            System.out.println(clientes[inicio].getNome() + " removido da fila.");
            clientes[inicio] = null;
            if (inicio == fim) {
                inicio = -1;
                fim = -1;
            } else {
                inicio++;
            }
        }
    }

    public void mostrar_Fila() {
        if (Fila_Vazia()) {
            System.out.println("A Fila de clientes está vazia");
        } else {
            for (int i = inicio; i <= fim; i++) {
                System.out.println(clientes[i].toString());
            }
        }
    }
}
