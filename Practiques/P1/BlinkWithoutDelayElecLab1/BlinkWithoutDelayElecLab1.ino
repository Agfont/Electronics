/* Blink without Delay

  Turns on and off a light emitting diode(LED) connected to a digital
  pin, without using the delay() function.  This means that other code
  can run at the same time without being interrupted by the LED code.

  The circuit:
   LED attached from pin 13 to ground.
   Note: on most Arduinos, there is already an LED on the board
  that's attached to pin 13, so no hardware is needed for this example.


  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 27 Apr 2012
  by Robert Wessels

  This example code is in the public domain.


  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

// constants won't change. Used here to
// set pin numbers:
const int ledPin =  78;      // the number of the LED pin
int control = 0;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)
long interval2 = 10;

// Se define el LED Green como output
void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

//Bucle que ejecuta el programa
void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.

  //Se pilla el tiempo actual
  unsigned long currentMillis = millis();

  //Se resta el tiempo actual con el tiempo anterior, si este es mayor, querra decir que ha pasado mas de 1 segundo
  if (currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    //Se actualiaza el previous
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:

    //Si esta apagado se enciende y sino, se apaga
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    //Se escribe en el output
    digitalWrite(ledPin, ledState);
    // Inicializamos control a cero
    control = 0;
    
  } else {
    //Si no pasa un segundo, pero ha pasado mas del tiempo del interval y ya se ha ejecutado una vez
    if ((currentMillis - previousMillis > interval2) && (control == 0)) {
      // Se apaga el led
      digitalWrite(ledPin, LOW);
      // Vuelve a poner control a uno
      control = 1;
    }
  }
}


