/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

/**
 * Called once, at first.
 */
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
}

/**
 * Called repeatedly.
 */
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, LOW);
  // digitalWrite(7, HIGH);
}
