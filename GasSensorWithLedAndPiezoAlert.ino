int const sensor_gas = A1; 

int led_verde = 3;  
int led_amarelo = 4; 
int led_laranja = 5; 
int led_vermelho = 6;

int piezo = 7;

void setup()  
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_laranja, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  
  Serial.begin(9600);  
}


void loop()  
{  
  int valor = analogRead(sensor_gas); 
  
  valor = map(valor, 300, 750, 0, 100);
  
  digitalWrite(led_verde, valor >=0 ? HIGH : LOW); 
  digitalWrite(led_amarelo, valor >= 4 ? HIGH : LOW); 
  digitalWrite(led_laranja, valor >= 12 ? HIGH : LOW); 
  digitalWrite(led_vermelho, LOW);
  
  if(valor >= 24) {
    digitalWrite(led_vermelho, HIGH);
    if(valor >= 48) {
    	tone(piezo, 150 , 100);
  		delay(250);
      	digitalWrite(led_vermelho, LOW);
      	tone(piezo, 250, 100);
    }
  }
  
  delay(250);  
}
