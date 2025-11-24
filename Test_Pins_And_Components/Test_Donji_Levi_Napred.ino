// ========================================
// TEST: DONJI LEVI TOCAK NAPRED
// Cilj: Pronaci koji pinovi kontrolisu samo donji levi tocak
// Gledaj Serial Monitor da vidis koja kombinacija radi!
// ========================================

// Svi PWM pinovi koji mogu kontrolisati brzinu
int pwmPinovi[] = {3, 5, 6, 9, 10, 11};
int brojPWM = 6;

// Svi digital pinovi koji mogu kontrolisati pravac
int digitalPinovi[] = {2, 4, 7, 8, 12, 13};
int brojDigital = 6;

void setup() {
  Serial.begin(9600);
  Serial.println("===================================");
  Serial.println("TEST: DONJI LEVI TOCAK NAPRED");
  Serial.println("===================================");
  Serial.println("");
  delay(2000);
  
  // Postavi sve pinove kao OUTPUT
  for(int i = 0; i < brojPWM; i++) {
    pinMode(pwmPinovi[i], OUTPUT);
  }
  for(int i = 0; i < brojDigital; i++) {
    pinMode(digitalPinovi[i], OUTPUT);
  }
}

void loop() {
  // Probaj svaki PWM pin
  for(int pwm = 0; pwm < brojPWM; pwm++) {
    
    // Za svaki PWM, probaj kombinacije digital pinova
    // Kombinacija 1: Samo prvi digital pin HIGH
    for(int d1 = 0; d1 < brojDigital; d1++) {
      testirajKombinaciju(pwmPinovi[pwm], digitalPinovi[d1], -1);
    }
    
    // Kombinacija 2: Dva digital pina HIGH
    for(int d1 = 0; d1 < brojDigital; d1++) {
      for(int d2 = d1 + 1; d2 < brojDigital; d2++) {
        testirajKombinaciju(pwmPinovi[pwm], digitalPinovi[d1], digitalPinovi[d2]);
      }
    }
  }
  
  Serial.println("");
  Serial.println("===================================");
  Serial.println("TEST ZAVRSEN! Ponavljam...");
  Serial.println("===================================");
  Serial.println("");
  delay(5000);
}

void testirajKombinaciju(int pwmPin, int digitalPin1, int digitalPin2) {
  // Iskljuci sve prvo
  for(int i = 0; i < brojPWM; i++) {
    analogWrite(pwmPinovi[i], 0);
  }
  for(int i = 0; i < brojDigital; i++) {
    digitalWrite(digitalPinovi[i], LOW);
  }
  
  delay(200);
  
  // Prikazi sta testiramo
  Serial.print("TEST: PWM=");
  Serial.print(pwmPin);
  Serial.print(" (200) | Digital: ");
  Serial.print(digitalPin1);
  Serial.print("=HIGH");
  if(digitalPin2 != -1) {
    Serial.print(", ");
    Serial.print(digitalPin2);
    Serial.print("=HIGH");
  }
  Serial.println();
  
  // Aktiviraj PWM pin
  analogWrite(pwmPin, 200);
  
  // Aktiviraj digital pinove
  digitalWrite(digitalPin1, HIGH);
  if(digitalPin2 != -1) {
    digitalWrite(digitalPin2, HIGH);
  }
  
  // Sacekaj 3 sekunde da vidis sta se desava
  delay(3000);
  
  // Iskljuci sve
  analogWrite(pwmPin, 0);
  digitalWrite(digitalPin1, LOW);
  if(digitalPin2 != -1) {
    digitalWrite(digitalPin2, LOW);
  }
  
  Serial.println(">>> STOP 10 sekundi <<<");
  Serial.println("");
  delay(10000);
}
