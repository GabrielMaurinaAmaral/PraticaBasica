package Aula_5;
public class Aula_5_Ponto2D {
  private double x, y, valor;

  public Aula_5_Ponto2D(double x, double y, double valor) {
    this.x = x;
    this.y = y;
    this.valor = valor;
  }

  public void inicializaPonto2D(double _x, double _y, double _valor) {
    x = _x;
    y = _y;
    valor = _valor;
  }

  public double getValor() {
    return valor;
  }

  public double getX() {
    return x;
  }

  public double getY() {
    return y;
  }

  public boolean eIgual(Aula_5_Ponto2D outroPonto2D) {
    if ((x == outroPonto2D.x) && (y == outroPonto2D.y))
      return true;
    else
      return false;
  }

  public Aula_5_Ponto2D origem() {
    Aula_5_Ponto2D temporario = new Aula_5_Ponto2D(0, 0, 0);
    temporario.inicializaPonto2D(0, 0, 0);
    return temporario;
  }

  public Aula_5_Ponto2D clona() {
    Aula_5_Ponto2D temporario = new Aula_5_Ponto2D(0, 0, 0);
    temporario.inicializaPonto2D(x, y, valor);
    return temporario;
  }

  public String toString() {
    String resultado = (x + "," + y + "," + valor);
    return resultado;
  }
}