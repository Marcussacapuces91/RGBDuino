const auto pinBuzzer = 8;
const auto buttonPin = 2;
const auto frequency = 2000;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  const auto buttonState = digitalRead(buttonPin);
  if(buttonState == LOW) {
    tone(pinBuzzer, frequency);
  } else {
    noTone(pinBuzzer);
  }
}
