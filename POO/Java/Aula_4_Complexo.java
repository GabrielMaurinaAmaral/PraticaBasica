import math;

public class Aula_4_Complexo {
    private int real, imaginario;

    public Aula_4_Complexo() {
        real = 0;
        imaginario = 0;
    }

    public Aula_4_Complexo(int r) {
        real = r;
        imaginario = 0;
    }

    public Aula_4_Complexo(int r, int i) {
        real = r;
        imaginario = i;
    }

    public void inicializaNumero(int r, int i) {
        real = r;
        imaginario = i;
    }

    public void imprimirNumero() {
        System.out.println(real + " + " + imaginario + "i");
    }

    public boolean elgual(Aula_4_Complexo c) {
        if (c.real == this.real || c.imaginario == this.imaginario)
            return true;
        else
            return false;
    }

    public void soma(Aula_4_Complexo c) {
        this.real += c.real;
        this.imaginario += c.imaginario;
    }

    public void subtrai(Aula_4_Complexo c) {
        this.real -= c.real;
        this.imaginario -= c.imaginario;
    }

    public void multiplica(Aula_4_Complexo c) {
        this.real = (this.real*c.real)-(this.imaginario*c.imaginario);
        this.imaginario = (this.real*c.imaginario)+(this.imaginario*c.real);
    }

    public void divide(Aula_4_Complexo c) {
        this.real = ((this.real*c.real)-(this.imaginario*c.imaginario)) / (pow(c.imaginario,2));
        
        
        
        
        
        
        this.imaginario = ((this.real*c.imaginario)+(this.imaginario*c.real));
    }
}
