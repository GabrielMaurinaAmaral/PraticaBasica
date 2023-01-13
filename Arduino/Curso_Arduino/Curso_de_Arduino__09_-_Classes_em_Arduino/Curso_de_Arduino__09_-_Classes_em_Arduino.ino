#define ledB 2
#define ledG 3
#define ledR 4
#define botao 7

class Botao{
public:
  int btnClicado, btnLiberado, pino;

  Botao(int p){
    pino = p;
    btnClicado = 0;
    btnLiberado = 0;
  }

  bool press(){
    if (digitalRead(pino) == HIGH){
      btnClicado = 1;
      btnLiberado = 0;
    }
    else{
      btnLiberado = 1;
    }
    if ((btnClicado == 1)and(btnLiberado==1)){
        btnClicado = 0;
        btnLiberado = 0;
        return true;
    }
    else{
      return false;
    }
  }
};

class Cor{
public:
  int pinoR, pinoB, pinoG, ciclo, maximo;
  Cor(int pR, int pG, int pB) : pinoR(pR), pinoG(pG), pinoB(pB){
    ciclo = 0;
    maximo = 3;
  }
  trocaLed(){
    if(ciclo==0){
      corLed(1,0,0);
    }
    else if(ciclo==1){
      corLed(0,1,0);
    }
    else if(ciclo==2){
      corLed(0,0,1);
    }
    ciclo++;
    if(ciclo>maximo-1){
      ciclo=0;
    }
  }
private:
     void corLed(int r, int g, int b){
        digitalWrite(pinoR, r);
        digitalWrite(pinoG, g);
        digitalWrite(pinoB, b);
     }
};

Botao btn(botao);
Cor cor(ledR,ledG, ledB);

void setup(){
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);
}

void loop(){
  if(btn.press()){
    cor.trocaLed();
  }
}
