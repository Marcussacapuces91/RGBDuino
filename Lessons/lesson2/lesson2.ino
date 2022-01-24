/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

void setup() {
  // Set pin mode to output
  pinMode(7, OUTPUT);
}

/**
 * Set pin on & off every 2 seconds.
 */
void loop() {
  // Set pin on (+5v)
  digitalWrite(7, HIGH);
  delay(1000);

  // Set pin off (0v)
  digitalWrite(7, LOW);
  delay(1000);
}
