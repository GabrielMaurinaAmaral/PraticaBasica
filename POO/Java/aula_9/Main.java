class A {
    private int a;
    A(int a) {
        this.a = a;
    }
    public int get_A() {
        return this.a;
    }
}
class B {
    private String b;
    B(String b) {
        this.b = "b";
    }
    public String get_B() {
        return this.b;
    }
}
class C extends A {
    private B b;
    public C(int a, String b) {
        super(a);
        this.b = new B(b);
    }
    public String toString() {
        return super.get_A() + " " + this.b.get_B();
    }
}
public class Main {
    public static void main(String[] args) {
        C c = new C(20, "Gabriel");
        System.out.println(c.toString());
    }
}
