public class Aula_5_ArrayPontos2D {
    private Aula_5_Ponto2D[] Pontos;

    public Aula_5_ArrayPontos2D(int numero) {
        Pontos = new Aula_5_Ponto2D[numero];
    }

    public int tamanho() {
        return Pontos.length;
    }

    public void modifica(int posicao, Double valor) {
        if ((posicao >= 0) && (posicao < Pontos.length))
            Pontos[posicao] = new Aula_5_Ponto2D(posicao, posicao, valor);
    }

    public double valor(int posicao) {
        if ((posicao >= 0) && (posicao < Pontos.length) && Pontos[posicao] != null)
            return Pontos[posicao].getValor();
        else
            return Double.NaN;
    }

    public String toString() {
        String resultado = "O Pontos tem " + Pontos.length + " elementos:\n";
        for (int i = 0; i < Pontos.length; i++)
            if (Pontos[i] != null)
                resultado += Pontos[i].getValor() + " ";
        return resultado;
    }
}
