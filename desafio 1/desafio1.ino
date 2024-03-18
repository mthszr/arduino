int ledVerde = 13;
int ledAmarelo = 12;
int ledVermelho = 11;
int botao = 2;

void setup() {
  
	pinMode(botao, INPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAmarelo, OUTPUT);
  	pinMode(ledVermelho, OUTPUT);

}


void loop() {
  
  unsigned long tempoPassado = 0;
  int tempoRestante = 0;
  int estadoBotao = digitalRead(botao);
  
  int flag = 0;
  
  digitalWrite(ledVerde, HIGH);//sinal aberto para veiculos
  
  if (estadoBotao == 1 && !flag) { //caso botao seja pressionado
    tempoPassado = millis();
    //reduz pela metade o tempo restante de espera
    tempoRestante = (10000 - tempoPassado)/2;
    delay(tempoRestante);//espera um tempo para abrir
  } else { //caso botao nao seja pressionado
    tempoRestante = 10000; //espera os 10s padrao
    delay(tempoRestante);//espera um tempo para abrir
  }
  
  
  //prepando para fechar
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);
  delay(3000);//espera um tempo
  
  //aberto para pedestres
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  delay(5000);//espera um tempo
  
}