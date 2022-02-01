// set pin numbers:
const int buttonPin = PUSH2;     // the number of the pushbutton pin
const int buttonPin2 = PUSH1;
const int ledPinGreen =  GREEN_LED;      // the number of the LED pin
const int ledPinBlue =  BLUE_LED;      // the number of the LED pin
const int ledPinRed =  RED_LED;      // the number of the LED pin

// variables will change:
int buttonState = 0;
int buttonState2 = 0;  // variable for reading the pushbutton status
boolean control = false;

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(115200);
  pinMode(ledPinGreen, OUTPUT);      
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);     
}

//Funcion que pone el led blanco
void setLeds(boolean state){
  digitalWrite(ledPinGreen, state); 
  digitalWrite(ledPinRed, state); 
  digitalWrite(ledPinBlue, state); 
  control = true;
}

void loop() {
  // put your main code here, to run repeatedly: 

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  //Añadimos un delay de 100 milis
  delay(100);
  //Pillamos un numero random del 0 al 1000
  int num = random(0,1000);
  //Imprimimos los valores en el plotter
   Serial.print(990);
   Serial.print(",");
   Serial.println(num);
   //Si el numero random es superior a 990 se enciende el juego
  if(num > 990){
    setLeds(HIGH);
  }

  //Si uno de los dos botones se ha pulsado, este se cambia de color enseñando al ganador
  if(buttonState == LOW || buttonState2 == LOW && control){
    //digitalWrite(ledPin, LOW); 
    if(buttonState == LOW )    {
      Serial.println(300);
      digitalWrite(ledPinGreen, LOW); 
    }
    if(buttonState2 == LOW )    {
      Serial.println(500);
      digitalWrite(ledPinBlue, LOW); 
    }
    //Se inicializan los valores a por defecto
    num = 0;
    control = false;
  }

  
  
}
