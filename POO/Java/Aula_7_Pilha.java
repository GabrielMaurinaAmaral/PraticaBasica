public class Aula_7_Pilha {
    private Aula_7_Revista[] revistas;
    private int capacidade_max, topo;

    public Aula_7_Pilha(int tam) {
        this.capacidade_max = tam;
        this.topo = tam-1;
        revistas = new Aula_7_Revista[tam];
    }

    public void inserir(String titulo, int quant_page, int num_edicao, int mes, int ano) {
        if (topo >= capacidade_max) {
            System.out.println("Pilha cheia");
        } else {
            revistas[topo] = new Aula_7_Revista(titulo, quant_page, num_edicao, mes, ano);
            topo--;
            System.out.println("revista foi inserida");
        }
    }

    public void remove() {
        if (topo > 49) {
            System.out.println("pilha esta vazia");
        } else {
            revistas[topo] = null;
            topo++;
            System.out.println("revista foi removida");
        }
    }

    public void mostrar_Pilha() {
        for (int i = topo; i < capacidade_max; i++) {
            System.out.println(revistas[i].toString());
        }
    }
}
