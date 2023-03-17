public class Aula_4_usar_Complexo {
    public static void main(String[] args) {
        Aula_4_Complexo c1 = new Aula_4_Complexo();
        Aula_4_Complexo c2 = new Aula_4_Complexo(4);
        Aula_4_Complexo c3 = new Aula_4_Complexo(6, 9);

        c1.inicializaNumero(2, 5);
        c2.inicializaNumero(2, 5);

        c1.imprimirNumero();
        c2.imprimirNumero();
        c3.imprimirNumero();

        System.out.println(c1.elgual(c2));
        System.out.println(c1.elgual(c3));

        c1.soma(c2);
        c1.imprimirNumero();

        c2.subtrai(c3);
        c2.imprimirNumero();

        c1.multiplica(c2);
        c1.imprimirNumero();

        c1.divide(c3);
        c1.imprimirNumero();
    }
}
