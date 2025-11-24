// ========================================
// TEST: SENZOR SA PIN 10
// Testira pin 10 kao TRIG ili ECHO
// ========================================

int moguciPinovi[] = {2, 3, 4, 7, 8, 12, 13, A0, A1, A2, A3, A4, A5};
int brojPinova = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("===================================");
  Serial.println("TEST: SENZOR SA PIN 10");
  Serial.println("===================================");
  Serial.println("");
  Serial.println("Stavi objekat 20-30cm ispred senzora!");
  Serial.println("");
  delay(3000);
}

void loop() {
  Serial.println("========== FAZA 1: Pin 10 kao TRIG ==========");
  Serial.println("Testiram druge pinove kao ECHO...");
  Serial.println("");
  delay(2000);
  
  // Pin 10 je TRIG, drugi pinovi su ECHO
  for(int i = 0; i < brojPinova; i++) {
    int echoPin = moguciPinovi[i];
    testirajKombinaciju(10, echoPin, 1);
  }
  
  Serial.println("");
  Serial.println(">>> FAZA 1 ZAVRSENA <<<");
  Serial.println("");
  delay(3000);
  
  Serial.println("========== FAZA 2: Pin 10 kao ECHO ==========");
  Serial.println("Testiram druge pinove kao TRIG...");
  Serial.println("");
  delay(2000);
  
  // Pin 10 je ECHO, drugi pinovi su TRIG
  for(int i = 0; i < brojPinova; i++) {
    int trigPin = moguciPinovi[i];
    testirajKombinaciju(trigPin, 10, 2);
  }
  
  Serial.println("");
  Serial.println(">>> FAZA 2 ZAVRSENA <<<");
  Serial.println("");
  delay(3000);
  
  Serial.println("========== PONAVLJAM TESTOVE ==========");
  Serial.println("");
  delay(5000);
}

void testirajKombinaciju(int trig, int echo, int faza) {
  // Postavi pinove
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  // Ocisti
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // Posalji signal
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Cekaj odgovor
  long duration = pulseIn(echo, HIGH, 30000);
  
  // Konvertuj u cm
  long razdaljina = duration * 0.034 / 2;
  
  // Prikazi sve testove
  Serial.print("Test: TRIG=");
  Serial.print(trig);
  Serial.print(", ECHO=");
  Serial.print(echo);
  Serial.print(" >>> ");
  
  if(razdaljina == 0) {
    Serial.println("0 cm [nema signala]");
  } else {
    Serial.print(razdaljina);
    Serial.print(" cm");
    
    // Oznaci ako je razumna vrednost
    if(razdaljina > 2 && razdaljina < 300) {
      Serial.print(" <<<===== [*** RADI! ***] =====>>>");
    }
    Serial.println("");
  }
  
  // Resetuj pinove
  pinMode(trig, INPUT);
  pinMode(echo, INPUT);
  
  delay(1000);  // Pauza 1 sekunda izmedju testova
}
