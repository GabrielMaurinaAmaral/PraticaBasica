#include <LiquidCrystal.h>

//LiquidCrystal LCD(2,3,4,5,6,7,8,9,10,11,12,13); criando o objeto lcd com os pinos
// rw -> porta de escrita
// vd->  varia o constraste da fonte
// BD0 ao BD7 -> pinos de dados

LiquidCrystal LCD(2,4,10,11,12,13);

void setup() {
  LCD.begin(16,2);// ligar o display 16x2
  LCD.print("gabriel maurina amaral"); // informar diversos caracter, aparece no display
  LCD.setCursor(0,1); //informa coluna e linha;
  LCD.clear(); // limpa o texto
  LCD.write('X'); // informa um caracter
}

void loop() {
  

}
