import java.util.HashSet;

public class ExemploSet4 {
    public static void main(String[] args) {
        HashSet<Integer> set = new HashSet<Integer>();

        set.add(new Integer(123));
        set.add(111);
        set.add(Integer.parseInt("877"));
        // set.add(”877”); Erro de compila ̧c ̃ao: m ́etodo n ̃ao aplic ́avel
        set.add(123);

        int sum = 0;
        System.out.print("Soma de ");

        for (Integer i : set) {
            System.out.print(i + " ");
            sum += i;
        }
        System.out.println(" ́e " + sum);
        // Soma de 111 877 123 ́e 1111]
    }
}
