/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 25 July 2009
 by David A. Mellis
 
 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */


// include the library code:
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"


Adafruit_LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buttonUp = 24;
int buttonDown =26;

int angka =0 ;
int bacaTombolUp =0;
int bacaTombolDown=0;

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
   }

void loop() {
  bacaTombolUp = digitalRead(buttonUp);
  bacaTombolDown = digitalRead(buttonDown);
  if (bacaTombolUp == HIGH)
  {
    angka=angka+1;
    }
   if (bacaTombolDown == HIGH)
   {
      angka=angka-1;
    }

 lcd.clear();
 lcd.setCursor(0, 1);
 lcd.print(angka);
 delay(50);

  
}

