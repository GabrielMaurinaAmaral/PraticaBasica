import java.util.Random;

class Animais {
    private Animal[] animais;

    public Animais(int tamanho) {
        animais = new Animal[tamanho];
        Random random = new Random();
        for (int i = 0; i < tamanho; i++) {
            switch (random.nextInt(7)) {
                case 0:
                    animais[i] = new Animal();
                    break;
                case 1:
                    animais[i] = new Mamifero();
                    break;
                case 2:
                    animais[i] = new Peixe();
                    break;
                case 3:
                    animais[i] = new Ave();
                    break;
                case 4:
                    animais[i] = new Cachorro();
                    break;
                case 5:
                    animais[i] = new Pug();
                    break;
                case 6:
                    animais[i] = new Acara();
                    break;
                default:
                    break;
            }
        }

    }

    public void imprimir_sons() {
        for (Animal a : animais) {
            a.emitir_som();
        }
    }

    public void imprimir_animais() {
        for (Animal a : animais) {
            System.out.println(a.toString());
        }
    }
}

class Animal {
    private String nome;
    private int idade;
om
    public Animal() {
        this.nome = "";
        this.idade = 0;
    }

    public Animal(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public void emitir_som() {
        System.out.println("O animal emite um som.");
    }

    public String toString() {
        return " eh um Animal \n seu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}

class Mamifero extends Animal {
    public Mamifero() {
        super("", 0);
    }

    public Mamifero(String nome, int idade) {
        super(nome, idade);
    }

    public void emitir_som() {
        System.out.println("Mamifero urra.");
    }

    public String toString() {
        return "eh um Mamifero \nseu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}

class Cachorro extends Mamifero {
    public Cachorro() {
        super("", 0);
    }

    public Cachorro(String nome, int idade) {
        super(nome, idade);
    }

    public void emitir_som() {
        System.out.println("Cachorro late.");
    }

    public String toString() {
        return "eh um Cachorro \nseu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}

class Pug extends Cachorro {
    public Pug() {
        super("", 0);
    }

    public Pug(String nome, int idade) {
        super(nome, idade);
    }

    public void emitir_som() {
        System.out.println("Pug nao late, pq teve um infarto tentando.");
    }

    public String toString() {
        return "eh um Cachorro \nseu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}

class Peixe extends Animal {
    public Peixe() {
        super("", 0);
    }

    public Peixe(String nome, int idade) {
        super(nome, idade);
    }

    public void emitir_som() {
        System.out.println("peixe nao faz barulho.");
    }

    public String toString() {
        return "eh um Peixe \nseu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}

class Acara extends Peixe {
    public Acara() {
        super("", 0);
    }

    public Acara(String nome, int idade) {
        super(nome, idade);
    }

    public void emitir_som() {
        System.out.println("acara nao faz barulho.");
    }

    public String toString() {
        return "eh uma Acara \nseu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}

class Ave extends Animal {
    public Ave() {
        super("", 0);
    }

    public Ave(String nome, int idade) {
        super(nome, idade);
    }

    public void emitir_som() {
        System.out.println("ave gargalha.");
    }

    public String toString() {
        return "eh uma Ave \nseu nome eh " + getNome() + " e tem " + getIdade() + "anos de idade\n";
    }
}