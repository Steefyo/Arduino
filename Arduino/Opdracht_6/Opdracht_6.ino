// Gebruik Library
#include<Servo.h>

// Defineer Knoppen / Logica
const int knop_1 = 13;
const int knop_2 = 12;
int logic_knop_1 = LOW;
int logic_knop_2 = LOW;

// Declareer motor
Servo servoMotor;

// Zet knop ontvangen aan
// Zet motor op pin 3
// Start Serial Monitor
void setup() {
  pinMode(knop_1, INPUT);
  pinMode(knop_2, INPUT);
  servoMotor.attach(3);
  Serial.begin(9600);
}

void loop() {
  // Sla knop waardes op
  logic_knop_1 = digitalRead(knop_1);
  logic_knop_2 = digitalRead(knop_2);
  Serial.println(logic_knop_1);
  Serial.println(logic_knop_1);

  // Welke knop staat aan
  if (logic_knop_1 == HIGH && logic_knop_2 == LOW){
    // Laat de servo bewegen
    servo_logic(8,0);
  }
  if (logic_knop_1 == LOW && logic_knop_2 == HIGH){
    servo_logic(4,0);
  }
  if (logic_knop_1 == HIGH && logic_knop_2 == HIGH){
    servo_logic(8, 2000);
  }

  // Geen invoer
  else{
    servoMotor.write(0);
  }
}

void servo_logic (int snelheid, int tussenstop) {
  // Als de positie kleiner is dan 120 graden
  // Positie veranderen
  // Snelheid van het draaien
  for (int positie = 0; positie < 120; positie++) {
    servoMotor.write(positie);
    delay(snelheid);
  }
  // Wachten om terug te draaien
  delay(tussenstop);
  // Als de positie groter is dan 0 graden
  // Positie veranderen
  // Snelheid van het draaien
  for (int positie = 120; positie > 0; positie--){
    servoMotor.write(positie);
    delay(snelheid);
  }
 }
