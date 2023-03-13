import java.util.Scanner;

public class Aula_2_exercicio_4 {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int num = teclado.nextInt();
        int cont;

        for (int i = 1; i <= num; i++) {
            cont = 0;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) {
                    cont++;
                }
            }
            if (cont == 2) {
                System.out.print("\n" + i);
            }
        }
    }
    Sy
}