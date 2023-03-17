public class Aula_4_Rational {
    private int numerador;
    private int demoninador;

    public Aula_4_Rational() {
        numerador = 1;
        demoninador = 1;
    }

    public Aula_4_Rational(int n) {
        numerador = n;
        demoninador = 1;
    }

    public Aula_4_Rational(int n, int d) {
        numerador = n / MDC(n, d);
        demoninador = d / MDC(n, d);
        System.out.println(MDC(n, d));
    }

    private int MDC(int a, int b) {
        while (b != 0) {
            int resto = a % b;
            a = b;
            b = resto;
        }
        return a;

        
    }

    public void mostrar() {
        System.out.println(numerador + "/" + demoninador);
    }
}
