import java.util.Random;

public class Aula_4_Die {
    private int sideUp;

    public Aula_4_Die() {
        sideUp = 1;
    }

    public Aula_4_Die(int s) {
        sideUp = s;
    }

    public int getSideUp() {
        return sideUp;
    }

    public void roll() {
        Random num = new Random();
        sideUp = num.nextInt(6)+1;
    }
    public void mostrar() {
        System.out.println(sideUp);
    }
}