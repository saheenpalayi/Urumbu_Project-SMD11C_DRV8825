//
// urumbu-d11c-drv8825.ino
//
// serial step-and-direction
//
// Neil Gershenfeld 4/11/21
// Quentin Bolsee 12/7/21 : add button
// Saheen Palayi 06/04/2024 : removed microstepping and added LED, 
//
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose, but must
// acknowledge this project. Copyright is retained and
// must be preserved. The work is provided as is; no
// warranty is provided, and users accept all liability.
//


#define Address "000" // change address here

#define LED 30
#define EN 5
#define DIR 2
#define STEP 4
#define BUTTON 31


void setup() {
  SerialUSB.begin(0);

  pinMode(LED, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(LED, HIGH);
  digitalWrite(EN, HIGH);
  digitalWrite(STEP, LOW);
  digitalWrite(DIR, LOW);
}

void loop() {
  if (SerialUSB.available()) {
    char c = SerialUSB.read();
    if (c == 'f') {
      digitalWrite(DIR, HIGH);
      digitalWrite(STEP, HIGH);
      digitalWrite(LED, HIGH);
      delayMicroseconds(2);
      digitalWrite(STEP, LOW);
      digitalWrite(LED, LOW);
    } else if (c == 'r') {
      digitalWrite(DIR, LOW);
      digitalWrite(LED, HIGH);
      delayMicroseconds(2);
      digitalWrite(STEP, LOW);
      digitalWrite(LED, LOW);
    } else if (c == '?') {
      // reply with button value
      int btn = digitalRead(BUTTON);
      SerialUSB.write(btn ? '1' : '0');
    } else if (c == '@') {
      SerialUSB.write(Address); 
    }
  }
}
