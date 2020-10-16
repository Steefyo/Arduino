// Gebruik Library
#include<Servo.h>
 
// Definieer de pins.
const int TrigPin = 11;
const int EchoPin = 12;
 
// Definieer de logica voor de servo
Servo Servo1;
int Positie = 0;
 
float Tijd;
float Afstand;
 
void setup() {
  // Zet Servo op poort 7.
  Servo1.attach(7); 

  // Start Serial Monitor.
  Serial.begin(9600);

  // Zet de gedefinieerde pins open.
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}
    
void loop() {
  // Zet aan en uit met vertraging.
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin , LOW);

  // Echo
  Tijd = pulseIn(EchoPin,HIGH);

  //tijd : door 58
  Afstand = Tijd / 58; 

  // Toon op Serial Monitor
  Serial.print(Afstand);
  Serial.println("cm");

  // Wacht
  delay(100);
 
  // Als afstand onder of gelijk aan 10
  // en boven en gelijk aan 4
  if (Afstand <= 10 && Afstand >= 4) { 
    // map van 4,10,180,0
    int PosAf = map(Afstand, 4, 10, 180, 0); 
    Servo1.write(PosAf);
    delay(20);
  }
}
