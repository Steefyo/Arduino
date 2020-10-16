// Importeer een Library
#include <Servo.h>

// Definieer de Servo en hoek.
Servo myservo;
int angle;

// Defineer de knoppen en knop status.
const int Button1 = 10;
const int Button2 = 9;
int buttonState1 = 0;
int buttonState2= 0;

// Vertraging.
const int incrementDelay = 0.83;

void setup() {
  // Zet servo op pin 3.
  // Zet andere pins open.
  myservo.attach(3);
  pinMode(Button1, INPUT);   
  pinMode(Button2, INPUT);     
}

void loop() {
  // Lees de status van de knop uit.
  buttonState1 = digitalRead(Button1);
  buttonState2 = digitalRead(Button2);

  // Als knop 1 is ingedrukt.
  if (buttonState1 == HIGH) { 
    // Draaisnelheid.
    int angleIncrement = 1;
    // Tot doel is bereikt.
    for (angle = 0; angle < 120; angle += angleIncrement) { 
       // Draai motor.
        myservo.write (angle);
        // vertragingstijd is de variabele.
      delay (incrementDelay);
    }   
  }

  // Als knop 2 is ingedrukt.
  else if (buttonState2 == HIGH){
    // Draaisnelheid.
    int angleIncrement = 2;
    // Tot doel is bereikt.
    for (angle = 0; angle < 120; angle += angleIncrement) {
        // Draai motor.
    myservo.write (angle);
        // vertragingstijd is de variabele.
    delay (incrementDelay);
    }
  }
  
  // Als knop 1 en 2 zijn ingedrukt.
  else if (buttonState2 == HIGH && buttonState1 == HIGH){
    // Draaisnelheid.
    int angleIncrement = 2;
    // Tot doel is bereikt.
    for (angle = 0; angle < 120; angle += angleIncrement) {
        // Draai motor.
    myservo.write (angle);
        // vertragingstijd.
    delay (2000);
    }
  }

  // Als er geen invoer is.
  else{
    myservo.write(0);
  }
  
  // Vertraging.
  delay(15);
}
