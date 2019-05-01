
#include <Password.h> // https://playground.arduino.cc/uploads/Code/Password/index.zip
#include <Keypad.h> // http://www.arduino.cc/playground/uploads/Code/Keypad.zip

// set password yang benar
Password password = Password( "1234" );

const byte ROWS = 4; //empat baris
const byte COLS = 4; //empat kolom

// definisi keypad
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

// inisialisasi LED RGB
byte ledPin = 12;
byte ledPin2 = 11;
byte ledPin3 = 10;
int servonya = A0;
int i;

// buat objek keypad baru
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);

  pinMode (servonya, OUTPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);

  Serial.println(".: Selamat Datang :.\n");
  Serial.println("Masukkan Password Anda");

  keypad.addEventListener(keypadEvent);
}

void loop() {
  keypad.getKey();
}

// bvuat keadaan saat keypad ditekan
void keypadEvent(KeypadEvent eKey) {

  switch (keypad.getState()) {
    case PRESSED:
      //Serial.print("Pressed: ");
      Serial.println(eKey);

      switch (eKey) {
        case '*': checkPassword();
          //Serial.print("Masukkan Password: \n");
          break;

        case '#': password.reset();
          Serial.print("Password Dibersihkan \n");
          digitalWrite(ledPin, LOW);
          digitalWrite(ledPin2, LOW);
          digitalWrite(ledPin3, HIGH);
          break;

        default: password.append(eKey);
      }
  }
}

// check password yang ditekan
void checkPassword() {

  // jika password benar
  if (password.evaluate()) {
    Serial.println("Password Benar!\n");
    Serial.println("Anda dapat menggunakan fasilitas kami.\n");
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    naik(20);
  }

  // jika password salah
  else {
    Serial.println("Password Salah!\n");
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    turun(20);
  }
}

void naik(char j)
{
  for (i = 0; i < j; i++) {

    digitalWrite(servonya, HIGH);
    delayMicroseconds(1900);
    digitalWrite(servonya, LOW);
    delay(50);
  }
}

void turun(char j)
{
  for (i = 0; i < j; i++) {

    digitalWrite(servonya, HIGH);
    delayMicroseconds(1400);
    digitalWrite(servonya, LOW);
    delay(50);
  }
}

