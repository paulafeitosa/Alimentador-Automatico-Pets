#include <ESP32Servo.h>

#define ROTACAO 6                // Número de rotações
#define INTERVALO_5_MINUTOS 300000 // 5 minutos em milissegundos (300.000 ms)


//Pinos VCC é o Vin, e o GND da placa
// Define o pino onde o sensor infravermelho está conectado
const int pinoSensor = 32;  // Pino D32

// Define o pino onde o servo motor está conectado
const int pinoServo = 26;  // Pino D26 (ou outro pino PWM)

// Cria um objeto da classe Servo
Servo meuServo;

// Variáveis para controle do timer
unsigned long tempoInicioRotacao = 0; // Armazena o tempo de início da rotação
unsigned long tempoUltimaAtivacao = 0; // Armazena o tempo da última ativação
bool emRotacao = false; // Indica se o servo está em rotação
bool primeiraAtivacao = true; // Indica se é a primeira ativação

void setup() {
  // Inicia a comunicação serial para monitoramento
  Serial.begin(115200);
  
  // Configura o pino do sensor como entrada
  pinMode(pinoSensor, INPUT);
  
  // Anexa o servo ao pino definido
  meuServo.attach(pinoServo);
  
  // Para o servo inicialmente
  meuServo.write(90);  // 90 é o ponto neutro (parado) para servos de rotação contínua
}

void loop() {
  // Lê o valor do sensor
  int valorSensor = digitalRead(pinoSensor);
  
  // Debug do valor lido no sensor
  Serial.print("Valor do sensor: ");
  Serial.println(valorSensor);
  
  // Verifica se o sensor está em LOW e se é a primeira ativação ou já passaram 5 minutos desde a última ativação
  if (valorSensor == LOW && !emRotacao && (primeiraAtivacao || (millis() - tempoUltimaAtivacao >= INTERVALO_5_MINUTOS))) {
    Serial.println("Iniciando rotação...");
    
    // Marca o tempo de início da rotação
    tempoInicioRotacao = millis();
    emRotacao = true; // Indica que o servo está em rotação
    primeiraAtivacao = false; // Marca que a primeira ativação já ocorreu
    
    // Gira no sentido horário (ajuste o valor conforme necessário)
    meuServo.write(0);  // Valor 0 para rotação máxima em um sentido
  }
  
  // Verifica se o servo está em rotação e se o tempo de rotação já passou
  if (emRotacao && (millis() - tempoInicioRotacao >= ROTACAO * 1000)) {
    // Para o servo
    meuServo.write(90);  // Volta ao ponto neutro (parado)
    
    // Marca o tempo da última ativação
    tempoUltimaAtivacao = millis();
    emRotacao = false; // Indica que o servo parou de girar
    
    Serial.println("Rotação concluída. Aguardando 5 minutos para próxima ativação.");
  }
  
  // Aguarda um pouco antes de ler novamente
  delay(100);
}