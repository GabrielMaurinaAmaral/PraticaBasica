package aula_7;
public class Aula_7_DataHora {
    private Aula_7_Data estaData;
    private Aula_7_Hora estaHora;

    public Aula_7_DataHora() {
        estaData = new Aula_7_Data();
        estaHora = new Aula_7_Hora();
    }

    public Aula_7_DataHora(int dia, int mes, int ano) {
        estaData = new Aula_7_Data(dia, mes, ano);
        estaHora = new Aula_7_Hora();
    }

    public Aula_7_DataHora(int hora, int minuto, int segundo, int dia, int mes, int ano) {
        estaHora = new Aula_7_Hora(hora, minuto, segundo);
        estaData = new Aula_7_Data(dia, mes, ano);
    }

    public boolean eIgual(Aula_7_DataHora outraDataHora) {
        if (this.estaData.eIgual(outraDataHora.estaData) && this.estaHora.eIgual(outraDataHora.estaHora)) {
            return true;
        } else {
            return false;
        }
    }

    public String toString() {
        return estaData.toString() + " " + estaHora.toString();
    }
}
