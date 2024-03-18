int ledVerde = 12;
int ledVermelho = 11;
int botao = 2;

void setup() {
  
	pinMode(botao, INPUT);
    pinMode(ledVerde, OUTPUT);
  	pinMode(ledVermelho, OUTPUT);

}


void loop() {
  
  int estadoBotao = digitalRead(botao);

  if (estadoBotao == 1) { //caso botao seja pressionado
      digitalWrite(ledVerde, HIGH);   //liga o LED verde
   	  digitalWrite(ledVermelho, LOW); //desliga o LED vermelho
  } else { //caso botao nao seja pressionado
    digitalWrite(ledVermelho, HIGH);    //liga o LED vermelho
    digitalWrite(ledVerde, LOW);   //desliga o LED verde
  }
  
  delay(1);
  

  
}