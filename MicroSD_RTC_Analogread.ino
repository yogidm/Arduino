#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "DS3231.h"

RTClib RTC;
const int chipSelect = 4;
int jam,menit,detik;
String waktu, tanggal;
File myFile;

void setup() {
   Wire.begin();
   pinMode(12, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  if (SD.exists("dataldr.csv")) {
    Serial.println("dataldr.txt exists.");
  } else {
    Serial.println("dataldr.txt doesn't exist.");
  }
 Serial.println("Creating example.txt...");
  myFile = SD.open("dataldr.csv", FILE_WRITE);
  myFile.close();

    if (SD.exists("dataldr.csv")) {
    Serial.println("dataldr.txt exists.");
  } else {
    Serial.println("dataldr.txt doesn't exist.");
  }

  
}

void loop() {
  digitalWrite(12, HIGH);
  DateTime now = RTC.now();
  String jam=String (now.hour(),DEC);
  String menit=String (now.minute(),DEC);
  String detik=String (now.second(),DEC);
  String waktu=String(jam + ":" + menit + ":" + detik);
 // Serial.println(waktu);
  //Serial.println(now.second(),DEC);
  

  
  // make a string for assembling the data to log:
  String dataString = "";
  String suhuc= "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
     
    int suhu = analogRead(1);
    float c=(suhu*5.0*100)/1024;
    //int c=suhu/9.31;
    suhuc=c;
      dataString += ",";
    }
  }


  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("dataldr.csv", FILE_WRITE);

  // if the file is available, write to it:
  if (myFile) {
    myFile.println(waktu + "," + dataString + ","+ suhuc);
    myFile.close();
    // print to the serial port too:
    Serial.println(waktu + "," + dataString + ","+ suhuc);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening...");
  }

  delay(100);
}









