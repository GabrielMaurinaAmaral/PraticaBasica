#include <Servo.h>  // biblioteca para ultilizar o modulo do serco motor
#include <HCSR04.h> // biblioteca para ultilizar o modulo de sersor ultrasonico(sensor de distancia)

// pinos do mortor dc, pneu direito
#define pino_velocidade_m1 3
#define pino1_motor1 4
#define pino2_motot1 5

// pinos do mortor dc, pneu esquerdo
#define pino_velocidade_m2 6
#define pino1_motor2 7
#define pino2_motor2 8

// pino o qual o servo motor esta conectado
#define pino_servo 10

// pinos do sensor ultrasonic
#define pino_trigger 11
#define pino_echo 12

// tempo que o servo espera parar girar, nese caso esta definido como 0,5 segundos
#define tempo_giro 500

// tempo de espera parar leitura
#define tempo_leitura

// criando servo e definindo
Servo servo;
UltraSonicDistanceSensor distancia(pino_trigger, pino_echo);

// velociade dos motor DC
#define velocidade = 200

// distancia minima que o sensor deve dectar para virar
#define distancia_minima 20

// variavel global
float distancia_cm;

// classe do motor
class Motor{
public:
    int pino_1, pino_2, pino_velocidade;
    
    // metodo construtor do motor
    Motor(int p1, int p2, int pv){
        this->pino_1 = p1;
        this->pino_2 = p2;
        this->pino_velocidade = pv;
        
        // definir esser tres pinos como saida de dados
        pinMode(pino_1, OUTPUT);
        pinMode(pino_2, OUTPUT);
        pinMode(pv, OUTPUT);
        
        // digitalWrite  muda o estado do pino, para HIGH(1) ou LOW(1)
        digitalWrite(pino_1, LOW); // começa desligado/em baixa
        digitalWrite(pino_2, LOW); // começa desligado/em baixa
        
        // começa com valor analogico 0, podendo variar de 0 a 255(0% a 100% do motor), no cado 100% é 140RPM em 4,5V
        analogWrite(pino_velociadede, 0);
    }
    
    // funçoes do motor
    void frente(int v){
        digitalWrite(pino_1.HIGH);
        digitalWrite(pino_2.LOW);
        analogWrite(pino_velocidade, v);
    }
    void re(int v){
        digitalWrite(pino_1.LOW);
        digitalWrite(pino_2.HIGH);
        analogWrite(pino_velocidade, v);
    }
    void parar(){
        digitalWrite(pino_1.LOW);
        digitalWrite(pino_2.LOW);
        analogWrite(pino_velocidade, 0);
    }
    void freiar(){
        digitalWrite(pino_1.HIGH);
        digitalWrite(pino_2.HIGH);
        analogWrite(pino_velocidade, velocidade / 2); // corta a velocidade para metade/50%
    }
};

// crando o objeto para cada moror
Motor *motor_direito = new Motor(pino1_motor1, pino2_motor1, pino_velocidade_m1);
Motor *motor_esquerdo = new Motor(pino1_motor2, pino2_motor2, pino_velocidade_m2);

//funçoes para simplificar a função escolher_lado
void direita(int v){
    Serial.println("Virando para direita");
    md->frente(v);
    me->re(v);
}
void esquerda(int v){
    Serial.println("Virando para esquerda");
    md->re(v);
    me->frente(v);
}
void frente(int v){
    Serial.println("Andadno para frente");
    md->frente(v);
    me->frente(v);
}
void re(int v){
    Serial.println("Dando re");
    md->re(v);
    me->re(v);
}
void parar(int v){
    Serial.println("Parando");
    md->parar;
    me->freiar;
}
void friar(int v){
    Serial.println("Freiando");
    md->freiar;
    me->freiar;
}

// função que ira decidir qual lado virar
void escolher_lado(){
    float direita = 0, esquerda = 0;

    delay(500);
    servo.write(0); // olhando pra direita, com 0°
    delay(500);
    direita = distanceSensor.measureDistanciaCm(); // medindo a distancia da superficie mais proxima a direita
    delay(250);
    servo.write(180); // olha para esquerda, com  180°
    delay(500);
    esquerda = distanceSensor.measureDistanciaCm(); // medindo a distancia da superficie mais proxima a esquerda
    delay(250);
    servo.write(90); // olha para frente, com 90°
    delay(250);

    // só para saber oquer o sensor esta recebendo de cada lado;
    Serial.print("DIREITA..: ");
    Serial.println(direita);
    Serial.print("ESQUERDA.: ");
    Serial.println(esquerda);
    
    // verificar para que lado ele vai firar
    if (direta >= esquerda){
        direita(velocidade);
        delay(tempo_giro);
    }
    else{
        esquerda(velocidade);
        delay.(tempo_giro);
    }
    Serial.println("------------------------");
}

void setup(){
    servo.attach(pino_servo); // pino o qual o servo vai mandar os dados
    servo.write(90);          // função servo.write serve para girar o servo, no caso 90° vai ser para a frente do robo.
    Serial.begin(9600);       // Configura a taxa de transferência em bits por segundo (baud rate) para transmissão serial, no a taxa de dados para 9600 bps.
    delay(5000)              // 5 segundo antes do robo começar
}

void loop(){
    distancia_cm = DistanceSensor.measureDistanceCm(); // sensor que esta olhando para frende mede, e distancia a frente;
    Serial.print("Distancia em cm: ");
    Serial.println(distancia_cm);                      // so pra ver qual informação distancia_cm esta recebendo em cm;

    if (distancia < distanciaMinima && distancia_cm != -1){ // -1 é se caso der erro/mal contato{
        friar(); // reduz a velocidade parar virar
        escolherLado();
    }
    else{
        frente(velocidade); // vai continuar andando para frente até achar uma parede
    }
}
