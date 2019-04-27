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

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){

    //Tampilkan pada serial monitor hasil pembacaan
    Serial.println(key);
  }
}
