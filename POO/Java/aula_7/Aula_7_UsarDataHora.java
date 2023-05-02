package aula_7;
public class Aula_7_UsarDataHora {
    public static void main(String[] args) {
        Aula_7_DataHora zero = new Aula_7_DataHora();
        Aula_7_DataHora so_data = new Aula_7_DataHora(31, 3, 2003);
        Aula_7_DataHora hoje_1 = new Aula_7_DataHora(9, 11, 45, 30, 5, 2023);
        Aula_7_DataHora hoje_2 = new Aula_7_DataHora(9, 11, 45, 30, 5, 2023);

        System.out.print(hoje_1);
        System.out.print(" e igual a ");
        System.out.print(hoje_2);
        System.out.println(" ?");

        if (hoje_1.eIgual(hoje_2))
            System.out.println("é igual");
        else
            System.out.println("não é igual");

        System.out.print(so_data.toString());
        System.out.print(" e igual a ");
        System.out.print(zero.toString());
        System.out.println(" ?");

        if (so_data.eIgual(zero))
            System.out.println("é igual");
        else
            System.out.println("não é igual");
    }
}