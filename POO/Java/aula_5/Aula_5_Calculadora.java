package Aula_5;
public class Aula_5_Calculadora {
  public static void main(String[] argumentos) {
    if (argumentos.length < 3) {
      System.out.println("Este programa precisa que tres argumentos sejam passados " + "pela linha de comando.");
      System.exit(1);
    }

    int[] valor = new int[argumentos.length];
    int resultado = 0;

    for (int i = 1; i < argumentos.length; i++)
      valor[i - 1] = Integer.parseInt(argumentos[i]);

    switch (argumentos[0].charAt(0)) {
      case '+':
        for (int i = 0; i < argumentos.length; i++)
          resultado += valor[i];
        break;
      case 'x':
        resultado = 1;
        for (int i = 0; i < argumentos.length; i++)
          resultado *= valor[i];
        break;
    }

    for (int indice = 0; indice < argumentos.length; indice++)
      System.out.print(argumentos[indice] + " ");

    System.out.println("= " + resultado);
  }
}
