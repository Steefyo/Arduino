// Defineer pins
int ledR = 13;
int ledO = 12;
int ledG = 11;  

// Defineer variable van bluetooth
char Incoming_value = 0; 

// Zet Serial monitor aan
// Zet lamp op pin
void setup() {
  Serial.begin(9600);         
  pinMode(ledR, OUTPUT);
  pinMode(ledO, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  // Controleer de ingevoerde data
  // Sla de data op in een variable
  // Toon de variable in Serial monitor
  if(Serial.available() > 0) {
    Incoming_value = Serial.read(); 
    Serial.print(Incoming_value);   
    Serial.print("\n");
  }

  // Als variable 1 is
  if(Incoming_value == '1') { 
      // Zet lamp aan en zet vorige lamp uit
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      delay(1000);
      digitalWrite(ledG, LOW);
      digitalWrite(ledO, HIGH);
      delay(1000);
      digitalWrite(ledO, LOW);
      digitalWrite(ledR, HIGH);
      delay(1000);
  } else {
      // Zet lamp groen/rood uit
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      // Knipper oranje
      digitalWrite(ledO, HIGH);
      delay(1000);
      digitalWrite(ledO, LOW);
      delay(1000);      
  }
}
