#include <Arduino.h>
#include <TM1637Display.h>

/*
  
*/

const uint8_t READ_PIN = 12;

TM1637Display display(10, 11);

void setup() {
  Serial.begin(9600);
  // Set pins to inputs
  pinMode(READ_PIN, INPUT);
  display.setBrightness(0x0f);
}

bool isLive(uint8_t pin) {
  uint8_t active = 0;
  // Set as HIGH output
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(1);
  // Read result
  active = digitalRead(READ_PIN);
  // Set as LOW and INPUT
  digitalWrite(pin, LOW);
  pinMode(pin, LOW);
  //
  return active;
}

void loop() {
  uint8_t i = 9;
  uint8_t level = 0;
  while(isLive(i) && i > 1)
  {
    level++;
    i--;
  }
  // Serial.print("Level: ");
  // Serial.print(level);
  // Serial.println(" cm");
  display.showNumberDec(level, false);
  delay(20);
}