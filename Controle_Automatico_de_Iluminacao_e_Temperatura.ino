
// Cria a variável com o número do pino de entrada analógico utilizado:
int sinalPin = 0;

// Cria as variáveis para armazenar a leitura do sinal analógico e a média:
float sinal;
float amostra;

// Cria as variáveis com o número de cada pino de saída para cada LED do bargraph:
int const led_g1 = 2;
int const led_g2 = 3;
int const led_y1 = 4;
int const led_y2 = 5;
int const led_r1 = 6;
int const led_r2 = 7;

void setup() {
  // Inicializa a comunicação serial:
  Serial.begin(9600);

  // Configura cada pino dos LEDs como saída:
  pinMode(led_g1, OUTPUT);
  pinMode(led_g2, OUTPUT);
  pinMode(led_y1, OUTPUT);
  pinMode(led_y2, OUTPUT);
  pinMode(led_r1, OUTPUT);
  pinMode(led_r2, OUTPUT);
}

void loop() {
  
  amostra = 0; // Zera a variavel amostra

  // Faz a leitura de 100 amostras:
  for(int i=0; i < 100; i++) {
    sinal = analogRead(sinalPin);             // Armazena o valor lido pelo TMP36
    sinal = ((sinal/1023.0*5.0)-0.5)/0.01;    // Converte o valor para para ser exibido em ºC
    amostra = amostra + sinal;                // Armazena na variavel amostra
  }
  amostra = amostra / 100;                    // Tira uma média das amostras

  // Envia o valor em graus Célsius da variável amostra para ao monitor serial:
  Serial.print("Temperatura = ");             
  Serial.print(amostra, 0);                   
  Serial.print("*C");                         
  
  int vMin = -1;  
  int vMax = 123;   

  //Conversão do valor lido em porcentagem:
  amostra = map(amostra, vMin, vMax, 0, 100);

  // Envia o valor convertido da variável amostra para a porta serial:
  Serial.print(" | ");                        
  Serial.print(amostra, 1);                   
  Serial.println("%");                        

  // Chama a função LED_ON_OFF e passa a informação da leitura para acionamento dos LEDs de acordo com a temperatura:
  LED_ON_OFF(amostra);
}

void LED_ON_OFF(float valor) {
  // Acionamento dos LEDs conforme a temperatura
  // LED verde
  if (valor >  5) digitalWrite(led_g1,HIGH);
  else            digitalWrite(led_g1,LOW);
  if (valor > 15) digitalWrite(led_g2,HIGH);
  else            digitalWrite(led_g2,LOW);
  // LED amarelo
  if (valor > 30) digitalWrite(led_y1, HIGH);
  else        digitalWrite(led_y1, LOW);
  if (valor > 45) digitalWrite(led_y2, HIGH);
  else        digitalWrite(led_y2, LOW);
  // LED vermelho
  if (valor > 60) digitalWrite(led_r1,HIGH);
  else            digitalWrite(led_r1,LOW);
  if (valor > 75) digitalWrite(led_r2,HIGH);
  else            digitalWrite(led_r2,LOW);
}
