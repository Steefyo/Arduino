// Gebruik Library
#include <IRremote.h>

// Knop IR code.
#define button_1 38108
#define button_2 29937
#define button_3 22976
#define button_4 34528

// Definieer pins.
int receiver_pin = 5;
int led_1 = 12;
int led_2 = 10;
int led_3 = 8;
int led_4 = 7;

// Definieer een opslag voor de lamp logica.
int led[] = {0,0,0,0};
int timer[] = {100, 200, 300, 400};

// Zet reciever klaar.
IRrecv receiver(receiver_pin);

// Verwerk de uitkomst.
decode_results output;

// Start Serial Monitor
// Start de reciever
// Zet de gedefinieerde pins open.
void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
}

void loop() {
  // Ontvang de IR signalen.
  if (receiver.decode(&output)) {
    // Sla het signaal op.
    unsigned int value = output.value;
    // Kijk wel signaal het is.
    switch(value) {
      // Zet per knop de lamp aan/uit en zet boolean
      case button_1:
        if(led[0] == 1) {
          digitalWrite(led_1, LOW);
          led[0] = 0;
        } else {
          led[0] = 1;
        }
        break;
      case button_2:
        if(led[1] == 1) {
          digitalWrite(led_2, LOW);
          led[1] = 0;
        } else {
          led[1] = 1;
        }
        break;
      case button_3:
        if(led[2] == 1) {
          digitalWrite(led_3, LOW);
          led[2] = 0;
        } else {
          led[2] = 1;
        }
        break;
      case button_4:
        if(led[3] == 1) {
          digitalWrite(led_4, LOW);
          led[3] = 0;
        } else {
          led[3] = 1;
        }
        break;
    }

    // Toon in Serial Monitor.
    // Wacht op het volgende signaal.
    Serial.println(value);
    receiver.resume();
  }

  // Zet de lamp aan/uit op basis van de invoer. (incl timer)
  if (led[0] == 0 && led[1] == 0 && led[2] == 0 && led[3] == 0) {
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    delay(timer[2]);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    delay(timer[2]);
  }
  
  if (led[0] == 1) {
    digitalWrite(led_1, HIGH);
    delay(timer[0]);
    digitalWrite(led_1, LOW);
    delay(timer[0]);
  }
  
  if (led[1] == 1) {
    digitalWrite(led_2, HIGH);
    delay(timer[1]);
    digitalWrite(led_2, LOW);
    delay(timer[1]);
  }
  
  if (led[2] ==1) {
    digitalWrite(led_3, HIGH);
    delay(timer[2]);
    digitalWrite(led_3, LOW);
    delay(timer[2]);
  }
  
  if (led[3] == 1) {
    digitalWrite(led_4, HIGH);
    delay(timer[3]);
    digitalWrite(led_4, LOW);
    delay(timer[3]);
  }
}
