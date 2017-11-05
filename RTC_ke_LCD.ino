#include <Wire.h>
#include "Adafruit_LiquidCrystal.h"
#include "DS3231.h"

RTClib RTC;
Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Wire.begin();
  lcd.begin(16, 2);
  
}

void loop() {
  lcd.clear();
  DateTime now = RTC.now();
  lcd.print("Jam=> ");
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  
  lcd.setCursor(0,1);
  lcd.print("Tgl=> ");
  lcd.print(now.day());
  lcd.print("-");
  lcd.print(now.month());
  lcd.print("-");
  lcd.print(now.year());
  delay(1000);
  
}
