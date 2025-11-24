// TEST - Svi 4 tockovi IDU UNAZAD
// Obrnuto od Test_Napred-Perfektno.ino BEZ pinova 2,4

#define ENA 5
#define IN1 7
#define IN2 8
#define ENB 6
#define IN3 12
#define IN4 13

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // UNAZAD - obrnuto od Test_Napred-Perfektno
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  
  // Test_Napred-Perfektno: LOW, HIGH, LOW, HIGH
  // Za unazad:
  digitalWrite(IN1, HIGH);  // Perfektno je LOW
  digitalWrite(IN2, LOW);   // Perfektno je HIGH
  
  digitalWrite(IN3, HIGH);  // Perfektno je LOW
  digitalWrite(IN4, LOW);   // Perfektno je HIGH
}

void loop() {
  delay(100);
}
