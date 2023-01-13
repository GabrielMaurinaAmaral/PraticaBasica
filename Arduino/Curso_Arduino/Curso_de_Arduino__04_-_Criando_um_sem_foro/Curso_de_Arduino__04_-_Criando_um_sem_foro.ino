//int led_r=8;
//int led_y=9;
//int led_g=10;
#define led_r 8
#define led_y 9
#define led_g 10

void setup(){
  pinMode(led_r, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_g, OUTPUT);
}

void red(int temp){
  digitalWrite(led_r, HIGH);
  digitalWrite(led_y, LOW);
  digitalWrite(led_g, LOW);
  delay(temp);  
}

void yellow(int temp){
  digitalWrite(led_r, LOW);
  digitalWrite(led_y, HIGH);
  digitalWrite(led_g, LOW);
  delay(temp);
}

void green(int temp){
  digitalWrite(led_r, LOW);
  digitalWrite(led_y, LOW);
  digitalWrite(led_g, HIGH);
  delay(temp);
}
void loop() {
  red(5000);
  yellow(2000);
  green(7000);
}
