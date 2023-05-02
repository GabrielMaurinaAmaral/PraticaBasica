package aula_2;
import java.util.Random;

public class Aula_2_exercicio_5 {
    public static void main (String[] args){
        int[] vetor = new int[10];
        Random x = new Random();
        int i, j, aux;

        for(i = 0; i<10; i++){
    		    vetor[i] = x.nextInt(10);
        }
        
        for(i=0; i<10; i++){
            for(j=0; j<i; j++){
                if(vetor[i]<vetor[j]){
                    aux=vetor[i];
                    vetor[i]=vetor[j];
                    vetor[j]=aux;
                }
            }
        }

        System.out.print("\nVetor: |");
        for(i = 0; i<10; i++){
            System.out.print(vetor[i] + "|");
        }
    }
}
