/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

const auto LED_PIN = 6;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, 255);  //same with HIGH
  delay(1000);
  analogWrite(LED_PIN, 123);
  delay(1000);
  analogWrite(LED_PIN, 50);
  delay(1000);
  analogWrite(LED_PIN, LOW);  //same with 0
  delay(1000);
}
