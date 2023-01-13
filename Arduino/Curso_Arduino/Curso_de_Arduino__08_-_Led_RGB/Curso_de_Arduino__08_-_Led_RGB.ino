#define ledR 2
#define ledB 3
#define ledG 4
#define botao 7
#define maximo 3
int btnClicado=0;
int btnLiberado=0;
int ciclo=0;

void red(){
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,LOW);
}
void green(){
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,HIGH);
  digitalWrite(ledB,LOW);
}
void blue(){
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,HIGH);
}
void trocaLed(){
  if(ciclo==0){
    red();
  }
  else if(ciclo==1){
    green();
  }
  else if(ciclo==2){
    blue();
  }
  ciclo++;
  if(ciclo>maximo-1){
    ciclo=1;
  }
}
void verificar_btn(){
  if(digitalRead(botao)==HIGH){
    btnClicado=1;
    btnLiberado=0;
  }
  else{
    btnLiberado=1;
  }
  if((btnClicado==1)and(btnLiberado==1)){
    btnClicado=0;
    btnLiberado=0;
    trocaLed();
  }
}

void setup() {
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(botao,INPUT);
}

void loop() {
   verificar_btn();

}
