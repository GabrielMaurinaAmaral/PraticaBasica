public class Aula_7_UsaFilaCliente {
    public static void main(String[] args) {
        Aula_7_FilaCliente fila = new Aula_7_FilaCliente(10);
        Aula_7_Cliente cliente = new Aula_7_Cliente("ana", 'f');

        fila.Enfileirar(cliente);
        fila.Desenfileirar();
        cliente = new Aula_7_Cliente("marco", 'm');
        fila.Enfileirar(cliente);
        cliente = new Aula_7_Cliente("leuila", 'f');
        fila.Enfileirar(cliente);
        cliente = new Aula_7_Cliente("gabriel", 'm');
        fila.Enfileirar(cliente);
        fila.Desenfileirar();
        fila.mostrar_Fila();
    }
}
