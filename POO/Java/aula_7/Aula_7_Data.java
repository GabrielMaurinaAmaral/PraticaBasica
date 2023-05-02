package aula_7;
public class Aula_7_Data {
    private int dia, mes;
    private int ano;

    public Aula_7_Data() {
        dia = 0;
        mes = 0;
        ano = 0;
    }

    public Aula_7_Data(int d, int m, int a) {
        if (dataEValida(d, m, a)) {
            dia = d;
            mes = m;
            ano = a;
        } else {
            dia = 0;
            mes = 0;
            ano = 0;
        }
    }

    public boolean dataEValida(int d, int m, int a) {
        if ((d >= 1) && (d <= 31) && (m >= 1) && (m <= 12)) {
            return true;
        } else {
            return false;
        }
    }

    public boolean eIgual(Aula_7_Data outraData) {
        if ((dia == outraData.dia) && (mes == outraData.mes) && (ano == outraData.ano)) {
            return true;
        } else {
            return false;
        }
    }

    public String toString() {
        return dia + "/" + mes + "/" + ano;
    }
}