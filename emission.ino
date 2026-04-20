// ============================================
// UART Communication - Arduino Emitter
// Project: Serial Data Transmission with Buttons
// Author: Nada Djazari
// University of Jijel
// ============================================

// Button pins (analog pins used as digital)
const int x1 = A0; // Button 1 connected to analog pin A0
const int x2 = A1; // Button 2 connected to analog pin A1
const int x3 = A2; // Button 3 connected to analog pin A2

// Transmission pin
const int TX_PIN = 3; // Digital pin 3 used for transmission

void setup() {
  // Declare buttons as inputs with internal pull-up resistors
  pinMode(x1, INPUT_PULLUP); // Button 1 declared as input
  pinMode(x2, INPUT_PULLUP); // Button 2 declared as input
  pinMode(x3, INPUT_PULLUP); // Button 3 declared as input

  // Declare transmission pin as output
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW); // Initial state: LOW

  Serial.begin(9600); // Transmission speed: 9600 bits per second
}

void loop() {
  // Read button states using digitalRead (buttons use INPUT_PULLUP)
  // With INPUT_PULLUP: button pressed = 0, button released = 1
  bool bp1 = digitalRead(x1); // Read digital state of pin A0
  bool bp2 = digitalRead(x2); // Read digital state of pin A1
  bool bp3 = digitalRead(x3); // Read digital state of pin A2

  // If all buttons are released (=1), do nothing
  if (bp1 == 1 && bp2 == 1 && bp3 == 1) {
    // Do nothing
  }
  else {

    // If button 1 is pressed: emit signal pattern for button 1
    // HIGH 500µs → LOW 700µs → HIGH 300µs
    if (bp1 == 0) {
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(700);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(300);
      digitalWrite(TX_PIN, LOW); // Return to LOW after signal
      delay(200); // Wait 200ms between transmissions
    }

    // If button 2 is pressed: emit signal pattern for button 2
    // HIGH 300µs → LOW 100µs → HIGH 800µs
    if (bp2 == 0) {
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(300);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(100);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(800);
      digitalWrite(TX_PIN, LOW); // Return to LOW after signal
      delay(200); // Wait 200ms between transmissions
    }

    // If button 3 is pressed: emit signal pattern for button 3
    // HIGH 800µs → LOW 200µs → HIGH 600µs
    if (bp3 == 0) {
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(800);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(200);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(600);
      digitalWrite(TX_PIN, LOW); // Return to LOW after signal
      delay(200); // Wait 200ms between transmissions
    }

  }
}
