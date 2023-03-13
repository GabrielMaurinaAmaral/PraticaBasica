public class Aula_4_usar_pessoa {
	public static void main(String[] Args) {
		Aula_4_Pessoa Ana = new Aula_4_Pessoa();
		Aula_4_Pessoa Bete = new Aula_4_Pessoa("Bete");
		Aula_4_Pessoa Carlos = new Aula_4_Pessoa("Carlos", "333.444.555-66", 1960);

		Ana.imprimirDados();
		Bete.imprimirDados();
		Carlos.imprimirDados();

		Ana.setNome("Joao");
		Ana.setCPF("423.532.534-55");
	    Ana.setAno(2000);
		Ana.imprimirDados();
	}

}