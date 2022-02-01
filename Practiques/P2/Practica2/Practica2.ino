// set pin numbers:
const int btnPulsador = PUSH2;     // the number of the pushbutton pin
//Min y Max values
const double minV = 3;
const double maxV = 5;
//Valor actual
double actualV = 0;

// variables will change:
int btnPulsadorState = 0;
//Para pulsarlo solo una vez
boolean control = false;
//Variables de tiempo
long previousMillis = 0;        // will store last time LED was updated
//Tiempo que se esconde
long tNoVisible = 100;           // interval at which to blink (milliseconds)

void setup() {
  // put your setup code here, to run once:
  // initialize the pushbutton pin as an input:
  pinMode(btnPulsador, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly: 
  btnPulsadorState = digitalRead(btnPulsador);

  //Cosas por hacer
  //Pillar actualV en la placa
  //Esconder grafica
  
  //Para imprimir
  Serial.print(maxV);  
  Serial.print(",");
  Serial.print(actualV);
  Serial.print(",");
  Serial.print(minV);

  

  //Si el boton contador ha sido pulsado, quito la grafica
  if ( btnPulsadorState == LOW && !control){
    actualV = 0;
    control = true;
    //Esconder grafica

    //Se pilla el tiempo actual
    unsigned long currentMillis = millis();
    //Despues de que hayan pasado 100ms
    if (currentMillis - previousMillis > tNoVisible) {
      //Se actualiaza el previous
      previousMillis = currentMillis;
      //Captar actualV


      //Si esta en el rango gana, else pierde
      if(actualV <= maxV && actualV >= minV){
        //Win
      }else{
        //Lose
      }
      control = false;
    }    
  }

  
  
}
