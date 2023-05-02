package aula_4;
public class Aula_4_DieDemo {
    public static void main(String[] args) {
        Aula_4_Die d1 = new Aula_4_Die();
        Aula_4_Die d2 = new Aula_4_Die(5);

        d1.mostrar();
        d2.mostrar();
        d1.roll();
        d2.roll();
        d1.mostrar();
        d2.mostrar();
        int soma = d1.getSideUp() + d2.getSideUp();
        System.out.println("Soma: " + soma);
    }
}
