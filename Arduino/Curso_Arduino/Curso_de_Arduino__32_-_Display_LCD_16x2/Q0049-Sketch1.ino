#include <LiquidCrystal.h>

LiquidCrystal displayTeste(2,4,10,11,12,13);

int efeito = 0;
int contraste = 0;
boolean aumenta = true;


byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  analogWrite(5, 0);

  displayTeste.createChar(0, smiley);
  displayTeste.begin(16,2);
  //displayTeste.cursor();
  displayTeste.blink();// mostra o curso pistacando

  displayTeste.print("Brincando com");
  displayTeste.setCursor(2,1);
  displayTeste.print("Ideias ");
  displayTeste.write(byte(0));
  
  displayTeste.setCursor(1,1);
  displayTeste.home();
  
  //Teste da Tabela de Caracteres
  displayTeste.setCursor(15,1);
  displayTeste.write(byte(244));

}

void loop() {
  // put your main code here, to run repeatedly:

  if (efeito == 1) {
     analogWrite(5, contraste);
     delay(20);

     if (aumenta) contraste++;
     else         contraste--;
  
     if (contraste == 150) aumenta = false;

     if (contraste == 0) aumenta = true;
  }

  if (efeito == 2) {
     displayTeste.noDisplay();
     delay(500);
     displayTeste.display();
     delay(500);
  }

  if (efeito == 3) {
     displayTeste.scrollDisplayLeft();
     delay(350);
  }

  if (efeito == 4) {
     displayTeste.scrollDisplayRight();
     delay(350);
  }
  
}
