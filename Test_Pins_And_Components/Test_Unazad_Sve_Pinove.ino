// TEST - Pronalazak pinova za UNAZAD
// Testira različite kombinacije pinova!

int testBroj = 1;

void setup() {
  // SVE pinove kao OUTPUT
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("╔════════════════════════════════════════╗");
  Serial.println("║  TEST: Tražim pinove za UNAZAD        ║");
  Serial.println("║  Testiram različite kombinacije...    ║");
  Serial.println("╚════════════════════════════════════════╝");
  
  delay(2000);
}

void loop() {
  // TEST 1: Pinovi 7,8,12,13 obrnuti + ostali HIGH
  testKombinaciju(1, "7,8,12,13 obrnuti + 2,4 HIGH");
  analogWrite(5, 200);
  analogWrite(11, 200);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  delay(3000);
  zaustaviSve();
  
  // TEST 2: Samo pinovi 2,4 obrnuti
  testKombinaciju(2, "Samo 2,4 obrnuti (HIGH, HIGH)");
  analogWrite(5, 200);
  analogWrite(11, 200);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  delay(3000);
  zaustaviSve();
  
  // TEST 3: Pinovi 9,11 kontrola
  testKombinaciju(3, "9=HIGH, 11=HIGH");
  analogWrite(5, 200);
  analogWrite(11, 200);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(3000);
  zaustaviSve();
  
  // TEST 4: Samo 2 HIGH, 4 LOW
  testKombinaciju(4, "2=HIGH, 4=LOW");
  analogWrite(5, 200);
  analogWrite(11, 200);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  delay(3000);
  zaustaviSve();
  
  // TEST 5: 2 LOW, 4 HIGH
  testKombinaciju(5, "2=LOW, 4=HIGH");
  analogWrite(5, 200);
  analogWrite(11, 200);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  delay(3000);
  zaustaviSve();
  
  // TEST 6: Svi digitalni na HIGH osim 7,8,12,13
  testKombinaciju(6, "2,4,9,11 svi HIGH");
  analogWrite(5, 200);
  analogWrite(11, 200);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(3000);
  zaustaviSve();
  
  Serial.println("\n╔════════════════════════════════════════╗");
  Serial.println("║  Ponavljam sve testove...             ║");
  Serial.println("╚════════════════════════════════════════╝\n");
  delay(2000);
}

void testKombinaciju(int broj, String opis) {
  Serial.println("\n========================================");
  Serial.print("TEST ");
  Serial.print(broj);
  Serial.print(": ");
  Serial.println(opis);
  Serial.println(">>> Gledaj točkove - idu NAPRED ili NAZAD?");
  Serial.println("========================================");
}

void zaustaviSve() {
  analogWrite(5, 0);
  analogWrite(11, 0);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  Serial.println(">>> STOP - čekam 10 sekundi...\n");
  delay(10000);  // 10 sekundi pauze
}

