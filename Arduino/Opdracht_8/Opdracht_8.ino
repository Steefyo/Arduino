// Gebruiken van een library
#include<IRremote.h>

// Afstandingsbediening resultaten opslaan
decode_results resultaten;

// Tel hoeveel lampen er aanstaan.
int lampOnCount = 0;

// Defineer de lampen aan.
int ledAan1 = 0;
int ledAan2 = 0;

// Knipper tijd
unsigned long blinkerTime = 0;

// Defineer pins van de leds
int ledPins[] = {13, 12, 10, 9};

// Defineer afstandsbediening
int IR = 5;
IRrecv irrecv(IR);

// Toetsen op de afstandsbediening
long int knop_1 = 16;
long int knop_2 = 2064;
long int knop_3 = 1040;
long int knop_4 = 3088;

// Zet elke pin aan de lamp
// Serial monitor
// IR ontvanger aanzetten
void setup() {
  for (int i = 0; i > 4; i++) {
    pinMode(ledPins[0], OUTPUT);
  }
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // Lees de lamp uit
  int statusLed1 = digitalRead(ledPins[0]);
  int statusLed2 = digitalRead(ledPins[1]);
  int statusLed3 = digitalRead(ledPins[2]);
  int statusLed4 = digitalRead(ledPins[3]);

  // Lees IR uit in resultaten
  if (irrecv.decode(&resultaten)) {
    // Toon welke is ingetoetst.
    Serial.println(resultaten.value);
    // Ga verder met ontvangen.
    irrecv.resume();
    // Als er minder dan 2 lampen aanstaan
    if (lampOnCount < 2) {
      // Op lamp ...
      // Zet lamp ... in de functie
      if (resultaten.value == knop_1 && statusLed1 == LOW) {
        onthoudLed(ledPins[0]);
      } else if (resultaten.value == knop_2 && statusLed2 == LOW) {
        onthoudLed(ledPins[1]);
      } else if (resultaten.value == knop_3 && statusLed3 == LOW) {
        onthoudLed(ledPins[2]);
      } else if (resultaten.value == knop_4 && statusLed4 == LOW) {
        onthoudLed(ledPins[3]);
      }
    }
  }

  // Als er 2 lampen aanstaan
  if (lampOnCount == 2) {
    // Welke knippertijd wordt het
    // 0.1 sec / 0.2 sec / 0.3 sec / 0.4 sec
    if (resultaten.value == knop_1) {
      zetLedKnipperTijd(100);
    }
    if (resultaten.value == knop_2) {
      zetLedKnipperTijd(200);
    }
    if (resultaten.value == knop_3) {
      zetLedKnipperTijd(300);
    }
    if (resultaten.value == knop_4) {
      zetLedKnipperTijd(400);
    }
  }
}

void onthoudLed(int ledPin) {
  // Zet lamp aan
  digitalWrite(ledPin, HIGH);
  // Als lamp uit is zet aan
  //    Sla op welke lamp aan staat.
  //    Aantal lampen aan +1
  // Anders zet de andere lamp aan
  if (ledAan1 == 0) {
    ledAan1 = ledPin;
    lampOnCount++;
  } else {
    ledAan2 = ledPin;
    lampOnCount++;
  }
}

void zetLedKnipperTijd(int tijd) {
  // Huidige tijd
  unsigned long tijdNu = millis();
  // Lees de lampen uit
  int statusLamp1 = digitalRead(ledAan1);
  int statusLamp2 = digitalRead(ledAan2);
  // Vergelijk de tijden met elkaar
  // Nieuwe tijd is groter
  // Update deze tijd
  if (tijdNu - blinkerTime >= tijd) {
    blinkerTime = tijdNu;
    if (statusLamp1 == LOW && statusLamp2 == LOW) {
      // Zet beide lampen aan
      digitalWrite(statusLamp1, HIGH);
      digitalWrite(statusLamp2, HIGH);
    } else {
      // Zet beide lampen uit
      digitalWrite(statusLamp1, LOW);
      digitalWrite(statusLamp2, LOW);
    }
  }
}
