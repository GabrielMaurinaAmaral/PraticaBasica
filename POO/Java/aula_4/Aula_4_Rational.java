package aula_4;
public class Aula_4_Rational {
    private int numerador;
    private int denominador;

    public Aula_4_Rational() {
        numerador = 1;
        denominador = 1;
    }

    public Aula_4_Rational(int n) {
        numerador = n;
        denominador = 1;
    }

    public Aula_4_Rational(int n, int d) {
        numerador = n;
        denominador = d;
        this.simplificar();
    }

    private void simplificar() {
        int mdc = MDC(numerador, denominador);
        this.numerador = numerador / mdc;
        this.denominador = denominador / mdc;
    }

    private int MDC(int a, int b) {
        while (b != 0) {
            int resto = a % b;
            a = b;
            b = resto;
        }
        return a;
    }

    public void somar(Aula_4_Rational r) {
        if (this.denominador == r.denominador) {
            this.numerador += r.numerador;
        } else {
            int aux_1 = this.numerador;
            int aux_2 = this.denominador;
            int aux_3 = r.numerador;
            int aux_4 = r.denominador;

            this.numerador = aux_1 * aux_4;

            this.numerador += aux_3 * aux_2;
            this.denominador = aux_2 * aux_4;
            this.simplificar();
        }
    }

    public void subtrair(Aula_4_Rational r) {
        if (this.denominador == r.denominador) {
            this.numerador -= r.numerador;
        } else {
            int aux_1 = this.numerador;
            int aux_2 = this.denominador;
            int aux_3 = r.numerador;
            int aux_4 = r.denominador;

            this.numerador = aux_1 * aux_4;
            r.numerador = aux_3 * aux_2;

            this.numerador -= r.numerador;
            this.denominador = aux_2 * aux_4;
            this.simplificar();
        }
    }

    public void multiplicar(Aula_4_Rational r) {
        int aux_1 = this.numerador;
        int aux_2 = this.denominador;

        this.numerador = aux_1 * r.numerador;
        this.denominador = aux_2 * r.denominador;
        this.simplificar();
    }

    public void dividir(Aula_4_Rational r) {
        int aux_1 = this.numerador;
        int aux_2 = this.denominador;

        this.numerador = aux_1 * r.denominador;
        this.denominador = aux_2 * r.numerador;
        this.simplificar();
    }

    public void imprimirFracao() {
        System.out.println(numerador + "/" + denominador);
    }

    public void imprimirNumerico(int casas) {
        System.out.printf("%." + casas + "f\n", (float) numerador / (float) denominador);
    }
}
