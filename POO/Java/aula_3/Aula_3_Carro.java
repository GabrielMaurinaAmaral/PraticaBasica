package aula_3;

public class Aula_3_Carro {
    // atributos
    private double velocidade;
    private String marca;

    // metodos
    public void acelerar(double intensidade) {}
    public void frear(double intensidade) {}
    public String obterMarca() {return marca;}
    public void imprimirVelocidade() {
        System.out.println("Velocidade: " + velocidade);
    }

}
