public class Aula_5_usar_Banco {
    public static void main(String[] args) {
        Aula_5_Banco b = new Aula_5_Banco(5);

        b.inserir_Banco(0, "GABRIEL", 100.0);
        b.inserir_Banco(1, "BRENO", 50.0);
        b.inserir_Banco(2, "WILLIAM", 10.0);
        b.inserir_Banco(3, "JAMEL", 20.0);
        b.inserir_Banco(4, "PEDRO", 70.0);

        System.out.println(b.total());

    }
}
