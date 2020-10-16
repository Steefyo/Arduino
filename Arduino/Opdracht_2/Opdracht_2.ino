// Defineer pins
int led = 11;
int button = 2;
 
// Defineer extra variables voor de knop
boolean oldState = LOW;
boolean newState = LOW;
boolean ledState = LOW;
 
// Zet gedefinieerde pins open
void setup() {
    pinMode(led, OUTPUT);  
    digitalWrite(led,LOW); 
    pinMode(button, INPUT); 
}

// 
void loop() {
  // Lees de knop status uit.
  newState = digitalRead(button);

  // Geef het systeem een vertraging.
  delay(5);

  // Als de knop status veranderd voer dit uit.
  if(newState != oldState) {
    // De knop staat aan.
    if(newState == HIGH) {
      // Als de lamp uit is voer dit uit.
      if(ledState == LOW) {
        // Zet lamp aan.
        digitalWrite(led, HIGH);
        ledState = HIGH;
      } else {
        // Zet lamp uit.
        digitalWrite(led, LOW);
        ledState = LOW;
      }
    }

    // Verander de status van de knop.
    oldState = newState;
  }   
}
