// Defineer pins
const int pm = A5;
int pmw = 0;
int l1 = 13;
int l2 = 12;
int l3 = 11;
int l4 = 10;
int l5 = 9;
int l6 = 8;
int l7 = 7;

// Defineer map waarde
int im;             

// Zet gedefinieerde pins open
void setup() {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
}

void loop() {
  // Lees de meter uit.
  pmw = analogRead(pm);

  // Zet een limiet aan de potentiële waarde.
  im = map(pmw, 0, 1023, 0, 700);
  
  // Zet lamp aan/uit d.m.v. de waarde.
  if (im >= 100) {
    digitalWrite(l1, HIGH);
  } else {
    digitalWrite(l1, LOW);
  }

  if (im >= 200) {
    digitalWrite(l2, HIGH);
  } else {
    digitalWrite(l2, LOW);
  }
  
  if (im >= 300) {
    digitalWrite(l3, HIGH);
  } else {
    digitalWrite(l3, LOW);
  }
  
  if (im >= 400) {
    digitalWrite(l4, HIGH);
  } else {
    digitalWrite(l4, LOW);
  }
  
  if (im >= 500) {
    digitalWrite(l5, HIGH);
  } else {
    digitalWrite(l5, LOW);
  }
  
  if (im >= 600) {
    digitalWrite(l6, HIGH);
  } else {
    digitalWrite(l6, LOW);
  }
  
  if (im >= 700) {
    digitalWrite(l7, HIGH);
  } else {
    digitalWrite(l7, LOW);
  }
}
