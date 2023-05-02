package aula_7;
public class Aula_7_Hora {
    private int segundo, minutos;
    private int hora;

    public Aula_7_Hora() {
        segundo = 0;
        minutos = 0;
        hora = 0;
    }

    public Aula_7_Hora(int h, int m, int s) {
        if (dataEValida(h, m, s)) {
            segundo = h;
            minutos = m;
            hora = s;
        } else {
            segundo = 0;
            minutos = 0;
            hora = 0;
        }
    }

    public boolean dataEValida(int h, int m, int s) {
        if ((s >= 0) && (s <= 59) && (m >= 0) && (m <= 59) && (h >= 0) && (h <= 23)) {
            return true;
        } else {
            return false;
        }
    }

    public boolean eIgual(Aula_7_Hora outraHora) {
        if ((segundo == outraHora.segundo) && (minutos == outraHora.minutos) && (hora == outraHora.hora)) {
            return true;
        } else {
            return false;
        }
    }

    public String toString() {
        return hora + ":" + minutos + ":" + segundo;
    }
}
