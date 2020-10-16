// Defineer pins
const int pm = A5;
int pmw = 0;

// Start de serial monitor.
void setup() {
  Serial.begin(9600);
}

void loop() {
   // Zet een limiet aan de potentiële waarde.
  pmw = map(analogRead(pm), 0, 1023, 0, 500);
  
  // Zet text in het scherm
  Serial.print("Temperatuur in graden Celsius = ");
  Serial.println(pmw);


  // Wacht 500 miliseconden (halve seconde)
  delay(500);
}
