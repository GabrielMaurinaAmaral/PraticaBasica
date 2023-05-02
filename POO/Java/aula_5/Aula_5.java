package Aula_5;
public class Aula_5 {
    public static void main(String[] args) {
        ///////////
        int[] categorias = new int[30];
        categorias[0] = 100;
        categorias[29] = 0;
        categorias[1] = categorias[0];
        categorias[2] = categorias[3 * 2 + 1];
        for (int i = 0; i < 30; i++)
            categorias[i] = i + 70;

        ///////////
        int size = 10;
        int[] nums = new int[10];
        for (int a = 1; a < size; a++)
            for (int b = size - 1; b >= a; b--) {
                if (nums[b - 1] > nums[b]) { // se es ta fora de
                    // ordem t roca os elementos
                    int t = nums[b - 1];
                    nums[b - 1] = nums[b];
                    nums[b] = t;
                }
            }

        ///////////
        int[][] table = new int[3][4];
        table[0][1] = 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                table[i][j] = i + j;
        int[][] newTable = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

        ///////////
        int[][] data = new int[3][];
        data[0] = new int[1];
        data[1] = new int[2];
        data[2] = new int[4];
        int[][] moreData = { { 1 }, { 2, 3 }, { 4, 5, 6 } };

        int[] data2 = { 3, 4, 5, 6 };
        // os dois lacos fazem a mesma coisa
        for (int i = 0; i < data2.length; i++)
            System.out.println(data2[i]);
        for (int v : data2)
            System.out.println();
    }
}