import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class Aula_6_DemoPessoaGravar {
   public static void main(String[] args) {
      Aula_6_Pessoa_1[] agenda = new Aula_6_Pessoa_1[3];

      agenda[0] = new Aula_6_Pessoa_1("Madalena", "123", "(46)99887766");
      agenda[1] = new Aula_6_Pessoa_1("Jose", "456", "(46)11223344");
      agenda[2] = new Aula_6_Pessoa_1("Pedro", "789", "(46)33445566");

      File arquivo = new File("agenda.dat");

      try {
         FileOutputStream fout = new FileOutputStream(arquivo);
         ObjectOutputStream oos = new ObjectOutputStream(fout);
         oos.writeObject(agenda);
         oos.flush();
         oos.close();
         fout.close();
      } catch (Exception ex) {
         System.err.println("erro: " + ex.toString());
      }
   }
}
