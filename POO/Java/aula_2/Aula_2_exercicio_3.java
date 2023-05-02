package aula_2;
import java.util.Scanner;

public class Aula_2_exercicio_3 {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int num = teclado.nextInt();

        int cont = 0;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                cont += i;
            }
        }
        if (cont == num) {
            System.out.print("e perfeito");
        } else {
            System.out.print("nao e perfeito");
        }
    }
}
