//M1
#define velocidadeM1 3
#define M1a 4
#define M1b 5
//M2
#define velocidadeM2 11
#define M2a 12
#define M2b 13

#define tempo 5000
int velocidade=255;

void setup() {
  //M1
  pinMode(velocidadeM1,OUTPUT);
  pinMode(M1a,OUTPUT);
  pinMode(M1b,OUTPUT);
  analogWrite(velocidadeM1,0);
  analogWrite(M1a,LOW);
  analogWrite(M1b,LOW);
  //M2
  pinMode(velocidadeM2,OUTPUT);
  pinMode(M2a,OUTPUT);
  pinMode(M2b,OUTPUT);
  analogWrite(velocidadeM2,0);
  analogWrite(M2a,LOW);
  analogWrite(M2b,LOW);
}

void loop() {
  //M1
  analogWrite(velocidadeM1,velocidade);
  digitalWrite(M1a,HIGH);
  digitalWrite(M1b,LOW);
  //M2
  analogWrite(velocidadeM2,velocidade);
  digitalWrite(M2a,LOW);
  digitalWrite(M2b,HIGH);
  delay(tempo);
  
  //M1
  analogWrite(velocidadeM1,0);
  digitalWrite(M1a,LOW);
  digitalWrite(M1b,LOW);
  //M2
  analogWrite(velocidadeM2,0);
  digitalWrite(M2a,LOW);
  digitalWrite(M2b,LOW);
  delay(100);
  
  //M1
  analogWrite(velocidadeM1,velocidade);
  digitalWrite(M1a,LOW);
  digitalWrite(M1b,HIGH);
  //M2
  analogWrite(velocidadeM2,velocidade);
  digitalWrite(M2a,HIGH);
  digitalWrite(M2b,LOW);
  delay(tempo);
}
