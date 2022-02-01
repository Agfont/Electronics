//Mirar si PWM es lo mismo que 40
const int pinFotoDiodo = 40;
const int pinBuzzer = 19
                      //Para 0
#define NOTE_A  392
                      //Para 1
#define NOTE_B  1175
int diodoValue = 0;

const int interval = 500;
void setup() {
  // put your setup code here, to run once:
  //TODO Pillar bien el pin del diodo, seria un output?
  pinMode(pinFotoDiodo, OUTPUT)
  pinMode(pinBuzzer, OUTPUT)
  Serial.begin(9600); // for LCD debug output
}

void loop() {
  unsigned long currentMillis = millis();
  // put your main code here, to run repeatedly:
  //Capturar el valor del fotodiodo, pero aun no sabemos????
  diodoValue = analogRead(pinFotoDiodo);
  //Preguntar como capturar la luz
  //CurrentMillis nos da el tiempo actual y tenemos un intervalo
  
  //Mirar si esto es valido
  digitalWrite(buzzerPin, HIGH);
  if (diodoValue) {    
    tone(pinBuzzer, NOTE_A, 200);
    Serial.println("0");
  } else {    
    tone(pinBuzzer, NOTE_B, 400);
    Serial.println("1");
  }
  delay(10);  
  noTone(pinBuzzer);
}
