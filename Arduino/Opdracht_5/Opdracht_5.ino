// Definieer Led pins.
const int ledRed = 11;
const int ledGroen = 9;
const int ledBlauw = 10;

// Definieer variables
int roodWaarde; 
int groenWaarde; 
int blauwWaarde; 

void setup() {
  // Zet pins open.
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Zet lamp aan.
  analogWrite(ledRed, HIGH);
}

void loop() {
  // Definieer een start waarde rood.
  roodWaarde = 255;
  groenWaarde = 0;
  blauwWaarde = 0;
  
  // Logica van kleur rood.
  for (int i = 0; i < 255; i++) {
    // Pas waardes aan.
    roodWaarde--;
    groenWaarde++;
    // Functie voor kleur aanspreken.
    RGBLed(roodWaarde, groenWaarde, blauwWaarde);
  }

  // Definieer een start waarde groen.
  roodWaarde = 0;
  groenWaarde = 255;
  blauwWaarde = 0;
  
  // Logica van kleur groen.
  for (int i = 0; i < 255; i++) {
    // Pas waardes aan.
    groenWaarde--;
    blauwWaarde++;
    // Functie voor kleur aanspreken
    RGBLed(roodWaarde, groenWaarde, blauwWaarde);
  }

  // Definieer een start waarde blauw.
  roodWaarde = 0;
  groenWaarde = 0;
  blauwWaarde = 255;
    
  // Logica van kleur blauw.
  for (int i = 0; i < 255; i++) {
    // Pas waardes aan.
    blauwWaarde--;
    roodWaarde++;
    // Functie voor kleur aanspreken
    RGBLed(roodWaarde, groenWaarde, blauwWaarde);
  }
}

// Logica van led licht.
// Geef waardes door naar het Led licht
// D.m.v. een delay verander de kleuren.
void RGBLed(int rood, int groen, int blauw) {
  for (int i = 0; i < 3; i++) {
      analogWrite(ledRed, rood);
      analogWrite(ledGroen, groen);
      analogWrite(ledBlauw, blauw);
      delay(10);
    }
}
