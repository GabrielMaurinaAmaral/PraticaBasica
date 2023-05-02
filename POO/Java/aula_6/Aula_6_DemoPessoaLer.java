package aula_6;
import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class Aula_6_DemoPessoaLer {
  public static void main(String[] args) {
    File arquivo = new File("agenda.dat");

    try {
      FileInputStream fin = new FileInputStream(arquivo);
      ObjectInputStream oin = new ObjectInputStream(fin);

      Aula_6_Pessoa_1[] agendaArq = (Aula_6_Pessoa_1[]) oin.readObject();
      oin.close();
      fin.close();

      for (Aula_6_Pessoa_1 p : agendaArq) {
        p.imprimirDados();
      }
    } catch (Exception ex) {
      System.err.println("erro: " + ex.toString());
    }
  }
}