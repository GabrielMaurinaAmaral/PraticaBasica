import javax.swing.JOptionPane;

public class Aula_2_3 {
    public static void main(String[] args) {
        String texto;

        texto = JOptionPane.showInputDialog("Entre com um numero");
        
        int numero = Integer.parseInt(texto);
        JOptionPane.showMessageDialog(null, "O numero digitado foi: \n" + numero, "Este eh o titulo", 0);
    }
}
