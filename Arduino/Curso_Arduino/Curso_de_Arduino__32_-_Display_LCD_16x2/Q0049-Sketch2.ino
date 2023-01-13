#include <LiquidCrystal.h>

LiquidCrystal displayTeste(2,4,10,11,12,13);

void setup() {
  pinMode(5, OUTPUT);
  analogWrite(5, 0);

  displayTeste.begin(16,2);
  displayTeste.blink();
}

void loop() {

  displayTeste.clear();
  displayTeste.home();

  //displayTeste.setCursor(15,0);
  //displayTeste.rightToLeft();

  //displayTeste.setCursor(0,0);
  //displayTeste.leftToRight();
  
  //displayTeste.autoscroll();
  //displayTeste.setCursor(8,0);
  
  for (int c = 0; c < 10; c++) {
      displayTeste.write(byte(48 + c));
      delay(1000);
  }
}
