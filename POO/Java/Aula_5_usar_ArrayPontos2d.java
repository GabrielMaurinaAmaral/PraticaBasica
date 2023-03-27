public class Aula_5_usar_ArrayPontos2d {
    public static void main(String[] args) {
        Aula_5_ArrayPontos2D pontos = new Aula_5_ArrayPontos2D(5);

        System.out.println(pontos.tamanho());

        pontos.modifica(0, 2.0);
        pontos.modifica(1, 4.0);
        pontos.modifica(2, 6.0);
        pontos.modifica(4, 10.0);
        pontos.modifica(5, 12.0);

        for (int i = 0; i < pontos.tamanho(); i++)
            System.out.print(" - " + pontos.valor(i));

        System.out.println(pontos.toString());

    }
}
