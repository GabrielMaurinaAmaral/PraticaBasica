
public class Aula_7_UsaPilhaRevista {
    public static void main(String[] args) {
        Aula_7_Pilha pilha = new Aula_7_Pilha(50);

        pilha.inserir("aaaa", 111, 2, 12, 2005);
        pilha.inserir("bbbb", 222, 3, 11, 2004);
        pilha.inserir("cccc", 333, 4, 10, 2003);
        pilha.inserir("dddd", 444, 5, 9, 2002);
        pilha.inserir("eeee", 555, 6, 8, 2001);
        pilha.remove();
        pilha.remove();
        pilha.mostrar_Pilha();
    }
}
