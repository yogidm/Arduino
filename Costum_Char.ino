#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte customChar[8] = {
0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b11111,
  0b01010,
  0b00000
};

void setup() {
  lcd.createChar(0, customChar);
  lcd.begin(16, 2);  
lcd.write((uint8_t)0);
}

void loop() {}
