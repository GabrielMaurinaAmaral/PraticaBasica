package aula_2;
import java.util.Random;

public class Aula_2_2 {
    public static void main() {
        double d;
        d = Math.sqrt(25);
        d = Math.pow(2, 4);
        d = Math.sin(93);

        Random num = new Random();
        int i = num.nextInt(10);

        System.out.printf("%8.2f", d);
        int[] vetor = new int[10];
        vetor[0] = 5;
        vetor[9] = 9;
        System.out.println("imprimir qualquer coisa");
    }
}
