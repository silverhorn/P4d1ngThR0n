// ========================================
// TEST: SAMO DONJI LEVI TOCAK (A2) NAPRED
// Cilj: Pronaci pinove koji kontrolisu SAMO donji levi tocak
// Ne sme da se pokrece gornji levi tocak!
// ========================================

void setup() {
  Serial.begin(9600);
  Serial.println("===================================");
  Serial.println("TEST: SAMO DONJI LEVI (A2) NAPRED");
  Serial.println("===================================");
  Serial.println("");
  delay(3000);
  
  // Postavi sve pinove kao OUTPUT
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("========== POCINJE TESTIRANJE ==========");
  Serial.println("");
  
  // TEST 1: PWM=5, samo pin 4 HIGH (gornji levi mozda?)
  testiraj("TEST 1", 5, 4, -1, -1);
  
  // TEST 2: PWM=5, samo pin 2 HIGH (donji levi mozda?)
  testiraj("TEST 2", 5, 2, -1, -1);
  
  // TEST 3: PWM=3, samo pin 4 HIGH
  testiraj("TEST 3", 3, 4, -1, -1);
  
  // TEST 4: PWM=3, samo pin 2 HIGH
  testiraj("TEST 4", 3, 2, -1, -1);
  
  // TEST 5: PWM=6, samo pin 4 HIGH
  testiraj("TEST 5", 6, 4, -1, -1);
  
  // TEST 6: PWM=6, samo pin 2 HIGH
  testiraj("TEST 6", 6, 2, -1, -1);
  
  // TEST 7: PWM=5, pin 2 HIGH, pin 7 HIGH
  testiraj("TEST 7", 5, 2, 7, -1);
  
  // TEST 8: PWM=5, pin 2 HIGH, pin 8 HIGH
  testiraj("TEST 8", 5, 2, 8, -1);
  
  // TEST 9: PWM=5, pin 4 LOW, pin 2 HIGH (obrnuto od obicnog)
  testiraj_obrnuto("TEST 9", 5, 4, 2);
  
  // TEST 10: PWM=3, pin 4 LOW, pin 2 HIGH
  testiraj_obrnuto("TEST 10", 3, 4, 2);
  
  // TEST 11: PWM=5, pin 7 HIGH
  testiraj("TEST 11", 5, 7, -1, -1);
  
  // TEST 12: PWM=5, pin 8 HIGH
  testiraj("TEST 12", 5, 8, -1, -1);
  
  // TEST 13: PWM=5, pin 12 HIGH
  testiraj("TEST 13", 5, 12, -1, -1);
  
  // TEST 14: PWM=5, pin 13 HIGH
  testiraj("TEST 14", 5, 13, -1, -1);
  
  // TEST 15: PWM=5, pin 2 HIGH, pin 4 LOW
  testiraj_sa_low("TEST 15", 5, 2, 4);
  
  Serial.println("");
  Serial.println("========== KRAJ - PONAVLJAM TESTOVE ==========");
  Serial.println("");
  delay(5000);
}

void testiraj(String naziv, int pwmPin, int pin1, int pin2, int pin3) {
  // Iskljuci sve
  ugasi_sve();
  delay(500);
  
  // Prikazi test
  Serial.print(naziv);
  Serial.print(": PWM=");
  Serial.print(pwmPin);
  Serial.print(" (200) | Pin ");
  Serial.print(pin1);
  Serial.print("=HIGH");
  if(pin2 != -1) {
    Serial.print(", Pin ");
    Serial.print(pin2);
    Serial.print("=HIGH");
  }
  if(pin3 != -1) {
    Serial.print(", Pin ");
    Serial.print(pin3);
    Serial.print("=HIGH");
  }
  Serial.println();
  
  // Aktiviraj
  analogWrite(pwmPin, 200);
  digitalWrite(pin1, HIGH);
  if(pin2 != -1) digitalWrite(pin2, HIGH);
  if(pin3 != -1) digitalWrite(pin3, HIGH);
  
  // Radi 5 sekundi
  delay(5000);
  
  // Stop
  ugasi_sve();
  Serial.println(">>> STOP 10 sekundi <<<");
  Serial.println("");
  delay(10000);
}

void testiraj_obrnuto(String naziv, int pwmPin, int pinLow, int pinHigh) {
  // Iskljuci sve
  ugasi_sve();
  delay(500);
  
  // Prikazi test
  Serial.print(naziv);
  Serial.print(": PWM=");
  Serial.print(pwmPin);
  Serial.print(" (200) | Pin ");
  Serial.print(pinLow);
  Serial.print("=LOW, Pin ");
  Serial.print(pinHigh);
  Serial.println("=HIGH");
  
  // Aktiviraj
  analogWrite(pwmPin, 200);
  digitalWrite(pinLow, LOW);
  digitalWrite(pinHigh, HIGH);
  
  // Radi 5 sekundi
  delay(5000);
  
  // Stop
  ugasi_sve();
  Serial.println(">>> STOP 10 sekundi <<<");
  Serial.println("");
  delay(10000);
}

void testiraj_sa_low(String naziv, int pwmPin, int pinHigh, int pinLow) {
  testiraj_obrnuto(naziv, pwmPin, pinLow, pinHigh);
}

void ugasi_sve() {
  // Ugasi sve PWM pinove
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
  
  // Ugasi sve digitalne pinove
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
