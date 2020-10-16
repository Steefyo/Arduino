// Defineer pins
int ledPins[] = { 11, 9, 10 };
int inputPin = 0;

// Zet gedefinieerde pins open
void setup() {
  pinMode(inputPin, INPUT);
  
  for(int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Krijg input waarde
  int inputValue = analogRead(inputPin);
  // Limiteer de waarde
  int hueValue = map(inputValue, 0, 1024, 0, 360);
  
  // Stuur naar de functie kleurenschema
  setHueValue(hueValue);
}

void setHueValue(int hueValue) {
  // Vertaal de kleur van HSV naar RGB
  // Ga daarna naar de volgende code
  setColor(ledPins, hsvToRgb(hueValue, 1, 1));
}

void setColor(int* led, const byte* color) {
  // D.m.v. de waardes verander de RGB Led
  for(int i = 0; i < 3; i++) {
    analogWrite(led[i], 255-color[i]);
  }
}

// Defineer 3 bytes; gebruikt voor 3 kleuren.
byte rgb[3];

// Gebruik de 3 bytes in de functie.
byte* hsvToRgb(int h, double s, double v) {
  // Definieer het maximale voor de waardes
  h = max(0, min(360, h));
  s = max(0, min(1.0, s));
  v = max(0, min(1.0, v));
  
  // Definieer de standaard logica/waarde.
  if(s == 0) {
    rgb[0] = rgb[1] = rgb[2] = round(v * 255);
    return rgb;
  }
  
  // Bereken welke kleur er aan de beurt is.
  // Faculteit deel van h
  double hs = h / 60.0; 
  int i = floor(hs);
  double f = hs - i; 
  double p = v * (1 - s);
  double q = v * (1 - s * f);
  double t = v * (1 - s * (1 - f));
  double r, g, b;

// D.m.v. de waarde i krijg de correcte kleur.
  switch(i) {
    case 0:
      r = v; g = t; b = p; break;
    case 1:
      r = q; g = v; b = p; break;
    case 2:
      r = p; g = v; b = t; break;
    case 3:
      r = p; g = q; b = v; break;
    case 4:
      r = t; g = p; b = v; break;
    default: // case 5:
      r = v; g = p; b = q;
  }

  // Zet de kleuren in de waardes
  rgb[0] = round(r * 255.0);
  rgb[1] = round(g * 255.0);
  rgb[2] = round(b * 255.0);
  
  // Stuur de waarde terug
  return rgb;
}
