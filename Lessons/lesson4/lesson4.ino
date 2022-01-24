/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

const auto LED = 4;
const auto BUTTON = 2;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(BUTTON) == LOW)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}
