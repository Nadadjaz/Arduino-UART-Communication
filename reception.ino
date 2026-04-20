// ============================================
// UART Communication - Arduino Receiver
// Project: Serial Data Reception with LEDs
// Author: Nada Djazari
// University of Jijel
// ============================================

// LED pins
#define led1 A0 // LED 1 connected to analog pin A0
#define led2 A1 // LED 2 connected to analog pin A1
#define led3 A2 // LED 3 connected to analog pin A2

// Reception pin
const int RX_PIN = 0; // Digital pin 0 used for reception

// Time variables for pulseIn measurements
unsigned long t1; // Time measured at HIGH state (first pulse)
unsigned long t2; // Time measured at LOW state
unsigned long t3; // Time measured at HIGH state (third pulse)

void setup() {
  // Declare LEDs as outputs
  pinMode(led1, OUTPUT); // LED 1 declared as output
  pinMode(led2, OUTPUT); // LED 2 declared as output
  pinMode(led3, OUTPUT); // LED 3 declared as output

  // Declare reception pin as input
  pinMode(RX_PIN, INPUT); // Pin 0 declared as input

  // Turn off all LEDs at start
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  Serial.begin(9600); // Transmission speed: 9600 bits per second
}

void loop() {
  // Read state of reception pin
  bool etat2 = digitalRead(RX_PIN); // Read voltage level of digital pin 0

  // If a signal is detected (pin HIGH)
  if (etat2 == 1) {
    t1 = pulseIn(RX_PIN, HIGH); // Measure duration of HIGH state (first pulse)
    t2 = pulseIn(RX_PIN, LOW);  // Measure duration of LOW state
    t3 = pulseIn(RX_PIN, HIGH); // Measure duration of HIGH state (third pulse)
  }

  delay(200); // Wait 200ms

  // ── Pattern Button 1: t1≈500µs, t2≈700µs, t3≈300µs ──
  // FIXED: correct range comparison in C (0 < t1 < 500 is WRONG in C)
  if (t1 > 400 && t1 < 600 && t2 > 600 && t2 < 800 && t3 > 200 && t3 < 400) {
    digitalWrite(led1, HIGH); // Turn on LED 1
    delay(200);               // Keep ON for 200ms
  } else {
    digitalWrite(led1, LOW);  // Turn off LED 1
    delay(200);
  }

  delay(100);

  // ── Pattern Button 2: t1≈300µs, t2≈100µs, t3≈800µs ──
  if (t1 > 200 && t1 < 400 && t2 > 50 && t2 < 200 && t3 > 700 && t3 < 900) {
    digitalWrite(led2, HIGH); // Turn on LED 2
    delay(200);               // Keep ON for 200ms
  } else {
    digitalWrite(led2, LOW);  // Turn off LED 2
    delay(200);
  }

  delay(100);

  // ── Pattern Button 3: t1≈800µs, t2≈200µs, t3≈600µs ──
  if (t1 > 700 && t1 < 900 && t2 > 100 && t2 < 300 && t3 > 500 && t3 < 700) {
    digitalWrite(led3, HIGH); // Turn on LED 3
    delay(200);               // Keep ON for 200ms
  } else {
    digitalWrite(led3, LOW);  // Turn off LED 3 (FIXED: was led1 by mistake)
    delay(200);
  }

  // If no signal detected: turn off all LEDs
  if (etat2 == 0) {
    digitalWrite(led1, LOW); // Turn off LED 1
    digitalWrite(led2, LOW); // Turn off LED 2
    digitalWrite(led3, LOW); // Turn off LED 3
  }

  delay(100);
}
