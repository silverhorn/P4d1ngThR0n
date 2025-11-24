// TEST - SAMO levi tockovi IDU NAPRED
// Aktiviram SVE pinove, ali samo leve motore pokrećem

void setup() {
  // Aktiviraj SVE pinove
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
  
  // SVE PWM pinove aktiviraj
  analogWrite(3, 200);
  analogWrite(5, 200);
  analogWrite(6, 200);
  analogWrite(9, 200);
  analogWrite(10, 200);
  analogWrite(11, 200);
  
  // LEVI motori (7,8,12,13) - napred
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  
  // DESNI motori (10,11) - STOP (ne pokrećem ih)
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  // Ostali pinovi na LOW
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  delay(100);
}
