/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

const auto LED = 3;   // Pin 3
auto brightness = 0;
auto fadeAmount = 5;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  analogWrite(LED, brightness);               // analogic value, not binarie as HIGH/LOW
  brightness += fadeAmount;                   // brightness = brightness + fadeAmount
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}
