int ledVerde = 3;
int ledVermelho = 5; 
int potenciometro = A0;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(potenciometro, INPUT);
  Serial.begin(9600);
}

void loop() {
  int entrada = analogRead(potenciometro); //le o valor do potenciômetro
  Serial.println(entrada); //imprime os valores da entrada

  if (entrada < 512) 
  {
    //mapeia o valor lido para a faixa de brilho do LED verde
    int brilhoVerde = map(entrada, 0, 511, 0, 255);
    analogWrite(ledVerde, brilhoVerde); //define o brilho do LED verde de acordo
    digitalWrite(ledVermelho, LOW); //desliga o LED vermelho
  } 
  
  else 
  {
    //mapeia o valor lido para a faixa de brilho do LED vermelho
    int brilhoVermelho = map(entrada, 512, 1024, 0, 255);
    analogWrite(ledVermelho, brilhoVermelho); //define o brilho do LED vermelho de acordo
    digitalWrite(ledVerde, LOW); //desliga o LED verde
  }
}