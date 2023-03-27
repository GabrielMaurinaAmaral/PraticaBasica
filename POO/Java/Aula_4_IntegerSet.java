public class Aula_4_IntegerSet {
    private boolean[] array = new boolean[101];

    public Aula_4_IntegerSet() {
        for (int i = 0; i < 101; i++) {
            array[i] = false;
        }
    }

    public Aula_4_IntegerSet union(Aula_4_IntegerSet a) {
        Aula_4_IntegerSet array_2 = new Aula_4_IntegerSet();

        for (int i = 0; i < 101; i++) {
            if (this.array[i] || a.array[i]) {
                array_2.array[i] = true;
            }
        }
        return array_2;
    }

    public Aula_4_IntegerSet intersection(Aula_4_IntegerSet a) {
        Aula_4_IntegerSet array_2 = new Aula_4_IntegerSet();
        for (int i = 0; i < 101; i++) {
            if (this.array[i] && a.array[i] == true) {
                array_2.array[i] = true;
            }
        }
        return array_2;
    }

    public void insertElement(int i) {
        this.array[i] = true;
    }

    public void deleteElement(int i) {
        this.array[i] = false;
    }

    public String toString() {
        String s = "";
        for (int i = 0; i < 101; i++)
            if (array[i] == true)
                s += " " + i + " ";
        return s;
    }

    public Boolean isEqualTo(Aula_4_IntegerSet a) {
        for (int i = 0; i < 101; i++) {
            if (this.array[i] != a.array[i])
                return false;
        }
        return true;
    }
}
