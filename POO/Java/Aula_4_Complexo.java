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
        if (imaginario > 0)
            System.out.println("Numero Complexo: " + real + " + " + imaginario + "i");
        else if (imaginario == 0)
            System.out.println(real);
        else
            System.out.println(real + " " + imaginario + "i");
    }
 
    public boolean elgual(Aula_4_Complexo c) {
        if (c.real == this.real && c.imaginario == this.imaginario)
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
        int aux_r = (this.real * c.real) - (this.imaginario * c.imaginario);
        int aux_i = (this.real * c.imaginario) + (this.imaginario * c.real);

        this.real = aux_r;
        this.imaginario = aux_i;
    }

    public void divide(Aula_4_Complexo c) {
        int aux_r = ((this.real * c.real) + (this.imaginario * c.imaginario)) / ((c.real * c.real) + (c.imaginario * c.imaginario));
        int aux_i = ((this.imaginario * c.real) - (this.real * c.imaginario)) / ((c.real * c.real) + (c.imaginario * c.imaginario));
        this.real = aux_r;
        this.imaginario = aux_i;
    }
}
