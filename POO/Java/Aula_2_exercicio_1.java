import java.util.Scanner;

public class Aula_2_exercicio_1 {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int num = teclado.nextInt();

        for (int i = 0; i <= num; i++) {
            System.out.println(i);
        }
    }
}
