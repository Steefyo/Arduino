// Definieer de pins.
const int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6};
 
// Ga door alle 8 de pins.
// Zet gedefinieerde pins open.
void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
 
void loop() {
  // Ga door alle 8 de pins (vooruit). 
  // Zet lamp aan, wacht, zet lamp uit.
  for(int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(60);
    digitalWrite(ledPins[i], LOW);
  }
  
  // Ga door alle 8 de pins (achteruit).
  // Zet lamp aan, wacht, zet lamp uit.
  for(int i = 8; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(60);
    digitalWrite(ledPins[i], LOW);
  }
}
