class Quadrilatero {
    private int x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2;
    public Quadrilatero(int x1_1, int y1_1, int x1_2, int y1_2, int x2_1, int y2_1, int x2_2, int y2_2) {
        this.x1_1 = x1_1;
        this.y1_1 = y1_1;
        this.x1_2 = x1_2;
        this.y1_2 = y1_2;
        this.x2_1 = x2_1;
        this.y2_1 = y2_1;
        this.x2_2 = x2_2;
        this.y2_2 = y2_2;
    }
    public float Area() {
        return 0.0;
    }
}
class Trapezio extends Quadrilatero {
    public Trapezio(int x1_1, int y1_1, int x1_2, int y1_2, int x2_1, int y2_1, int x2_2, int y2_2) {
        super(x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2);
    }
    public float Area() {
        float baseMaior = Math.abs(x1_2 - x1_1);
        float baseMenor = Math.abs(x2_2 - x2_1);
        float altura = Math.abs(y2_1 - y1_1);
        return ((baseMaior + baseMenor) * altura) / 2;
    }
}
class Paralelograma extends Quadrilatero {
    public Paralelograma(int x1_1, int y1_1, int x1_2, int y1_2, int x2_1, int y2_1, int x2_2, int y2_2) {
        super(x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2);
    }
    public float Area() {
        float base = Math.abs(x1_2 - x1_1);
        float altura = Math.abs(y2_1 - y1_1);
        return base * altura;
    }
}
class Retangulo extends Paralelograma {
    public Retangulo(int x1_1, int y1_1, int x1_2, int y1_2, int x2_1, int y2_1, int x2_2, int y2_2) {
        super(x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2);
    }
    public float Area() {
        float base = Math.abs(x1_2 - x1_1);
        float altura = Math.abs(y2_1 - y1_1);
        return base * altura;
    }
}
class Quadrado extends Retangulo {
    public Quadrado(int x1_1, int y1_1, int x1_2, int y1_2, int x2_1, int y2_1, int x2_2, int y2_2) {
        super(x1_1, y1_1, x1_2, y1_2, x2_1, y2_1, x2_2, y2_2);
    }
    public float Area() {
        return Math.pow(Math.abs(x1_2 - x1_1), 2);
    }
}
