//****************************
//***   P4 - Transistors   ***
//*** Tocar notes musicals ***
//****************************

//Fitxer que relaciona text amb les freqüències de notes musicals
#include "notes_frequencies.h"

//Partituras
//Partitura 01
//Notes amb silencis (): (C:Do, D:Re, E:Mi, F:Fa, G: Sol, A:La, B:Si)
//unsigned int notes[] = {NA4,ND4,NF4,NG4,NA4,ND4,NF4,NG4,NE4,NG4,NC4,NF4,NE4,NG4,NC4,NF4,NE4,ND4,ND4};
//Duracio notes normalitzades a t0
//unsigned int duracio_notes[] = {6,6,1,1,4,4,1,1,12,6,6,1,1,4,6,1,1,4,6};
//Partitura 02
unsigned int notes[] = {ND3,ND3,ND3,NG3,ND4,NC4,NB3,NA3,NG4,ND4,NC4,NB3,NA3,NG4,ND4,NC4,NB3,NC4,NA3};
unsigned int duracio_notes[] = {2,2,2,8,8,2,2,2,8,4,2,2,2,8,4,2,2,2,4};

unsigned int t0=100;  //Base de temps (1) per la duració de les notes (en mil·lisegons)

/** variables a usar **/
const int pinButton = 23;
const int pinBuzzer = 19;
const int buttonPin = PUSH2;     // the number of the pushbutton pin
const int buttonPin2 = PUSH1;

int buttonState = 0;
int buttonState2 = 0;  // variable for reading the pushbutton status
int actualIndex = 0;

void setup() {
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(9600); // for LCD debug output

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP); 
}

void loop() { 

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2); 
  
  //Si se pulsa cualquiera de los dos botones
  if(buttonState == LOW || buttonState2 == LOW ){
    //Si se pulsa el boton1 se pillan las notas del 0 hasta la mitad
    if(buttonState == LOW ){
      actualIndex = random(0, (sizeof(notes)/2)-1);      
    }
    //Si se pulsa el otro, se pillan las notas de la mitad hasta el final
    if(buttonState2 == LOW )    {
      actualIndex = random((sizeof(notes)/2)-1, sizeof(notes)-1);            
    }    
    //Finalmente se usa la nota junto su duracion
    tone(pinBuzzer, notes[2], duracio_notes[2]);
  }
  
  delay(10);
  noTone(pinBuzzer);
  
}
