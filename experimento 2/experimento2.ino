int ledVerde = 12;
int ledVermelho = 11;

//funcao para o efeito fade
void fade(int led) {
  
  	//aumenta a intensidade
 	for (int brilho = 0; brilho <= 255; brilho++) {
    	analogWrite(led, brilho);
    	delay(15); //intervalo para o efeito ser perceptível
  	}

  	//diminui a intensidade
  	for (int brilho = 255; brilho >= 0; brilho--) {
    	analogWrite(led, brilho); 
    	delay(15); //intervalo para o efeito ser perceptível
  	}
  
}

void setup() {
  	
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
    
  Serial.begin(9600);

}


void loop() {
  
  int entrada;
  int serial = Serial.available(); //verifica a disponibilidade da porta
  
  if (serial > 0) //verifica se tem dados
  {
	entrada = Serial.read(); //lê o valor na serial
    entrada -= 48; //converte de bits para decimal
    Serial.println(entrada); //imprime a entrada
  }
 
  
  switch(entrada)
  {
    
  	case 0: //caso a entrada seja 0
  		 
    	digitalWrite(ledVerde, HIGH); //liga o primeiro led
  		digitalWrite(ledVermelho, LOW);
   		break;
    
    case 1: //caso a entrada seja 1
    
    	digitalWrite(ledVerde, LOW);
  		digitalWrite(ledVermelho, HIGH); //liga o segundo led
    	break;  
    
    case 2: //caso a entrada seja 2
    
    	while(Serial.available() <= 0){
    		fade(12); //fade no primeiro LED
  			fade(11); //fade no segundo LED
        }
        break;
    
  } 
  
}