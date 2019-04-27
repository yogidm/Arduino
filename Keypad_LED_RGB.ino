#include <Keypad.h>

const byte ROWS = 4; //empat baris
const byte COLS = 4; //empat kolom

//inisialisasi huruf pada keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
//hubungkan pada pin baris
byte rowPins[ROWS] = {5, 4, 3, 2};

//hubungkan pada pin kolom
byte colPins[COLS] = {7, 6, 8, 9};


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 12;
byte ledPin2 = 11;
byte ledPin3 = 10;

boolean blink = false;
boolean ledPin_state;
boolean ledPin_state2;
boolean ledPin_state3;

void setup() {
  Serial.begin(9600);

  //inisialisai pinMode
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  //Nyalakan semua warna LED
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);

  //Posisi logika LED trakhir
  ledPin_state = digitalRead(ledPin);
  ledPin_state2 = digitalRead(ledPin2);
  ledPin_state3 = digitalRead(ledPin3);

  // Tambahkan event keypad
  keypad.addEventListener(keypadEvent);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
  }
  if (blink) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    digitalWrite(ledPin2, !digitalRead(ledPin2));
    digitalWrite(ledPin3, !digitalRead(ledPin3)); // Change the ledPin from Hi2Lo or Lo2Hi.
    delay(100);
  }
}

// untuk event salah satu keypad tertekan.
void keypadEvent(KeypadEvent key) {
  switch (keypad.getState()) {
    case PRESSED:
      if (key == '#') {
        digitalWrite(ledPin, !digitalRead(ledPin));
        ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
      }

      if (key == '0') {
        digitalWrite(ledPin2, !digitalRead(ledPin2));
        ledPin_state2 = digitalRead(ledPin2);        // Remember LED state, lit or unlit.
      }
      if (key == '*') {
        digitalWrite(ledPin3, !digitalRead(ledPin3));
        ledPin_state3 = digitalRead(ledPin3);        // Remember LED state, lit or unlit.
      }
      break;
    // Event saat keypad dilepas
    case RELEASED:
      if (key == '9') {
        digitalWrite(ledPin, ledPin_state);
        digitalWrite(ledPin2, ledPin_state2);
        digitalWrite(ledPin3, ledPin_state3); // Restore LED state from before it started blinking.
        blink = false;
      }
      break;
    //event keypad saat ditekan dan ditahan
    case HOLD:
      if (key == '9') {
        blink = true;    // Blink the LED when holding the * key.
      }
      break;
  }
}
