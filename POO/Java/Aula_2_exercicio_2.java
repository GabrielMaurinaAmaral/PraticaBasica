import java.util.Scanner;

public class Aula_2_exercicio_2 {
    public static void main(String[] args){
        Scanner teclado = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int num = teclado.nextInt();
        
        int cont = 0;
        for (int i = 1; i<=num; i++){
            if(num%i==0){
                cont++;
            }
        }
        if(cont==2){
            System.out.print("e primo");
        }
        else{
            System.out.print("nao e primo");
        }
    }
}
