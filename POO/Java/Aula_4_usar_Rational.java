public class Aula_4_usar_Rational {
    public static void main(String[] args) {
        Aula_4_Rational f1 = new Aula_4_Rational();
        Aula_4_Rational f2 = new Aula_4_Rational(3);
        Aula_4_Rational f3 = new Aula_4_Rational(3, 9);
        Aula_4_Rational f4 = new Aula_4_Rational(12, 24);

        f1.imprimirFracao();
        f2.imprimirFracao();
        f3.imprimirFracao();
        f4.imprimirFracao();
        System.out.println(" SOMA -------------------------");
        f1.somar(f2);
        f3.somar(f4);
        f1.imprimirFracao();
        f3.imprimirFracao();

        System.out.println(" SUBTRAIR-------------------------");
        f2.subtrair(f1);
        f4.subtrair(f3);
        f2.imprimirFracao();
        f4.imprimirFracao();

        System.out.println(" MULTIPLICAR-------------------------");
        f1.multiplicar(f3);
        f2.multiplicar(f4);
        f1.imprimirFracao();
        f2.imprimirFracao();

        System.out.println(" DIVIDIR-------------------------");
        f3.dividir(f1);
        f4.dividir(f2);
        f3.imprimirFracao();
        f4.imprimirFracao();
        System.out.println("-------------------------");

        f1.imprimirNumerico(0);
        f2.imprimirNumerico(1);
        f3.imprimirNumerico(2);
        f4.imprimirNumerico(3);
    }
}
