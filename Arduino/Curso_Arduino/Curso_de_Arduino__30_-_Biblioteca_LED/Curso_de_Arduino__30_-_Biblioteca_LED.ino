#include <biblioteca_led.h>

Biblioteca_LED led1(13);
Biblioteca_LED led2(7);
Biblioteca_LED led3(6);

void setup() {
  led1.acender();
  led2.acender();
  led3.acender();
}

void loop() {
  led1.apagar_t(10000);
  led2.acender_t(10000);
  led3.piscar(100, 10);
  delay(100)

}
