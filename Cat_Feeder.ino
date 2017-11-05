// now.pde
// Prints a snapshot of the current date and time along with the UNIX time
// Modified by Andy Wickert from the JeeLabs / Ladyada RTC library examples
// 5/15/11

#include <Wire.h>
#include "DS3231.h"
int menit;
int servonya = 7;
int i;



RTClib RTC;

void setup () {
    Serial.begin(57600);
    Wire.begin();
    pinMode (servonya, OUTPUT);   
}

void naik(char j)
{
 for (i=0;i<j;i++){
  
digitalWrite(servonya, HIGH);
delayMicroseconds(1800);
digitalWrite(servonya, LOW);
delay(0);    }     
}

void turun(char j)
{
 for (i=0;i<j;i++){
  
digitalWrite(servonya, HIGH);
delayMicroseconds(2100);
digitalWrite(servonya, LOW);
delay(50);    }     
}
void loop () {
  
    delay(1000);
  
    DateTime now = RTC.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    menit=now.second();

    if(menit==10)
    {
      Serial.print(" sayaaa aaaabbccc");
      naik(10);
      turun(20);
      }

    if(menit==40)
    {
      Serial.print(">>>>>> sayaaa aaaabbccc");
      naik(10);
      turun(20);
      }

        if(menit==20)
    {
      Serial.print(">>>>>> sayaaa aaaabbccc");
      naik(10);
      turun(20);
      }
        if(menit==30)
    {
      Serial.print(">>>>>> sayaaa aaaabbccc");
      naik(10);
      turun(20);
      }

              if(menit==50)
    {
      Serial.print(">>>>>> sayaaa aaaabbccc");
      naik(10);
      turun(20);
      }

              if(menit==59)
    {
      Serial.print(">>>>>> sayaaa aaaabbccc");
      naik(10);
      turun(20);
      }
}


