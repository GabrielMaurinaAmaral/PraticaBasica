public class Aula_4_usar_IntegerSet {
    public static void main(String[] args) {
        Aula_4_IntegerSet set_1 = new Aula_4_IntegerSet();
        Aula_4_IntegerSet set_2 = new Aula_4_IntegerSet();

        set_1.insertElement(1);
        set_1.insertElement(2);
        set_1.insertElement(3);
        set_1.insertElement(4);
        set_1.deleteElement(3);
        System.out.println(set_1.toString());

        set_2.insertElement(3);
        set_2.insertElement(4);
        set_2.insertElement(5);
        set_2.insertElement(6);
        set_2.deleteElement(5);
        System.out.println(set_2.toString());

        Aula_4_IntegerSet set_4 = set_1.union(set_2);
        System.out.println(set_4.toString());

        Aula_4_IntegerSet set_5 = set_1.intersection(set_2);
        System.out.println(set_5.toString());

        System.out.println(set_1.isEqualTo(set_5));

    }
}
