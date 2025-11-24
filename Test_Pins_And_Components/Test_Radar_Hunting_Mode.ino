// ========================================
// RADAR HUNTING MODE
// Servo trazi najblizu prepreku i "ciljka" je
// ========================================

#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 13
#define SERVO_PIN 10

Servo radarServo;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  radarServo.attach(SERVO_PIN);
  radarServo.write(90);
  
  Serial.println("===================================");
  Serial.println("   RADAR HUNTING MODE - AKTIVAN");
  Serial.println("===================================");
  Serial.println("Robot trazi najblizu metu...");
  Serial.println("");
  delay(2000);
}

void loop() {
  Serial.println("");
  Serial.println("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
  Serial.println("▓  POCINJE LOV NA METU          ▓");
  Serial.println("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
  Serial.println("");
  
  // Promenljive za najblizi objekat
  int najbliziUgao = 90;
  long najblizaRazdaljina = 999;
  
  // BRZO SKENIRANJE - trazi metu
  Serial.println(">>> Skeniram okolinu... <<<");
  Serial.println("");
  
  for(int ugao = 0; ugao <= 180; ugao += 15) {
    radarServo.write(ugao);
    delay(300);
    
    long razdaljina = izmeriRazdaljinu();
    
    Serial.print("Ugao ");
    Serial.print(ugao);
    Serial.print("° : ");
    Serial.print(razdaljina);
    Serial.print(" cm");
    
    // Da li je ovo najblizi objekat?
    if(razdaljina < najblizaRazdaljina && razdaljina > 5) {
      najblizaRazdaljina = razdaljina;
      najbliziUgao = ugao;
      Serial.print(" <<< NOVA META!");
    }
    
    Serial.println("");
  }
  
  Serial.println("");
  
  // Da li smo nasli metu?
  if(najblizaRazdaljina < 300) {
    Serial.println("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
    Serial.println("▓  META PRONADJENA!             ▓");
    Serial.println("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
    Serial.print(">>> UGAO: ");
    Serial.print(najbliziUgao);
    Serial.println("°");
    Serial.print(">>> RAZDALJINA: ");
    Serial.print(najblizaRazdaljina);
    Serial.println(" cm");
    Serial.println("");
    
    // CILJAMO METU
    Serial.println(">>> Cilja se na metu... <<<");
    radarServo.write(najbliziUgao);
    delay(500);
    
    // "PUCAMO" 3 puta sa preciznim merenjem
    for(int i = 1; i <= 3; i++) {
      Serial.print("METAK ");
      Serial.print(i);
      Serial.print(": ");
      
      long preciznaRazdaljina = izmeriRazdaljinu();
      
      Serial.print(preciznaRazdaljina);
      Serial.println(" cm >>> POGODAK!");
      
      delay(1000);
    }
    
    Serial.println("");
    Serial.println(">>> MISIJA USPESNA! <<<");
    
  } else {
    Serial.println("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
    Serial.println("▓  NEMA META U DOMETU           ▓");
    Serial.println("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
    Serial.println(">>> Okolina je slobodna <<<");
  }
  
  // Vrati na centar
  Serial.println("");
  Serial.println(">>> Vracam se na centar... <<<");
  radarServo.write(90);
  
  Serial.println("");
  delay(3000);
}

long izmeriRazdaljinu() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  long razdaljina = duration * 0.034 / 2;
  
  if(razdaljina == 0 || razdaljina > 400) {
    razdaljina = 999;
  }
  
  return razdaljina;
}
