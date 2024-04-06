//
// urumbu-drv8825-test.ino
//
// DRV8825-D11C stepper test code
//
// Saheen Palayi 06/04/24
//
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose, but must
// acknowledge this project. Copyright is retained and
// must be preserved. The work is provided as is; no
// warranty is provided, and users accept all liability.
//

#define LED 30
#define EN 5
#define DIR 2
#define STEP 4

void setup() {
  pinMode(LED, OUTPUT);   // LED pin as output
  pinMode(EN, OUTPUT);    // Enable pin as output
  pinMode(DIR, OUTPUT);   // Direction pin as output
  pinMode(STEP, OUTPUT);  // Step pin as output
}

void loop() {
  digitalWrite(LED, HIGH);  // Turn on LED to indicate motor is running

  digitalWrite(EN, LOW);    // Enable the motor driver
  digitalWrite(DIR, HIGH);  // Set direction to clockwise

  // Rotate motor
  for (int i = 0; i < 200; i++) {  // 200 steps for one complete revolution
    digitalWrite(STEP, HIGH);      // Step high
    delayMicroseconds(500);        // Wait 0.5ms
    digitalWrite(STEP, LOW);       // Step low
    delayMicroseconds(500);        // Wait 0.5ms
  }

  digitalWrite(EN, HIGH);  // Disable the motor driver
  digitalWrite(LED, LOW);  // Turn off LED
  delay(1000);             // Wait for 1 second before next rotation
}
