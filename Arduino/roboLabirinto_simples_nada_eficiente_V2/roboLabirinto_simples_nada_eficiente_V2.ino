#include <Servo.h> // biblioteca para ultilizar o modulo do serco motor

// pinos do mortor dc, pneu direito
#define pino_velocidade_m1 3
#define pino1_motor1 4
#define pino2_motor1 5

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
#define tempo_giro 1000

// tempo de espera parar leitura
#define tempo_leitura 1000

// criando servo e definindo
Servo servo;

// variavel global
int velocidade;         // pode variar de 0(0°) ou 255(100°) de potencia do motor
float distancia_minima; // distancia minima que queros que o objeto chega parar virar

// classe do motor
class Motor
{
public:
    int pino_1, pino_2, pino_velocidade;

    // metodo construtor do motor
    Motor(int p1, int p2, int pv)
    {
        this->pino_1 = p1;
        this->pino_2 = p2;
        this->pino_velocidade = pv;

        // definir esser tres pinos como saida de dados
        pinMode(pino_1, OUTPUT);
        pinMode(pino_2, OUTPUT);
        pinMode(pino_velocidade, OUTPUT);

        // digitalWrite  muda o estado do pino, para HIGH(1) ou LOW(1)
        digitalWrite(pino_1, LOW); // começa desligado/em baixa
        digitalWrite(pino_2, LOW); // começa desligado/em baixa

        // começa com valor analogico 0, podendo variar de 0 a 255(0% a 100% do motor), no cado 100% é 140RPM em 4,5V
        analogWrite(pino_velocidade, 0);
    }

    // funçoes do motor
    void frente(int v)
    {
        digitalWrite(pino_1, HIGH);
        digitalWrite(pino_2, LOW);
        analogWrite(pino_velocidade, v);
    }
    void re(int v)
    {
        digitalWrite(pino_1, LOW);
        digitalWrite(pino_2, HIGH);
        analogWrite(pino_velocidade, v);
    }
    void parar()
    {
        digitalWrite(pino_1, LOW);
        digitalWrite(pino_2, LOW);
        analogWrite(pino_velocidade, 0);
    }
    void freiar()
    {
        digitalWrite(pino_1, HIGH);
        digitalWrite(pino_2, HIGH);
        analogWrite(pino_velocidade, velocidade / 2); // corta a velocidade para metade/50%
    }
};

// criando o objeto para cada moror
Motor *motor_direito = new Motor(pino1_motor1, pino2_motor1, pino_velocidade_m1);
Motor *motor_esquerdo = new Motor(pino1_motor2, pino2_motor2, pino_velocidade_m2);

// funçoes para simplificar a função escolher_lado
void direita_vira(int v)
{
    Serial.println("Virando para direita");
    motor_direito->frente(v);
    motor_esquerdo->re(v);
}
void esquerda_vira(int v)
{
    Serial.println("Virando para esquerda");
    motor_direito->re(v);
    motor_esquerdo->frente(v);
}
void frente(int v)
{
    Serial.println("Andamdo para frente");
    motor_direito->frente(v);
    motor_esquerdo->frente(v);
}
void re(int v)
{
    Serial.println("Dando re");
    motor_direito->re(v);
    motor_esquerdo->re(v);
}
void parar()
{
    Serial.println("Parando");
    motor_direito->parar();
    motor_esquerdo->parar();
}
void freiar()
{
    Serial.println("Freiando");
    motor_direito->freiar();
    motor_esquerdo->freiar();
}

// função que ira decidir qual lado virar
void escolher_lado()
{
    float direita, esquerda;

    delay(tempo_leitura / 2); // tempo de espera para virar o servo para direita
    servo.write(0);           // olhando pra direita, com 0°
    delay(tempo_leitura / 2); // tempo de espera parar  o sensor começar a ler

    digitalWrite(pino_trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(pino_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trigger, LOW);

    direita = pulseIn(pino_echo, HIGH); // Armazena o valor lido
    direita = direita / 58;

    delay(tempo_leitura); // tempo de espera para o servo vira para esquerda.
    servo.write(180);     // olha para esquerda, com  180°
    delay(tempo_leitura); // tempo de espera antes do servo começar a ler

    digitalWrite(pino_trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(pino_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trigger, LOW);

    esquerda = pulseIn(pino_echo, HIGH); // Armazena o valor lido pelo sensor
    esquerda = esquerda / 58;            // convertendo para cm

    delay(tempo_leitura / 2); // tempo de espera para virar o servo para frente
    servo.write(90);          // olha para frente, com 90°
    delay(tempo_leitura / 2); // tempo de espera pro servo começar a decidir para onde virar

    // só para saber oquer o sensor esta recebendo de cada lado;
    Serial.print("DIREITA..: ");
    Serial.println(direita);
    Serial.print("ESQUERDA.: ");
    Serial.println(esquerda);

    // verificar para que lado ele vai firar
    if (direita > esquerda)
    {
        direita_vira(velocidade);
        delay(tempo_giro);
    }
    else
    {
        esquerda_vira(velocidade);
        delay(tempo_giro);
    }
    Serial.println("------------------------");
}

void setup()
{
    pinMode(pino_trigger, OUTPUT); // configurando como saida de dados o trigger
    pinMode(pino_echo, INPUT);     // configurando o echo como entrada de dados

    velocidade = 255;       // 100° da velocidade possivel
    distancia_minima = 100; // 100 cm de distancia de distancia do objeto ele muda de distancia

    servo.attach(pino_servo); // pino o qual o servo vai mandar os dados
    servo.write(90);          // função servo.write serve para girar o servo, no caso 90° vai ser para a frente do robo.

    Serial.begin(9600); // Configura a taxa de transferência em bits por segundo (baud rate) para transmissão serial, no a taxa de dados para 9600 bps.
    // delay(5000);      // 5 segundo antes do robo começar. OBS: PRECISA SER CONFIGURADO PRA COMEÇAR COM UM BOTÃO
}

void loop()
{
    float distancia_cm; // variavel que ficara lendo toda fora até bater ser menor que a distancia_minima

    digitalWrite(pino_trigger, LOW); // começa deligado
    delayMicroseconds(5);
    digitalWrite(pino_trigger, HIGH); // ligar
    delayMicroseconds(10);            // tempo de esposição do lazer
    digitalWrite(pino_trigger, LOW);  // desliga

    distancia_cm = pulseIn(pino_echo, HIGH); // Armazena o valor lido do sensor que foi o tempo que o lazer levou pra ir e voltar
    distancia_cm = distancia_cm / 58;        // convertando para centimetro

    Serial.print("Distancia em cm: ");
    Serial.println(distancia_cm); // so pra ver qual informação distancia_cm esta recebendo em cm;

    if (distancia_cm < distancia_minima && distancia_cm != -1)
    {                    // -1 é se caso der erro/mal contato
        parar();         // para o carrinho pra decedir que lado ele vai ir agora
        escolher_lado(); // função que faz o carrinh decedir que lado ele vai ir
    }
    else
    {
        frente(velocidade); // vai continuar andando para frente até achar uma parede
    }
}