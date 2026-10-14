// ==========================================
// MINEGUARD-X
// ESP32 + L298N + HC-SR04 + Buzzer
// ==========================================


// ---------- MOTOR PINS ----------
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 13


// ---------- HC-SR04 ----------
#define TRIG_PIN 18
#define ECHO_PIN 19


// ---------- BUZZER ----------
#define BUZZER_PIN 32


// ---------- DISTANCE LIMITS ----------
#define SAFE_DISTANCE 100
#define CAUTION_DISTANCE 60
#define WARNING_DISTANCE 30


// ==========================================
// MOTOR FUNCTIONS
// ==========================================

void forward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void stopMotors() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// ==========================================
// ULTRASONIC DISTANCE FUNCTION
// ==========================================

float getDistance() {

  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);


  // Measure echo
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);


  // No echo received
  if (duration == 0) {
    return -1;
  }


  // Calculate distance
  float distance = duration * 0.0343 / 2;

  return distance;
}


// ==========================================
// SETUP
// ==========================================

void setup() {

  Serial.begin(115200);


  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  // Ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);


  // Buzzer
  pinMode(BUZZER_PIN, OUTPUT);


  // Initial state
  stopMotors();
  digitalWrite(BUZZER_PIN, LOW);

  digitalWrite(TRIG_PIN, LOW);


  Serial.println();
  Serial.println("================================");
  Serial.println("        MINEGUARD-X");
  Serial.println("   Mine Vehicle Safety System");
  Serial.println("================================");
  Serial.println();


  delay(2000);
}


// ==========================================
// MAIN LOOP
// ==========================================

void loop() {

  float distance = getDistance();


  // ========================================
  // SENSOR ERROR / NO ECHO
  // ========================================

  if (distance < 0) {

    Serial.println("Distance: No reading");

    // For this test, continue moving
    forward();

    digitalWrite(BUZZER_PIN, LOW);

    delay(100);

    return;
  }


  // ========================================
  // DISPLAY DISTANCE
  // ========================================

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");


  // ========================================
  // SAFE
  // Distance > 100 cm
  // ========================================

  if (distance > SAFE_DISTANCE) {

    Serial.println(" | STATUS: SAFE");

    forward();

    digitalWrite(BUZZER_PIN, LOW);
  }


  // ========================================
  // CAUTION
  // 60 - 100 cm
  // ========================================

  else if (distance > CAUTION_DISTANCE) {

    Serial.println(" | STATUS: CAUTION");

    forward();

    digitalWrite(BUZZER_PIN, LOW);
  }


  // ========================================
  // WARNING
  // 30 - 60 cm
  // ========================================

  else if (distance > WARNING_DISTANCE) {

    Serial.println(" | STATUS: WARNING");

    forward();

    digitalWrite(BUZZER_PIN, LOW);
  }


  // ========================================
  // CRITICAL
  // ≤ 30 cm
  // ========================================

  else {

    Serial.println(" | STATUS: CRITICAL - STOP");

    stopMotors();

    digitalWrite(BUZZER_PIN, HIGH);
  }


  delay(100);
}