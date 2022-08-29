/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

#include <Adafruit_NeoPixel.h>

enum 
{
  RGB_1 = 12,
  RGB_2 = 13,

  TONEPIN = 8,

  LED_1 = 2,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,
  LED_7,
  LED_8,
  LED_9,
  LED_10,

};

#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 112

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

const int tune[] = {
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD3,NTD2,NTD2,
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD2,NTD1,NTD1,
  NTD2,NTD2,NTD3,NTD1,
  NTD2,NTD3,NTD4,NTD3,NTD1,
  NTD2,NTD3,NTD4,NTD3,NTD2,
  NTD1,NTD2,NTDL5,NTD0,
  NTD3,NTD3,NTD4,NTD5,
  NTD5,NTD4,NTD3,NTD4,NTD2,
  NTD1,NTD1,NTD2,NTD3,
  NTD2,NTD1,NTD1
};

const float durt[] = {
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,0.5,0.5,1,1,
  1,0.5,0.5,1,1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,0.5,0.5,
  1,1,1,1,
  1+0.5,0.5,1+1,
};

static const auto length = sizeof(tune)/sizeof(tune[0]);

// Parameter 1 = number of pixels in strip1
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, RGB_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, RGB_2, NEO_GRB + NEO_KHZ800);
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  for(unsigned n = LED_1 ; n <= LED_10 ; ++n) {
    digitalWrite(n, LOW);
    pinMode(n, OUTPUT);
  }

  strip1.begin();
  strip2.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.show();

  pinMode(TONEPIN, OUTPUT);
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(Adafruit_NeoPixel::Color(50, 0, 0), 500);   // Red
  colorWipe(Adafruit_NeoPixel::Color(255, 0, 0), 500);  // Red
  colorWipe(Adafruit_NeoPixel::Color(0, 50, 0), 500);   // Green
  colorWipe(Adafruit_NeoPixel::Color(0, 255, 0), 500);  // Green
  colorWipe(Adafruit_NeoPixel::Color(0, 0, 50), 500);   // Blue
  colorWipe(Adafruit_NeoPixel::Color(0, 0, 255), 500);  // Blue
  colorWipe(Adafruit_NeoPixel::Color(0, 0, 50), 500);   // Blue
  colorWipe(Adafruit_NeoPixel::Color(0, 0, 0), 500);    // Dark
  turn1();
  clean();
 // turn2();
 // clean();
 // turn3();
 // clean();
  for(unsigned x = 0 ; x < length ; x++) {
    tone(TONEPIN, tune[x]);
    delay(190 * durt[x]);
    noTone(TONEPIN);
    delay(10 * durt[x]);
  }
  delay(2000);
}
// Fill the dots one after the other with a color


void colorWipe(uint32_t c, unsigned wait) {
  for (unsigned i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
  for (unsigned i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
}

void turn1() {
  for (unsigned n = LED_1 ; n <= LED_10 ; n++) {
      digitalWrite(n, HIGH);
      delay(300);
  }
  for (unsigned n = LED_1 ; n <= LED_10 ; n++) {
      digitalWrite(n, LOW);
      delay(300);
  }
}

void turn2() { 
  for (auto x = 0 ; x <= 2 ; x++) {
    for(auto n = 2 ; n <= 13 ; n++) {
      digitalWrite(n,HIGH);   
    }
    delay(300); 
    for (auto n = 2 ; n <= 13 ; n++) {
      digitalWrite(n,LOW); 
    }
    delay(300);
  }
}

void turn3() {
  for (auto x = 0 ; x <= 2 ; x++) {
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    for(auto n = 10 ; n <= 11 ; n++) {
      digitalWrite(n,LOW);
    }
    delay(300);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    delay(300);
    for(auto n = 2 ; n <= 11 ; n++) {
      digitalWrite(n,LOW);
    }
    delay(300);
  }
}

void clean() { 
  for(unsigned n = LED_1 ; n <= LED_10 ; n++) {
      digitalWrite(n,LOW); 
  }
  delay(300);
}
