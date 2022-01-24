/**
 * Copyright (c) 2022, Marc SIBERT
 * 
 * @see ../LICENSE
 */

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

static const int tune[] = {
  NTD3, NTD3, NTD4, NTD5,
  NTD5, NTD4, NTD3, NTD2,
  NTD1, NTD1, NTD2, NTD3,
  NTD3, NTD2, NTD2,
  NTD3, NTD3, NTD4, NTD5,
  NTD5, NTD4, NTD3, NTD2,
  NTD1, NTD1, NTD2, NTD3,
  NTD2, NTD1, NTD1,
  NTD2, NTD2, NTD3, NTD1,
  NTD2, NTD3, NTD4, NTD3, NTD1,
  NTD2, NTD3, NTD4, NTD3, NTD2,
  NTD1, NTD2, NTDL5, NTD0,
  NTD3, NTD3, NTD4, NTD5,
  NTD5, NTD4, NTD3, NTD4, NTD2,
  NTD1, NTD1, NTD2, NTD3,
  NTD2, NTD1, NTD1
};

static const byte durt[] = {
  2,    2,    2,    2,
  2,    2,    2,    2,
  2,    2,    2,    2,
  3,    1,    4,
  2,    2,    2,    2,
  2,    2,    2,    2,
  2,    2,    2,    2,
  3,    1,    4,
  2,    2,    2,    2,
  2,    1,    1,    2,    2,
  2,    1,    1,    2,    2,
  2,    2,    2,    2,
  2,    2,    2,    2,
  2,    2,    2,    1,    1,
  2,    2,    2,    2,
  3,    1,    4,
};

int length;
const auto TONEPIN = 8;
const auto BUTTON = 2;

void setup()
{
  pinMode(TONEPIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  length=sizeof(tune)/sizeof(tune[0]);
}

void loop()
{
  if (!digitalRead(BUTTON)) {
    for(auto x = 0; x < length; x++) {
      tone(TONEPIN, tune[x]);
      delay(100 * durt[x]);
      noTone(TONEPIN);
      delay(10);
    }
    delay(2000);
  }
}
