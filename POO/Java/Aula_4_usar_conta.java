public class Aula_4_usar_conta {
    public static void main(String[] args) {
        Aula_4_Conta fred = new Aula_4_Conta("Fred", 1000);
        Aula_4_Conta richard = new Aula_4_Conta("Richard", 2000);
        richard.retira(500);
        fred.deposita(500); 
        System.out.println(fred);
        System.out.println(richard);
    }
}
