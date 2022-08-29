

class RTTTL {

public:
  RTTTL(const __FlashStringHelper* const aString) : 
    start((const PROGMEM char *)aString),
    sep1(strchr_P((const PROGMEM char *)aString, ':')),
    sep2(strchr_P(sep1 + 1, ':')),
    len(strlen_P((const PROGMEM char *)aString))
  {}

  String name() const {
    String s;
    for (const char* p = start; p < sep1; ++p) {
      s += char(pgm_read_byte_near(p));
    }
    return s;
  }

  void def(byte& duration, byte& octave, byte& beat) const {
    const char* p = sep1+1;
    while (p < sep2) {
      String s;
      switch (pgm_read_byte_near(p)) {
        case 'd':
          p +=2;
          while (pgm_read_byte_near(p) >= '0' and pgm_read_byte_near(p) <= '9') {
            s += char(pgm_read_byte_near(p++));
          }
          duration = s.toInt();
          break;
        case 'o':
          p +=2;
          while (pgm_read_byte_near(p) >= '0' and pgm_read_byte_near(p) <= '9') {
            s += char(pgm_read_byte_near(p++));
          }
          octave = s.toInt();
          break;
        case 'b':
          p +=2;
          while (pgm_read_byte_near(p) >= '0' and pgm_read_byte_near(p) <= '9') {
            s += char(pgm_read_byte_near(p++));
          }
          beat = s.toInt();
          break;
        default:
          ++p;
      }
    }
  }

  void play(const byte aPin) const {
    byte d = 0, o = 0, b = 0;
    def(d, o, b);
    const char* p = sep2+1;
    while (p < start + len) {
      String s;
// Duration 1/t (1, 2... 32)
      while ((pgm_read_byte_near(p) >= '0' && pgm_read_byte_near(p) <= '9') || pgm_read_byte_near(p) == ' ') {
        s += char(pgm_read_byte_near(p++));
      }
      const unsigned duration = s.toInt() ? s.toInt() : d;  // default
      
// Pitch (A, B...)
      s = char(pgm_read_byte_near(p++));
      if (char(pgm_read_byte_near(p)) == '#') {
        s += '#';
        ++p;
      }
      s.toUpperCase();
/// @see https://pages.mtu.edu/~suits/notefreqs.html
      const String n[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
      float freq = 2093;  // C7
      if (s == "P") {
        freq = 0;
      } else {
        for (byte i = 0; i < sizeof(n) / sizeof(n[0]); ++i) {
          freq *= pow(2, 1/12.0);
          if (s == n[i]) {
            break;
          }
        }
      }
            
// Dotted (duration * 1.5)
      const bool dot = char(pgm_read_byte_near(p)) == '.';
      if (dot) ++p;

// Octave
      byte octave = o;  // default
      if (pgm_read_byte_near(p) >= '0' && pgm_read_byte_near(p) <= '9') {
        octave = char(pgm_read_byte_near(p)) - '0';
        ++p;
      }

      if (freq) {
        tone(aPin, unsigned(round(freq)) / (1 << (7 - octave)));
        delay((dot ? (1.5 * 60000UL / b / duration) : (60000U / b / duration))*4);
        noTone(aPin);
        delay(50);
      } else {
        delay((dot ? ((1.5 * 60000UL / b) / duration) : ((60000U / b) / duration))*4);
      }

// Next ','
      while (char(pgm_read_byte_near(p)) != ',') ++p;
// Next sign
      ++p;

    }
  }

private:
  const char* const start;
  const char* const sep1;
  const char* const sep2;
  const unsigned len;
  
};


static const auto SOUND_PIN = 8;
static const auto BUTTON_PIN = 2;

const char PROGMEM ELISE[]  = "Beethovem - Fur Elise : d=4,o=5,b=160:8e7,8d#7,8e7,8d#7,8e7,8b6,8d7,8c7,8a6,8e,8a,8c6,8e6,8a6,8b6,8e,8g#,8e6,8g#6,8b6,8c7,8e,8a,8e6,8e7,8d#7,8e7,8d#7,8e7,8b6,8d7,8c7,8a6,8e,8a,8c6,8e6,8a6,8b6,8e,8g#,8e6,8c7,8b6,2a6";
const char PROGMEM JB_THEME[]  = "James Bond Theme : d=4,o=5,b=140:8e,16f#,16f#,8f#,f#,8e,8e,8e,8e,16g,16g,8g,g,8f#,8f#,8f#,8e,16f#,16f#,8f#,f#,8e,8e,8e,8e,16g,16g,8g,g,8f#,8f,8e,8d#6,2d.6,8b,8a,1b,";
const char PROGMEM MARSEILLAISE[]  = "French National Anthem : d=4,o=5,b=225:8d,p,d,8g,p,8g,p,8a,p,8a,p,8d6,8d6,p,b,g,2p,g,8b,g,8e,p,8c6,c6,2p,p,8a,f#,8g,";
const char PROGMEM BS_OOPS[]  = "Britney Spears - Oops I Did It again:d=4,o=5,b=100:g#6,c#6,8c6,8c#6,8d#6,c#.6,8p,8b,8b,8d#6,8f#6,e.6,8p,8b,8f#6,8g#6,8f#6,e.6,8p,8g#6,8f#6,8e6,8c#6,8c6,g#6,c#6,8c6,8c#6,8d#6,16e6,16d#6,c#6,8p,16b,16b,8b,8d#6,8f#6,a6,g#6,f#6,8e6,8p,8e6,g#6,g#6,8f#6,8e6,c#6,";

void setup() {
  Serial.begin(115200);
  while (!Serial) ;
  Serial.println(F("Hello World! I'll alive."));
  Serial.print(F("Starting "));
  Serial.println(__FILE__);

  for (auto i = 2; i <= 11; ++i) pinMode(i, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(SOUND_PIN, OUTPUT);
  delay(1000);
}

void loop() {
  const char* m[] = { ELISE, JB_THEME, MARSEILLAISE, BS_OOPS };
  
  for (byte i = 0 ; i < sizeof(m)/sizeof(m[0]); ++i) {
    Serial.print(F("Loading "));
    const RTTTL melody((__FlashStringHelper*)m[i]);
    Serial.println(melody.name());

    Serial.print(F("Press button to start... "));
    while (digitalRead(BUTTON_PIN)) ;
    Serial.println(F("Ok!"));

    Serial.print(F("Playing... "));
    melody.play(SOUND_PIN);
    Serial.println(F("Done."));
  }
}
