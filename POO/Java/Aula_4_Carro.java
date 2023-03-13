public class Aula_4_Carro {
    private float velocidade;
    
    public void definirVelocidade(float v) {
        if (v <= 200)
            velocidade = v;
        else
            velocidade = 0;
    }

    public void acelerar(float v) {
        if ((velocidade + v) <= 200)
            velocidade += v;
        else
            velocidade = 200;
    }

    public void mostrar_velocidade(){
        System.out.println(velocidade);
    }
}